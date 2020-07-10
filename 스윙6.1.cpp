#include <iostream>
#include <string>
using namespace std;

class ATM {
private:
	string name; //계좌주 이름
	int pw; // 계좌 비밀번호
	int money; // 계좌 잔액
public:
	ATM();
	ATM(int n, ATM* atm); // 생성자
	void deposit(); // 입금
	void withdraw(); // 인출
	void send(string receiver, int receiveMon); // 이체 - 받음
	void receive(int sendMon); // 이체 - 보냄
	int getMoney(); // 얼마있는지 출력
	string getName(); // 이름 불러오기
	void checking();
};

ATM::ATM() {}

string ATM::getName() {
	return name;
}

void ATM::deposit() {
	int input;

	cout << "입금할 금액을 입력해주세요 >> ";
	cin >> input;
	money += input;
	cout << endl << "현재 " << name << "님의 잔액은 " << money << "원 입니다." << endl;
}

void ATM::withdraw() {
	int input, pass;

	cout << "얼마를 인출하시겠습니까? >> ";
	cin >> input;
	cout << "비밀 번호를 입력해 주세요 >> ";
	cin >> pass;

	if (pass != pw) {
		do
		{
			cout << "비밀 번호가 틀렸습니다." << endl << "다시 입력해 주세요 >> ";
			cin >> pass;
		} while (pass != pw);
	}

	money -= input;
	cout << endl << "현재 " << name << "님의 잔액은 " << money << "원 입니다." << endl;
}

void ATM::send(string receiver, int receiveMon) {
	money += receiveMon;
}

void ATM::receive(int sendMon) {
	money -= sendMon;
}

int ATM::getMoney() {
	return money;
}

ATM::ATM(int n, ATM* atm) {
	int check;

	for (int i = 0; i < n; i++)
	{
		cout << "\n성명을 입력하세요 >> ";
		cin >> atm[i].name;
		atm[i];
		do
		{
			cout << "비밀번호를 입력해주세요 >> ";
			cin >> atm[i].pw;
			cout << "한 번 더 입력해주세요 >> ";
			cin >> check;
			if (atm[i].pw != check)
				cout << "\n비밀번호가 서로 다릅니다.\n";
		} while (atm[i].pw != check);
		cout << "입금할 금액을 입력해주세요 >> ";
		cin >> atm[i].money;
	}
};

void ATM::checking()
{
	int epw;
	cin >> epw;

	if (epw != pw)
	{
		while (epw != pw) // 입력된 비밀번호가 pw와 다를 때 계속 반복
		{
			cout << "비밀번호가 틀렸습니다." << endl;
			cout << "비밀번호를 입력해주세요 >> ";
			cin >> epw;
		}
	}
};

int main(void) {
	int n = 0, count = 0, k = -1;
	int inputnum = 0, sendMon = 0;
	string customer, receiver, epw;

	cout << "은행에 가입할 인원을 입력해주세요 > ";
	cin >> n;
	ATM* atm = new ATM[n];
	ATM(n, atm);

	do
	{
		count = 0;
		cout << endl << "--- SWING ATM ---" << endl;
		cout << "성함을 입력해주세요 (종료라면 x를 입력해주세요) >> ";
		cin >> customer;

		for (int i = 0; i < n; i++) {
			if (customer == atm[i].getName()) {
				break;
			}
			count++;
		}

		if (count >= n && customer!="x") {
			cout << endl << "존재하지 않는 계좌주입니다." << endl;
			continue;
		}

		if (count < n) {
			do
			{
				cout << endl << endl << "--- SWING ATM " << customer << " ---" << endl;
				cout << "1. 입금" << endl << "2. 인출" << endl << "3. 이체" << endl << "4. 잔액 확인" << endl << "5. 종료" << endl;
				cout << endl << "번호를 선택해주세요 >> ";
				cin >> inputnum;

				switch (inputnum)
				{
				case 1:
					atm[count].deposit();
					break;
				case 2:
					atm[count].withdraw();
					break;
				case 3:
					k = 0;
					cout << "누구에게 보내겠습니까? >> ";
					cin >> receiver;
					for (int i = 0; i < n; i++) {
						if (receiver == atm[i].getName()) {
							k++;
							break;
						}
					}
					cout << "비밀번호를 입력해주세요 >> ";
					atm[count].checking();

					if (k == 1) {
						cout << "얼마를 보내시겠습니까? >> ";
						cin >> sendMon;
						int receiveMon = sendMon;
						atm[k].send(receiver, receiveMon);
						atm[count].receive(sendMon);
					}
					break;
				case 4:
					cout << atm[count].getName() << "님의 현재 잔액은 " << atm[count].getMoney() << "원 입니다.";
					break;
				}

			} while (inputnum != 5);
		}
		continue;
	} while (customer != "x");

	delete[] atm;
	return 0;
}
