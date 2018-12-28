#include <iostream>
#include <utility>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int n;
int age;
string str;
vector <pair<int, string> > v;
pair<int, string> p;

bool compare(const pair<int, string>&i, const pair<int, string>&j)
{
	if (i.first == j.first)
		return 0;
	return i.first < j.first;
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> age >> str;
		v.push_back(make_pair(age, str));
	}
	stable_sort(v.begin(), v.end(), compare);

	for (int i = 0; i < n; i++) {
		cout << v[i].first << ' ' << v[i].second << '\n';
	}
	return 0;
}