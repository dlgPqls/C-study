#include <iostream>
using namespace std;

class PhoneBook {
private:
	string number; // 전화번호
	string name; // 이름
public:
	PhoneBook(); // 생성자
	void setPnum(string number); // 전화번호 저장
	void setName(string name); // 이름 저장
	void addPhone(string name, string number); // 이름과 전화번호 저장
	string getPnum(); // 전화번호 가져오기
	string getName(); // 이름 가져오기
	void editPnum(string number);
};

class PhoneBookManager {
private:
	PhoneBook* phoneB; // 객체 배열 생성을 위한 선언
	int size; // 객체 배열의 크기
public:
	PhoneBookManager();
	PhoneBookManager(int num); // 생성자 – PhoneBook으로 객체 배열 생성
	void showAll(); // 전화번호부 목록 보기
	void searchPnum(); // 전화번호 찾기
	void addPnum(); // 전화번호 객체 추가 생성 (배열의 원소 개수가 +1되야 함)
	void editPnum(); // 전화번호 수정
};

int main(void) {
	int num = 0;
	int inputnum = 0;

	cout << "저장할 전화번호의 수를 입력해주세요 >> ";
	cin >> num;
	PhoneBookManager pbm(num);

	while (inputnum != 5)
	{
		cout << endl << "--- SWING 전화번호부 --- " << endl;
		cout << "1. 전화번호부 보기" << endl;
		cout << "2. 전화번호 검색" << endl;
		cout << "3. 전화번호 추가하기" << endl;
		cout << "4. 전화번호 수정하기" << endl;
		cout << "5. 종료" << endl;
		cout << "번호를 입력하세요 >> ";
		cin >> inputnum;

		switch (inputnum)
		{
		case 1:
			pbm.showAll();
			break;
		case 2:
			pbm.searchPnum();
			break;
		case 3:
			pbm.addPnum();
			break;
		case 4:
			pbm.editPnum();
			break;
		case 5:
			break;
		}
	}
}

PhoneBookManager::PhoneBookManager() {};
PhoneBook::PhoneBook() {}

void PhoneBook::setPnum(string number) {
	this->number = number;
}

void PhoneBook::setName(string name) {
	this->name = name;
}

string PhoneBook::getPnum() {
	return number;
}

string PhoneBook::getName() {
	return name;
}

void PhoneBook::addPhone(string name, string number) {
	this->name = name;
	this->number = number;
}

void PhoneBook::editPnum(string number) {
	this->number = number;
}

PhoneBookManager::PhoneBookManager(int num) {
	string name, number;
	size = num;
	phoneB = new PhoneBook[size];

	cout << endl << "--- SWING 전화번호부 --- " << endl;
	for (int i = 0; i < num; i++) {
		cout << i+1 << "번째 사람의 이름을 입력해주세요. >> ";
		cin >> name;
		cout << i+1 << "번째 사람의 전화번호를 입력해주세요. >> ";
		cin >> number;
		phoneB[i].setName(name);
		phoneB[i].setPnum(number);
		cout << endl;
	}
}

void PhoneBookManager::showAll() {
	cout << endl << endl;
	for (int i = 0; i < size;i++) {
		cout << i+1 << " . ";
		cout << phoneB[i].getName() << " : " << phoneB[i].getPnum() << endl;
	}
}

void PhoneBookManager::searchPnum() {
	string findname;
	int find = 0;

	cout << endl << endl;
	cout << "누구의 번호를 검색하겠습니까? >> ";
	cin >> findname;

	for (int i = 0; i < size; i++) {
		if (findname==phoneB[i].getName()) {
			find++;
			break;
		}
	}
	if (find == 0) {
		cout << "연락처가 존재하지 않습니다.";
	}
	else {
		cout << findname << "님의 전화번호 : " << phoneB[find].getPnum() << endl;
	}
}

void PhoneBookManager::addPnum() {
	string name, pnum;

	size++;
	cout << endl;
	cout << "이름을 입력해주세요 >> ";
	cin >> name;
	cout << "전화번호를 입력해주세요 >> ";
	cin >> pnum;

	PhoneBook* pb = new PhoneBook[size ];

	for (int i = 0; i < size -1; i++) {
		pb[i] = phoneB[i];
	}

	delete[] phoneB;
	size++;

	phoneB = new PhoneBook[size];
	for (int i = 0; i < size-1; i++)
	{
		phoneB[i] = pb[i];
	}

	phoneB[size - 2].addPhone(name, pnum);
}

void PhoneBookManager::editPnum() {
	int count = -1;
	string editname, change;
	cout << endl << endl;
	cout << "누구의 번호를 수정하겠습니까? >> ";
	cin >> editname;
	for (int i = 0; i < size; i++) {
		count++;
		if (editname == phoneB[i].getName()) {
			break;
		}
	}
	if (count >= size) {
		cout << "연락처가 존재하지 않습니다.";
	}
	cout << "변경할 번호를 입력해주세요 >> ";
	cin >> change;

	phoneB[count].editPnum(change);
	cout << "전화번호가 변경되었습니다. " << endl;
}
