class Solution {
public:
    int minimumLines(vector<vector<int>>& arr) {
        sort(arr.begin(),arr.end());
        int n=arr.size();
        int count=0;
        long double  prev=(long double)INT_MAX;
       
        
        for(int i=1;i<n;i++)
        {
            long double   y2=arr[i][1],x2=arr[i][0];
            long double  y1=arr[i-1][1],x1=arr[i-1][0];
            
            long double   m=(y2-y1)/(x2-x1);
            if(m!=prev)
            {
                count++;
                prev=m;
            }
            
        }
        return count;
        
    }
};