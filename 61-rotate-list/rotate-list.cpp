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
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode*temp =head;
        int n=1 ;
        if(head == NULL || head->next == NULL){
            return head;
        }
        while(temp->next != NULL){
            temp = temp->next ;
            n++ ;
        }
         k = k %n ;
        temp->next = head ;
        temp= head;
        int count = 1 ;
        while(count < n-k){
            temp = temp->next ;
            count++ ;
            
        }
        ListNode* newHead = temp->next ;
        
        temp->next = NULL;
        return newHead;
    }
};