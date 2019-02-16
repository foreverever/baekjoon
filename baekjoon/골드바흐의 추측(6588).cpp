#include <iostream>
#include <map>
#include<vector>
#include <utility>
#define MAX 1000000
using namespace std;

int n;
bool number[1000001];
map<int, bool> prime;
map<int, bool>::iterator iter;

bool isPrime(int n) {
	int cnt = 0;
	for (int i = 2; i <= n; i++) {
		if (n%i == 0) cnt++;
	}
	return cnt == 1;
}

void erase(int n) {
	for (int i = 1; i*n <= MAX; i++) {
		if (number[i*n] == false) {
			number[i*n] = true;
		}
	}
}

void getPrime() {
	for (int i = 2; i <= MAX; i++) {
		if (number[i] == false) {
			prime[i] = true;
			erase(i);
		}
	}
	prime.erase(2);
}

int main() {
	for (int i = 3; i <= MAX; i++) {
		number[i] = false;
	}

	getPrime();
	while (1) {
		int a = 0, b = 0;
		scanf("%d", &n);
		if (n == 0) break;
		for (iter = prime.begin(); iter != prime.end(); iter++) {
			if (prime.count(n - iter->first)) {
				a = iter->first;
				b = n - iter->first;
				printf("%d = %d + %d\n", n, a, b);
				break;
			}
			if (n <= iter->first) {
				printf("%s\n", "Goldbach's conjecture is wrong.");
				break;
			}
		}
	}
	return 0;
}