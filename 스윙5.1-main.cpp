#include <iostream>
using namespace std;
#include "Class.h"

int main() {
	phoneBook A;
	int answer = 0;
	cout << "--- swing 전화번호부 ---" << endl;
	A.addPhone();

	while (answer != 3) {
		cout << "1. 최신 등록 전화번호 조회" << endl;
		cout << "2. 최신 등록 전화번호 수정" << endl;
		cout << "3. 종료 " << endl << " >> ";
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
