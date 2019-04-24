#include <string>
#include <vector>

using namespace std;
vector<int> answer;

void gcd(int n, int m) {
	if (m == 0) {
		answer.push_back(n);
		return;
	}
	else gcd(m, n%m);
}

int lcm(int n, int m) {
	int g = answer.front();

	if (n%m == 0) return n;
	return g * (n / g)*(m / g);
}

vector<int> solution(int n, int m) {
	int big = 0, small = 0;
	if (n >= m) {
		big = n, small = m;
	}
	else big = m, small = n;

	gcd(big, small);
	answer.push_back(lcm(big, small));
	return answer;
}