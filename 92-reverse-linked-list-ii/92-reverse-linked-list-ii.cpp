/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
private:
    ListNode* reverse(ListNode* node, ListNode* right){
        if(node == right) return right;
        ListNode* head = reverse(node->next,right);
        node->next->next = node;
        node->next = NULL;
        return head;
    }
public:
    ListNode* reverseBetween(ListNode* head, int l, int r) {
        if(!head or !head->next) return head;
        ListNode* left = NULL, *left_prev = NULL;
        ListNode* right = NULL, *right_next = NULL;
        ListNode* node = head;
        while(node){
            if(l == 2) left_prev = node;
            if(l == 1) left = node;
            if(r == 1) right = node;
            node = node->next;
            l--,r--;
        }
        if(!left or !right) return head;
        right_next = right->next;
        ListNode* temp = reverse(left,right);
       
        if(left_prev) left_prev->next = temp;
        left->next = right_next;

        if(left == head) return temp;
        return head;
    }
};