#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
	int answer = 0;
	for (string skill_trees : skill_trees) {
		string s;
		for (int i = 0; i < skill_trees.size(); i++) {
			if (skill.find(skill_trees[i]) != string::npos) {
				s += skill_trees[i];
			}
		}
		int check = 0;
		for (int i = 0; i < s.size(); i++) {
			if (skill[i] != s[i]) break;
			check++;
		}
		if (check == s.size()) answer++;
	}
	return answer;
}

int main() {
	string skill = "CBD";
	vector<string> skill_trees = { "BACDE" , "CBADF", "AECB", "BDA" };
	cout << solution(skill, skill_trees);
	return 0;
}