#include <string>
#include <vector>
#define DIV 1234567
using namespace std;

long long f[2001];

long long solution(int n) {
	f[1] = 1;
	f[2] = 2;
	for (int i = 3; i <= n; i++) {
		f[i] = f[i - 1] % DIV + f[i - 2] % DIV;
	}
	return f[n] % DIV;
}

//피보나치 수열 문제이다. n에 따른 결과값을 나열해야 그 규칙을 찾을 수 있었던 문제이다. 그렇지 못하면 절대 해결방법을 못찾았을듯..
//단, 수의 범위가 크기때문에, 1234567를 나눈 나머지값을 피보나치 배열에 저장하게끔 한다.
//(a+b)%c == a%c + b%c 가 성립하는 수학적(?) 특성을 이용해서 풀어야 한다.