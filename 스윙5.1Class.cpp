#include <iostream>
using namespace std;

#include <class.h>

void phoneBook::addPhone() {
	cout << "�̸��� �Է����ּ��� >> ";
	cin >> name;
	cout << "��ȭ��ȣ�� �Է����ּ��� >> ";
	cin >> phoneNum;
}

void phoneBook::editPhone() {
	string inputname;

	cout << "�̸��� �Է����ּ��� >> ";
	cin >> inputname;

	while (inputname != name) {
		cout << "����ó�� �������� �ʽ��ϴ�. �ٽ� �Է����ּ���";
		cin >> inputname;
	}
	name = inputname;
	cout << "������ ��ȭ��ȣ�� �Է��� �ּ��� >> ";
	cin >> phoneNum;
}

string phoneBook::getName() {
	return name;
}

string phoneBook::getPnum() {
	return phoneNum;
}