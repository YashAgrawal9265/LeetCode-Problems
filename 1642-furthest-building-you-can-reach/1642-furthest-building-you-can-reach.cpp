class Solution {
public:
    int furthestBuilding(vector<int>& arr, int bricks, int ladders) {
        priority_queue<int> pq;
        int result = 0;
        int i;
        for(i=0;i<arr.size()-1;i++){
            if(arr[i] >= arr[i+1])
                continue;
                
            int diff = arr[i+1] - arr[i];
            if(bricks >= diff){
                bricks -= diff;
                pq.push(diff);
            }
            else{
                if(ladders == 0) break;
                if(!pq.empty() and pq.top() > diff){
                    bricks += pq.top();
                    pq.pop();
                    bricks -= diff;
                    pq.push(diff);
                }
                ladders--;
            }
           
        }
        return i;
    }
};