/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
   ListNode*left = head;
   ListNode*right =head;
   while(right != NULL && right->next != NULL){
    left= left ->next ;
    right = right->next->next ;
    if(left ==  right){
        return true ;
    }
   }
   return false;


     }};