#include <iostream>
using namespace std;

void sort(char arr[10]);
void print(char arr[10]);

int main(void)
{
	char arr[10] = { 0 };
	int i;

	cout << "숫자 다섯개를 입력해주세요. (띄어쓰기로 구분) : ";
	for (i = 0; i < 5; i++)
		cin >> arr[i];

	cout << endl << "<정렬 전>" << endl << endl;
	print(arr);

	sort(arr);

	cout << endl << "<정렬 후>" << endl << endl;
	print(arr);
	
}

void print(char arr[10])
{
	int i;
	for (i = 0; i < 5; i++)
		cout << i + 1 << ". " << arr[i] << endl;
}

void sort(char arr[10]) 
{
	int i, k, tmp;
	
	for (i = 0; i < 5; i++)
	{
		for (k = 0; k < 4-k; k++)
		{
			if (arr[k] > arr[k + 1])
			{
				tmp = arr[k];
				arr[k] = arr[k + 1];
				arr[k + 1] = tmp;
			}
		}
	}
}