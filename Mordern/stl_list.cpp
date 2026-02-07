// #define STL_LIST
#ifdef STL_LIST

/*
	이중 연결 리스트로 만들어져 있는 순차 컨테이너
	vector는 메모리상 연속
	deque는 연속이 아닐 수 이으나, 블록 단위로 연속
	list는 연속이 아님, 각 노드가 포인터로 연결되어 있음
	논리적으로는 연속적인 데이터를 저장한다
*/

#include <iostream>
#include <list>
#include <string>

using namespace std;

// 엄청 편하다 auto 키워드, C++20부터는 함수 매개변수에도 사용 가능
// 템플릿 함수보다 좋은듯 거의 뭐 파이썬인데?
void print_arr(const auto& arr) {
	for (const auto& val : arr) {
		cout << val << " ";
	} cout << endl;
}

// 원래라면 이런 형식이겠다
template <typename T>
void print_array(const T& lt) {
	for (const auto& val : lt) {
		cout << val << " ";
	} cout << endl;
}

int main(void) {
	list<int> lt;
	list<int> lt2;

	lt.push_back(10);
	lt.push_back(20);
	lt.push_back(30);

	lt2.push_back(12);
	lt2.push_back(33);
	lt2.push_back(55);
	lt2.push_back(2);
	lt2.push_back(0);

	for (auto i = lt.begin(); i != lt.end(); ++i) {
		cout << *i << " "; // 역참조 연산자로 값에 접근
	} cout << endl;

	// deque와 마찬가지로, 앞쪽에 요소 추가 가능
	lt.push_front(-5);
	lt.push_front(-10);
	for (const auto& val : lt) {
		cout << val << " ";
	} cout << endl;

	// 참고로, list는 하나씩 움직여야함
	// deque 마냥 +5 같은거 못 함
	// 즉, 45번째 원소를 알고 싶으면, 1부터 하나씩 올라가야한다는 뜻
	// 인덱스 접근이 빈번하면 vector나 deque 쓰기
	// 대신 자료 중간에 삽입 및 삭제하는게 많다면
	// list가 훨씬 빠름
	for (auto p = lt.begin(); p != lt.end(); ++p) {
		if (*p == 20) { // 데이터에서 20을 찾으면
			lt.insert(p, 15); // 20 앞에 15를 삽입한다
			lt.splice(p, lt2); // 20 앞에 lt2 리스트를 연결한다
			break;
		}
	}

	print_arr(lt);
	print_array<list<int>>(lt);
	print_array(lt); // 템플릿 타입 추론, C++98부터

	// 변수 선언이나 객체 생성 때는 넣어주는게 맞는데
	// C++17 부터는 위 경우에도 추론 기능이 확대되어서 생략 가능

}

#endif