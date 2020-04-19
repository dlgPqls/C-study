#include <iostream>
#include<string>
using namespace std;

int main()
{
	int a[10],oddnum[10],evennum[10];
	int i, k=0, j=0;
	

	for (i = 0; i < 4; i++) {
		cout << "¼ýÀÚ¸¦ ÀÔ·ÂÇÏ¼¼¿ä : ";
		cin >> a[i];
			
	}
	cout << endl << "-------°á°ú--------" << endl << endl;

	
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
	
	
	cout << "È¦¼ö:";
	for (i = 0; i < k; i++) {
		cout << "  " << oddnum[i]<<"  ";
	}
	cout << endl << "È¦¼ö´Â ÃÑ " << i << "°³ ÀÔ´Ï´Ù." << endl;

	cout << "Â¦¼ö:";
	for (i = 0; i < j; i++) {
		cout <<"  " << evennum[i] <<"  ";
	}
	cout << endl << "Â¦¼ö´Â ÃÑ " << j << "°³ ÀÔ´Ï´Ù." << endl;

}