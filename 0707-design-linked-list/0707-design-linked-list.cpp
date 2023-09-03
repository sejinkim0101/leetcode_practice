// include <iostream>
class MyLinkedList {
public:
    MyLinkedList() : head(NULL), size(0) {}

    int get(int index) {
        if (index < 0 || index >= size) {
            return -1;
        }
        ListNode *cur = head;
        for (int i = 0; i < index; ++i) {
            cur = cur->next;
        }
        return cur->val;
    }

    void addAtHead(int val) {
        ListNode *new_node = new ListNode(val);
        new_node->next = head;
        head = new_node;
        size++;
    }

    void addAtTail(int val) {
        ListNode *new_node = new ListNode(val);
        if (size == 0) {
            head = new_node;
        } else {
            ListNode *cur = head;
            while (cur->next) {
                cur = cur->next;
            }
            cur->next = new_node;
        }
        size++;
    }

    void addAtIndex(int index, int val) {
        if (index > size) {
            return;
        }
        if (index <= 0) {
            addAtHead(val);
        } else {
            ListNode *cur = head;
            for (int i = 0; i < index - 1; ++i) {
                cur = cur->next;
            }
            ListNode *new_node = new ListNode(val);
            new_node->next = cur->next;
            cur->next = new_node;
            size++;
        }
    }

    void deleteAtIndex(int index) {
        if (index < 0 || index >= size) {
            return;
        }
        if (index == 0) {
            ListNode *temp = head;
            head = head->next;
            delete temp;
        } else {
            ListNode *cur = head;
            for (int i = 0; i < index - 1; ++i) {
                cur = cur->next;
            }
            ListNode *temp = cur->next;
            cur->next = cur->next->next;
            delete temp;
        }
        size--;
    }

private:
    ListNode *head;
    int size;
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */