#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int TC, N;

struct Applicant {
	int first, second;

	Applicant(int y, int x) {
		this->first = y;
		this->second = x;
	}
	Applicant() {};
};

bool cmp(Applicant &first, Applicant &second) {
	return first.first > second.first;
}

int findAns() {
	vector<Applicant> v;
	int cnt = 0;
	int y, x;

	for (int i = 0; i < N; i++) {
		cin >> y >> x;
		v.push_back(Applicant(y, x));
	}

	sort(v.begin(), v.end(), cmp);

	for (int i = 0; i < N - 1; i++) {
		for (int j = i+1; j < N; j++) {
			if (v[i].second > v[j].second) {
				cnt++;
				break;
			}
		}
	}
	return N - cnt;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> TC;
	for (int t = 1; t <= TC; t++) {
		cin >> N;
		cout << findAns() << '\n';
	}
	return 0;
}