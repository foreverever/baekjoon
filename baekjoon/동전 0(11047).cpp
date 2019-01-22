#include <iostream>
#include <vector>

using namespace std;

int N, K, ans;
vector <int> v;
void input() {
	int x;
	for (int i = 0; i < N; i++) {
		cin >> x;
		v.push_back(x);
	}
}

//´Ü¼ø »¬¼À (180ms)
void findAns() {
	while (K != 0) {
		if (K < v[N - 1]) {
			N--;
			continue;
		}
		K -= v[N - 1];
		ans++;
	}
}

//³ª´©±â·Î (0ms)
void findAns2() {
	while (K != 0) {
		if (K < v[N - 1]) {
			N--;
			continue;
		}
		ans += K / v[N - 1];
		K %= v[N - 1];
	}
}

int main() {
	cin >> N >> K;
	input();
	findAns2();
	cout << ans;
	return 0;
}