/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
public:
    vector<int> arr;
    int ptr;
    void solve(NestedInteger a, vector<int>& temp){
        if(a.isInteger()){
            temp.push_back(a.getInteger());
            return;
        }
        for(auto i: a.getList()){
            solve(i,temp);
        }
    }
    NestedIterator(vector<NestedInteger> &nestedList) {
        ptr = 0;
        for(int i=0;i<nestedList.size();i++){
            solve(nestedList[i],arr);
        }
    }
    
    int next() {
       int value = arr[ptr];
       ptr++;
       return value; 
    }
    
    bool hasNext() {
        if(ptr >= arr.size()) return false;
        return true;
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */