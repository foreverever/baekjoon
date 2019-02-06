//나눈후, 뒤집은 문자열에 대해 맨 앞 알파벳을 하나하나씩 자르면서 사전순 비교  
#include <iostream>
#include <string>

using namespace std;
string str, word, ans;
int index;

string reverse(string word) {
	string rev;
	for (int i = word.size() - 1; i >= 0; i--) {
		rev += word[i];
	}
	return rev;
}

string findMinWord(string word) {
	string minWord = word.substr(0);
	index = word.size()-1;
	for (int i = 1; i < word.size(); i++) {
		if (minWord > word.substr(i)) {
			minWord = word.substr(i);
			index = (word.size() - 1) - i;
		}
	}
	str = str.substr(index+1);
	return minWord;
}

void findAns() {
	for (int i = 2; i >= 1; i--) {
		word = str.substr(0, str.size() - i);
		ans += findMinWord(reverse(word));
	}
	for (int i = str.size() - 1; i >= 0; i--) {
		ans += str[i];
	}
}

int main() {
	cin >> str;
	findAns();
	cout << ans;
	return 0;
}

//중복 처리 못한 코드
//#include <iostream>
//#include <string>
//
//using namespace std;
//string str, tmp, ans;
//
//void reverse(int index) {
//	for (int i = index; i >= 0; i--) {
//		ans += tmp[i];
//	}
//	str = str.substr(index + 1);
//}
//
//void findMinAlphabet(string tmp) {
//	char m = tmp[0];
//	int index = 0;
//	for (int i = 1; i < tmp.size(); i++) {
//		if (m > tmp[i]) {
//			m = tmp[i];
//			index = i;
//		}
//	}
//	reverse(index);
//}
//
//void findAns() {
//	tmp = str.substr(0, str.size() - 2);
//	findMinAlphabet(tmp);
//	tmp = str.substr(0, str.size() - 1);
//	findMinAlphabet(tmp);
//	for (int i = str.size() - 1; i >= 0; i--) {
//		ans += str[i];
//	}
//}
//
//int main() {
//	cin >> str;
//	findAns();
//	cout << ans;
//	return 0;
// }