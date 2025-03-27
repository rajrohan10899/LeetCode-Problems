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
    ListNode* deleteMiddle(ListNode* head) {

        if (head == NULL || head->next == NULL) {
            return NULL;
        }

        ListNode* slow_P = head;
        ListNode* fast_P = head;
        fast_P = fast_P->next->next;

        while (fast_P != NULL && fast_P->next != NULL) {
            slow_P = slow_P->next;
            fast_P = fast_P->next->next;
        }

        ListNode* delNode = slow_P->next;
        slow_P->next = slow_P->next->next;
        delete delNode;

        return head;
    }
};
