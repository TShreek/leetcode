using namespace std;
class Solution {
public:
    int maxArea(vector<int>& height) { 
        int currentArea=0, highest=0;
        int left=0,right = height.size()-1;
        while(left < right){
            currentArea = (right-left) * min(height[left],height[right]);
            highest = max(currentArea, highest);
            
            if(height[right]>height[left]){
                left++;
            }
            else{
                right--;
            }
        }
        return highest;
    }
};
