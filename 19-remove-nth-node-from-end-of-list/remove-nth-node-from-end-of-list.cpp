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
        int count =1 ;
        ListNode* temp =head ;

        while(temp->next){
            temp =temp ->next ;
            count++ ;
        }
        if(count == n){
            ListNode*newHead = head->next;
            delete head;
            return newHead ;
        }
        temp=head ;
        int steps = count - n-1 ;
        while(steps--){
            temp = temp->next ;

        }
        ListNode* del = temp->next ;
        temp->next =del->next ;
      delete del ;
        return head;

    }
};