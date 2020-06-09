#include <iostream>
using namespace std;

class VendingMachine
{
private:
	string name;  //�����̸�
	int price;  //����
	int total;  //���� �ջ� ��
public:
	VendingMachine();  //������
	void purchase(double v1);
	void menu();
	string getName();
	double getPrice();
	double newPrice();
	double getTotal();
	void setName(string n);
	void setPrice(int P);
	void setTotal(int t);
};

void VendingMachine::purchase(double v1) {
	int won ;
	cout << "�� �ݾ� : " << v1 << endl;
	cout << "���� �Է��ϼ��� : ";
	cin >> won;

	while (1) {   //�ݾ��� �����ϸ� �ٽ� �ְ� �ݺ��ؾ��Ѵ�.
		if (won == v1) {
			cout << "�Ž������� �����ϴ�. �ȳ���������.";
			break;
		}
		else if (won < v1)
		{
			cout << "�ݾ��� �����մϴ�. �ٽ� �־��ּ��� : ";
			cin >> won;
			continue;
		}
		else if (won > v1)
		{
			int change = won - v1;   //�Ž����� ���
			int numF = change / 500;   //500���� �� �� �������� ���
			int numO = (change-500*numF) / 100;   //100���� �� �� �������� ���
			if (change % 100 == 0)   //������ �������� 10�� ������ 1�� ������ �ִ� Ȯ��
			{
				cout << "�Ž����� �Դϴ�." << endl;
			}
			else {
				cout << "�Ž������� 500���� 100���� �����մϴ�." << endl;
			}
			cout << "500�� : " << numF << "��" << endl;
			cout << "100�� : " << numO << "��" << endl;
			cout << "�ȳ���������.";
			break;
		}
	}
}

VendingMachine::VendingMachine() {
	cout << "===SWING ���Ǳ�=== " << endl;
	cout << "1. ��ī�ݶ� : 1500��" << endl;
	cout << "2. ��Ÿ500 : 900��" << endl;
	cout << "3. �Ŀ����̵� : 2000��" << endl;
	cout << "4. �غ���" << endl;
	cout << "5.���" << endl << endl;
}

void VendingMachine::menu() {
	cout << endl << endl;
	cout << "===SWING ���Ǳ�=== " << endl;
	cout << "1. ��ī�ݶ� : 1500��" << endl;
	cout << "2. ��Ÿ500 : 900��" << endl;
	cout << "3. �Ŀ����̵� : 2000��" << endl;
	cout << "4. " << name << " : " << price <<"��"<< endl;
	cout << "5.���" << endl << endl;
}

void VendingMachine::setName(string n) {   //��� ������ �����Ѵ�.
	name = n;
}
 
string VendingMachine::getName() {   //���ο� �̸��� �޴´�.
	cout << "�߰��� ���� �̸��� �Է����ּ��� : ";
	cin >> name;
	return name;
}

void VendingMachine::setPrice(int P) {   //��������� �����Ѵ�.
	price = P;
}

double VendingMachine::getPrice() {   //���ο� ������ �޴´�.
	cout << "�Ǹ��� ������ �Է��ϼ��� : ";
	cin >> price;
	return price;
}

double VendingMachine::getTotal() {   //�� ���� total���� ��ȯ�Ѵ�.
	return total;
}

void VendingMachine::setTotal(int t) {   //������ ������� total�� ������Ų��.
	total += t;
}

double VendingMachine::newPrice() {   //���� �Էµ� ������ ��꿡 �̿��� �� �ֵ��� ���ִ� �Լ�
	return price;
}

int main(void) {
	VendingMachine vm;
	VendingMachine* ptr = &vm;  //��ü ������ ����
	int count, inputnum;

	ptr->setName(vm.getName());  //���ο� ����� �̸��� �޾� �ѱ���, name�� �����Ѵ�.
	ptr->setPrice(vm.getPrice());   //���ο� ����� �̸��� �޾� �ѱ���, price�� �����Ѵ�.
	vm.menu();   //����� �޴��� ����Ѵ�.

	do   //�ѹ��� �ݺ��ؾ��Ѵ�. 5���� ���.
	{
		cout << "��ȣ�� �������ּ��� : ";
		cin >> inputnum;   //������ ����� ��ȣ�� �޴´�.
		switch (inputnum)
		{
		case 1:
			cout << "������ ������ �Է����ּ��� : ";
			cin >> count;
			ptr -> setTotal(1500 * count);   //����� ���� setTotal()�� ������Ų��.
			break;
		case 2:
			cout << "������ ������ �Է����ּ��� : ";
			cin >> count;
			ptr->setTotal(900 * count);
			break;
		case 3:
			cout << "������ ������ �Է����ּ��� : ";
			cin >> count;
			ptr->setTotal(2000 * count);
			break;
		case 4:
			cout << "������ ������ �Է����ּ��� : ";
			cin >> count;
			ptr ->setTotal(vm.newPrice() * count);
			break;
		}
	} while (inputnum != 5);
	cout << "��� ���Դϴ�. ��ٷ��ּ��� . . . ." << endl << endl;
	vm.purchase(ptr->getTotal());
}
