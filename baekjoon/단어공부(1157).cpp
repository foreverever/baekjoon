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
////���ĺ��� pair�� vector ���� (���ĺ�(char),�ش簳��(int))
//void initAlphabet() {
//	for (int i = 65; i < 91; i++) {
//		v.push_back(make_pair(i, 0));
//	}
//}
//
////���ĺ� ���� ����
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
////���� ã��(�ִ� ���ĺ� ã�� �� �ߺ� üũ)
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