/*
// Definition for an Interval.
class Interval {
public:
    int start;
    int end;

    Interval() {}

    Interval(int _start, int _end) {
        start = _start;
        end = _end;
    }
};
*/

class Solution {
public:
    bool static cmp(Interval a, Interval b){
        return a.start < b.start;
    }
    vector<Interval> employeeFreeTime(vector<vector<Interval>> schedule) {
        vector<Interval> arr;
        for(auto it: schedule){
            for(auto i: it){
                arr.push_back(i);
            }
        }
        sort(arr.begin(),arr.end(),cmp);
        vector<Interval> result;
        int end = arr[0].end;
        for(int i=1;i<arr.size();i++){
            if(arr[i].start > end){
                result.push_back(Interval(end,arr[i].start));
               
            }
            end = max(end,arr[i].end);
        }
        return result;
    }
};