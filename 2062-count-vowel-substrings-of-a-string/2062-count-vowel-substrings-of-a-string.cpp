class Solution {
public:
    bool isVowel(char c){
        if(c == 'a' or c == 'e' or c == 'i' or c == 'o' or c == 'u') return true;
        return false;
    }
    int solve(string str, int k){
        unordered_map<char,int> mp;
        int left = 0, right = 0, count = 0;
        int n = str.size();
        while(right < n){
            if(!isVowel(str[right])){
                mp.clear();
                left = right + 1;
            }
            else{
                mp[str[right]]++;
                while(mp.size() > k){
                    mp[str[left]]--;
                    if(mp[str[left]] == 0) mp.erase(str[left]);
                    left++;
                }
                count += (right - left + 1);
            }
            right++;
        }
        return count;
    }
    int countVowelSubstrings(string str) {
       
        return solve(str,5) - solve(str,4);
    }
};