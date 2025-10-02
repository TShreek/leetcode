class Solution {
public:
    int mySqrt(int x) {
        if(x < 2) return x;
        int lo = 2, high = x/2, ans = 1;
        while(lo <= high){
            int mid = lo + (high-lo)/2;
            if( mid <= x / mid){
                ans = mid;
                lo = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        return ans;
    }
};
