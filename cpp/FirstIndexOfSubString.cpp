class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.length()==0){
            return 0;
        }
        int needLen = needle.length();
        int hayLen = haystack.length();
        for(int i=0;i <= hayLen - needLen ;i++)
        {
            int j=0;
            while(j < needLen && haystack[i+j] == needle[j])
            {
                j++;
            }
            if(j == needLen){
                return i;
            }
        }
        return -1;
    }   
};
