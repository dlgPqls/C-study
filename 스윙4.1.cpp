#include<iostream>
#include<cstdlib>   //srand 함수 사용을 위해
#include<ctime>    //time 함수 사용을 위해
using namespace std;

class Random {
public:
	Random();
	int next();
	int nextInRange(int x,int y);
};

Random::Random() {                // 난수 발생시 시작값을 다르게 해주는 생성자,next와 nextInRandom 함수의 객체에 필요
	srand((unsigned int)time(NULL));   
}

int Random::next() {            //따로 지정한 범위가 아닌 기본 unsigned int(0~32767) 내에서 난수 반환
	int n = rand();            //난수 값을 n에 저장한 후 n값 반환 
	return n;
}

int Random::nextInRange(int x,int y) {    //x와 y 사이로 정해진 범위 내에서 난수 반환
	int n = x + rand() % (y - x + 1);    // rand()%(y+1)은 0<[난수]< y 이다. 여기서 시작점이 x이므로 x를 더해줘야한다. 그후 끝값을 위해 다시 x를 빼줘야한다.
	return n;
}                                  

int main(void) {
	int i,n;
	Random randNum;   //이름이 randNum인 Random 타입의 객체를 생성

	cout << "-- 0에서" << RAND_MAX << "까지의 10가지 난수--" << endl;   //RAND_MAX = 32767
	for (i = 0; i < 10; i++) {
		n = randNum.next();
		cout << n << ' ';
	}
	cout << endl << endl;

	cout << "== 2에서 4까지의 10가지 난수==" << endl;
	for (i = 0; i < 10; i++) {
		n = randNum.nextInRange(2, 4);
		cout << n << ' ';
	}

}