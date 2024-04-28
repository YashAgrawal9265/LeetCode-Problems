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
    ListNode* merge(ListNode* left, ListNode* right){
        ListNode* dummyNode = new ListNode(-1);
        ListNode* temp = dummyNode;
        while(left and right){
            if(left->val < right->val){
                temp->next = left;
                left = left->next;
            }
            else{
                temp->next = right;
                right = right->next;
            }
            temp = temp->next;
        }
        if(left) temp->next = left;
        else temp->next = right;
        return dummyNode->next;
    }
    ListNode* findMiddle(ListNode* head){
        ListNode* slow = head, *fast = head->next;
        while(fast and fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    ListNode* mergeSort(ListNode* head){
        if(!head or !head->next){
            return head;
        }
        ListNode* middle = findMiddle(head);
        ListNode* left = head;
        ListNode* right = middle->next;
        middle->next = NULL;
        left = mergeSort(left);
        right = mergeSort(right);
        head = merge(left,right);
        return head;
    }
public:
    ListNode* sortList(ListNode* head) {
        return mergeSort(head);
    }
};