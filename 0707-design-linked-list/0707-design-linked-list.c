typedef struct {
    struct ListNode *head;
    int size;
} MyLinkedList;

MyLinkedList* myLinkedListCreate() {
    MyLinkedList *obj = (MyLinkedList *) malloc(sizeof(MyLinkedList));
    obj->head = NULL;
    obj->size = 0;
    return obj;
}

int myLinkedListGet(MyLinkedList* obj, int index) {
    if (index < 0 || index >= obj->size) {
        return -1;
    }
    struct ListNode *cur = obj->head;
    for (int i = 0; i < index; ++i) {
        cur = cur->next;
    }
    return cur->val;
}

void myLinkedListAddAtHead(MyLinkedList* obj, int val) {
    struct ListNode *new_node = (struct ListNode *) malloc(sizeof(struct ListNode));
    new_node->val = val;
    new_node->next = obj->head;
    obj->head = new_node;
    obj->size++;
}

void myLinkedListAddAtTail(MyLinkedList* obj, int val) {
    struct ListNode *new_node = (struct ListNode *) malloc(sizeof(struct ListNode));
    new_node->val = val;
    new_node->next = NULL;
    if (obj->size == 0) {
        obj->head = new_node;
    } else {
        struct ListNode *cur = obj->head;
        while (cur->next) {
            cur = cur->next;
        }
        cur->next = new_node;
    }
    obj->size++;
}

void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {
    if (index > obj->size) {
        return;
    }
    if (index <= 0) {
        myLinkedListAddAtHead(obj, val);
    } else {
        struct ListNode *cur = obj->head;
        for (int i = 0; i < index - 1; ++i) {
            cur = cur->next;
        }
        struct ListNode *new_node = (struct ListNode *) malloc(sizeof(struct ListNode));
        new_node->val = val;
        new_node->next = cur->next;
        cur->next = new_node;
        obj->size++;
    }
}

void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {
    if (index < 0 || index >= obj->size) {
        return;
    }
    if (index == 0) {
        struct ListNode *temp = obj->head;
        obj->head = obj->head->next;
        free(temp);
    } else {
        struct ListNode *cur = obj->head;
        for (int i = 0; i < index - 1; ++i) {
            cur = cur->next;
        }
        struct ListNode *temp = cur->next;
        cur->next = cur->next->next;
        free(temp);
    }
    obj->size--;
}

void myLinkedListFree(MyLinkedList* obj) {
    while (obj->head) {
        struct ListNode *temp = obj->head;
        obj->head = obj->head->next;
        free(temp);
    }
    free(obj);
}