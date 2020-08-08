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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* head = NULL;
        int count = 0;
        if(lists.size() > 0) {
            head = lists[0];
        } else {
            return NULL;
        }
        for (int i = 1; i < lists.size(); i++) {
            ListNode* temp = head;
            ListNode* node = lists[i];
            ListNode* prev = NULL;
            while (node && temp) {
                //cout << node->val << " :: " << temp->val << endl;
                if (node->val > temp->val) {
                    prev = temp;
                    temp = temp->next;
                } else if (temp) {
                    ListNode* nl = new ListNode(node->val);
                    //nl->val = node->val;
                    nl->next = temp;
                    if (prev) {
                        prev->next = nl;
                    } else {
                        head = nl;
                    }
                    prev = nl;
                    node = node->next;
                } 
                if (node && temp == NULL) {
                    prev->next = node;
                    node = NULL;
                    break;
                }
            }
            if (head == NULL && node) {
                head = node;
            }
        }
        
        return head;
    }
};
