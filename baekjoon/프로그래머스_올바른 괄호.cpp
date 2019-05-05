#include<string>
#include <iostream>

using namespace std;
int cnt;

bool check(string s) {
	for (char c : s) {
		if (c == '(') cnt++;
		else cnt--;
		if (cnt < 0) return false;
	}
	return !cnt;
}

bool solution(string s) {
	return check(s);
}

//문자열 s를 순차적으로 탐색하면서, 여는괄호가 나올 시, cnt++, 닫는괄호가 나올 시, cnt--를 해준다.
//만약 탐색 과정에서 닫는괄호가 더 많이 나왔다면(cnt<0) 올바른 괄호가 될 수 없으므로 false 리턴
//탐색 종료 후, 최종 cnt가 0이면(여는괄호, 닫는괄호의 수가 동일) true, 아니면 false 리턴