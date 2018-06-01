/* Given a string and an integer k, you need to reverse the first k characters for every 2k characters counting from the start of the string. If there are less than k characters left, reverse all of them. If there are less than 2k but greater than or equal to k characters, then reverse the first k characters and left the other as original.
Example:
Input: s = "abcdefg", k = 2
Output: "bacdfeg"
Restrictions:
The string consists of lower English letters only.
Length of the given string and k will in the range [1, 10000] */


// hack to provide speed on LeetCode
static const auto _____ = []()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	return nullptr;
}();

class Solution {
public:
    string reverseStr(string s, int k) {
        bool reverse = false;
        for(int i=0, j = s.size(); i < j; i+=k){
            if (i + k > j) {
                k = j - i;
            }
            reverse = !reverse;
            if(reverse) reverseInterval(i, i+k-1, s);
        }
        return s;
    }
    
    void reverseInterval(int from, int to, string& str){
        char temp;
        while (from < to) {
            temp = str[from];
            str[from++] = str[to];
            str[to--] = temp;
        }
    }
};

