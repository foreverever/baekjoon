#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(string s) {
	string answer = "";
	bool isFirstWord = true;

	for (char c : s) {
		if (c == ' ') {
			answer += c;
			isFirstWord = true;
			continue;
		}
		if (isFirstWord) {
			answer += toupper(c);
			isFirstWord = false;
			continue;
		}	
		answer += tolower(c);
	}
	return answer;
}

//공백이 나오고, 그 다음이 문자라면 반드시 대문자(toupper())
//아니라면, 반드시 소문자(tolower())
//단, 공백이 연속해서 나올 수 있는 점을 주의하도록 한다. (공백을 먼저 체크하고, continue를 활용한다.)