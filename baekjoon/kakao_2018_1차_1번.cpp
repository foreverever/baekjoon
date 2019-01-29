#include <iostream>
#include <string>
#include <vector>
using namespace std;
int arr1[17], arr2[17];
int n;

void input(int arr[]) {
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
}

vector<string> findAns(int n, int arr1[], int arr2[]) {
	vector<string> ans(n);
	for (int i = 0; i < n; i++) {
		arr1[i] |= arr2[i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			ans[i] = ((arr1[i] % 2 == 1) ? "#" : " ") + ans[i];
			arr1[i] /= 2;
		}
	}
	return ans;
}

int main() {
	cin >> n;
	input(arr1);
	input(arr2);
	vector<string> v = findAns(n, arr1, arr2);
	for (string var : v) {
		cout << var << ' ';
	}
	return 0;
}

///////////////////////////¹®Á¦ : http://tech.kakao.com/2017/09/27/kakao-blind-recruitment-round-1/ //////////////////////