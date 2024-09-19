/*
Given a list of non-negative integers nums, arrange them such that they form the largest number and return it.
Since the result may be very large, so you need to return a string instead of an integer.
  */
class Solution {
public:
    // Custom comparator function
    static bool compare(string& a, string& b) {
        return a + b > b + a;
    }

    string largestNumber(vector<int>& nums) {
        // Convert all integers to strings
        vector<string> nums_str;
        for (int num : nums) {
            nums_str.push_back(to_string(num));
        }

        // Sort the strings using the custom comparator
        sort(nums_str.begin(), nums_str.end(), compare);

        // Edge case: if the largest number is '0', return '0'
        if (nums_str[0] == "0") {
            return "0";
        }

        // Concatenate the sorted strings to form the largest number
        string result;
        for (string& num_str : nums_str) {
            result += num_str;
        }

        return result;
    }
};
