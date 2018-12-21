#include <iostream>
#include <algorithm>
using namespace std;

int num[10001];
int N;
int input;
int maxValue = -2e9;

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		scanf("%d", &input);
		maxValue = maxValue < input ? input : maxValue;
		num[input]++;
	}
	for (int i = 1; i <= maxValue; i++) {
		while (num[i] > 0) {
			printf("%d\n", i);
			num[i]--;
		}
	}
	return 0;
}

///////////////////////////////////메모리 초과 why??////////////////////////////////
//#include <iostream>
//#include <map>
//using namespace std;
//int N;
//int input;
//map<int, int> m;
//
//int main() {
//	cin >> N;
//	for (int i = 1; i <= N; i++) {
//		cin >> input;
//		m[input]++;
//	}
//	for (int i = 1; i <= N; i++) {
//		while (m[i] > 0) {
//			cout << i << '\n';
//			m[i]--;
//		}
//	}
//	return 0;
//}