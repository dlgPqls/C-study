#include <iostream>
#include<string>

using namespace std;

int main()
{
	string name;
	cout << "�̸��� �Է��ϼ���: ";
	getline(cin, name);
	
	string birth;
	cout << "������ �Է��ϼ���: ";
	getline(cin, birth);
	
	string age;
	cout << "���̸� �Է��ϼ���: ";
	getline(cin, age);

	string belong;
	cout << "�Ҽ� �а��� �Է��ϼ���: ";
	getline(cin, belong);

	cout <<endl<<"==============================" <<endl<< "<ȸ������>" << endl;
	cout << "�̸�: " << name << endl;
	cout << "����: " << birth << endl;
	cout << "����: " << age << endl;
	cout << "�Ҽ� �а�: " << belong << endl;
}