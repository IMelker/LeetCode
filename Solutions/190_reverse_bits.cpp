/* Reverse bits of a given 32 bits unsigned integer.

Example:

Input: 43261596
Output: 964176192
Explanation: 43261596 represented in binary as 00000010100101000001111010011100, 
             return 964176192 represented in binary as 00111001011110000010100101000000.
Follow up:
If this function is called many times, how would you optimize it?*/

// hack to provide speed on LeetCode
static const auto _____ = []()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	return nullptr;
}();

// crazy solution on union
class CrazySolution {
    union IntWrapper {
        uint32_t n_;
        std::bitset<32> b_;
        IntWrapper(uint32_t n) {n_ = n;}
    };
public:
    uint32_t reverseBits(uint32_t n) {
        IntWrapper wrapper(n);
        int i = 0, j = 31;
        bool temp;
        while (i < j) {
            temp =  wrapper.b_[i];
            wrapper.b_[i++] = wrapper.b_[j];
            wrapper.b_[j--] = temp;
        }
        return wrapper.n_;
    }
};

//right solution
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t reversed_n = 0;
        for (int i = 0; i < 32; i++) {
            reversed_n <<= 1;
            reversed_n += n & 1;
            n >>= 1;
        }
        return reversed_n;
    }
};



