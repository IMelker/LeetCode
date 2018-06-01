/* Given a string, you need to reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.

Example 1:
Input: "Let's take LeetCode contest"
Output: "s'teL ekat edoCteeL tsetnoc"
Note: In the string, each word is separated by single space and there will not be any extra space in the string..*/

// hack to provide speed on LeetCode
static const auto _____ = []()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	return nullptr;
}();

class Solution {
public:
	string reverseWords(string s) {
		int i = 0, end = s.size();
		for (int j = 0; j <= end; j++) {
			if (s[j] == ' ' || s[j] == 0) {
				reverseInterval(i, j - 1, s);
				i = j + 1;
			}
		}
		return s;
	}

	void reverseInterval(int i, int j, string& s) {
		char temp;
		while (i < j) {
			temp = s[i];
			s[i++] = s[j];
			s[j--] = temp;
		}
	}
};
