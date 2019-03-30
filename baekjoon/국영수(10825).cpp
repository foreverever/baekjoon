#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

struct Student {
	string name;
	int kr, en, mt;

	Student(string name, int kr, int en, int mt) {
		this->name = name;
		this->kr = kr;
		this->en = en;
		this->mt = mt;
	}

	Student() {}
};

bool cmp(Student &s1, Student &s2) {
	if (s1.kr == s2.kr) {
		if (s1.en == s2.en) {
			if (s1.mt == s2.mt) return s1.name < s2.name;
			else return s1.mt > s2.mt;
		}
		else return s1.en < s2.en;
	}
	else return s1.kr > s2.kr;
}

Student st[100001];
int N;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	string s;
	int a, b, c;

	for (int i = 0; i < N; i++) {
		cin >> s;
		cin >> a >> b >> c;
		st[i] = Student(s, a, b, c);
	}
	sort(st, st + N, cmp);
	for (int i = 0; i < N; i++) {
		cout << st[i].name << '\n';
	}
	return 0;
}