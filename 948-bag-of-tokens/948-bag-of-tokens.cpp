class Solution {
public:
    int bagOfTokensScore(vector<int>& arr, int power) {
        int n = arr.size();
        sort(arr.begin(),arr.end());
        int mxScore = 0, score = 0;
        int i = 0, j = n-1;
        while(i <= j){
            if(power >= arr[i]){
                score++;
                power -= arr[i];
                i++;
            }
            else if(score >= 1){
                score--;
                power += arr[j];
                j--;
            }
            else break;
            mxScore = max(mxScore,score);
        }
        return mxScore;
        
    }
};