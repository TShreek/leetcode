/*
There are n children standing in a line. Each child is assigned a rating value given in the integer array ratings.
You are giving candies to these children subjected to the following requirements:
Each child must have at least one candy.
Children with a higher rating get more candies than their neighbors.
Return the minimum number of candies you need to have to distribute the candies to the children.

  class Solution {
public:
    int candy(vector<int>& ratings) {
       int candies=0;
        if(ratings.empty())
            return 0;
        candies += (ratings[0] < ratings[1]) ? 1 : 2;
        if(ratings.size() < 2)
            return candies;
        for(int i=1;i<ratings.size();i++){
            if(ratings[i]>ratings[i-1])
                candies+=2;
            else
                candies+=1;
        }
        return candies;
    }
};

Original code writtten by me first try, passed 4 / 48 test cases coz i didnt get the question
Correction after using chatGPT:
*/
class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        if (n == 0) return 0;

        vector<int> candies(n, 1); // Each child gets at least 1 candy

        // Left to right pass
        for (int i = 1; i < n; i++) {
            if (ratings[i] > ratings[i - 1]) {
                candies[i] = candies[i - 1] + 1;
            }
        }

        // Right to left pass
        for (int i = n - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1]) {
                candies[i] = max(candies[i], candies[i + 1] + 1);
            }
        }

        // Calculate total candies
        int totalCandies = 0;
        for (int c : candies) {
            totalCandies += c;
        }

        return totalCandies;
    }
};
