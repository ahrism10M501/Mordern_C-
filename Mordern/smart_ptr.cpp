#include <iostream>
#include <memory>
#include <cstring>

using namespace std;

class Chulsoo {
private:
	char* name;
	int* age;
public:
	Chulsoo(const char* inputName, int inputAge) {
		name = new char[strlen(inputName) + 1];
		strcpy_s(this->name, strlen(inputName) + 1, inputName);

		age = new int;
		*age = inputAge;

		cout << "Chulsoo constructed: " << name << ", " << *age << endl;
	}

	~Chulsoo() {
		delete[] name;
		delete age;
		cout << "Chulsoo destructed." << endl;
	}

	void introduce();
};

/*
int main(void) {
	// Chulsoo* pChulsoo = new Chulsoo("Chulsoo", 25);
	// pChulsoo->introduce();
	
	// delete pChulsoo;
	
	//unique_ptr<Chulsoo> chulsooSmptr(new Chulsoo("Chulsoo", 25));
	auto chulsooSmptr = make_unique<Chulsoo>("Chulsoo", 25);

	// unique는 대입, 참조 불가. std::move 함수로 소유권을 이동시키기
	// like singleton
	shared_ptr<Chulsoo> chulsoo2 = move(chulsooSmptr);
	shared_ptr<Chulsoo> chulsoo3 = chulsoo2;
	chulsooSmptr->introduce();
	chulsoo2->introduce();

	return 0;
}
*/