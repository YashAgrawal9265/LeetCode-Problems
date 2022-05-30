class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& arr) {
        sort(arr.begin(),arr.end());
        int result = 0;
        int visRow = 0;
        for(int idx=0;idx<arr.size();idx++){
            int row = arr[idx][0];
            visRow++;
            vector<int> temp(11,0);
            int count = 0;
            int j;
            for(j=idx;j<arr.size();j++){
                if(row != arr[j][0]){
                    idx = j-1;
                    break;
                }
                temp[arr[j][1]] = 1;
            }
            if(j == arr.size()) idx = j-1;
            bool flag = true;
            for(int i=2;i<=5;i++){
                if(temp[i] == 1){
                    flag = false;
                    break;
                }
            }
            if(flag) count++;
            flag = true;
            for(int i=6;i<=9;i++){
                if(temp[i] == 1){
                    
                    flag = false;
                    break;
                }
                
            }
            if(flag) count++;
            flag = true;
            if(count == 0){
                for(int i=4;i<=7;i++){
                    if(temp[i] == 1){
                        flag = false;
                        break;
                    }
                }
                if(flag) count++;
            }
            
            result += count;
            
        }
        result += (n-visRow)*2;
        return result;
    }
};