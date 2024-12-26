// REMEMBER TO HANDLE THE INT MAX AND -INT MAX TEST CASES

class Solution {
public:
    int reverse(int x) {
        if (x == INT_MIN) {
            return 0;
        }
        bool negative = x < 0;
        long long rev=0;
        x = abs(x);
        while(x > 0){
            rev =rev*10 + x%10;
            x /= 10;
        }
        if(rev > INT_MAX || rev < INT_MIN){
            return 0;
        }
        return negative? -rev : rev;
    }
};
