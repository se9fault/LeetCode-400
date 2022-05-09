/*
A strobogrammatic number is a number that looks the same when rotated 180
degrees (looked at upside down).

Find all strobogrammatic numbers that are of length = n.

For example,
Given n = 2, return ["11","69","88","96"].
*/

// Time Complexity: O(N)
// Space Complexity: O(N)
class Solution {
public:
    vector<string> findStrobogrammatic(int n) {
        return find(n, n);
    }

private:
    // m: length of current core
    // n: total length
    vector<string> find(const int m, const int n) {
        if (m == 0)
            return {""};
        if (m == 1)
            return {"0", "1", "8"};

        vector<string> t = find(m - 2, n), ans;
        for (auto a : t) {
            if (m != n) {
                ans.push_back("0" + a + "0");
            }
            ans.push_back("1" + a + "1");
            ans.push_back("6" + a + "9");
            ans.push_back("8" + a + "8");
            ans.push_back("9" + a + "6");
        }
        return ans;
    }
};
