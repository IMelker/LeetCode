/*Given a 32-bit signed integer, reverse digits of an integer.

Example 1:

Input: 123
Output: 321
Example 2:

Input: -123
Output: -321
Example 3:

Input: 120
Output: 21
Note:
Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−231,  231 − 1]. For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.;
*/

static const int x = []()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int reverse(int x) {       
        int result = 0;
        do {
            if (__builtin_mul_overflow(result, 10, &result)) {
                return 0;
            }
            result += x%10;
            x /= 10;
        } while(x != 0);
        return result;
    }
};


