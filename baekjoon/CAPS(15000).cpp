#include <iostream>
#include <string>
#include <algorithm>	//transform
#include <ctype.h>	//toupper, tolower
using namespace std;
string str;

//�ݺ���, �ƽ�Ű�ڵ� ��� (28ms)
void findAns1() {
	cin >> str;
	for (char var : str) {
		cout << char(var - 32);
	}
}

//transform, toupper ��� (8ms)
void findAns2() {
	cin >> str;
	transform(str.begin(), str.end(), str.begin(), ::toupper);		//toupper : �ҹ��ڸ� �빮�ڷ� tolower : �빮�ڸ� �ҹ��ڷ� 
	cout << str;
}

int main() {
	ios_base::sync_with_stdio(false);
	findAns1();
	//findAns2();
	return 0;
}