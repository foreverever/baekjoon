//#include <iostream>
//#include <string>
//#include <string.h>
//#include <vector>
//#include <utility>
//
//using namespace std;
//string str;
//vector <pair <char, int> > v;
//
////알파벳별 pair형 vector 생성 (알파벳(char),해당개수(int))
//void initAlphabet() {
//	for (int i = 65; i < 91; i++) {
//		v.push_back(make_pair(i, 0));
//	}
//}
//
////알파벳 개수 세기
//void countAlphabet() {
//	for (int i = 0; i < str.size(); i++) {
//		for (int j = 0; j < v.size(); j++) {
//			if (str[i] == v[j].first || str[i] == v[j].first + 32) {
//				v[j].second++;
//			}
//		}
//	}
//}
//
////정답 찾기(최대 알파벳 찾기 및 중복 체크)
//char findAns() {
//	int max = -2e9;
//	int dupl = 0;
//	char ans;
//	for (int i = 0; i < v.size(); i++) {
//		max = v[i].second > max ? v[i].second : max;
//	}
//	for (int i = 0; i < v.size(); i++) {
//		if (v[i].second == max) {
//			dupl++;
//			ans = v[i].first;
//		}
//	}
//	if (dupl > 1) {
//		return '?';
//	}
//	return ans;
//}
//
//int main() {
//	cin >> str;
//	initAlphabet();
//	countAlphabet();
//	char ans = findAns();
//	cout << ans;
//	return 0;
//}