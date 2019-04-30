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

//������ ������, �� ������ ���ڶ�� �ݵ�� �빮��(toupper())
//�ƴ϶��, �ݵ�� �ҹ���(tolower())
//��, ������ �����ؼ� ���� �� �ִ� ���� �����ϵ��� �Ѵ�. (������ ���� üũ�ϰ�, continue�� Ȱ���Ѵ�.)