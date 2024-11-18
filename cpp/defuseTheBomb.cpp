/*

*/
class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        vector<int> sums(code.size(),0);
        for(int i=0;i<code.size();i++){
            if(k>0){
                int j=i,sum=0;
                for(int a=0;a<k;a++){
                    j=(j+1) % code.size();
                    sum += code[j];
                }
                sums[i]=sum;
            }
            if(k<0){
                int j=i,sum=0;
                for(int a=0;a<abs(k);a++){
                    j=(j-1 + code.size()) % code.size();
                    sum += code[j];
                }
                sums[i] = sum;
            }
            
        }
        return sums;
    }
};
