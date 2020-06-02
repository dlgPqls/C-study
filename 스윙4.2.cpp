#include <iostream>
using namespace std;

class phoneBook {
private:
	string phoneNum;
	string name;
public:
	void addPhone();   //입력한 전화번호 등록 함수
	void editPhone();   //전화번호 수정 함수
	string getPnum();   //입력된 전화번호 불러오는(반환하는) 함수
	string getName();   //입력된 이름 불러오는(반환하는) 함수
};

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

int main() {
	phoneBook A;
	int answer = 0;
	cout << "--- swing 전화번호부 ---" << endl ;
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