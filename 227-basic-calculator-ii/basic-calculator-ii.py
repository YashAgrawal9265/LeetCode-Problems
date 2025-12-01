class Solution:
    def calculate(self, str: str) -> int:

        n = len(str)
        stack = []
        opr = '+'
        curNum = 0
        lastNum = 0
        result = 0

        for i in range(n):
            ch = str[i]
            if ch.isdigit():
                curNum = curNum*10 + int(ch)
            
            if (not ch.isdigit() and ch != ' ') or i == n-1:
               
                if opr == '+':
                    # print('+')
                    result += lastNum
                    lastNum = curNum
                    # stack.append(curNum)
                elif opr == '-':
                    # print('e-')
                    result += lastNum
                    lastNum = -curNum
                    # stack.append(-curNum)
                elif opr == '*':
                    # print('*')
                    lastNum = lastNum * curNum
                    # stack.append(stack.pop() * curNum)
                elif opr == '/':
                    # print('/')
                    # stack.append(int(stack.pop() / curNum))
                    lastNum = int(lastNum / curNum)

                curNum = 0
                opr = ch
        
        result += lastNum
        return result
     
        # while stack:
        #     result += stack.pop()

        # return result

            

        