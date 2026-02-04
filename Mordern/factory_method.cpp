#include <iostream>
#include <memory>
#include <string>

// --- 공통 Product 클래스 ---
class Pizza {
public:
    virtual void prepare() = 0;
    virtual ~Pizza() = default;
};

class CheesePizza : public Pizza {
public:
    // override 키워드: 부모의 가상 함수 재정의라고 컴파일러에 명시적으로 알리는 안전장치
    // 이게 있으면 부모 함수에 같은 이름의 virtual 함수가 있는지 검사, 없으면 에러
    // override 안쓰며느 없으면 그냥 새로운 함수를 만들어버림(다형성)
    void prepare() override { std::cout << "[CheesePizza] 치즈를 듬뿍 뿌립니다.\n"; }
};

class PepperoniPizza : public Pizza {
public:
    void prepare() override { std::cout << "[PepperoniPizza] 페퍼로니를 올립니다.\n"; }
};

// --- 1. 가상 함수 (Traditional Factory Method) ---
class PizzaStore {
public:
    // 템플릿 메서드: 피자를 만드는 전체 공정은 부모가 가짐
    void orderPizza() {
        std::cout << "--- 주문 (Virtual) ---\n";
        std::unique_ptr<Pizza> pizza = createPizza(); // 런타임에 결정됨 (vtable 참조)
        pizza->prepare();
    }

    virtual ~PizzaStore() = default;

protected:
    // 팩토리 메서드: 자식이 구현
    virtual std::unique_ptr<Pizza> createPizza() = 0;
};

// 구현체
class CheesePizzaStore : public PizzaStore {
protected:
    std::unique_ptr<Pizza> createPizza() override {
        return std::make_unique<CheesePizza>();
    }
};

class PepperoniPizzaStore : public PizzaStore {
protected:
    std::unique_ptr<Pizza> createPizza() override {
        return std::make_unique<PepperoniPizza>();
    }
};

// --- 2. CRTP (Static Factory Method) ---
template <typename Derived>
class CRTPPizzaStore {
public:
    void orderPizza() {
        std::cout << "--- 주문 (CRTP) ---\n";
        // 컴파일 타임에 Derived가 누구인지 앎. vtable 오버헤드 없음.
        // this를 자식 포인터로 캐스팅하여 직접 호출
        std::unique_ptr<Pizza> pizza = static_cast<Derived*>(this)->createPizza();
        pizza->prepare();
    }
};

// 구현체: 자기 자신을 부모의 템플릿 인자로 전달
class CRTPCheeseStore : public CRTPPizzaStore<CRTPCheeseStore> {
public: // CRTP에서는 부모가 접근해야 하므로 public이거나 friend 선언 필요
    std::unique_ptr<Pizza> createPizza() {
        return std::make_unique<CheesePizza>();
    }
};

class CRTPPepperoniStore : public CRTPPizzaStore<CRTPPepperoniStore> {
public:
    std::unique_ptr<Pizza> createPizza() {
        return std::make_unique<PepperoniPizza>();
    }
};

// --- 3. 템플릿 방식 (Simple Template / Policy) ---
template <typename PizzaType>
class TemplatePizzaStore {
public:
    void orderPizza() {
        std::cout << "--- 주문 (Template) ---\n";
        // 팩토리 메서드조차 필요 없음. 타입이 곧 생성 로직.
        auto pizza = std::make_unique<PizzaType>();
        pizza->prepare();
    }
};

/*
int main() {
    // 1. 가상 함수 방식 사용
    // 장점: 포인터 하나로 여러 가게를 가리킬 수 있음 (런타임 다형성)
    std::unique_ptr<PizzaStore> store1 = std::make_unique<CheesePizzaStore>();
    store1->orderPizza();

    std::cout << "\n";

    // 2. CRTP 방식 사용
    // 장점: 상속 구조를 유지하면서도 가상함수 비용 제거
    CRTPPepperoniStore store2;
    store2.orderPizza();

    std::cout << "\n";

    // 3. 템플릿 방식 사용
    // 장점: 가장 단순하고 빠름. 상속 불필요.
    TemplatePizzaStore<CheesePizza> store3;
    store3.orderPizza();

    return 0;
}
*/