#ifndef CLASS_H
#define CLASS_H

class phoneBook {
private:
	string phoneNum;
	string name;
public:
	void addPhone();   //입력한 전화번호 등록 함수
	void editPhone();   //전화번호 수정 함수
	string getPnum();   //입력된 전화번호 불러오는(반환하는) 함수
	string getName();   //입력된 이름 불러오는(반환하는) 함수
};

#endif // !CLASS_H
