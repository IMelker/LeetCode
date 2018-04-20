/* Given a string, find the length of the longest substring without repeating characters.

Examples:

Given "abcabcbb", the answer is "abc", which the length is 3.*/

// hack to provide speed on LeetCode
static const auto _____ = []()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	return nullptr;
}();

// my solution
class Solution {
public:

	int lengthOfLongestSubstring(string s) {
		int chars[256];
		memset(chars, -1, sizeof(chars));
		size_t max_size = 0;
		int start_count_point = 0;

		size_t cursor = 0;
		while (cursor < s.length()) {
			const char& c = s.at(cursor);
			int char_pos = chars[c];
			if (char_pos >= start_count_point) {
				start_count_point = chars[c] + 1;
			}
			chars[c] = cursor;
			++cursor;

			int size = cursor - start_count_point;
			if (size > max_size) {
				max_size = size;
			}
		}
		return max_size;
	}
};

