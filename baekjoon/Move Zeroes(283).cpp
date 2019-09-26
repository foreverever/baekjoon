//Given an array nums, write a function to move all 0's to the end of it 
//while maintaining the relative order of the non-zero elements.
//
//Example:
//
//Input: [0, 1, 0, 3, 12]
//	Output : [1, 3, 12, 0, 0]
//	Note :
//
//	You must do this *in - place* without making a copy of the array.
//	Minimize the total number of operations.

#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
	void moveZeroes(vector<int>& nums) {
		queue<int> q;

		for (int val : nums) {
			if (val != 0) q.push(val);
		}

		int nonZero = q.size();

		while (!q.empty()) {
			nums[nonZero - q.size()] = q.front();
			q.pop();
		}
		for (int i = nonZero; i < nums.size(); i++) nums[i] = 0;
	}
};