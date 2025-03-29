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
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow_P = head;
        ListNode* fast_P = head;

        while(fast_P != NULL && fast_P->next != NULL) {
            slow_P = slow_P->next;
            fast_P = fast_P->next->next;

            //1. Detect Loop:
            if(slow_P == fast_P) { // Loop is there
                //2. Step : Find Starting Point.
                slow_P = head;
                while(slow_P != fast_P) {
                    slow_P = slow_P->next;
                    fast_P = fast_P->next;
                }
                return slow_P;
            }
        }
        return NULL;
    }
};