/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        if (!head) {
            return head;
        }
        
        // Initialize stack and push the head node
        std::stack<Node*> stack;
        stack.push(head);
        Node* prev = new Node();
        
        while (!stack.empty()) {
            // Pop a node from the stack
            Node* curr = stack.top();
            stack.pop();
            
            // Link previous node to current node
            prev->next = curr;
            curr->prev = prev;
            
            // If current node has a next node, push it to the stack
            if (curr->next) {
                stack.push(curr->next);
            }
            
            // If current node has a child, push it to the stack
            if (curr->child) {
                stack.push(curr->child);
                // Detach the child
                curr->child = nullptr;
            }
            
            // Move the prev pointer to the current node
            prev = curr;
        }
        
        // Detach the pseudo head node and return the flattened list
        head->prev = nullptr;
        return head;
    }
};