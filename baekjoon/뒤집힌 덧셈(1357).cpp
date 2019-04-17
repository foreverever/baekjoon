#include <iostream>
#include <queue>
#include <math.h>
using namespace std;

int a, b;

int rev(int n) {
	queue <int> q;
	int result = 0;

	while (n != 0) {
		q.push(n % 10);
		n /= 10;
	}

	while (!q.empty()) {
		result += q.front() * pow(10, q.size() - 1);
		q.pop();
	}

	return result;
}

int main() {
	scanf("%d %d", &a, &b);
	printf("%d", rev(rev(a) + rev(b)));
	return 0;
}