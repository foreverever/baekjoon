#include <iostream>
#include <string>
#include <vector>

using namespace std;
vector<string> v;
int mxSize = -2e9;

void input() {
	string input = "";
	int size = 0;

	for (int i = 0; i < 5; i++) {
		getline(cin, input);
		v.push_back(input);
		size = input.size();
		mxSize = size > mxSize ? size : mxSize;
	}
}

string findAns() {
	string ans = "";
	for (int i = 0; i < mxSize; i++) {
		for (int j = 0; j < v.size(); j++) {
			if (v[j].size() < i + 1) continue;
			ans += v[j][i];
		}
	}
	return ans;
}

int main() {
	input();
	cout << findAns();
	return 0;
}
//string 최대 15개 받음
//각 입력받은 string 벡터에 담음
//string.size()가 최대인 만큼 for문돌리고, 그 안에 다시 벡터의 사이즈만큼 for문 돌림
//각 string.size()보다 클경우는 continue;
//아니라면 string타입의 ans에 해당 문자 더해줌