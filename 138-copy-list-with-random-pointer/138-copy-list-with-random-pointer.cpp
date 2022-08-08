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
        unordered_map<Node*, Node*> mp;
        Node* original = head;
        Node* dummy = new Node(0);
        Node* clone = dummy;
        while(original){
            Node* temp = new Node(original->val);
            mp[original] = temp;
            clone->next = temp;
            clone = temp;
            original = original->next;
        }
        original = head;
        clone = dummy->next;
        while(original){
            clone->random = mp[original->random];
            original = original->next;
            clone = clone->next;
        }
        return dummy->next;
    }
};