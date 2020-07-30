/*
Given an array of citations (each citation is a non-negative integer) of a
researcher, write a function to compute the researcher's h-index.

If a scientist has h papers that has been cited for at least h times, then
he/she has a h-index of h.
e.g. [0, 1, 3, 5, 6] has 3 papers with citations ≥ 3, and other papers has
citations ≤ 3.
*/

class Solution {
public:
    int hIndex(vector<int>& citations) {
        std::sort(citations.begin(), citations.end());
        int len = citations.size();
        for (int i = 0; i < len; i++) {
            if (citations[i] >= len - i)
                return len - i;
        }
        return 0;
    }
};
