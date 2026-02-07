// #define STL_QUEUE
#ifdef STL_QUEUE

/*
	컨테이너 어댑터 중 queue
	컨테이너 어댑터는 앞서 배운 순차 컨테이너를 이용해 만들어짐

	queue의 경우 선입 선출의 법칙을 따름 (First In First Out, FIFO)
	놀이공원에 들어가기 위한 줄을 세운다는 것으로 이해하면 되겠다
*/

#include <iostream>
#include <queue>

using namespace std;

int main(void) {
	queue<int> q;

	q.push(10);
	q.push(20);
	q.push(30);
	q.push(40);
	q.push(50);

	// 만약 이렇게 안 쓰고 반복문에 바로 q.size() 를 하면 의도치 않은 결과가 발생한다
	size_t q_size = q.size();

//	for (size_t i = 0; i < q_size; ++i) {
	//	cout << q.front() << " ";
	//	q.pop();
	// }

	while (!q.empty()) {
		cout << q.front() << " ";
		q.pop();
	}
	return 0;
}

#endif