#ifdef STD_VECTOR2

#include <iostream>
#include <vector>
#include <typeinfo>

using namespace std;

int main(void) {
	vector<int> v(6, 1);

	cout << "capacity: " << v.capacity() << ", size: " << v.size() << endl;
	for (auto i = 0; i < v.size(); ++i) {
		cout << v[i] << " ";
	} cout << endl;

	v.assign(4, 3); // capacity는 유지되고, size만 변경됨
	cout << "capacity: " << v.capacity() << ", size: " << v.size() << endl;
	for (auto i = 0; i < v.size(); ++i) {
		cout << v.at(i) << " ";
	} cout << endl;

	v[2] = 7;
	for (vector<int>::iterator it = v.begin() + 1; it != v.end(); it++) 
		*it = 9;
	
	v.push_back(10);
	v.push_back(20);
	// push_back 할 때마다 capacity가 늘어나는지 확인
	cout << "capacity: " << v.capacity() << ", size: " << v.size() << endl;
	for (const int& i : v) {
		cout << i << " ";
	} cout << endl;

	v.push_back(30);
	// size가 6에서 7로 늘어나면서 capacity가 9로 늘어난다
	// 이는 메모리 재할당을 안정적으로 하기 위함으로, 초기 설정된 값의
	// 2배로 늘어난다. 컴파일러나 os에 따라 다를 수 있다. MSVC는 1.5배, GCC는 2배
	// 따라서, 벡터에 많은 데이터를 추가할 때는 미리 reserve()로 메모리를 할당받자
	// 그렇지 않으면, 메모리 재할당이 빈번히 일어나 성능이 저하될 수 있다
	// 단, reserve()로 할당받은 메모리는 size에는 영향을 미치지 않는다
	// size는 실제로 벡터에 저장된 데이터의 개수를 의미한다
	// 늘어나는 순간에는 포인터 값의 복사가 일어난다
	// 이를 이동 시맨틱이라 하며, 얕은 복사로 이루어진다
	cout << "capacity: " << v.capacity() << ", size: " << v.size() << endl;
	for (const int& i : v) {
		cout << i << " ";
	} cout << endl;

	v.resize(17);
	cout << "capacity: " << v.capacity() << ", size: " << v.size() << endl;
	for (const int& i : v) {
		cout << i << " ";
	} cout << endl;

	// shrink_to_fit: capacity를 size에 맞게 줄인다
	// 요청일뿐이라 구현에 따라 실제로 안 줄어들수도 있음. 어지간해서는 잘 되는 편
	v.shrink_to_fit();

	vector<int>(v).swap(v); // swap을 이용한 강제 축소
	vector<int>().swap(v); // 완전 비우기
	cout << "capacity: " << v.capacity() << ", size: " << v.size() << endl;

	return 0;
}

#endif