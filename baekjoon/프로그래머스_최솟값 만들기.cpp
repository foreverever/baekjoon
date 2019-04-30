#include <iostream>
#include<vector>
#include <algorithm>
using namespace std;

bool cmp(int &first, int &second) {
	return first > second;
}

int solution(vector<int> A, vector<int> B)
{
	int answer = 0;
	sort(A.begin(), A.end());
	sort(B.begin(), B.end(), cmp);

	for (int i = 0; i < A.size(); i++) {
		answer += A[i] * B[i];
	}

	return answer;
}

//하나의 배열은 오름차순, 하나의 배열은 내림차순으로 해서 각각 같은위치의 곱을 한다.
//이는 현재까지 최대값 x 현재까지 최소값을 의미한다.
//이 과정을 반복하여 구해진 모든 값을 합하면 된다.
