class Solution:
    def calculate(self, s: str) -> int:

        n = len(s)
        curNumber = 0
        lastNumber = 0
        result = 0
        opr = '+'

        for i in range(n):
            ch = s[i]
            if(ch.isdigit()):
                curNumber = curNumber*10 + int(ch)
            if(not ch.isdigit() and ch != ' ' or i == n-1):
                if opr == '+':
                    result += lastNumber
                    lastNumber = curNumber
                if opr == '-':
                    result += lastNumber
                    lastNumber = -curNumber
                if opr == '*':
                    lastNumber = lastNumber * curNumber
                if opr == '/':
                    lastNumber = int(lastNumber / curNumber)
            
                curNumber = 0
                opr = ch
        

        result += lastNumber
        return result

        