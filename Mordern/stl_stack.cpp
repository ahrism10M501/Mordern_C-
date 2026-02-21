// ㄴ#define STL_STACK
#ifdef STL_STACK

/*
	FILO(First In Last Out), 무거운 원판을 위에 계속 쌓는 것과 같다.
	20kg 10장을 아래서부터 위로 쌓았을 떄, 맨 아래에 있는 원판을 꺼내기 위해서는 위의 것을 먼저 빼야한다.
*/

#include <iostream>
#include <stack>

using namespace std;

int main(void) {
	stack<int> st;

	st.push(10);
	st.push(20);
	st.push(30);
	st.push(40);
	st.push(40);
	st.push(10);
	st.push(20);

	while (!st.empty()) {
		cout << st.top() << " ";
		st.pop();
	} cout << endl; // 20 10 40 40 30 20 10 -> 들어간 순서와 반대로 나온다


	return 0;
}

#endif