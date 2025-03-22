class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> seen;
        while(n != 1){
            int sum=0,temp=n;
            while(temp>0){
                int digit = temp%10;
                sum += digit*digit;
                temp /= 10;
            }
            if(seen.count(sum)>0) return false;
            else seen.insert(sum);
            n=sum;
        }
        return true;
    }
};
