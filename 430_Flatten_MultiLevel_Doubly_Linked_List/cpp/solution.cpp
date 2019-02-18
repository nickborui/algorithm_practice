/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;

    Node() {}

    Node(int _val, Node* _prev, Node* _next, Node* _child) {
        val = _val;
        prev = _prev;
        next = _next;
        child = _child;
    }
};
*/
class Solution {
public:
    Node* flatten(Node* head) {
        Node* dummy = head;
        flatten_helper(dummy);
        return head;
    }
    
    
private:
    Node* flatten_helper(Node* cur) {
        if (cur == nullptr) return cur;
        
        Node* prev = nullptr;
        while (cur) {
            prev = cur;
            if (cur->child) {
                Node* lastNode = flatten_helper(cur->child);
                // handle child node
                cur->child->prev = cur;
                
                // handle cur node
                Node* newCur = cur->next;
                cur->next = cur->child;
                cur->child = nullptr;
                
                // handle new cur node
                if (newCur) {
                    newCur->prev = lastNode;
                    lastNode->next = newCur;
                }
                
            } else {
                cur = cur->next;
            }
        }
        
        return prev;
    }
};
