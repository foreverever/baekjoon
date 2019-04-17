#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

unordered_map<string, bool> m;

vector<int> solution(int n, vector<string> words) {
	vector<int> answer;
	m[words[0]] = true;
	int person = 0;
	int order = 0;

	for (int i = 0; i < words.size() - 1; i++) {
		if (words[i].back() == words[i + 1].front() && !m.count(words[i + 1])) {
			m[words[i + 1]] = true;
			continue;
		}
		person = (i + 1) % n + 1;
		order = (i + 1) / n + 1;
		break;
	}

	answer.push_back(person); 
	answer.push_back(order);
	
	return answer;
}