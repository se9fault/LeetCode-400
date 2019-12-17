/*
Write a function to generate the generalized abbreviations of a word.

Example:
Given word = "word", return the following list (order does not matter):
["word", "1ord", "w1rd", "wo1d", "wor1", "2rd", "w2d", "wo2", "1o1d", "1or1",
"w1r1", "1o2", "2r1", "3d", "w3", "4"]
*/

class Solution {
public:
    vector<string> generateAbbreviations(string word) {
        vector<string> ans;
        for (int i = 0; i < pow(2, word.size()); ++i) {
            string out = "";
            int cnt = 0, t = i;
            for (int j = 0; j < word.size(); ++j) {
                if (t & 1 == 1) {
                    ++cnt;
                    if (j == word.size() - 1) {
                        out += to_string(cnt);
                    }
                } else {
                    if (cnt != 0) {
                        out += to_string(cnt);
                        cnt = 0;
                    }
                    out += word[j];
                }
                t >>= 1;
            }
            ans.push_back(out);
        }
        return ans;
    }
};
