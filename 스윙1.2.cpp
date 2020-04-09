#include<iostream>
using namespace std;

int main()
{
	double num1, num2;

	cout << "첫번째 숫자를 입력하세요: ";
	cin >> num1;
	cout << "두번째 숫자를 입력하세요: ";
	cin >> num2;

	cout << "========계산결과========"<<endl;
	cout << num1 << "+" << num2 << "=" << num1 + num2 << endl;
	cout << num1 << "-" << num2 << "=" << num1 - num2 << endl;
	cout << num1 << "*" << num2 << "=" << num1 * num2 << endl;
	cout << num1 << "/" << num2 << "=" << num1 / num2 << endl;

}