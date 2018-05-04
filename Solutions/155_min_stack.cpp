/* Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
getMin() -- Retrieve the minimum element in the stack.

Example:
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin();   --> Returns -3.
minStack.pop();
minStack.top();      --> Returns 0.
minStack.getMin();   --> Returns -2. */

// hack to provide speed on LeetCode
static const auto _____ = []()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	return nullptr;
}();

class MinStack {
public:
	/** initialize your data structure here. */
	MinStack() :
		array_size_(2048),	// hack array size for better speed
		stack_size_(0),
		min_value_index_(0) {
		ptrarray_ = new int[array_size_];
	}

	~MinStack() {
		delete[] ptrarray_;
	}

	void push(int x) {
		// reorginize data array
		if (stack_size_ == array_size_) {
			int new_array_size_ = array_size_ * 1.75;

			int *new_array = new int[new_array_size_];
			for (int i = 0; i < array_size_; ++i) {
				new_array[i] = ptrarray_[i];
			}

			ptrarray_ = new_array;
			array_size_ = new_array_size_;
		}

		ptrarray_[stack_size_] = x;
		// new min for faster getMin()
		if (x < ptrarray_[min_value_index_] && min_value_index_ != -1) {
			min_value_index_ = stack_size_;
		}
		++stack_size_;
	}

	void pop() {
		// if min value was poped
		if (stack_size_ - 1 == min_value_index_) {
			min_value_index_ = -1;
		}

		if (stack_size_ > 0) {
			--stack_size_;
		}
	}

	int top() {
		return ptrarray_[stack_size_ - 1];
	}

	int getMin() {
		// if need to refind min value
		if (min_value_index_ == -1) {
			min_value_index_ = 0;
			for (int i = 0; i < stack_size_; ++i) {
				if (ptrarray_[i] < ptrarray_[min_value_index_]) {
					min_value_index_ = i;
				}
			}
		}

		return ptrarray_[min_value_index_];
	}

private:
	int *ptrarray_;
	int array_size_;
	int stack_size_;
	int min_value_index_;
};