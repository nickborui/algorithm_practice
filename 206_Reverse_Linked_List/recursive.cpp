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
    
    ListNode* reverseHelper(ListNode* head, ListNode* prev) {
        if (head == nullptr) return prev;
        
        ListNode* next = head->next;
        head->next = prev;
        
        return reverseHelper(next, head);
    }
    
    
    ListNode* reverseList(ListNode* head) {
        return reverseHelper(head, nullptr);
    }
};
