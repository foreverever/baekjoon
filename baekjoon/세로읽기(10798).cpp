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
//string �ִ� 15�� ����
//�� �Է¹��� string ���Ϳ� ����
//string.size()�� �ִ��� ��ŭ for��������, �� �ȿ� �ٽ� ������ �����ŭ for�� ����
//�� string.size()���� Ŭ���� continue;
//�ƴ϶�� stringŸ���� ans�� �ش� ���� ������