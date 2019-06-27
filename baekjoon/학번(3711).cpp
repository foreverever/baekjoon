#include <iostream>
#include <set>
#define MAX 301
#define ARRMAX 1000001

using namespace std;

int tc;
int numbers[MAX];

int findAnsByUsingSet() {
	int n, m = 0;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> numbers[i];
	}
	set<int> s;

	while (s.size() != n) {	//최대 백만
		s.clear();
		m++;
		for (int i = 0; i < n; i++) {	//최대 300
			s.insert(numbers[i] % m);
		}
	}
	return m;
}

bool check[ARRMAX];
bool isDuplicate;

void initCheck(int size, int k) {
	for (int i = 0; i < size; i++) {
		check[numbers[i] % k] = false;
	}
	isDuplicate = false;
}

int findAns() {
	int n;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> numbers[i];
	}
	if (n == 1) return 1;

	for (int k = 1; k < ARRMAX; k++) {
		//check 초기화
		initCheck(n, k);
		//check 수행
		for (int i = 0; i < n; i++) {
			if (check[numbers[i] % k]) isDuplicate = true;
			check[numbers[i] % k] = true;
		}
		if (isDuplicate) continue;
		initCheck(n, k);
		return k;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		cout << findAns() << '\n';
	}
	return 0;
}

//findAnsByUsingSet()
//1) 배열에 숫자를 담는다
//2) set의 사이즈가 담은 배열의 사이즈와 같을 때 까지 반복문을 돌린다
//3) set은 각 배열값을 m으로 나눈 나머지가 된다.
//4) 같으면 해당 숫자가 가장 작은 정수 m
//5) 680ms 시간걸림 단축할 필요

//findAns()
//1) 반복문 돌면서, 배열값을 나눈 나머지를 인덱스로 하는 또 다른 배열을 만든다.
//2) 해당 나머지 배열의 값이 true라면 이전에 나왔던 나머지이므로 다음 반복 진행
//3) 만약 이전에 나왔던 나머지가 없을 경우, 그 때의 m 리턴