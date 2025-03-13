class Solution {
public:
    vector<int> asteroidCollision(vector<int>& arr) {
        stack<int> st;

        int n = arr.size();
        int i = 0;
        while(i < n){
            if(st.empty()){
                st.push(arr[i]);
                i++;
            }
            else{
                if((st.top() > 0 and arr[i] > 0) || (st.top() < 0 and arr[i] < 0)){
                    st.push(arr[i]);
                    i++;
                }
                else{
                    // if top is positive and array element is negative
                    if(st.top() > 0 and arr[i] < 0){
                        if(abs(arr[i]) == st.top()){
                            st.pop();
                            i++;
                        }
                        else if(abs(arr[i]) > st.top()){
                            st.pop();
                        }
                        else{
                            i++;
                        }
                    }
                    else if(st.top() < 0 and arr[i] > 0){
                        st.push(arr[i]);
                        i++;
                    }
                }
            }
        }
        vector<int> result;
        while(!st.empty()){
            result.push_back(st.top());
            st.pop();
        }
        reverse(result.begin(),result.end());
        return result;
    }
};