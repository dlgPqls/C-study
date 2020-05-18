#include <iostream>
#include <string>
using namespace std;

int main()
{
	int i, k, inputnum, line = 0;
	int standard, n;

	do {   //최소 한번은 실행
		cout << "-----별찍기 시스템-------" << endl;
		cout << "만들고 싶은 모양을 선택해주세요." << endl;
		cout << "1. 직각삼각형" << endl;
		cout << "2. 정삼각형" << endl;
		cout << "3. 나비" << endl;
		cout << "4. 나가기" << endl;

		cin >> inputnum;

		switch (inputnum){   //메뉴얼의 입력값에 따라 결과가 다름.

		case 1:
		{
			cout << "직각삼각형을 선택하셨습니다." << endl;
			cout << "행의 개수를 선택해주세요." << endl;
			cin >> line;

			for (k = 1; k < line + 1; k++) {   //직각이 오른쪽 아래인 삼각형의 행의 개수 결정
				for (i = 0; i < line - k; i++)  
					cout << " ";   //아래로 갈수록 공백 개수 감소
				for (i = 1; i < k + 1; i++)
					cout << "*";   //아래로 갈수록 별 개수 증가
				cout << endl;   
			}

			cout << endl;

			for (k = 1; k < line + 1; k++) {  //직각이 왼쪽 위인 삼각형의 행의 개수 결정
				for (i = 0; i < line - k + 1; i++)
					cout << "*";   //아래로 갈수록 별 개수 감소
				for (i = 0; i < k; i++)
					cout << " ";   //아래로 갈수로 공백 개수 증가
				cout << endl;
			}

			cout << endl;
			for (k = 0; k < line; k++) {   //직각이 오른쪽 위인 행의 개수 결정
				for (i = 0; i < k; i++)
					cout << " ";   //아래로 갈수록 공백 개수 증가
				for (i = 0; i < line - k; i++)
					cout << "*";   //아래로 갈수록 별 개수 감소
				cout << endl;
			}
		}break;   //case를 맞추면 다시 

		case 2:
		{
			cout << "정삼각형을 선택하셨습니다." << endl;
			cout << "행의 개수를 선택해주세요." << endl;
			cin >> line;

			int standard, n;

			int count = 2 * line - 1;   //한 행당 별의 개수 정의
			int middle = count / 2;   //한 행의 중간 위치를 정의
			standard = 1;   //처음 시작 위치 정의

			for (n = 0; n < line; n++)
			{
				count = count - (standard + middle);   //마지막으로 반복되는 for문의 공백 개수 제한

				for (i = 0; i < middle; i++) {  //가운데 별을 중심으로 왼쪽 공백 만들기
					cout << " ";
				}
				middle -= 1;   //아래로 갈수록 공백 개수 감소

				for (k = 0; k < standard; k++) {
					cout << "*";
				}
				standard += 2;  //아래로 갈수록 별 개수 증가


				for (i; i < count; i++) {   //가운데 별을 중심으로 오른쪽 공백 만들기
					cout << " ";
				}
				cout << endl;
			}
			cout << endl;
		}break;

		case 3:
		{
			cout << "나비모양을 선택하셨습니다." << endl;
			int vline;

			cout << "행의 개수를 선택해주세요 : ";
			cin >> vline;

			while (vline % 2 != 1) {   //홀수인지 아닌지 판별
				cout << "홀수로 입력하세요. : ";
				cin >> vline;   
			}

			standard = 1;
			int hline = vline + 1;   //최대 열의 개수(전체에서 가운데 열) 정의

			for (n = 0; n < vline / 2; n++) {   //가운데 행을 중심으로 위쪽 그리기

				for (i = 0; i < standard; i++) {
					cout << "*";
				}
				for (k = 0; k < hline - 2 * standard; k++) {   //별을 제외한 나머지 부분 모두 공백
					cout << " ";
				}
				for (i = 0; i < standard; i++) {
					cout << "*";
				}
				cout << endl;

				standard += 1;   //아래로 갈수록 별의 개수 증가

			}

			for (i = 0; i < hline; i++)   //가운데 행의 별 그리기
				cout << "*";
			cout << endl;

			standard -= 1;

			for (n = 0; n < vline / 2; n++)   // 가운데 행을 중심으로 아래쪽 그리기
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

				standard -= 1;   //아래로 갈수록 별의 개수 증가
			}
			cout << endl;
		}break;

		case 4:
		{
			return 0;   //0을 반환하여 끝냄
		}break;

		default:
		{
			break;   //나머지 숫자는 다시 입력하도록 함.
		}
		}
	} while (inputnum != 4);
}
