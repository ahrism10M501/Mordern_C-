// #define STL_PRIORITY_QUEUE
#ifdef STL_PRIORITY_QUEUE

/*
	queue에 정렬 기능이 들어갔다
	오름차순, 내림차순이 가능하다
*/

#include <iostream>
#include <queue>

using namespace std;

int main(void) {
	priority_queue<int> pq;
	priority_queue<int, vector<int>, greater<int>> pq2; // vector나 deque를 이용햐서도 만들 수 있다
	priority_queue<int, deque<int>, greater<int>> pq3;

	pq.push(10);
	pq.push(20);
	pq.push(30);
	pq.push(40);
	pq.push(40);
	pq.push(10);
	pq.push(20);

	while (!pq.empty()) {
		cout << pq.top() << " ";
		pq2.push(pq.top());
		pq.pop();
	} cout << endl; // 40 40 30 20 20 10 10 -> 기본적으로 내림차순

	while (!pq2.empty()) {
		cout << pq2.top() << " ";
		pq3.push(pq2.top());
		pq2.pop();
	} cout << endl;

	while (!pq3.empty()) {
		cout << pq3.top() << " ";
		pq3.pop();
	} cout << endl;


	return 0;
}

#endif