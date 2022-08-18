/*
Given the head of a linked list, remove the nth node from the end of the list and return its head.

Example 1:
Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]

Example 2:
Input: head = [1], n = 1
Output: []

Example 3:
Input: head = [1,2], n = 1
Output: [1]
 
Constraints:
The number of nodes in the list is sz.
1 <= sz <= 30
0 <= Node.val <= 100
1 <= n <= sz
 
Follow up: Could you do this in one pass?
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head)
            return head;
        
        ListNode *prev=NULL, *slow=head, *fast=head;
        int i = 0;

        while(i<n)
        {
            fast = fast->next;
            i++;
        }

        while(fast)
        {
            prev = slow;
            slow = slow->next;
            fast = fast->next;
        }
        
        if(!prev)
        {
            head = head->next;  
            return head;
        }
 
        prev->next = slow->next;        
        slow->next = NULL;
        delete slow;
        
        return head;
    }
};
