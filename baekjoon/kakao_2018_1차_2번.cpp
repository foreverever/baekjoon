#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
using namespace std;

map<string, int> m;
map<string, int>::iterator iter;
int ans, maxVal;
void upAge() {
	for (iter = m.begin(); iter != m.end(); iter++) {
		iter->second++;
	}
}

int findMax() {
	maxVal = -2e9;
	for (iter = m.begin(); iter != m.end(); iter++) {
		maxVal = iter->second > maxVal ? iter->second : maxVal;
	}
	return maxVal;
}

void LRU(int cacheSize, string cities[], int size) {
	int ans = 0;
	//cout << sizeof(cities) <<'\n';	//배열 포인터의 사이즈가 반환 됨

	for (int i = 0; i < size; i++) {
		//대소문자 통일 (소문자로)
		transform(cities[i].begin(), cities[i].end(), cities[i].begin(), tolower);
		//캐시 사이즈가 0일 때
		if (cacheSize == 0) {
			ans += 5;
			continue;
		}
		//히트
		if (m.count(cities[i])) {
			upAge();
			m[cities[i]] = 1;
			ans += 1;
		}
		//미스
		else {
			//비어있는 캐시
			if (m.size() != cacheSize) {
				upAge();
				m[cities[i]] = 1;
				ans += 5;
				continue;
			}
			//꽉찬 캐시
			else {
				findMax();
				for (iter = m.begin(); iter != m.end(); iter++) {
					if (iter->second == maxVal) {
						m.erase(iter);
						break;
					}
				}
				upAge();
				m[cities[i]] = 1;
				ans += 5;
			}
		}
	}
	m.clear();
	cout << ans << '\n';;
	ans = 0;
}

int main() {
	string cities1[10] = { "Jeju", "Pangyo", "Seoul", "NewYork", "LA", "Jeju", "Pangyo", "Seoul", "NewYork", "LA" };
	string cities2[9] = { "Jeju", "Pangyo", "Seoul", "Jeju", "Pangyo", "Seoul", "Jeju", "Pangyo", "Seoul" };
	string cities3[12] = { "Jeju", "Pangyo", "Seoul", "NewYork", "LA", "SanFrancisco", "Seoul", "Rome", "Paris", "Jeju", "NewYork", "Rome" };
	string cities4[12] = { "Jeju", "Pangyo", "Seoul", "NewYork", "LA", "SanFrancisco", "Seoul", "Rome", "Paris", "Jeju", "NewYork", "Rome" };
	string cities5[4] = { "Jeju", "Pangyo", "NewYork", "newyork" };
	string cities6[5] = { "Jeju", "Pangyo", "Seoul", "NewYork", "LA" };
	LRU(3, cities1, sizeof(cities1) / sizeof(string));
	LRU(3, cities2, sizeof(cities2) / sizeof(string));
	LRU(2, cities3, sizeof(cities3) / sizeof(string));
	LRU(5, cities4, sizeof(cities4) / sizeof(string));
	LRU(2, cities5, sizeof(cities5) / sizeof(string));
	LRU(0, cities6, sizeof(cities6) / sizeof(string));
	return 0;
}