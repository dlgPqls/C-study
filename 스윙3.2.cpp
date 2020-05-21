#include <iostream>
using namespace std;

void swap(int *num1, int *num2);

int main()
{
	int x=0 ,y=0;
	cout << "First Number : ";
	cin >> x ;
	cout << "Second Number : ";
	cin >> y;

	cout << "swap Àü : " << x << "  " << y << endl;

	swap(&x, &y);

	cout << "swap ÈÄ : " << x << "  " << y << endl;

}

void swap(int *num1, int *num2)
{
	int tmp = 0;

	tmp = *num1;
	*num1 = *num2;
	*num2 = tmp;
}