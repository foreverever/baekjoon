////#include <iostream>
////#include <utility>
////#include <algorithm>
////#include <string>
////#include <vector>
////using namespace std;
////
////int n;
////int age;
////string str;
////vector <pair<int, string> > v;
////pair<int, string> p;
////
////bool compare(const pair<int, string>&i, const pair<int, string>&j)
////{
////	if (i.first == j.first)
////		return 0;
////	return i.first < j.first;
////}
////
////int main() {
////	cin >> n;
////	for (int i = 1; i <= n; i++) {
////		cin >> age >> str;
////		v.push_back(make_pair(age, str));
////	}
////	stable_sort(v.begin(), v.end(), compare);
////
////	for (int i = 0; i < n; i++) {
////		cout << v[i].first << ' ' << v[i].second << '\n';
////	}
////	return 0;
////}
//
//
/////////////////////////////////////////// 84ms -> ios_base::sync_with_stdio(false), cin.tie(0) : 48ms
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int n;
struct Person {
	int age, idx;
	string name;
};

Person p[100001];

bool cmp(Person &p1, Person &p2) {
	if (p1.age == p2.age) return p1.idx < p2.idx;
	return p1.age < p2.age;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> p[i].age >> p[i].name;
		p[i].idx = i;
	}
	sort(p, p + n, cmp);
	for (int i = 0; i < n; i++) {
		cout << p[i].age << ' ' << p[i].name << '\n';
	}
	return 0;
}