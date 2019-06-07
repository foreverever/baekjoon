#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N;
vector<int> v;

void input() {
	cin >> N;
	int x;

	for (int i = 0; i < N; i++) {
		cin >> x;
		v.push_back(x);
	}
}

int findAns() {
	sort(v.begin(), v.end());
	int size = v.size();
	int mx = -2e9;

	for (int i = 0; i < v.size(); i++) {
		int tmp = v[i] * (size - i);
		mx = tmp > mx ? tmp : mx;
	}
	return mx;
}

int main() {
	input();
	cout << findAns();
	return 0;
}
//���� ���ڴ� �ڽź���(�ڽ� ����) ū ��� ������ ����ؾ� ��ü �ִ밪�� ����
//�� ���� ���� ���ڸ� �����Ҷ� �ڽź���(�ڽ� ����) ū ��� ������ ����ؾ� ��ü �ִ밪�� ����
//���� �ݺ��ϸ�, ��ü �ִ밪�� �� ���� ū ���� ����