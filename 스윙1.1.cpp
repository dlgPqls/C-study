#include <iostream>
#include<string>

using namespace std;

int main()
{
	string name;
	cout << "이름을 입력하세요: ";
	getline(cin, name);
	
	string birth;
	cout << "생일을 입력하세요: ";
	getline(cin, birth);
	
	string age;
	cout << "나이를 입력하세요: ";
	getline(cin, age);

	string belong;
	cout << "소속 학과를 입력하세요: ";
	getline(cin, belong);

	cout <<endl<<"==============================" <<endl<< "<회원정보>" << endl;
	cout << "이름: " << name << endl;
	cout << "생일: " << birth << endl;
	cout << "나이: " << age << endl;
	cout << "소속 학과: " << belong << endl;
}