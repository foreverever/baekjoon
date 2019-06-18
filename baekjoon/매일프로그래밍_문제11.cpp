//길이가 같은 두 문자열(string) A 와 B가 주어지면, A 가 B 로 1:1 암호화 가능한지 찾으시오.
//Given two strings of equal length, check if two strings can be encrypted 1 to 1.
//
//예제)
//Input: “EGG”, “FOO”
//Output : True // E->F, G->O
//
//Input : “ABBCD”, “APPLE”
//Output : True // A->A, B->P, C->L, D->E
//
//Input : “AAB”, “FOO”
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