class Solution {
public:
    string decodeString(string str) {
        stack<int> numberSt;
        stack<string> stringSt;
        int k = 0;
        for(auto it: str){
            if(it >= '0' and it <= '9'){
                k = k*10 + (it-'0');
                continue;
            }
            else if(it == '['){
                numberSt.push(k);
                cout<<numberSt.top()<<endl;
                k = 0;
                stringSt.push(string(1,it));
            }
            else if(it >= 'a' and it <= 'z'){
                stringSt.push(string(1,it));
                continue;
            }
            else if(it == ']'){
                int num = numberSt.top();
                numberSt.pop();
                string str = "";
                while(!stringSt.empty() and stringSt.top() != "["){
                    str = stringSt.top() + str;
                    stringSt.pop();
                }
                
                stringSt.pop();
                string  temp = "";
                
                for(int i=0;i<num;i++){
                    temp += str;
                }
                
                stringSt.push(temp);
               
            }
        }
    
        string result = "";
        while(!stringSt.empty()){
            
            result = stringSt.top() + result;
            stringSt.pop();
        }
        return result;
    }
};