/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* original = head;
        Node* copy;
        while(original){
            copy = new Node(original->val);
            copy->next = original->next;
            original->next = copy;
            original = copy->next;
        }
        original = head;
        while(original){
            if(original->random) original->next->random = original->random->next;
            original = original->next->next;
        }
        Node* dummy = new Node(-1);
        copy = dummy;
        original = head;
        while(original){
            copy->next = original->next;
            copy = copy->next;
            original->next = copy->next;
            copy->next = NULL;
            original = original->next;
        }
        return dummy->next;
    }
};