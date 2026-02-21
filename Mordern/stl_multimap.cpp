// #define STL_MULTI_MAP
#ifdef STL_MULTI_MAP

#include <iostream>
#include <map>

/*
	map은 연관 컨테이너이다
	연관 컨테이너는 크게 map과 set으로 나뉘며 map, multimap, set, multuset 등이 있다.
	또한 python의 딕셔너리와 거의 동일한 unordered_map과 셋과 비슷한 unordered_set도 있다

	multi_map은 키:값 쌍으로 데이터를 저장하며, 키의 중복을 허용한다.
	따라서, 중복되는 여러 값이 있을 떄는 lower_bound(), upper_bound()로 범위를 조사하고 인덱스로 접근하거나
	equal_range() 를 이용해 특정 ket 값을 가지는 multimap을 찾을 수 있다
*/

using namespace std;

int main(void) {
	multimap<string, int> m;

	m.insert(make_pair("A", 10));
	m.insert(make_pair("B", 40));
	m.insert(make_pair("C", 30));
	m.insert(make_pair("D", 20));
	m.insert(make_pair("E", 10));
	m.insert(make_pair("C", 100));
	m.insert(make_pair("C", 200));
	m.insert(make_pair("C", 300));

	for (auto i = m.begin(); i != m.end(); ++i) {
		cout << "[" << i->first << " " << i->second << "] ";
	} cout << endl;

	auto i = m.find("C"); // 키의 위치 찾기, 중복되는 값 중 첫 번째 것을 가져온다
	cout << i->second << endl;

	auto lo_bo = m.lower_bound("C");
	auto up_bo = m.upper_bound("C");
	for (auto i = lo_bo; i != up_bo; ++i) {
		cout << "[" << i->first << " " << i->second << "] ";
	} cout << endl;

	auto eq_ra = m.equal_range("C");
	
	// eq_ra는 pair 형태로 나옴
	// first는 lower_bound, second는 upper_bound와 동일함
	for (auto i = eq_ra.first; i != eq_ra.second; ++i) {
		cout << "[" << i->first << " " << i->second << "] ";
	} cout << endl;

	return 0;
}

#endif