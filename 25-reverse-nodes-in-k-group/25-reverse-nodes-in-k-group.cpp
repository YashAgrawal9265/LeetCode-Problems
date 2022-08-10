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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head or k == 0) return head;
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;
        
        int len = 0;
        ListNode* node= head;
        while(node){
            node = node->next;
            len++;
        }
        node = head;
        while(node){
            if(len < k){
                temp->next = node;
                break;
            }
            ListNode* cur = node, *pre = NULL, *nex = NULL;
            int x = k;
            while(cur and x--){
                nex = cur->next;
                cur->next = pre;
                pre = cur;
                cur = nex;
            }
            temp->next = pre;
            temp = node;
            node = cur;
            len -= k;
        }
        return dummy->next;
    }
};