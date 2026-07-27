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
ListNode* reverse(ListNode* head) {
    ListNode* prev = NULL;
    ListNode* curr = head;

    while(curr != NULL) {
        ListNode* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}
    bool isPalindrome(ListNode* head) {
        if(head == NULL || head->next == NULL)
    return true;
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* mid = NULL;
        while(fast != NULL && fast->next != NULL){
            slow =slow ->next ;
            fast =fast->next->next ;
           
        }
        if(fast != NULL)
    slow = slow->next;

ListNode* secondHalf = reverse(slow);
ListNode* p1 = head ;
ListNode* p2 = secondHalf ;
while(p2 != NULL){
     if(p1->val != p2->val){
        return false;
    }
    p1 =p1->next ;
    p2 =p2->next ;
   
}
return true;
    }
};