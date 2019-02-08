#include <iostream>
#include <string>
#include <math.h>
using namespace std;

int getBinary(string s) {
	int decimal = 0;
	int val = 0;

	for (int i = 0; i < s.size(); i++) {
		val = s[(s.size() - 1) - i] - '0';
		decimal += val * pow(2, i);
	}
	return decimal;
}

int solution(string s) {
	int ans = 0;
	int decimal = getBinary(s);

	while (decimal) {
		if (decimal % 2 != 0) {
			decimal--;
			ans++;
		}
		else {
			decimal /= 2;
			ans++;
		}
	}
	return ans;
}

int main() {
	cout << solution("011000");
	return 0;
}