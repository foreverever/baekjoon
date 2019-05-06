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

//�Ǻ���ġ ���� �����̴�. n�� ���� ������� �����ؾ� �� ��Ģ�� ã�� �� �־��� �����̴�. �׷��� ���ϸ� ���� �ذ����� ��ã������..
//��, ���� ������ ũ�⶧����, 1234567�� ���� ���������� �Ǻ���ġ �迭�� �����ϰԲ� �Ѵ�.
//(a+b)%c == a%c + b%c �� �����ϴ� ������(?) Ư���� �̿��ؼ� Ǯ��� �Ѵ�.