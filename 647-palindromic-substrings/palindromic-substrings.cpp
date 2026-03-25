class Solution {
public:
    int countSubstrings(string str) {
        int n = str.size();
        int count = 0;
        for(int i=0;i<n;i++){
            int l = i, r = i;
            while(l >=0 and r < n and str[l] == str[r]){
                count++;
                l--;
                r++;
            }

            l = i, r = i+1;
            while(l >=0 and r < n and str[l] == str[r]){
                count++;
                l--;
                r++;
            }
        }
        return count;
    }
};