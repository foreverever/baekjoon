#include <iostream>
#include<string>
#include <stack>
using namespace std;

stack <char> st;

int solution(string s) {
	for (char c : s) {
		if (st.empty()) {
			st.push(c);
			continue;
		}
		if (st.top() == c) st.pop();
		else st.push(c);
	}
	return st.empty();
}