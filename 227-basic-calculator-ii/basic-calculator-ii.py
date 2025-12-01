class Solution:
    def calculate(self, str: str) -> int:

        n = len(str)
        stack = []
        opr = '+'
        curNum = 0

        for i in range(n):
            ch = str[i]
            if ch.isdigit():
                curNum = curNum*10 + int(ch)
            
            if (not ch.isdigit() and ch != ' ') or i == n-1:
                print(ch)
                if opr == '+':
                    # print('+')
                    stack.append(curNum)
                elif opr == '-':
                    # print('e-')
                    stack.append(-curNum)
                elif opr == '*':
                    # print('*')
                    stack.append(stack.pop() * curNum)
                elif opr == '/':
                    # print('/')
                    stack.append(int(stack.pop() / curNum))

                curNum = 0
                opr = ch
        
        result = 0
     
        while stack:
            result += stack.pop()

        return result

            

        