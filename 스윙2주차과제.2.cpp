#include <iostream>
#include <string>
using namespace std;

int main()
{
	int i, k, inputnum, line = 0;
	int standard, n;

	do {   //�ּ� �ѹ��� ����
		cout << "-----����� �ý���-------" << endl;
		cout << "����� ���� ����� �������ּ���." << endl;
		cout << "1. �����ﰢ��" << endl;
		cout << "2. ���ﰢ��" << endl;
		cout << "3. ����" << endl;
		cout << "4. ������" << endl;

		cin >> inputnum;

		switch (inputnum){   //�޴����� �Է°��� ���� ����� �ٸ�.

		case 1:
		{
			cout << "�����ﰢ���� �����ϼ̽��ϴ�." << endl;
			cout << "���� ������ �������ּ���." << endl;
			cin >> line;

			for (k = 1; k < line + 1; k++) {   //������ ������ �Ʒ��� �ﰢ���� ���� ���� ����
				for (i = 0; i < line - k; i++)  
					cout << " ";   //�Ʒ��� ������ ���� ���� ����
				for (i = 1; i < k + 1; i++)
					cout << "*";   //�Ʒ��� ������ �� ���� ����
				cout << endl;   
			}

			cout << endl;

			for (k = 1; k < line + 1; k++) {  //������ ���� ���� �ﰢ���� ���� ���� ����
				for (i = 0; i < line - k + 1; i++)
					cout << "*";   //�Ʒ��� ������ �� ���� ����
				for (i = 0; i < k; i++)
					cout << " ";   //�Ʒ��� ������ ���� ���� ����
				cout << endl;
			}

			cout << endl;
			for (k = 0; k < line; k++) {   //������ ������ ���� ���� ���� ����
				for (i = 0; i < k; i++)
					cout << " ";   //�Ʒ��� ������ ���� ���� ����
				for (i = 0; i < line - k; i++)
					cout << "*";   //�Ʒ��� ������ �� ���� ����
				cout << endl;
			}
		}break;

		case 2:
		{
			cout << "���ﰢ���� �����ϼ̽��ϴ�." << endl;
			cout << "���� ������ �������ּ���." << endl;
			cin >> line;

			int standard, n;

			int count = 2 * line - 1;   //�� ��� ���� ���� ����
			int middle = count / 2;   //�� ���� �߰� ��ġ�� ����
			standard = 1;   //ó�� ���� ��ġ ����

			for (n = 0; n < line; n++)
			{
				count = count - (standard + middle);   //���������� �ݺ��Ǵ� for���� ���� ���� ����

				for (i = 0; i < middle; i++) {  //��� ���� �߽����� ���� ���� �����
					cout << " ";
				}
				middle -= 1;   //�Ʒ��� ������ ���� ���� ����

				for (k = 0; k < standard; k++) {
					cout << "*";
				}
				standard += 2;  //�Ʒ��� ������ �� ���� ����


				for (i; i < count; i++) {   //��� ���� �߽����� ������ ���� �����
					cout << " ";
				}
				cout << endl;
			}
			cout << endl;
		}break;

		case 3:
		{
			cout << "�������� �����ϼ̽��ϴ�." << endl;
			int vline;

			cout << "���� ������ �������ּ��� : ";
			cin >> vline;

			while (vline % 2 != 1) {   //Ȧ������ �ƴ��� �Ǻ�
				cout << "Ȧ���� �Է��ϼ���. : ";
				cin >> vline;   
			}

			standard = 1;
			int hline = vline + 1;   //�ִ� ���� ����(��ü���� ��� ��) ����

			for (n = 0; n < vline / 2; n++) {   //��� ���� �߽����� ���� �׸���

				for (i = 0; i < standard; i++) {
					cout << "*";
				}
				for (k = 0; k < hline - 2 * standard; k++) {   //���� ������ ������ �κ� ��� ����
					cout << " ";
				}
				for (i = 0; i < standard; i++) {
					cout << "*";
				}
				cout << endl;

				standard += 1;   //�Ʒ��� ������ ���� ���� ����

			}

			for (i = 0; i < hline; i++)   //��� ���� �� �׸���
				cout << "*";
			cout << endl;

			standard -= 1;

			for (n = 0; n < vline / 2; n++)   // ��� ���� �߽����� �Ʒ��� �׸���
			{
				for (i = 0; i < standard; i++) {
					cout << "*";
				}

				for (k = 0; k < hline - 2 * standard; k++) {
					cout << " ";
				}

				for (i = 0; i < standard; i++) {
					cout << "*";
				}

				cout << endl;

				standard -= 1;   //�Ʒ��� ������ ���� ���� ����
			}
			cout << endl;
		}break;

		case 4:
		{
			return 0;
		}break;

		default:
		{
			break;
		}
		}
	} while (inputnum != 4);
}