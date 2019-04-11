/*
You are given two linked lists representing two non-negative numbers. 
The digits are stored in reverse order and each of their nodes contain a single digit.
 Add the two numbers and return it as a linked list.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
  public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {

        if (l1 == NULL || l2 == NULL)
            return (l1 == NULL) ? l2 : l1;
        ListNode *p1 = l1;
        ListNode *p2 = l2;
        int carry = 0, num;
        ListNode *res = new ListNode(-1);
        ListNode *p = res;
        while (p1 != NULL || p2 != NULL || carry)
        {
            num = (p1 ? p1->val : 0) + (p2 ? p2->val : 0) + carry;
            carry = num >= 10 ? 1 : 0;
            num %= 10;
            ListNode *tmp = new ListNode(num);
            p->next = tmp;
            p = p->next;
            if (p1)
                p1 = p1->next;
            if (p2)
                p2 = p2->next;
        }
        return res->next;
    }
};

int main(int argc, char const *argv[])
{

    return 0;
}
