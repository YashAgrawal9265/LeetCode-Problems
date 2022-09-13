class Solution {
public:
    string convertBinary(int n){
        string result = "";
        for(int i=7;i>=0;i--){
            if(n&(1<<i)){
                result += '1';
            }
            else{
                result += '0';
            }
        }
        return result;
    }
    int getByte(string& str){
        int i = 0;
        while(i < str.size() and str[i] != '0'){
            i++;
        }
        if(i > 4 or i == 1) return -1;
        return i;
    }
    bool validUtf8(vector<int>& data) {
        vector<string> arr;
        for(auto it: data){
            arr.push_back(convertBinary(it));
        }
        int n = arr.size();
        int i = 0;
        while(i < n){
            int byte = getByte(arr[i]);
            if(byte == -1) return false;
            if(byte == 0){
                i++;
                continue;
            }
            int j = i+1;
            int count = 0;
            while(j < n and j <= i + byte-1){
                if(arr[j][0] != '1' or arr[j][1] != '0') return false;
                j++;
                count++;
            }
            if(count != byte-1) return false;
            i = j;
        }
        return true;
    }
};