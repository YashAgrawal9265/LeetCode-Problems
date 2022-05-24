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
    ListNode* reverseEvenLengthGroups(ListNode* head) {
        vector<vector<ListNode*>> arr;
        int group = 1;
        while(head){
            vector<ListNode*> temp;
            int k = group;
            while(head and k>0){
                temp.push_back(head);
                head = head->next;
                k--;
            }
            arr.push_back(temp);
            group++;
        }
     
        
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;
        for(auto &it: arr){
            if(it.size() % 2 == 0) reverse(it.begin(),it.end());
            for(auto &i : it){
                temp->next = i;
                temp = temp->next;
            }
        }
        temp->next=NULL;
        return dummy->next;
    }
};