// #define STL_ARRAY
#ifdef STL_ARRAY

/*
	array는 기존 c언어 스타일의 배열과 동일한 기능을 수행하지만
	클래스 객체이므로 유리한 부분이 많다
	
	1. 매개변수 등에 넘길 때 크기 정보가 유지된다
	2. 다른 stl 기능인 begin, end, size 등의 인터페이스가 있다 (간편하다)
	3. 대입 연산자를 사용해 배열을 복사할 수 있다
	4. [] 와 다르게 .at() 을 통해 접근가능하다. -> 프로그램이 죽지 않고, 예외처리 가능하다
	5. 기존 배열과 성능 차이가 없다. 컴파일러라 그렇다

*/

#include <iostream>
#include <array>

using namespace std;

template <typename T>
void print_array(const T& lt) {
	for (const auto& val : lt) {
		cout << val << " ";
	} cout << endl;
}

int main(void) {
	// 크기 정보를 같이 지정해야 한다. 동적할당 불가하다
	array<int, 10> ar;
	ar = { 1, 2, 3 };
	print_array(ar);

	ar.fill(5); // 5로 채우기
	ar.at(3) = 4;
	ar[7] = 8;
	print_array(ar);

}

#endif