#include <iostream>
#include<string>
using namespace std;

int main()
{
	int a[10],oddnum[10],evennum[10];
	int i, k=0, j=0;
	

	for (i = 0; i < 4; i++) {
		cout << "���ڸ� �Է��ϼ��� : ";
		cin >> a[i];
			
	}
	cout << endl << "-------���--------" << endl << endl;

	
	for (i = 0; i < 4; i++) {
		if (a[i] % 2 == 0) {
			evennum[k] = a[i];
			k += 1;		
		}
		else {
			oddnum[j] = a[i];
			j += 1;
		
		}
	
	}
	
	
	cout << "Ȧ��:";
	for (i = 0; i < k; i++) {
		cout << "  " << oddnum[i]<<"  ";
	}
	cout << endl << "Ȧ���� �� " << i << "�� �Դϴ�." << endl;

	cout << "¦��:";
	for (i = 0; i < j; i++) {
		cout <<"  " << evennum[i] <<"  ";
	}
	cout << endl << "¦���� �� " << j << "�� �Դϴ�." << endl;

}