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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr || head->next == nullptr) return head;
        
        ListNode* old_tail = head;
        int n;
        for (n = 1; old_tail->next; n++) {
            old_tail = old_tail->next;
        }
        
        old_tail->next = head;
        
        ListNode* new_tail = head;
        for (int i = 0; i < n - (k % n) - 1; i++) {
            new_tail = new_tail->next;
        }
        
        head = new_tail->next;
        new_tail->next = nullptr;
        
        return head;
        
    }
};
