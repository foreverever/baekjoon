#include <iostream>
#include <vector>
using namespace std;

int dp[100001][4];

int findMax(int line[4], int cur) {
	int mx = -2e9;
	for (int i = 0; i < 4; i++) {
		if (i == cur) continue;
		if (mx < line[i]) mx = line[i];
	}
	return mx;
}

int solution(vector<vector<int> > land) {
	int answer = 0;

	for (int i = 0; i < 4; i++) dp[0][i] = land[0][i];	//ù �� �ʱ�ȭ

	for (int i = 1; i < land.size(); i++) {
		for (int j = 0; j < 4; j++) {
			dp[i][j] = findMax(dp[i - 1], j) + land[i][j];
		}
	}
	return findMax(dp[land.size() - 1], -1);
}

//dp�����μ�, ��ȭ���� ���쵵�� �Ѵ�.
//���� dp[i][j]�� i��j��° ���� �ִ밪�� �ǹ��ϵ��� ������ �迭�� �����ߴ�. ��, dp[i]�� i��° �� ������ �ִ밪 �迭�� �ȴ�.
//��ȭ���� 'dp[i][j] = max(dp[i-1][0], dp[i-1][1] ..) + land[i][j]' �� �������.
//�̶� ����������, �̿��� �࿡ ���ؼ� ���� ���� �����ؾ� �ϹǷ� ��ȭ���� max���ڷ� j��° �ִ밪�� dp[i][j]�� �����ϵ��� �Ѵ�.
//���� ���� dp�迭�� �� ������, dp�迭�� ������ �࿡�� ���� ū ���� ���� ���ϰ��� �ϴ� �ִ밪�� �ȴ�.