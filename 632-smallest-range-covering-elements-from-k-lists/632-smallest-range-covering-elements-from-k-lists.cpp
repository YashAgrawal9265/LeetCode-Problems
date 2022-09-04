class element
{
public:
    int row;
    int col;
    int ele;
    element(int _row, int _col, int _ele)
    {
        row = _row;
        col = _col;
        ele = _ele;
    }
};
struct cmp
{
    bool operator()(element a, element b)
    {
        return a.ele > b.ele;
    }
};
class Solution
{
public:
    vector<int> smallestRange(vector<vector<int>> &nums)
    {
        vector<int> result(2);
        priority_queue<element, vector<element>, cmp> pq;
        int maxi = INT_MIN;
        for (int i = 0; i < nums.size(); i++)
        {
            pq.push(element(i, 0, nums[i][0]));
            maxi = max(maxi, nums[i][0]);
        }
        int range = INT_MAX;
        int left,right;
        while (!pq.empty())
        {
            auto [row,col,mini] = pq.top();
            pq.pop();
            int temp_range = maxi - mini;
            if(temp_range < range){
                left = mini;
                right = maxi;
                range = temp_range;
            }
            if(col + 1 >= nums[row].size()) break;
            maxi = max(maxi,nums[row][col+1]);
            pq.push(element(row,col+1,nums[row][col+1]));
        }
        result[0] = left;
        result[1] = right;
        return result;
    }
};
