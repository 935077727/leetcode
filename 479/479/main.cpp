#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	int largestPalindrome(int n) {
		return 1;
	}
};

int stringToInteger(string input) {
	return stoi(input);
}

int main() {
	string line;
	while (getline(cin, line)) {
		int n = stringToInteger(line);

		int ret = Solution().largestPalindrome(n);

		string out = to_string(ret);
		cout << out << endl;
	}
	return 0;
}