/////////////////////////////////////////////////////////숫자 만들기////////////////////////////////////////////////////
//#include <iostream>
//#include <vector>
//using namespace std;
//int TC;
//int N;
//int maxNum = -2e9;
//int minNum = 2e9;
//vector <int> op, nums;
//
//void getInput() {
//	for (int i = 0; i < 4; i++) {
//		int input;
//		cin >> input;
//		op.push_back(input);
//	}
//	for (int j = 0; j < N; j++) {
//		int input;
//		cin >> input;
//		nums.push_back(input);
//	}
//}
//
//void findAns(int cnt, int result, int nextIndex) {
//	if (cnt == N - 1) {
//		maxNum = result > maxNum ? result : maxNum;
//		minNum = result < minNum ? result : minNum;
//		return;
//	}
//	for (int i = 0; i < 4; i++) {
//		if (op[i] != 0) {
//			if (i == 0) {
//				op[i]--;
//				findAns(cnt + 1, result + nums[nextIndex], nextIndex + 1);
//				op[i]++;
//			}
//			if (i == 1) {
//				op[i]--;
//				findAns(cnt + 1, result - nums[nextIndex], nextIndex + 1);
//				op[i]++;
//			}
//			if (i == 2) {
//				op[i]--;
//				findAns(cnt + 1, result * nums[nextIndex], nextIndex + 1);
//				op[i]++;
//			}
//			if (i == 3) {
//				op[i]--;
//				findAns(cnt + 1, result / nums[nextIndex], nextIndex + 1);
//				op[i]++;
//			}
//		}
//	}
//}
//
//int main() {
//	cin >> TC;
//	for (int i = 1; i <= TC; i++) {
//		cin >> N;
//		getInput();
//		findAns(0, nums[0], 1);
//		int ans = maxNum - minNum;
//		cout << "#" << i << ' ' << ans <<'\n';
//		maxNum = -2e9;
//		minNum = 2e9;
//		op.clear();
//		nums.clear();
//	}
//	return 0;
//}