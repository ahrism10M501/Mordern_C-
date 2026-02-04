#include <iostream>
#include <cstring>

using namespace std;

class Chulsoo {
private:
	char* name;
	int* age;
public:
	Chulsoo(const char* inputName, int inputAge) {
		name = new char[strlen(inputName) + 1];
		strcpy_s(this->name, strlen(inputName)+1, inputName);
		
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
	Chulsoo* pChulsoo = new Chulsoo("Chulsoo", 25);
	pChulsoo->introduce();
	
	delete pChulsoo; // malloc/free 와 달리 new/delete는 객체 생성자와 소멸자가 호출된다
	return 0;
}
*/
void Chulsoo::introduce() {
	cout << "Hello, my name is " << name << " and I am " << *age << " years old." << endl;
}