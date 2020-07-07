#include <iostream>
#include <string>
using namespace std;

class ATM {
private:
	string name; //������ �̸�
	int pw; // ���� ��й�ȣ
	int money; // ���� �ܾ�
public:
	ATM();
	ATM(int n, ATM* atm); // ������
	void deposit(); // �Ա�
	void withdraw(); // ����
	void send(string receiver, int receiveMon); // ��ü - ����
	void receive(int sendMon); // ��ü - ����
	int getMoney(); // ���ִ��� ���
	string getName(); // �̸� �ҷ�����
	void checking();
};

ATM::ATM() {}

string ATM::getName() {
	return name;
}

void ATM::deposit() {
	int input;

	cout << "�Ա��� �ݾ��� �Է����ּ��� >> ";
	cin >> input;
	money += input;
	cout << endl << "���� " << name << "���� �ܾ��� " << money << "�� �Դϴ�." << endl;
}

void ATM::withdraw() {
	int input, pass;

	cout << "�󸶸� �����Ͻðڽ��ϱ�? >> ";
	cin >> input;
	cout << "��� ��ȣ�� �Է��� �ּ��� >> ";
	cin >> pass;

	if (pass != pw) {
		do
		{
			cout << "��� ��ȣ�� Ʋ�Ƚ��ϴ�." << endl << "�ٽ� �Է��� �ּ��� >> ";
			cin >> pass;
		} while (pass != pw);
	}

	money -= input;
	cout << endl << "���� " << name << "���� �ܾ��� " << money << "�� �Դϴ�." << endl;
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
		cout << "\n������ �Է��ϼ��� >> ";
		cin >> atm[i].name;
		atm[i];
		do
		{
			cout << "��й�ȣ�� �Է����ּ��� >> ";
			cin >> atm[i].pw;
			cout << "�� �� �� �Է����ּ��� >> ";
			cin >> check;
			if (atm[i].pw != check)
				cout << "\n��й�ȣ�� ���� �ٸ��ϴ�.\n";
		} while (atm[i].pw != check);
		cout << "�Ա��� �ݾ��� �Է����ּ��� >> ";
		cin >> atm[i].money;
	}
};

void ATM::checking()
{
	int epw;
	cin >> epw;

	if (epw != pw)
	{
		while (epw != pw) // �Էµ� ��й�ȣ�� pw�� �ٸ� �� ��� �ݺ�
		{
			cout << "��й�ȣ�� Ʋ�Ƚ��ϴ�." << endl;
			cout << "��й�ȣ�� �Է����ּ��� >> ";
			cin >> epw;
		}
	}
};

int main(void) {
	int n = 0, count = 0, k = -1;
	int inputnum = 0, sendMon = 0;
	string customer, receiver, epw;

	cout << "���࿡ ������ �ο��� �Է����ּ��� > ";
	cin >> n;
	ATM* atm = new ATM[n];
	ATM(n, atm);

	do
	{
		cout << endl << "--- SWING ATM ---" << endl;
		cout << "������ �Է����ּ��� (������ x�� �Է����ּ���) >> ";
		cin >> customer;

		for (int i = 0; i < n; i++) {
			if (customer == atm[i].getName()) {
				break;
			}
			count++;
		}

		if (count >= n && customer!="x") {
			cout << endl << "�������� �ʴ� �������Դϴ�." << endl;
			continue;
		}

		if (count < n) {
			do
			{
				cout << endl << endl << "--- SWING ATM " << customer << " ---" << endl;
				cout << "1. �Ա�" << endl << "2. ����" << endl << "3. ��ü" << endl << "4. �ܾ� Ȯ��" << endl << "5. ����" << endl;
				cout << endl << "��ȣ�� �������ּ��� >> ";
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
					cout << "�������� �����ڽ��ϱ�? >> ";
					cin >> receiver;
					for (int i = 0; i < n; i++) {
						if (receiver == atm[i].getName()) {
							k++;
							break;
						}
					}
					cout << "��й�ȣ�� �Է����ּ��� >> ";
					atm[count].checking();

					if (k == 1) {
						cout << "�󸶸� �����ðڽ��ϱ�? >> ";
						cin >> sendMon;
						int receiveMon = sendMon;
						atm[k].send(receiver, receiveMon);
						atm[count].receive(sendMon);
					}
					break;
				case 4:
					cout << atm[count].getName() << "���� ���� �ܾ��� " << atm[count].getMoney() << "�� �Դϴ�.";
					break;
				}

			} while (inputnum != 5);
		}
		continue;
	} while (customer != "x");

	delete[] atm;
	return 0;
}