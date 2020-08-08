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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *link_prev, *link_curr, *link_temp, *prev, *curr, *next, *temp;
        prev = link_prev = link_curr = link_temp = NULL;
        curr = temp = head;
        int len = 0;
        while (temp) {
            temp = temp->next;
            len++;
        }
        if (len < k || k <= 1) {
            return head;
        }
        int node_count, rev_count, num;
        node_count = rev_count = 0;
        int rev_num = len / k;
        int deno = len % k;
        temp = head;
        cout << deno << endl;
        while (temp) {
            cout << temp->val << endl;
            cout << rev_count << " :: " << rev_num << endl;
            if (rev_count == rev_num) {
               // cout << "Returned!\n";
                return head;
            }
            while (node_count < k) {
                if (node_count == 0) {
                    link_temp = temp;
                }
                temp = temp->next;
                curr->next = prev;
                prev = curr;
                curr = temp;
                node_count++;
            }
            if (prev) {
                link_curr = prev;
            }
            if (link_prev) {
                link_prev->next = link_curr;
            }
            link_prev = link_temp;
            if (rev_count == 0) {
                head = prev;
            }
            if (rev_count == rev_num - 1 && deno == 0) {
                link_prev->next = NULL;
            } else if (rev_count == rev_num - 1) {
                link_prev->next = temp;
            }
            node_count = 0;
            rev_count++;
        }
        
        return head;
    }
};
