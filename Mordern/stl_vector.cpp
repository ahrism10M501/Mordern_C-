#ifdef VECTOR_STL1

#include <iostream>
#include <vector>
#include <typeinfo>

int main(void) {
	std::vector<int> v(5, 3); // 크기 5, 초기값 3으로 벡터 생성

	v.push_back(10);
	v.push_back(20);

	std::cout << v[1] << std::endl;
	std::cout << v.at(1) << std::endl; // at을 사용하면 메모리를 관리할 수 있다

	// int 대신 size_t 를 쓰는게 좋다
	for (int i = 0; i < v.size(); ++i) { // 컴파일러 따라 오류가 날 수도 있다. 정확한 타입은 size_type이다
		std::cout << v[i] << " ";
	} std::cout << std::endl;
	
	
	v.assign(3, 10); // 벡터 전체를 10으로 재지정; 크기가 줄어든다!

	for (auto i = 0; i < v.size(); ++i) {
		std::cout << v.at(i) << " ";
	} std::cout << std::endl;
	
	
	v[2] = 100; // 재지정
	v.at(0) = 32;
	v.push_back(50);
	v.push_back(60);

	for (std::vector<int>::size_type i = 0; i < v.size(); ++i) {
		std::cout << v[i] << " ";
	} std::cout << std::endl;
	
	// iterator를 이용해 3번 째 인덱스부터 끝까지 9로 변경
	// 포인터 형식, 3을 더하면 3번째 인덱스를 가리킨다
	// 만약 +10을 하면, 범위를 벗어나므로 런타임 에러가 발생하거나 무한루프에 빠질 수 있다
	for (std::vector<int>::iterator it = v.begin() + 3; it != v.end(); it++) {
		*it = 9;
	}

	// 범위 기반 for문 (C++11>=) 제일 편하다
	// 원래 auto를 쓰는게 일반적이나, vector<int>이므로 int로 명시해보았다
	for (const int& i : v) {
		std::cout << i << " " << typeid(i).name() << std::endl;
		} std::cout << std::endl;

	return 0;
}

#endif