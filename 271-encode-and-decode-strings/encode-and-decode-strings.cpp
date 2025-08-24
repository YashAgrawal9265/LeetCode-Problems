class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string str = "";
        for(auto it: strs){
            int n = it.size();
            str += to_string(n);
            str += "#";
            str += it;
        }
        return str;

    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string str) {
        // cout<<str<<endl;
        vector<string> result;
        int i = 0;
        while( i<str.size()){
            int j = i;
            while(str[j] != '#'){
                j++;
            }
            
            int strLen = stoi(str.substr(i,j-i));
            j = j+1;
            string temp = str.substr(j,strLen);
            result.push_back(temp);
            i = j+strLen;
        }
        return result;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));