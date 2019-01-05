#include <iostream>
#include <vector>
using namespace std;

int arr[3][4];
vector<char> ans;
vector<int> input;

void findAns() {
	int sum = 0;
	for (int i = 0; i < input.size(); i++) {
		if (input[i]) {
			sum++;
		}
	}
	//ธ๐
	if (sum == 4) {
		ans.push_back('E');
		return;
	}
	if (sum == 3) {
		ans.push_back('A');
		return;
	}
	if (sum == 2) {
		ans.push_back('B');
		return;
	}
	if (sum == 1) {
		ans.push_back('C');
		return;
	}
	//ภท
	if (sum == 0) {
		ans.push_back('D');
		return;
	}
}

int main() {
	int n;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 4; j++) {
			cin >> n;
			input.push_back(n);
		}
		findAns();
		input.clear();
	}
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << '\n';
	}
	ans.clear();
	return 0;
}