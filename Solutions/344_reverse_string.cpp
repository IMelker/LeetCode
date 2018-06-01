/* Write a function that takes a string as input and returns the string reversed.

Example:
Given s = "hello", return "olleh".*/

// hack to provide speed on LeetCode
static const auto _____ = []()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	return nullptr;
}();

class Solution {
public:
    string reverseString(string s) {
        int i = 0, j = s.size()-1;
        char temp;
        while (i < j) {
            temp = s[i];
            s[i++] = s[j];
            s[j--] = temp;
        }
        return s;
    }
};

