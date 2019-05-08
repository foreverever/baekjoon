#include <iostream>

using namespace std;

int A, I;

int main() {
	scanf("%d %d", &A, &I);
	printf("%d", A*(I - 1) + 1);
	return 0;
}
//앨범 수록 곡 개수 x (평균-1) 인 멜로디의 개수(S)의 평균은 원하는 평균의 -1한 값을 의미하므로
//올림을 통해  원하고자 하는 평균을 구하려면 적어도 S+1 이상의 멜로디 개수를 가져야 한다