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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
         if(headA == NULL || headB == NULL)
        return NULL;
     ListNode* left = headA ;
     ListNode* right = headB;
    
while(left != right){
     if(left==NULL){
        left = headB;

    }
        else{
left = left->next;
        }
     
    if(right == NULL){
    right = headA;
}
else{
  right = right->next ;
}
    if(left == right){
    return left ;
}
}
return left ;


    }
};