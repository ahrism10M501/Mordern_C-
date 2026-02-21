// #define STL_SET
#ifdef STL_SET

#include <iostream>
#include <set>

/*
	set도 연관 컨테이너이다.
	map보다 간결하게 키만 가지고 있다고 생각하자
	값이 중복되지 않으며, 자동으로 값이 정렬된다.
*/

using namespace std;

int main(void) {
	set<int> s;
	pair<set<int>::iterator, bool> pr;

	s.insert(10);
	s.insert(10);
	s.insert(20);
	s.insert(60);
	s.insert(40);
	s.insert(40);
	s.insert(50);
	pr = s.insert(40);
	pr = s.insert(10);

	for (auto i = s.begin(); i != s.end(); ++i) {
		cout << *i << " ";
	} cout << endl;

	s.insert(pr.first, 55);

	for (auto i = s.begin(); i != s.end(); ++i) {
		cout << *i << " ";
	} cout << endl;

	auto f = s.find(55);
	if (f != s.end()) {
		cout << *f << endl;
	}

	return 0;
}

#endif