// Definition for singly-linked list.
// struct ListNode {
//     int val;
//     struct ListNode *next;
// };
// Definition for a binary tree node.
// struct TreeNode {
//     int val;
//     struct TreeNode *left;
//     struct TreeNode *right;
// };

bool checkPath(struct ListNode* head, struct TreeNode* node) {
    if (!head) return true;
    if (!node) return false;
    if (head->val != node->val) return false;
    return checkPath(head->next, node->left) || checkPath(head->next, node->right);
}

bool isSubPath(struct ListNode* head, struct TreeNode* root) {
    if (!root) return false;
    return checkPath(head, root) || isSubPath(head, root->left) || isSubPath(head, root->right);
}
