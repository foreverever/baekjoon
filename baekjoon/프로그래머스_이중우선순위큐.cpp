#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;

string mxDel = "D 1";
string mnDel = "D -1";

deque<int> dq;

vector<int> solution(vector<string> operations) {
	int val = 0;
	string num = "";
	vector<int> answer;
	answer.resize(2);

	for (string str : operations) {
		if (str == mxDel) {
			if (!dq.empty()) dq.pop_back();
		}
		else if (str == mnDel) {
			if (!dq.empty()) dq.pop_front();
		}
		else {
			num = str.substr(2);
			val = stoi(num);
			dq.push_back(val);
		}
		sort(dq.begin(), dq.end());
	}
	answer[0] = dq.empty() ? 0 : dq.back();
	answer[1] = dq.empty() ? 0 : dq.front();
	return answer;
}