/*
Given the head of a singly linked list, return true if it is a palindrome.

Example 1:
Input: head = [1,2,2,1]
Output: true

Example 2:
Input: head = [1,2]
Output: false

Constraints:
The number of nodes in the list is in the range [1, 105].
0 <= Node.val <= 9

Follow up: Could you do it in O(n) time and O(1) space?
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
private:
    int length(ListNode *head) {
      int count=0;
      while(head)
      {
          count++;
          head = head->next;
      }
      return count;
}

ListNode *reverse(ListNode* head2)
{
    ListNode *p=head2,*q=NULL,*r=NULL;
    while(p)
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    head2 = q;
    return q;
}
public:
    bool isPalindrome(ListNode* head) {
      ListNode *p = head;
      int x = length(head)/2;

      if(head==NULL || head->next==NULL)
                return true;

      for(int i=1;i<x;i++)
      {
          p = p->next;
      }
      ListNode *head2 = p->next;
      p->next = NULL;
      head2 = reverse(head2);

      while(head && head2)
      {
          if(head->val != head2->val)
              return false;
          head = head->next;
          head2 = head2->next;
      }
       return true;
    }
};
