class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) { // Letters are sorted in ascending order so we just return first letter larger than target
        for(int i =0; i < letters.size(); i++){ // Iterate through the letters
            if(letters[i] - 'a' > target - 'a'){
                return letters[i];
            }
        }
        return letters[0]; // We have to return first letter incase no letter is found
    }
};
