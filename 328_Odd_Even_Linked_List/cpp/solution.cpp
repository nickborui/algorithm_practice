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
    ListNode* oddEvenList(ListNode* head) {
        if (head == nullptr) return head;
        
        ListNode* oddCur = head;
        ListNode* evenHead = head->next;
        ListNode* evenCur = evenHead;
        
        while (evenCur && evenCur->next) {
            oddCur->next = evenCur->next;
            evenCur->next = evenCur->next->next;
            oddCur = oddCur->next;
            evenCur = evenCur->next;
        }
        
        oddCur->next = evenHead;
        return head;
    }
};
