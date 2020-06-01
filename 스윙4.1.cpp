#include<iostream>
#include<cstdlib>   //srand �Լ� ����� ����
#include<ctime>    //time �Լ� ����� ����
using namespace std;

class Random {
public:
	Random();
	int next();
	int nextInRange(int x,int y);
};

Random::Random() {                // ���� �߻��� ���۰��� �ٸ��� ���ִ� ������,next�� nextInRandom �Լ��� ��ü�� �ʿ�
	srand((unsigned int)time(NULL));   
}

int Random::next() {            //���� ������ ������ �ƴ� �⺻ unsigned int(0~32767) ������ ���� ��ȯ
	int n = rand();            //���� ���� n�� ������ �� n�� ��ȯ 
	return n;
}

int Random::nextInRange(int x,int y) {    //x�� y ���̷� ������ ���� ������ ���� ��ȯ
	int n = x + rand() % (y - x + 1);    // rand()%(y+1)�� 0<[����]< y �̴�. ���⼭ �������� x�̹Ƿ� x�� ��������Ѵ�. ���� ������ ���� �ٽ� x�� ������Ѵ�.
	return n;
}                                  

int main(void) {
	int i,n;
	Random randNum;   //�̸��� randNum�� Random Ÿ���� ��ü�� ����

	cout << "-- 0����" << RAND_MAX << "������ 10���� ����--" << endl;   //RAND_MAX = 32767
	for (i = 0; i < 10; i++) {
		n = randNum.next();
		cout << n << ' ';
	}
	cout << endl << endl;

	cout << "== 2���� 4������ 10���� ����==" << endl;
	for (i = 0; i < 10; i++) {
		n = randNum.nextInRange(2, 4);
		cout << n << ' ';
	}

}