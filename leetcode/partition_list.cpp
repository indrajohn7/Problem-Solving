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
    ListNode* partition(ListNode* head, int x) {
        ListNode* temp; // = head;
        ListNode* curr = head;
        temp = NULL;
        ListNode* prev = NULL;
        int count = 0;
        bool flag = false;
        
        while (curr != NULL) {
            prev = temp;
            temp = curr;
            if (curr->val >= x) {
                curr = curr->next;
                break;
            }
            curr = curr->next;
            
        }
        if (curr->next == NULL) {
            return head;
        }
        ListNode* prev2 = temp;
        while (curr != NULL) {
            bool flag = false;
            if (curr->val < x) {
                
                int val = curr->val;
                prev2->next = curr->next;
                delete(curr);
                ListNode* lost = new ListNode(val);
                if (prev == NULL) {
                    head = prev = lost;
                    prev->next = temp;
                } else {
                    prev->next = lost;
                    lost->next = temp;
                }
                flag = true;
            }
            if (flag) {
                curr = prev2->next;
            } else {
                prev2 = curr;
                curr = curr->next;
            }
        }
        
        return head;
    }
};

