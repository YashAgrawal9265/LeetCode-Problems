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
    ListNode* reverse(ListNode* head){
        ListNode* cur = head, *pre = nullptr, *nex;
        while(cur){
            nex = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nex;
        }
        return pre;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        
        ListNode* temp = nullptr;
        l1 = reverse(l1);
        l2 = reverse(l2);
        while(l1 or l2 or carry){
            int sum = carry;
            if(l1) sum += l1->val;
            if(l2) sum += l2->val;
            ListNode* node = new ListNode(sum % 10);
            carry = sum / 10;
            node->next = temp;
            temp = node;
            if(l1) l1 = l1->next;
            if(l2) l2 = l2->next;
        }
        return temp;
    }
};