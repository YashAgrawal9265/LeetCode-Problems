class Solution {
public:
    vector<int> asteroidCollision(vector<int>& arr) {
        vector<int> result;
        stack<int> st;
        int i  = 0;
        while(i < arr.size()){
            if(st.empty()){
                st.push(arr[i]);
                i++;
            }
            else{
                if((st.top() > 0 and arr[i] > 0 )|| (st.top() < 0 and arr[i] < 0)){
                    st.push(arr[i]);
                    i++;
                }
                // if top element is positive and array element is negative
                else if(st.top() > 0 and arr[i] < 0){
                    if(st.top() > abs(arr[i])) i++;
                    else if(st.top() < abs(arr[i])) st.pop();
                    else{
                        st.pop();
                        i++;
                    }
                }
                else if(st.top() < 0 and arr[i] > 0){
                   st.push(arr[i]);
                   i++;
                }
            }
        }
        while(!st.empty()){
            result.push_back(st.top());
            st.pop();
        }
        reverse(result.begin(),result.end());
        return result;
    }
};