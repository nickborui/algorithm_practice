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
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        vector<ListNode*> res(k, nullptr);
        int len = 0;
        ListNode* node = root;
        while (node) {
            len++;
            node = node->next;
        }
        
        int d = len / k;
        int r = len % k;
        
        for (int i = 0; i < k && root; i++) {
            res[i] = root;
            
	    // Only first i parts can split one more item
            for (int j = 1; j < d + (i < r); j++) {
                root = root->next;
            }
            
            ListNode* next = root->next;
            root->next = nullptr;
            root = next;
        }
        
        return res;
    }
};
