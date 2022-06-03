class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        int freq[10] = {0};
        for(auto it: digits) freq[it]++;
        vector<int> result;
        for(int i=1;i<=9;i++){
            if(freq[i] == 0) continue;
            for(int j=0;j<=9;j++){
                if(freq[j] == 0) continue;
                else if(i == j and freq[j] < 2) continue;
                for(int k=0;k<=8;k+=2){
                    if(freq[k] == 0) continue;
                    else if(i == j and j == k and freq[k] < 3) continue;
                    else if(j == k and freq[k] < 2) continue;
                    else if(i == k and freq[k] < 2) continue;
                    
                    result.push_back(i*100 + j*10 + k);
                }
            }
        }
        return result;
    }
};