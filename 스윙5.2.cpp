#include <iostream>
using namespace std;

class VendingMachine
{
private:
	string name;  //음료이름
	int price;  //가격
	int total = 0;  //음료 합산 값
public:
	VendingMachine();  //생성자
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
	cout << "총 금액 : " << v1 << endl;
	cout << "지폐를 입력하세요 : ";
	cin >> won;

	while (1) {   //금액이 부족하면 다시 넣고 반복해야한다.
		if (won == v1) {
			cout << "거스름돈이 없습니다. 안녕히가세요.";
			break;
		}
		else if (won < v1)
		{
			cout << "금액이 부족합니다. 다시 넣어주세요 : ";
			cin >> won;
			continue;
		}
		else if (won > v1)
		{
			int change = won - v1;   //거스름돈 계산
			int numF = change / 500;   //500원이 몇 개 나오는지 계산
			int numO = (change-500*numF) / 100;   //100원이 몇 개 나오는지 계산
			if (change % 100 == 0)   //나머지 연산으로 10원 단위나 1원 단위가 있는 확인
			{
				cout << "거스름돈 입니다." << endl;
			}
			else {
				cout << "거스름돈은 500원과 100원만 가능합니다." << endl;
			}
			cout << "500원 : " << numF << "개" << endl;
			cout << "100원 : " << numO << "개" << endl;
			cout << "안녕히가세요.";
			break;
		}
	}
}

VendingMachine::VendingMachine() {
	cout << "===SWING 자판기=== " << endl;
	cout << "1. 코카콜라 : 1500원" << endl;
	cout << "2. 비타500 : 900원" << endl;
	cout << "3. 파워에이드 : 2000원" << endl;
	cout << "4. 준비중" << endl;
	cout << "5.계산" << endl << endl;
}

void VendingMachine::menu() {
	cout << endl << endl;
	cout << "===SWING 자판기=== " << endl;
	cout << "1. 코카콜라 : 1500원" << endl;
	cout << "2. 비타500 : 900원" << endl;
	cout << "3. 파워에이드 : 2000원" << endl;
	cout << "4. " << name << " : " << price <<"원"<< endl;
	cout << "5.계산" << endl << endl;
}

void VendingMachine::setName(string n) {   //멤버 변수에 저장한다.
	name = n;
}
 
string VendingMachine::getName() {   //새로운 이름을 받는다.
	cout << "추가할 음료 이름을 입력해주세요 : ";
	cin >> name;
	return name;
}

void VendingMachine::setPrice(int P) {   //멤버변수에 저장한다.
	price = P;
}

double VendingMachine::getPrice() {   //새로운 가격을 받는다.
	cout << "판매할 가격을 입력하세요 : ";
	cin >> price;
	return price;
}

double VendingMachine::getTotal() {   //다 계산된 total값을 반환한다.
	return total;
}

void VendingMachine::setTotal(int t) {   //가격을 멤버변수 total에 누적시킨다.
	total += t;
}

double VendingMachine::newPrice() {   //새로 입력된 가격을 계산에 이용할 수 있도록 해주는 함수
	return price;
}

int main(void) {
	VendingMachine vm;
	VendingMachine* ptr = &vm;  //객체 포인터 선언
	int count, inputnum;

	ptr->setName(vm.getName());  //새로운 음료수 이름을 받아 넘긴후, name에 저장한다.
	ptr->setPrice(vm.getPrice());   //새로운 음료수 이름을 받아 넘긴후, price에 저장한다.
	vm.menu();   //변경된 메뉴를 출력한다.

	do   //한번은 반복해야한다. 5번이 계산.
	{
		cout << "번호를 선택해주세요 : ";
		cin >> inputnum;   //선택할 음료수 번호를 받는다.
		switch (inputnum)
		{
		case 1:
			cout << "구매할 수량을 입력해주세요 : ";
			cin >> count;
			ptr -> setTotal(1500 * count);   //계산한 값을 setTotal()에 누적시킨다.
			break;
		case 2:
			cout << "구매할 수량을 입력해주세요 : ";
			cin >> count;
			ptr->setTotal(900 * count);
			break;
		case 3:
			cout << "구매할 수량을 입력해주세요 : ";
			cin >> count;
			ptr->setTotal(2000 * count);
			break;
		case 4:
			cout << "구매할 수량을 입력해주세요 : ";
			cin >> count;
			ptr ->setTotal(vm.newPrice() * count);
			break;
		}
	} while (inputnum != 5);
	cout << "계산 중입니다. 기다려주세요 . . . ." << endl << endl;
	vm.purchase(ptr->getTotal());
}
