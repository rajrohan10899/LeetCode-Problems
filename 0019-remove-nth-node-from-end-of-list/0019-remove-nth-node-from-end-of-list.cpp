class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len = 0;
        ListNode* temp = head;
        while(temp != NULL) {
            len++;
            temp = temp->next;
        }

        // Edge Case: if N is the head
        if(len == n) {
            ListNode* newHead = head->next;
            delete head;
            return newHead;
        }

        int resultant = len - n;
        temp = head;
        while(temp != NULL) {
            resultant--;

            if(resultant == 0) 
                break;

            temp = temp->next;
        }
        // Fix for n == 1 case (removing last node)
        if(temp->next != NULL) {
            ListNode* delNode = temp->next;
            temp->next = temp->next->next;
            delete delNode;
        } else {
            temp->next = nullptr; // This ensures safety if n==1
        }
        return head;
    }
};
