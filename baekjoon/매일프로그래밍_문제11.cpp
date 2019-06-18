//���̰� ���� �� ���ڿ�(string) A �� B�� �־�����, A �� B �� 1:1 ��ȣȭ �������� ã���ÿ�.
//Given two strings of equal length, check if two strings can be encrypted 1 to 1.
//
//����)
//Input: ��EGG��, ��FOO��
//Output : True // E->F, G->O
//
//Input : ��ABBCD��, ��APPLE��
//Output : True // A->A, B->P, C->L, D->E
//
//Input : ��AAB��, ��FOO��
//Output : False

#include <iostream>
#include <string>
#include <map>
#define TRUE "true"
#define FALSE "false"

using namespace std;
string first, second;
map<char, char> m;

void initMap() {
	for (int i = 0; i < first.size(); i++) m[first[i]] = second[i];
}

string findAns() {
	initMap();

	for (int i = 0; i < first.size(); i++) {
		if (m[first[i]] != second[i]) return FALSE;
	}
	return TRUE;
}

int main() {
	cin >> first >> second;
	cout << findAns();
	return 0;
}