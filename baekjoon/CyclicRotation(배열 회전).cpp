#include <iostream>
#include <vector>
#include <stack>

using namespace std;

stack<int> st;

vector<int> solution(vector<int> &A, int K) {
	vector<int> ans;
	if (A.size() == 0) return ans;

	int range = K % A.size();

	while (range > 0 && A.size() > 0) {
		st.push(A.back());
		A.pop_back();
		range--;
	}

	while (!st.empty()) {
		ans.push_back(st.top());
		st.pop();
	}
	for (int val : A) ans.push_back(val);

	return ans;
}