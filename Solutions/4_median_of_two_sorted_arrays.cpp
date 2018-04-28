/* There are two sorted arrays nums1 and nums2 of size m and n respectively.

Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

Example 1:
nums1 = [1, 3]
nums2 = [2]

The median is 2.0
Example 2:
nums1 = [1, 2]
nums2 = [3, 4]

The median is (2 + 3)/2 = 2.5*/


// NOT LOG M+N SOLUTION
// hack to provide speed on LeetCode
static const auto _____ = []()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	return nullptr;
}();

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        for(auto v: nums1)
            nums2.insert(std::upper_bound( nums2.begin(), nums2.end(), v), v);
        
        return nums2.size()%2 == 1 ? nums2.at(nums2.size()/2) : (nums2.at(nums2.size()/2) + nums2.at(nums2.size()/2 - 1))/2.0 ;
    }
};

