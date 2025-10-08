class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;

        for(int bits = 0; bits < 32; bits++){
            int count = 0;

            for(int num : nums){
                if(num >> bits & 1) count++;
            }

            if(count % 3 != 0){
                result |= (1 << bits);
            }
        }   
        return result;
    }
};
