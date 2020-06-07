#include <iostream>
using namespace std;

#include <class.h>

void phoneBook::addPhone() {
	cout << "이름을 입력해주세요 >> ";
	cin >> name;
	cout << "전화번호를 입력해주세요 >> ";
	cin >> phoneNum;
}

void phoneBook::editPhone() {
	string inputname;

	cout << "이름을 입력해주세요 >> ";
	cin >> inputname;

	while (inputname != name) {
		cout << "연락처가 존재하지 않습니다. 다시 입력해주세요";
		cin >> inputname;
	}
	name = inputname;
	cout << "변경할 전화번호를 입력해 주세요 >> ";
	cin >> phoneNum;
}

string phoneBook::getName() {
	return name;
}

string phoneBook::getPnum() {
	return phoneNum;
}