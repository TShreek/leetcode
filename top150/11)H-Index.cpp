/*
Given an array of integers citations where citations[i] is the number of citations a researcher received for their ith paper, 
return the researcher's h-index.
According to the definition of h-index on Wikipedia: 
The h-index is defined as the maximum value of h such that the given researcher has published at least h papers that have each been cited at least h times.

REFER EXAMPLE, QUESTION IS HARD TO COMPREHEND XD
  */
class Solution {
public:
    int hIndex(std::vector<int>& citations) {
        if (citations.empty())
            return 0;

        std::sort(citations.begin(), citations.end()); 
        int n = citations.size();

        for (int i = 0; i < n; i++) {
            if (citations[i] >= n - i) {
                return n - i;
            }
        }
        return 0; 
    }
};
