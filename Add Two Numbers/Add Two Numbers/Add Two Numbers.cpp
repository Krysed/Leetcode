/*
2. Add Two Numbers
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, 
and each of their nodes contains a single digit. 
Add the two numbers and return the sum as a linked list.
You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.
Example 2:

Input: l1 = [0], l2 = [0]
Output: [0]
Example 3:

Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
Output: [8,9,9,9,0,0,0,1]

Constraints:

The number of nodes in each linked list is in the range [1, 100].
0 <= Node.val <= 9
It is guaranteed that the list represents a number that does not have leading zeros.
*/
#include <iostream>
#include <memory>

  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 

  class Solution {
  public:
      ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
          ListNode* dummy = new ListNode();
          ListNode* current = dummy;
          int carry = 0;

          while (l1 != nullptr || l2 != nullptr) {
              int sum = carry;
              if (l1 != nullptr) {
                  sum += l1->val;
                  l1 = l1->next;
              }
              if (l2 != nullptr) {
                  sum += l2->val;
                  l2 = l2->next;
              }
              carry = sum / 10;
              current->next = new ListNode(sum % 10);
              current = current->next;
          }

          if (carry > 0) {
              current->next = new ListNode(carry);
          }

          return dummy->next; // Return the next node after the dummy node (head of the result list)
      }
  };


  int main() {
      ListNode* l1 = new ListNode(2);
      l1->next = new ListNode(4);
      l1->next->next = new ListNode(3);

      ListNode* l2 = new ListNode(5);
      l2->next = new ListNode(6);
      l2->next->next = new ListNode(4);

      Solution sol;
      ListNode* result = sol.addTwoNumbers(l1, l2);

      while (result != nullptr) {
          std::cout << result->val << " ";
          result = result->next;
      }
      std::cout << std::endl;
    return 0;
}
