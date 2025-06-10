class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        int i=0,n = intervals.size();
      // This is to ensure anything that doesnt match just passes into result
        while(i < n && intervals[i][1] < newInterval[0]){
            res.push_back(intervals[i]);
            i++;
        }
      // This only runs if there can be an overlap
        while(i < n && intervals[i][0] <= newInterval[1]){
            newInterval[0] = min(intervals[i][0],newInterval[0]);
            newInterval[1] = max(intervals[i][1],newInterval[1]);
            i++;
        }
        res.push_back(newInterval); // Ensure this is out of while loop otherwise it will run for every element in interval
      //Add everything
        while(i < n){
            res.push_back(intervals[i]);
            i++;
        }
        return res;
    }
};
