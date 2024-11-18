class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if(n == 0)
            return 0;
        
        int left=0,right=n-1;
        int water=0,maxLeft=0,maxRight=0;
        
        while(left <= right)
        {
            if(height[left] <= height[right])
            {
                if(height[left] > maxLeft)
                    maxLeft = height[left];
                else
                    water += maxLeft - height[left];
                left++;
            }
            else
            {
                if(maxRight < height[right])
                {
                    maxRight = height[right];
                }
                else
                    water+= maxRight- height[right];
                right--;
            }
            
        }
        return water;
    }
};
