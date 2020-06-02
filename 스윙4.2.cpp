#include <iostream>
using namespace std;

class phoneBook {
private:
	string phoneNum;
	string name;
public:
	void addPhone();   //�Է��� ��ȭ��ȣ ��� �Լ�
	void editPhone();   //��ȭ��ȣ ���� �Լ�
	string getPnum();   //�Էµ� ��ȭ��ȣ �ҷ�����(��ȯ�ϴ�) �Լ�
	string getName();   //�Էµ� �̸� �ҷ�����(��ȯ�ϴ�) �Լ�
};

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

int main() {
	phoneBook A;
	int answer = 0;
	cout << "--- swing ��ȭ��ȣ�� ---" << endl ;
	A.addPhone();

	while (answer != 3) {
		cout << "1. �ֽ� ��� ��ȭ��ȣ ��ȸ" << endl;
		cout << "2. �ֽ� ��� ��ȭ��ȣ ����" << endl;
		cout << "3. ���� " << endl << " >> ";
		cin >> answer;

		switch (answer)
		{
		case 1:
			cout << A.getName() << "::" << A.getPnum() << endl;
			break;
		case 2:
			A.editPhone();
			break;
		}
	}
}