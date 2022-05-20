class Solution {
public:
    bool isVowel(char c){
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') return true;
        return false;
    }
    int count_at_most_k_vowel(string& str, int k){
        int n = str.size();
        unordered_map<char,int> mp;
        int right = 0, left = 0;
        int count = 0;
        int result = 0;
        while(right < n){
            if(!isVowel(str[right])){
                left = right + 1;
                right++;
                mp.clear();
                count = 0;
                continue;
            }
            mp[str[right]]++;
            if(mp[str[right]] == 1) count++;
            while(count > k){
                mp[str[left]]--;
                if(mp[str[left]] == 0) count--;
                left++;
            }
            result += (right-left+1);
            right++;
        }
        return result;
    }
    int countVowelSubstrings(string str) {
        return count_at_most_k_vowel(str,5) - count_at_most_k_vowel(str,4);
        
    }
};