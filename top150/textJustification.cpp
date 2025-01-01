using namespace std;
class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;
        int n = words.size();
        int index=0;
        while(index < n){
            int totalChars=0;
            int start = index;

            while(index < n && totalChars + words[index].length() + (index-start) <= maxWidth)
            {
                totalChars += words[index].length();
                index++;
            }
            int numWords = index - start;
            int numSpaces = maxWidth - totalChars;

            string line;
            if(index == n || numWords == 1){
                for(int i=start;i<index;i++){
                    line += words[i];
                    if(i < index-1){
                        line += ' ';
                    } 
                }
                line += string(maxWidth - line.length(),' ');
            }
            else{
                int spacesBwWords = numSpaces / (numWords-1);
                int extraSpaces = numSpaces % (numWords-1);

                for(int i = start; i< index;i++){
                    line += words[i];
                    if(i < index-1){
                        line += string(spacesBwWords + (extraSpaces-- > 0? 1 : 0),' ');
                    }
                } 
            }
            result.push_back(line);
        }
        return result;
    }
};
