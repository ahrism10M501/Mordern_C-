/*
	double ended queue (deque)
	vector와 비슷하지만, 양쪽 끝에서 삽입과 삭제가 모두 가능한 순차 컨테이너
*/

// #define STD_DEQUE
#ifdef STD_DEQUE

#include <iostream>
#include <deque>

using namespace std;

int main(void) {

	deque<int> dq;

	// 뒤쪽에 요소 추가
	dq.push_back(10);
	dq.push_back(20);

	// 앞쪽에 요소 추가
	dq.push_front(5);
	dq.push_front(1);

	cout << "deque size: " << dq.size() << endl; 

	cout << "Deque elements: ";
	for (const auto& val : dq) {
		cout << val << " ";
	} cout << endl;
	
	// 뒤쪽에서 요소 제거
	dq.pop_back();
	// 앞쪽에서 요소 제거
	dq.pop_front();
	
	cout << "Deque elements after pop: ";
	for (auto i = 0; i < dq.size(); ++i) {
		cout << dq[i] << " ";
	} cout << endl;

	for (auto i = 0; i < 20; ++i) {
		dq.push_back(i * 3);
	}


	// 메모리 관리는 어떻게 되고 있는가!
	// deque는 블록 단위로 메모리를 할당받는다
	// 각 블록은 연속된 메모리 공간이지만, 블록들 간에는 연속적이지 않을 수 있다
	// 예를 들어, deque가 차지하는 메모리가 점점 많아져서, 다른 dq 랑 만나거나 할 때
	// 새로운 블록을 할당받아 연결하는 식으로 동작한다
	// 순차 컨테이너이지만, 메모리 상 끊어져 있을 수 있다.
	// 하지만, 사용자는 마치 연속된 메모리 공간인 것처럼 접근할 수 있다
	// 이는 내부적으로 포인터 배열을 사용하여 각 블록을 관리하기 때문이다
	// 따라서, vector와 달리, deque는 중간에 삽입/삭제가 빈번한 경우에도
	// 성능 저하가 덜하다
	// deque<int>::iterater 를 사용하면 주소가 끊겨있어도 문제없이 접근할 수 있다
	cout << "dq addresses\n";
	for (auto i = 0; i < dq.size(); ++i) {
		cout << &dq[i] << " " << endl;
	}

	return 0;
}


#endif