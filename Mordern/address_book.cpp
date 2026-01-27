/*
	모던 C++ 프로그래밍 책의 기초 내용을 바탕으로 작성한 주소록 프로그램
	나중에 객체지향을 적용하면 더 좋겠지만, 이번에는 기초적인 구조체와 입출력 함수로 구현했다
*/

#include <iostream>
#include <string>
#include "Infos.h"

void inputOwnerInfo(Infos::OwnerInfo &owner) {
	std::cout << "Enter owner's name: ";
	std::cin.getline(owner.name, 20);
	std::cout << "Enter owner's phone number: ";
	std::cin.getline(owner.phoneNumber, 15);
	std::cout << "Enter owner's email: ";
	std::cin.getline(owner.email, 30);
	std::cout << "Enter owner's address: ";
	std::cin.getline(owner.address, 50);
	std::cout << "Enter owner's Twitter account: ";
	std::cin.getline(owner.twitterAccount, 20);
	std::cout << "Owner information recorded successfully.\n";
}

void outputOwnerInfo(const Infos::OwnerInfo &owner) {
	std::cout << "Owner's Name: " << owner.name << "\n";
	std::cout << "Owner's Phone Number: " << owner.phoneNumber << "\n";
	std::cout << "Owner's Email: " << owner.email << "\n";
	std::cout << "Owner's Address: " << owner.address << "\n";
	std::cout << "Owner's Twitter Account: " << owner.twitterAccount << "\n";
}

Infos::ContactInfo addContact(Infos::ContactInfo &contact) {
	std::cout << "Enter contact's name: ";
	std::cin.getline(contact.name, 20);
	std::cout << "Enter contact's phone number: ";
	std::cin.getline(contact.phoneNumber, 15);
	std::cout << "Enter contact's email: ";
	std::cin.getline(contact.email, 30);
	std::cout << "Enter contact's address: ";
	std::cin.getline(contact.address, 50);
	std::cout << "Contact added successfully.\n";

	return contact;
}

void outputContactList(const Infos::ContactInfo contacts[], int contactSize) {
	int i;
	for (i = 0; i < contactSize; i++) {
		std::cout << i << ":" << contacts[i].name << "\n"; // std::endl은 flush를 유발하므로 성능 저하가 있을 수 있음
	}
}

// 객체로 만들었으면 이것보다 더 깔끔했을텐데, 지금은 이렇게 매개변수가 많은 더러운 코드다
int removeContactByIndex(Infos::ContactInfo contacts[], int &contactSize, int index) {
	if (index < 0 || index >= contactSize) {
		std::cout << "Invalid index. No contact removed.\n";
		return contactSize;
	}
	for (int i = index; i < contactSize - 1; i++) {
		contacts[i] = contacts[i + 1];
	}
	contactSize--;
	std::cout << "Contact removed successfully.\n";
	return contactSize; // 참조므로 필요없으나 일관성을 위해 반환
}

void runOwnerMenu(Infos::OwnerInfo &owner);
void runContactMenu(Infos::ContactInfo contacts[], int contactSize);

void runMainMenu() {
	int menuNumber = 0;
	Infos::OwnerInfo owner;
	const int contactSize = 100;
	Infos::ContactInfo contacts[contactSize];

	do {
		std::cout << "Address Book Main Menu\n";
		std::cout << "1. Switching Owner Menu\n";
		std::cout << "2. Switching Contact Menu\n";
		std::cout << "3. Exit\n";
		std::cout << "Select an option: ";

		std::cin >> menuNumber;
		std::cin.ignore();

		switch (menuNumber) {
		case 1:
			runOwnerMenu(owner);
			break;
		case 2:
			runContactMenu(contacts, contactSize);
			break;
		case 3:
			std::cout << "Exiting the program.\n";
			break;
		default:
			std::cout << "Invalid option. Please try again.\n";
			break;

		}
	} while (menuNumber != 3);
}

void runOwnerMenu(Infos::OwnerInfo &owner) {
	int menuNumber = 0;
	do {
		std::cout << "Owner Information Menu\n";
		std::cout << "1. Input Owner Information\n";
		std::cout << "2. View Owner Information\n";
		std::cout << "3. Return to Main Menu\n";
		std::cout << "Select an option: ";
		std::cin >> menuNumber;
		std::cin.ignore();
		switch (menuNumber) {
		case 1:
			inputOwnerInfo(owner);
			break;
		case 2:
			outputOwnerInfo(owner);
			break;
		case 3:
			std::cout << "Returning to Main Menu.\n";
			break;
		default:
			std::cout << "Invalid option. Please try again.\n";
			break;
		}
	} while (menuNumber != 3);
}

int contactCount = 0;

void runContactMenu(Infos::ContactInfo contacts[], int contactSize) {
	int menuNumber = 0;
	do {
		std::cout << "Contact Information Menu\n";
		std::cout << "1. Input Contact Information\n";
		std::cout << "2. View Contact Information\n";
		std::cout << "3. Return to Main Menu\n";
		std::cout << "Select an option: ";
		std::cin >> menuNumber;
		std::cin.ignore();
		switch (menuNumber) {
		case 1:
			addContact(contacts[contactCount++]); // 이래서 객체지향이 필요함
			break;
		case 2:
			outputContactList(contacts, contactSize);
			break;
		case 3:
			std::cout << "Returning to Main Menu.\n";
			break;
		default:
			std::cout << "Invalid option. Please try again.\n";
			break;
		}
	} while (menuNumber != 3);
}

/*
int main() {
	runMainMenu();
	return 0;
}
*/