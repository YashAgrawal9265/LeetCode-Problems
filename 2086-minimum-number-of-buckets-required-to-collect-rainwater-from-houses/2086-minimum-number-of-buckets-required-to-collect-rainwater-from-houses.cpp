class Solution {
public:
    int minimumBuckets(string str) {
        int n = str.size();
        int result = 0;
        for(int i=0;i<n;){
            if(str[i] == 'H'){
                if(i+1<n and str[i+1] == '.'){
                    result++;
                    i+=3;
                }
                else if(i-1 >= 0 and str[i-1] == '.'){
                    result++;
                    i++;
                }
                else{
                    return -1;
                }
            }
            else{
                i++;
            }
        }
        return result;
    }
};