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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<int> arr;
        while(head){
            arr.push_back(head->val);
            head = head->next;
        }
       
        vector<vector<int>> matrix(m, vector<int>(n,-1));
        
       
        
        int row_st=0,col_st=0,row_en=matrix.size()-1,col_en=matrix[0].size()-1;
        int dir = 0;
        
        int k = 0;
        while(col_st<=col_en and row_st<=row_en){
            if(k == arr.size()) break;
            if(dir == 0){
                // cout<<arr[k]<<endl;
                for(int col = col_st; col<=col_en;col++){
                    if(k == arr.size()) break;
                    matrix[row_st][col] = arr[k++];
                    // cout<<k<<endl;
                
                }
                
                row_st++;
            }
            else if(dir == 1){
                for(int row=row_st;row<=row_en;row++){
                    if(k == arr.size()) break;
                    matrix[row][col_en]= arr[k++];
                }
                col_en--;
            }
            else if(dir == 2){
                for(int col = col_en; col>=col_st;col--){
                    if(k == arr.size()) break;
                    matrix[row_en][col] = arr[k++];
                }
                row_en--;
            }
            else if(dir == 3){
                for(int row=row_en;row>=row_st;row--){
                    if(k == arr.size()) break;
                    matrix[row][col_st] = arr[k++];
                }
                col_st++;
            }
            dir = (dir+1) % 4;
        }
       
        
        return matrix;
    }
};