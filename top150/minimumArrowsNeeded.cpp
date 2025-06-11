class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if(points.empty()) return 0;
        sort(points.begin(),points.end(), [](const vector<int> &a, const vector<int> &b){
            return a[1]<b[1];
        });
        int arrows=1,n=points.size(),i=0;
        int last= points[0][1];
        while(i<n){
            if(points[i][0] > last){
                arrows++;
                last=points[i][1];
            }
            i++;
        }
        return arrows;
    }
};

// Intervals
