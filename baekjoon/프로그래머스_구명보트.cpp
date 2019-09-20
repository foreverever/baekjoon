#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

bool used[50001];

bool cmp(int &a, int &b) {
	return a > b;
}

int solution(vector<int> people, int limit) {
	int cnt = 0;
	int size = people.size();

	sort(people.begin(), people.end(), cmp);

	//시간초과
	/*for (int i = 0; i < size; i++) {
		if (!used[i]) {
			used[i] = true; cnt++;
			int remain = limit - people[i];
			for (int j = i + 1; j < size; j++) {
				if (people[j] <= remain && !used[j]) {
					used[j] = true;
					break;
				}
			}
		}
	}*/

	//투포인터 이용 (1중 for문)
	int s = 0, e = people.size() - 1;
	while (s <= e) {
		if (people[s] + people[e] <= limit) {
			s++;
			e++;
		}
		else s++;
		cnt++;
	}
	return cnt;
}