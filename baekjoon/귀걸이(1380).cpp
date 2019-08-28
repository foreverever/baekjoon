#include <iostream>
#include <string>
#include <vector>
using namespace std;

int N, tc;

struct Student {
	string name;
	int count = 0;

	Student(string name) {
		this->name = name;
	}

	Student() {};
};

string findAns() {
	vector<Student> v;

	for (int i = 0; i < N; i++) {
		string input;
		getline(cin, input);
		v.push_back(Student(input));
	}
	int num; char rand;

	for (int i = 0; i < 2 * N - 1; i++) {
		cin >> num >> rand;
		v[num - 1].count++;
	}
	for (int i = 0; i < N; i++) {
		if (v[i].count == 1) return v[i].name;
	}
}

int main() {
	while (1) {
		cin >> N;
		if (N == 0) break;
		cin >> ws;	//getline()이 N입력 후 엔터값을 받기 때문에 ws로 대신 받게 끔
		cout << ++tc << ' ' << findAns() << '\n';
	}
	return 0;
}