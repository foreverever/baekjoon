#include <string>
#include <vector>
#include <math.h>
using namespace std;

long long solution(long long n) {
	long long answer = 0;
	long long v = sqrt(n);
	return pow(v, 2) == n ? pow(v + 1, 2) : -1;
}