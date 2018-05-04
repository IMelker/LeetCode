/* Given an array nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.

For example,
Given nums = [1,3,-1,-3,5,3,6,7], and k = 3.

Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
Therefore, return the max sliding window as [3,3,5,5,6,7].

Note: 
You may assume k is always valid, ie: 1 ≤ k ≤ input array's size for non-empty array.

Follow up:
Could you solve it in linear time? */

#define vec_iter std::vector<int>::iterator

// hack to provide speed on LeetCode
static const auto _____ = []()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	return nullptr;
}();

/// -----MY FAST SOLUTION WITH NOT LINEAR TIME ----- ///
class NotLinearSolution {
public:

	vec_iter getMaxElement(vec_iter first, vec_iter last) {
		if (first == last) {
			return last;
		}
		vec_iter largest = first;
		++first;
		for (; first <= last; ++first) {
			if (*largest < *first) {
				largest = first;
			}
		}
		return largest;
	}

	void getMaxElementInRange(vec_iter last_max, vec_iter new_value, int range) {
		if (distance(last_max, new_value) >= range) { // if last max not in range
			last_max_ = getMaxElement(new_value - range + 1, new_value);
			return;
		}

		int a = *last_max, b = *new_value;
		last_max_ = (a < b) ? new_value : last_max;
	}

	vector<int> maxSlidingWindow(vector<int>& nums, int k) {
		vector<int> max_values;

		if (nums.empty() || k == 0) {
			return max_values;
		} if (k == 1) {
			return nums;
		}

		last_max_ = max_element(nums.begin(), nums.begin() + k);
		max_values.push_back(*last_max_);

		for (auto it = nums.begin() + k; it < nums.end(); ++it) {
			getMaxElementInRange(last_max_, it, k);
			max_values.push_back(*last_max_);
		}
		return max_values;
	}

private:
	vec_iter last_max_;
};


class BetterSolution {
public: 
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> index_queue;
        vector<int> max_values;
        for(int i = 0; i < nums.size(); ++i) {
            if(!index_queue.empty() && index_queue.front() == i - k) {
                index_queue.pop_front();
            }

            while(!index_queue.empty() && nums[index_queue.back()] < nums[i]) {
                index_queue.pop_back();
            }
            index_queue.push_back(i);
            
            if(i >= k - 1) { 
                max_values.push_back(nums[index_queue.front()]);
            }  
        }
        return max_values;
    }
};

