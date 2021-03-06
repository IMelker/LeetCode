/*
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example:
Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
// hack to provide speed on LeetCode
static const auto _____ = []()
{
     ios::sync_with_stdio(false);
     cin.tie(nullptr);
     return nullptr;
}();

// recoursive solution
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2, int add_val = 0) {
        int temp_num = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + add_val;
        if(l1 || l2 || temp_num != 0) {
            ListNode* last_num = new ListNode(temp_num % 10);
            last_num->next = addTwoNumbers(l1 ? l1->next : NULL,
                                           l2 ? l2->next : NULL,
                                           temp_num/10);
            return last_num;
        }
        return NULL;
    }
};

