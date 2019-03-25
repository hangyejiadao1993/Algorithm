/*

Given a singly linked list L: L 0→L 1→…→L n-1→L n,
reorder it to: L 0→L n →L 1→L n-1→L 2→L n-2→…

You must do this in-place without altering the nodes' values.

For example,
Given{1,2,3,4}, reorder it to{1,4,2,3}.

*/

#include <iostream>
#include <vector>
#include<stdlib.h>
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
    void recorderList(ListNode *head)
    {
       if(!head) return;
         
        vector<int> V;
        ListNode* ptr = head;
         
         while(ptr != NULL){
            V.push_back(ptr->val);
            ptr = ptr->next;
        }
         
        int i= 0;
        int j= V.size()-1;
        int flag = 0;
        ptr = head;
        while(i<=j){
            if((flag%2)==0){
                ptr->val = V[i]; i+=1;
            }
            else{
                ptr->val = V[j]; j-=1;
            }
            ++ flag;
             
            ptr = ptr->next;
        }
    }
};

int main(int argc, char const *argv[])
{
   
    int a;
    int arr[]={1,2,3,4};
    ListNode *tem=new ListNode(1);
    tem->next=new ListNode(2);
    tem->next->next=new ListNode(3);
    tem->next->next->next=new ListNode(4);
    
     
    Solution so;
    so.recorderList(tem);

       
    while(tem !=NULL){
        cout<<tem->val<<" ,";
        tem=tem->next;
    }
    system("pause");
    return 0;
}
