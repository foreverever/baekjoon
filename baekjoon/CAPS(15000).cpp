#include <iostream>
#include <string>
#include <algorithm>	//transform
#include <ctype.h>	//toupper, tolower
using namespace std;
string str;

//반복문, 아스키코드 방식 (28ms)
void findAns1() {
	cin >> str;
	for (char var : str) {
		cout << char(var - 32);
	}
}

//transform, toupper 방식 (8ms)
void findAns2() {
	cin >> str;
	transform(str.begin(), str.end(), str.begin(), ::toupper);		//toupper : 소문자를 대문자로 tolower : 대문자를 소문자로 
	cout << str;
}

int main() {
	ios_base::sync_with_stdio(false);
	findAns1();
	//findAns2();
	return 0;
}