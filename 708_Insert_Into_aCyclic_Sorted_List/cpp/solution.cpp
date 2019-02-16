/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node() {}
    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};
*/

class Solution {
public:
    Node* insert(Node* head, int insertVal) {
    	if (head == NULL) {
		Node* tmp = new Node;
		tmp->val = insertVal;
		tmp->next = tmp;
		head = tmp;
		return head;
	}
    	
	Node* prev = head;
	Node* cur  = head->next;

	while (cur != head) {
		if (prev->val <= insertVal <= cur->val) break;
		// 4 -> 1 case (4->5 or 4->0)
		if (prev->val > cur->val && (prev->val <= insertVal || cur->val >= insertVal)) break;

		prev = cur;
		cur  = cur->next;
	}

    	Node* tmp = new Node;
	tmp->val = insertVal;
	tmp->next = cur;
	pre->next = tmp;

	return head;
    
    };
