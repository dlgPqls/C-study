#ifndef CLASS_H
#define CLASS_H

class phoneBook {
private:
	string phoneNum;
	string name;
public:
	void addPhone();   //�Է��� ��ȭ��ȣ ��� �Լ�
	void editPhone();   //��ȭ��ȣ ���� �Լ�
	string getPnum();   //�Էµ� ��ȭ��ȣ �ҷ�����(��ȯ�ϴ�) �Լ�
	string getName();   //�Էµ� �̸� �ҷ�����(��ȯ�ϴ�) �Լ�
};

#endif // !CLASS_H