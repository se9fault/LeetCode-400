/*
Given a string containing digits from 2-9 inclusive, return all possible letter
combinations that the number could represent.

Example:
Input: "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].

Note: Although the above answer is in lexicographical order, your answer could
be in any order you want.
*/

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> results;
        if (digits.empty())
            return vector<string>();
        static const vector<string> dict = {"abc", "def", "ghi",
                                            "jkl", "mno", "pqrs",
                                            "tuv", "wxyz"};
        results.push_back("");
        for (int i = 0 ; i < digits.size(); ++i) {
            int num = digits[i] - '0';
            if (num < 2 || num > 9)
                throw std::runtime_error("invalid input");
            const string& letters = dict[num - 2];

            vector<string> tmp;
            for (int j = 0; j < letters.size(); ++j) {
                for (int k = 0; k < results.size(); ++k) {
                    tmp.push_back(results[k] + letters[j]);
                }
            }
            results.swap(tmp);
        }
        return results;
    }
};
