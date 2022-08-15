class Solution {
public:
    string intToRoman(int num) {
        string roman[] = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        int integer[] = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
        
        string result = "";
        for(int i=0;i<13;i++){
            int count = num / integer[i];
            while(count--){
                result += roman[i];
            }
            num %= integer[i];
        }
        return result;
    }
};