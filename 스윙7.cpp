#include <iostream>
using namespace std;

int main(void) {
	int count, tmp = 0, k = 0, min = 0;
	int number[100] = { 0 };

	cin >> count;
	for (int i = 0; i < count; i++) {
		cin >> number[i];
	}
	cout << endl;

	for (int i = 0; i < count - 1; i++) {
		min = number[i];
		for (int j = i + 1; j < count; j++) {
			if (min > number[j]) {
				min = number[j];
				k = j;
				tmp = number[i];
				number[i] = number[k];
				number[k] = tmp;
			}
		}
		for (int i = 0; i < count; i++)
			cout << number[i] << " ";
		cout << endl;
	}

}