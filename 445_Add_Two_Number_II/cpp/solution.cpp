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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1, s2;
        while (l1) {
            s1.push(l1->val);
            l1 = l1->next;
        }
        while (l2) {
            s2.push(l2->val);
            l2 = l2->next;
        }
        int carry_on = 0;
        ListNode *cur = NULL, *prev = NULL;
        
        while (s1.size() || s2.size() || carry_on) {
            int sum = carry_on;
            if (s1.size()) {
                sum += s1.top();
                s1.pop();
            }
            if (s2.size()) {
                sum += s2.top();
                s2.pop();
            }
            
            prev = new ListNode(sum % 10);
            prev->next = cur;
            cur = prev;
            carry_on = sum / 10;
        }
        
        return cur;
        
    }
};
