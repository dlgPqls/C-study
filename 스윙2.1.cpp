#include <iostream>
#include<string>
using namespace std;

int main()
{
	int a[10],oddnum[10],evennum[10]; 
	int i, k=0, j=0;
	

	for (i = 0; i < 4; i++) {
		cout << "숫자를 입력하세요 : ";
		cin >> a[i];
			
	}
	cout << endl << "-------결과--------" << endl << endl;

	
	for (i = 0; i < 4; i++) {
		if (a[i] % 2 == 0) {
			evennum[k] = a[i];
			k += 1;		
		}   //짝수 저장
		else {
			oddnum[j] = a[i];
			j += 1;
		
		}   //홀수 저장
	
	}
	
	
	cout << "홀수:";
	for (i = 0; i < k; i++) {
		cout << "  " << oddnum[i]<<"  ";
	}
	cout << endl << "홀수는 총 " << i << "개 입니다." << endl;

	cout << "짝수:";
	for (i = 0; i < j; i++) {
		cout <<"  " << evennum[i] <<"  ";
	}
	cout << endl << "짝수는 총 " << j << "개 입니다." << endl;

}
