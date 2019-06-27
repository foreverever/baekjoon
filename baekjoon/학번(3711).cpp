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

	while (s.size() != n) {	//�ִ� �鸸
		s.clear();
		m++;
		for (int i = 0; i < n; i++) {	//�ִ� 300
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
		//check �ʱ�ȭ
		initCheck(n, k);
		//check ����
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
//1) �迭�� ���ڸ� ��´�
//2) set�� ����� ���� �迭�� ������� ���� �� ���� �ݺ����� ������
//3) set�� �� �迭���� m���� ���� �������� �ȴ�.
//4) ������ �ش� ���ڰ� ���� ���� ���� m
//5) 680ms �ð��ɸ� ������ �ʿ�

//findAns()
//1) �ݺ��� ���鼭, �迭���� ���� �������� �ε����� �ϴ� �� �ٸ� �迭�� �����.
//2) �ش� ������ �迭�� ���� true��� ������ ���Դ� �������̹Ƿ� ���� �ݺ� ����
//3) ���� ������ ���Դ� �������� ���� ���, �� ���� m ����