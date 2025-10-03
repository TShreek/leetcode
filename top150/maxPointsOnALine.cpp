class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if(n <= 2) return n;

        int ans = 0;
        for(int i = 0;i < n; i++){
            unordered_map<double, int> slopeCount;
            int samePoint = 0;
            int localMax = 0;

            for(int j = i+1; j<n;j++){
                int dx = points[j][0] - points[i][0];
                int dy = points[j][1] - points[i][1];

                if(dx == 0 && dy == 0){
                    samePoint++;
                    continue;
                }

                double slope;
                if(dx == 0) slope = DBL_MAX;
                else slope = (double)dy/dx;

                localMax = max(localMax, ++slopeCount[slope]);
            }
            ans = max(ans, localMax + samePoint + 1);
        }
        return ans;
    }
};
