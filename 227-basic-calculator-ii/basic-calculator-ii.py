class Solution:
    def calculate(self, s: str) -> int:

        n = len(s)
        curNumber = 0
        stack = []
        opr = '+'

        for i in range(n):
            ch = s[i]
            if(ch.isdigit()):
                curNumber = curNumber*10 + int(ch)
            if(not ch.isdigit() and ch != ' ' or i == n-1):
                if opr == '+':
                    stack.append(curNumber)
                if opr == '-':
                    stack.append(-curNumber)
                if opr == '*':
                    stack.append(stack.pop() * curNumber)
                if opr == '/':
                    stack.append(int(stack.pop() / curNumber))
            
                curNumber = 0
                opr = ch
        

        result = 0
        while stack:
            result += stack.pop()
        return result

        