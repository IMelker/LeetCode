/* Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.

Note: 
You may assume k is always valid, 1 ≤ k ≤ BST's total elements.

Example 1:

Input: root = [3,1,4,null,2], k = 1
Output: 1
Example 2:

Input: root = [5,3,6,2,4,null,null,1], k = 3
Output: 3
*/

/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/

static const auto _____ = []()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	return nullptr;
}();

// simple solution
class Solution {
public:
	int kthSmallest(TreeNode* root, int k) {
		TreeToVector(root);
		std::nth_element(values.begin(), values.begin() + --k, values.end());
		return values.at(k);
	}

	void TreeToVector(TreeNode* root) {
		if (root == nullptr) return;
		values.push_back(root->val);
		TreeToVector(root->left);
		TreeToVector(root->right);
	}

private:
	std::vector<int> values;
};