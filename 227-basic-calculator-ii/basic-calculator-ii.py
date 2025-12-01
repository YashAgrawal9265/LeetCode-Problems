class Solution:
    def calculate(self, str: str) -> int:
        n = len(str)
        st = []
        curNum = 0
        opr = '+'

        for i in range(n):
            ch = str[i]
            if(ch.isdigit()):
                curNum = curNum*10 + int(ch)
            if(not ch.isdigit() and ch != ' ' or i == n-1):
                if(opr == '+'):
                    st.append(curNum)
                if(opr == '-'):
                    st.append(-curNum)
                if(opr == '*'):
                    st.append(st.pop() * curNum)
                if(opr == '/'):
                    st.append(int(st.pop() / curNum))
                curNum = 0
                opr = ch
        
        result = 0
        while(st):
            result += st.pop()
        return result
        