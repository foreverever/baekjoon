#include <iostream>
#include <string>
#define SMILE ":-)"
#define SAD ":-("

using namespace std;

string s;
int sm, sd;

string findAns() {
	string smile = s, sad = s;

	while (smile.find(SMILE) != string::npos) {
		smile = smile.substr(smile.find(SMILE) + 3);
		sm++;
	}

	while (sad.find(SAD) != string::npos) {
		sad = sad.substr(sad.find(SAD) + 3);
		sd++;
	}
	if (!sm && !sd) return "none";
	if (sm == sd) return "unsure";
	return sm > sd ? "happy" : "sad";
}

int main() {
	getline(cin, s);
	cout << findAns();
	return 0;
}