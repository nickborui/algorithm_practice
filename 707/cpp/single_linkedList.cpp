class MyLinkedList {
private:
    struct Node {
        int val;
        Node* next;
    };
    
    int size;
    Node* head;
    Node* tail;
    
public:
    /** Initialize your data structure here. */
    MyLinkedList() {
        size = 0;
        head = nullptr;
        tail = nullptr;
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        
        if (index < 0 || index >= size) return -1;
        
        Node* tmp = new Node;
        tmp = head;
        for (int i = 0; i < index; i++) {
            tmp = tmp->next;
        }
        
        return tmp->val;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        
        Node* tmp = new Node;
        tmp->val = val;
        tmp->next = head;
        head = tmp;
        
        if (size == 0) tail = head;
        
        size++;
        
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        Node* tmp = new Node;
        tmp->val = val;
        
        if (size == 0) {
            tmp->next = nullptr;
            head = tail = tmp;
            size++;
            return;
        }
        
        tail->next = tmp;
        tail = tmp;
        size++;
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if (index < 0 || index > size) return;
        
        if (index == 0) {
            addAtHead(val);
            return;
        } else if (index == size) {
            addAtTail(val);
            return;
        }
        
        Node* curNode = head;
        for (int i = 0; i < index - 1; i++) {
            curNode = curNode->next;
        }
        
        Node* tmp = new Node;
        tmp->val = val;
        tmp->next = curNode->next;
        curNode->next = tmp;
        size++;
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if (index < 0 || index >= size) return;
        else if (index == 0) {
            head = head->next;
            size--;
            return;
        }
        
        Node* curNode = head;
        for (int i = 0; i < index - 1; i++) {
            curNode = curNode->next;
        }
        
        curNode->next = curNode->next->next;
        if (index == size - 1) {
            tail = curNode;
        }
        size--; // Decrement the size after moving the tail pointer!!!
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList obj = new MyLinkedList();
 * int param_1 = obj.get(index);
 * obj.addAtHead(val);
 * obj.addAtTail(val);
 * obj.addAtIndex(index,val);
 * obj.deleteAtIndex(index);
 */
