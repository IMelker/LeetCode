#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

constexpr int base = 10;

inline int didgit_count(int n) {
    return n == 0 ? 1 : std::ceil(std::log(n+1)/std::log(base));
}

constexpr auto pow(auto base, int expand) {
    return static_cast<decltype(base)>(std::pow(base, expand));
}

template<typename T>
T expand(T num, int expand) {
    return num * pow(base, expand);
}

template<typename T>
T expandByStartDigitsOf(T num, int num_digits, T source, int source_digits) {
    int didigts_deltha = source_digits - num_digits;
    if (didigts_deltha <= 0)
        return num;
    
    auto res = expand(num, didigts_deltha);
    for (int i = 0; i < didigts_deltha; ++i)
        res += ((source / pow(base, source_digits - 1 - i)) % base) * pow(base, didigts_deltha - 1 - i);
    return res;
}

struct lexicographical_prioritise_longest  {
    bool operator()(int lhs, int rhs) const {
        if (lhs == rhs)
            return false;

        // Compensate for sign
        if (lhs < 0 && rhs < 0) {
            // Remove the sign and continue as for positive numbers.
            lhs *= -1;
            rhs *= -1;
        }
        else if (lhs < 0)
            return true; // lhs negative, rhs positive
        else if (rhs < 0)
            return false; // rhs negative, lhs positive

        auto lhs_digits = didgit_count(lhs);
        auto rhs_digits = didgit_count(rhs);

        // Now we loop through the positions, left-to-right,
        // calculating the digit at these positions for each
        // input, and comparing them numerically. The
        // lexicographic nature of the sorting comes from the
        // fact that we are doing this per-digit comparison
        // rather than considering the input value as a whole.
        const auto max_pos = std::max(lhs_digits, rhs_digits);
        for (auto pos = 0; pos < max_pos; pos++) {
            // If lhs out of digits, expand it by start digits from rhs and compare
            if (lhs_digits - pos == 0)
                return expandByStartDigitsOf(lhs, lhs_digits, rhs, rhs_digits) <= rhs;
                
            // If rhs out of digits, expand it by start digits from lhs and compare
            if (rhs_digits - pos == 0)
                return lhs <= expandByStartDigitsOf(rhs, rhs_digits, lhs, lhs_digits);

            const auto lhs_x = (lhs / pow(base, lhs_digits - 1 - pos)) % base;
            const auto rhs_x = (rhs / pow(base, rhs_digits - 1 - pos)) % base;

            if (lhs_x < rhs_x)
                return true;
            else if (rhs_x < lhs_x)
                return false;
        }
        return false;
    }
};

unsigned long long minValue(std::vector<int> data) {
    unsigned long long res = 0;
    std::sort(data.begin(), data.end(), lexicographical_prioritise_longest{});
    
    for (unsigned int i = 0; i < data.size(); ++i) {
        if (i && data[i-1] == data[i]) // ignore not unique
            continue;
        
        // TODO add overflow checks
        res = expand(res, didgit_count(data[i])) + data[i];
        
        std::cout << "digit="<< data[i] << " res=" << res << std::endl;
    }
    
    return res;
}

int main()
{
  std::cout << minValue({1,2,1001,100,10,3, 1013, 1000}) << std::endl;
}
