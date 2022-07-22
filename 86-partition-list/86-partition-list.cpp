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
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* dummy = new ListNode(0);
        ListNode* temp = dummy;
        ListNode* node = head;
        ListNode* newHead = NULL;
        ListNode* prev = NULL;
        while(node){
            // cout<<node->val<<endl;
            if(!newHead and node->val >= x){
                newHead = node;
            }
            if(node->val < x){
                if(prev) prev->next = node->next;
                temp->next = node;
                temp = node;
                if(prev) node = prev->next;
                else node = node->next;
            }
            else{
                prev = node;
                node = node->next;
            }
        }
        temp->next = newHead;
        return dummy->next;
    }
};