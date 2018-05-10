/* Given a data stream input of non-negative integers a1, a2, ..., an, ..., summarize the numbers seen so far as a list of disjoint intervals.

For example, suppose the integers from the data stream are 1, 3, 7, 2, 6, ..., then the summary will be:

[1, 1]
[1, 1], [3, 3]
[1, 1], [3, 3], [7, 7]
[1, 3], [7, 7]
[1, 3], [6, 7] */

/**
* Definition for an interval.
* struct Interval {
*     int start;
*     int end;
*     Interval() : start(0), end(0) {}
*     Interval(int s, int e) : start(s), end(e) {}
* };
*/
#define vec_iter std::vector<Interval>::iterator

// hack to provide speed on LeetCode
static const auto _____ = []()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	return nullptr;
}();

class SummaryRanges {
public:
	SummaryRanges() {}

	void addNum(int val) {
		vec_iter begin = intervals_.begin();
		vec_iter end = intervals_.end();

		for (vec_iter it = begin; it != end; ++it) {
			// in exists interval
			if (val >= it->start && val <= it->end) {
				return;
			}

			// near interval
			if (isInRange(it->start, val, -1)) {
				it->start = val;
				return;
			}
			else if (isInRange(it->end, val, 1)) {
				it->end = val;

				//check if need join
				vec_iter next = it + 1;
				if (next != end && isInRange(it->end, next->start, 1)) {
					it->end = next->end;
					intervals_.erase(next);
				}
				return;
			}
			else if (val < it->start) {
				intervals_.insert(it, Interval(val, val));
				return;
			}
		}
		intervals_.push_back(Interval(val, val));
	}

	bool isInRange(const int& border, const int& value, const int& range) {
		return (border + range == value);
	}

	vector<Interval> getIntervals() {
		return intervals_;
	}
private:
	vector<Interval> intervals_;
};

/**
* Your SummaryRanges object will be instantiated and called as such:
* SummaryRanges obj = new SummaryRanges();
* obj.addNum(val);
* vector<Interval> param_2 = obj.getIntervals();
*/