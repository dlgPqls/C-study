#include <iostream>
using namespace std;

int main() {
	phoneBook A;
	int answer = 0;
	cout << "--- swing ��ȭ��ȣ�� ---" << endl;
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