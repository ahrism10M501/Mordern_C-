// #define STL_FL
#ifdef STL_FL

/*
	list는 double linked list 형식이었던 반면 forward_list는 single linked list다
	1. list 와 비슷하지만 push_back 은 지원되지 않는다. front에만 추가가능
	2. before_begin 이라는 것도 있다. 왜 있지?


*/

#include <iostream>
#include <forward_list>

using namespace std;

template <typename T>
void print_array(const T& lt) {
	for (const auto& val : lt) {
		cout << val << " ";
	} cout << endl;
}

int main(void) {
    forward_list<int> fl = { 1, 2, 3 };

    // 1. 앞쪽에 추가 (O(1))
    fl.push_front(0);
    fl.push_front(-10);

    cout << "initial state: ";
    print_array(fl); // -10 0 1 2 3

    // 단방향 리스트는 '내 다음'은 알지만 '내 이전'은 모릅니다.
    // 그래서 첫 번째 원소(begin) 자리에 무언가를 'insert_after' 하려면
    // 첫 번째의 '이전' 위치가 필요합니다. 그게 바로 before_begin
    auto it = fl.before_begin();
    fl.insert_after(it, 500); // 가장 앞에 500 삽입

    cout << "insert using before_begin: ";
    print_array(fl); // 500 -10 0 1 2 3

    auto it2 = fl.begin(); // 현재 500을 가리킴
    advance(it2, 2);       // 두 칸 이동해서 '0'을 가리킴
    fl.insert_after(it2, 99);

    cout << "insert after: ";
    print_array(fl); // 500 -10 0 99 1 2 3

    // 4. 삭제 (After 방식)
    fl.pop_front();      // 맨 앞 500 삭제
    fl.erase_after(it2); // it2(0)의 다음 원소인 99 삭제

    cout << "after deleting: ";
    print_array(fl); // -10 0 1 2 3

    fl.sort();   // 단방향 리스트 전용 정렬 (O(n log n))
    fl.unique(); // 인접한 중복 원소 제거

    cout << "after sorting: ";
    print_array(fl); // -10 0 1 2 3

    forward_list<int> fl2 = {7, 6, 7, 9};
    for (auto i = fl2.begin(); i != fl2.end(); ++i) {
        if (*i == 30) {
            fl.splice_after(i, fl2);
            break;
        }
    }

    print_array(fl);

    forward_list<int> fl3 = { 100, 200, 300, 400 };
    auto p = fl.before_begin();
    fl.splice_after(p, fl3);
    print_array(fl);

    return 0;
}

#endif