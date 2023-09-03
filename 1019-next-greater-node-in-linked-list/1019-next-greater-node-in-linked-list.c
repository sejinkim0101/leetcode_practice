// Definition for singly-linked list.
// struct ListNode {
//     int val;
//     struct ListNode *next;
// };

int* nextLargerNodes(struct ListNode* head, int* returnSize){
    // Initialize stack and result array
    int stack[10000][2], top = -1, i = 0;
    int *res = (int*)malloc(10000 * sizeof(int));
    
    while (head) {
        res[i] = 0;
        while (top >= 0 && stack[top][1] < head->val) {
            res[stack[top][0]] = head->val;
            top--;
        }
        stack[++top][0] = i;
        stack[top][1] = head->val;
        head = head->next;
        i++;
    }
    
    *returnSize = i;
    return res;
}
