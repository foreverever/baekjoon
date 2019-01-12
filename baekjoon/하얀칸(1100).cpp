#include <iostream>
#include <string>

using namespace std;
string str;

int findAns() {
	int ans = 0;
	for (int i = 0; i < 8; i++) {
		cin >> str;
		if (i % 2 == 0) {
			for (int j = 0; j < 8; j++) {
				if (j % 2 == 0 && str[j] == 'F') {
					ans++;
				}
			}
		}
		else {
			for (int j = 0; j < 8; j++) {
				if (j % 2 != 0 && str[j] == 'F') {
					ans++;
				}
			}
		}
	}
	return ans;
}

int main() {
	cout << findAns();
	return 0;
}


////////////////////////////////for문안에 조건 넣어서////////////////////////
//#include<iostream>
//#include<string>
//
//using namespace std;
//
//int main() {
//	string line;
//	int answer = 0;
//
//	for (int i = 0; i < 8; i++) {
//		cin >> line;
//
//		for (int j = i % 2 == 0 ? 0 : 1; j < 8; j += 2) {
//			if (line[j] == 'F')
//				answer++;
//		}
//	}
//	cout << answer;
//}