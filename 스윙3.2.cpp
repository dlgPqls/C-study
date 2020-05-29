#include <iostream>
using namespace std;

void swap(int* x, int* y);

int main(void) {
	int num1 = 0, num2 = 0;

	cout << "first number : ";
	cin >> num1;
	cout << "second number : ";
	cin >> num2;

	int* ptr1 = &num1;
	int* ptr2 = &num2;

	cout << "swqp 전  :" << *ptr1 <<"  " << *ptr2 << endl;

	swap(ptr1, ptr2);
	cout << "swqp 후  :" << *ptr1 <<"  "<< *ptr2 << endl;
}

void swap(int* x, int* y) {
	int tmp;

	tmp = *x;
	*x = *y;
	*y = tmp;

}
