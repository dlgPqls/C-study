#include <iostream>
using namespace std;

void sort(char arr[10]);
void print(char arr[10]);

int main(void)
{
	char arr[10] = { 0 };
	int i;

	cout << "���� �ټ����� �Է����ּ���. (����� ����) : ";
	for (i = 0; i < 5; i++)
		cin >> arr[i];

	cout << endl << "<���� ��>" << endl << endl;
	print(arr);

	sort(arr);

	cout << endl << "<���� ��>" << endl << endl;
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