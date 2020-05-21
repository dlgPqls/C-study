#include <iostream>
using namespace std;

void sort(int &arr[5});
int print(int& arr[5]);

int main()
{
	int arr[5] = 0;
	int i;

	cout << "숫자 다섯개를 입력해주세요. (띄어쓰기로 구분) : ";
	for (i = 0; i < 5; i++)
		cin >> arr[i];

	cout << "<정렬 전>" << endl << endl;
	print(arr[5]);

	sort(arr[5]);

	cout << "<정렬 전>" << endl << endl;
	print(arr[5]);

}

void sort(int &arr[5})
{
	int i, k, tmp = 0;
	for (i = 0; i < 5; i++)
		for (k = i + 1; k < 5; k++)
			if (arr[i] > arr[k])
			{
				tmp = arr[i];
				*arr[i] = arr[k];
				*arr[k] = tmp;

			}
				
				
}

int print(int& arr[5])
{
	int i;

	for (i = 1; i < 6; i++)
	{
		cout << i << arr[i] << endl;
	}
}

