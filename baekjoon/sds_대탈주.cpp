#include <iostream>
#include <vector>
#include <utility>
#include <string.h>
#include <algorithm>
using namespace std;

int N, M, total;
bool check[1001];
vector <int> carColor, pass;

void input() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int x;
		cin >> x;
		total += x;
		if (x > 0) {
			for (int j = 0; j < x; j++) {
				carColor.push_back(i + 1);
			}
		}
	}
	for (int i = 0; i < N; i++) {
		int x;
		cin >> x;
		pass.push_back(x);
	}
}

int findAns() {
	int cnt = 0;
	for (int i = 0; i <= N - total; i++) {
		//도난차량 개수만큼 그룹지어
		for (int j = i; j < i + total; j++) {
			//도난차량에 대해
			for (int k = 0; k < carColor.size(); k++) {
				if (pass[j] == carColor[k] && check[k] == false) {
					cnt++;
					check[k] = true;
					break;
				}
			}
		}
		if (cnt == total) return (i + 1);
		cnt = 0;
		memset(check, false, sizeof(check));
	}
	return 0;
}

int main() {
	int tc;
	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		input();
		cout << '#' << t << ' ' << findAns() << '\n';
		carColor.clear();
		pass.clear();
		total = 0;
	}
	return 0;
}