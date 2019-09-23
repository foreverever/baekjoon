#include <iostream>
#include <string>
#define DOT "[.]"
using namespace std;

class Solution {
public:
	string defangIPaddr(string address) {
		string result = "";

		for (char c : address) {
			if (c == '.') {
				result += DOT;
				continue;
			}
			result += c;
		}
		return result;
	}
};