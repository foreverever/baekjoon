#include<string>
#include <iostream>

using namespace std;
int cnt;

bool check(string s) {
	for (char c : s) {
		if (c == '(') cnt++;
		else cnt--;
		if (cnt < 0) return false;
	}
	return !cnt;
}

bool solution(string s) {
	return check(s);
}

//���ڿ� s�� ���������� Ž���ϸ鼭, ���°�ȣ�� ���� ��, cnt++, �ݴ°�ȣ�� ���� ��, cnt--�� ���ش�.
//���� Ž�� �������� �ݴ°�ȣ�� �� ���� ���Դٸ�(cnt<0) �ùٸ� ��ȣ�� �� �� �����Ƿ� false ����
//Ž�� ���� ��, ���� cnt�� 0�̸�(���°�ȣ, �ݴ°�ȣ�� ���� ����) true, �ƴϸ� false ����