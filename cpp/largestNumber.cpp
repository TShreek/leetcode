/*
Given a list of non-negative integers nums, arrange them such that they form the largest number and return it.
Since the result may be very large, so you need to return a string instead of an integer.
  */
class Solution {
public:
    static bool compare(string a, string b){
        return a+b > b+a;
    }
    string largestNumber(vector<int>& nums) {
       vector<string> nums_str;
        for(int& num : nums){
            nums_str.push_back(to_string(num));
        }
        
        sort(nums_str.begin(),nums_str.end(),compare);
        
        if(nums_str[0] == "0")
            return "0";
        string result;
        for( string& num : nums_str){
            result += num;
        }
        return result;
    }
};
