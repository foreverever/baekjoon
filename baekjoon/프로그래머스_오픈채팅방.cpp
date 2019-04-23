#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#define ENTER "님이 들어왔습니다."
#define LEAVE "님이 나갔습니다."

using namespace std;

vector<string> split(string &str) {
	vector<string> v;
	string tmp = "";

	for (char c : str) {
		if (c == ' ') {
			v.push_back(tmp);
			tmp = "";
			continue;
		}
		tmp += c;
	}
	v.push_back(tmp);
	return v;
}

struct Result {
	string id, inOut;

	Result(string id, string inOut) {
		this->id = id;
		this->inOut = inOut;
	}

	Result() {};
};

Result results[100002];
unordered_map<string, string> m;

vector<string> solution(vector<string> record) {
	vector<string> answer;
	vector<Result> result;

	for (string str : record) {
		vector<string> v = split(str);
		if (v[0] == "Enter") {
			m[v[1]] = v[2];
			result.push_back(Result(v[1], v[0]));
		}
		else if (v[0] == "Leave") {
			result.push_back(Result(v[1], v[0]));
		}
		else {
			m[v[1]] = v[2];
		}
	}

	for (Result result : result) {
		if (result.inOut == "Enter") {
			answer.push_back(m[result.id] + ENTER);
		}
		else answer.push_back(m[result.id] + LEAVE);
	}
	return answer;
}