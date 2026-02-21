// #define STL_MAP
#ifdef STL_MAP

#include <iostream>
#include <map>

/*
	map은 연관 컨테이너이다 
	연관 컨테이너는 크게 map과 set으로 나뉘며 map, multimap, set, multuset 등이 있다.
	또한 python의 딕셔너리와 거의 동일한 unordered_map과 셋과 비슷한 unordered_set도 있다

	map은 키:값 쌍으로 데이터를 저장하며, 키의 중복을 허용하지 않는다.
*/

using namespace std;

int main(void) {
	map<string, int> m;

	m.insert(make_pair("A", 10));
	m.insert(make_pair("B", 40));
	m.insert(make_pair("C", 30));
	m.insert(make_pair("D", 20));
	m.insert(make_pair("E", 10));

	for (auto i = m.begin(); i != m.end(); ++i) {
		cout << "[" << i->first << " " << i->second << "] ";
	} cout << endl;

	auto i = m.find("A"); // 키의 위치 찾기

	// auto를 안 쓴다면
	// 이전 방식
	map<string, int>::iterator i2 = m.find("B");
	
	// full name
	_Tree_iterator<class std::_Tree_val<struct std::_Tree_simple_types<struct std::pair<class std::basic_string<char, struct std::char_traits<char>, class std::allocator<char> > const, int>>>> i3 = m.find("C");

	cout << i->second << endl; // 키를 이용해 값 찾기. first가 키, second가 값
	cout << i2->second << endl;
	cout << i3->second << endl;
	
	return 0;
}

#endif