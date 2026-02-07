#include <iostream>
#include <vector>
#include <string>

// 디폴트 타입과 템플릿 파라미터
template<typename T = int, int init = 0>
class vector_wrapper {
private:
    std::vector<T> data;
public:
    vector_wrapper() {
        if (init > 0) data.assign(init, T()); // init 개수만큼 기본값으로 채움
    }
    void add_tail(T const&);
    void delete_tail(void);
    void show_data(void) const;
};

// 클래스 선언의 템플릿 인자 개수와 일치시켜야 함
template <typename T, int init>
void vector_wrapper<T, init>::add_tail(T const& value) {
    data.push_back(value);
}

// 이런식으로 템플릿 타입 이름을 바꿔도 됨
// 다만, 관례상, 가독성을 위해, 같은 이름을 사용하는걸 권장함
template <typename piui, int init>
void vector_wrapper<piui, init>::delete_tail(void) {
    if (!data.empty()) {
        data.pop_back();
    }
}

template <typename T, int init>
void vector_wrapper<T, init>::show_data(void) const {
    for (const auto& val : data) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
}

/*
// 귀찮을 땐 gemini
int main(void) {
    // [Case 1] 디폴트 타입(int) 사용, 초기 크기 3으로 설정
    vector_wrapper<int, 3> int_vec;
    int_vec.add_tail(10);
    int_vec.add_tail(20);
    std::cout << "Int Vector: ";
    int_vec.show_data(); // 출력: 0 0 0 10 20 (init에 의해 0이 3개 생성됨)

    // [Case 2] string 타입 사용, 초기 크기
    vector_wrapper<std::string, 0> str_vec;
    str_vec.add_tail("Hello");
    str_vec.add_tail("Template");
    str_vec.delete_tail();
	str_vec.add_tail("World");
    std::cout << "String Vector: ";
    str_vec.show_data();

    return 0;
} // specialized는 귀찮다
*/