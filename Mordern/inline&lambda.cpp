#include <iostream>

class Chulsoo {
	public:
		int count;
		void Eat(int steakWeight);
		inline void EatInline(int steakWeight) {
			std::cout << "Chulsoo is eating " << steakWeight << " grams of steak (inline)." << std::endl;
		}
};

int main(void) {
	Chulsoo chulsoo;
	chulsoo.Eat(500);
	chulsoo.EatInline(300);
	
	// [캡쳐] <> mutable (예외목록) -> (반환형) { (함수 내용) } 
	[] (int steakWeight) { std::cout << "lambda " << steakWeight << std::endl; } (3000);

	// capture -> 외부 변수를 람다 내부로 끌어들임
	// [] : 캡쳐 없음
	// [=] : 외부 변수를 값으로 캡쳐, const로 가져오므로 수정 불가, 수정하고 싶으면 mutable 키워드 사용
	// [&] : 외부 변수를 참조로 캡쳐
	// [a, &b] : a는 값으로, b는 참조로 캡쳐
	// [=, &a, &b] : 기본값은 값으로 캡쳐이나, a와 b는 참조로 캡쳐
	// 이처럼 캡쳐 방식을 세밀하게 지정할 수 있다

	chulsoo.count = 0;
	for (int i = 0; i < 5; ++i) {
		/*[=] (int steakWeight)  { 
			std::cout << "lambda with capture by value " << steakWeight << ", count: " << chulsoo.count++ << std::endl; 
			} (1000);*/ // error: chulsoo is captured by value, but count is modified
		[=](int steakWeight) mutable {
			std::cout << "lambda with capture by value " << steakWeight << ", count: " << chulsoo.count++ << std::endl;
			} (1000);
		[&](int steakWeight) {
			std::cout << "lambda2 with capture by value " << steakWeight << ", count: " << chulsoo.count++ << std::endl;
			} (1000);


	}
	std::cout << [=](int steakWeight) mutable -> char {
		std::cout << "lambda2 with capture by value " << steakWeight << ", count: " << chulsoo.count++ << std::endl;
		return steakWeight;
		} (57) << std::endl;
	std::cout << [=](int steakWeight) mutable -> int {
		std::cout << "lambda2 with capture by value " << steakWeight << ", count: " << chulsoo.count++ << std::endl;
		return steakWeight;
		} (57) << std::endl;
	std::cout << [=](int steakWeight) mutable {
		std::cout << "lambda2 with capture by value " << steakWeight << ", count: " << chulsoo.count++ << std::endl;
		return steakWeight;
		} (57) << std::endl; // 반환형 지정 안 하면 return steakWeight의 타입으로 추론

	return 0;
}

void Chulsoo::Eat(int steakWeight) {
	std::cout << "Chulsoo is eating " << steakWeight << " grams of steak." << std::endl;
}

// 일반 함수는 호출 형식으로, 인라인 함수는 코드 삽입으로
// 즉, 일반 함수는 호출 오버헤드, 호출 시 내부 jmp 문으로 왔다갔다 하느라 시간이 들지만
// 인라인은 곧바로 그아래 대체되므로 호출 오버헤드가 없다
// 다만! 10번 100번 호출하면 그만큼 코드가 커지므로, 너무 크고 자주 사용하는 함수는 인라인으로 만들지 않는 것이 좋다

// 프로그래머가 코드에서 인라인 함수를 호출할 때 덮어씌워진다. getter나 setter에 쓰기 좋나?