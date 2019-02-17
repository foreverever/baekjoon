#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(string phone_number) {
	string answer = "";
	string back_number = phone_number.substr(phone_number.size() - 4);
	for (int i = 0; i < phone_number.size()-4; i++) {
		answer += "*";
	}
	answer += back_number;
	return answer;
}

int main() {
	cout << solution("01033334444");
	return 0;
}