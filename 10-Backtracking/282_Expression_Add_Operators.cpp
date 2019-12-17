/*
Given a string that contains only digits 0-9 and a target value, return all
possibilities to add binaryoperators (not unary) +, -, or * between the digits
so they evaluate to the target value.

Example 1:
Input: num = "123", target = 6
Output: ["1+2+3", "1*2*3"]

Example 2:
Input: num = "232", target = 8
Output: ["2*3+2", "2+3*2"]

Example 3:
Input: num = "105", target = 5
Output: ["1*0+5","10-5"]

Example 4:
Input: num = "00", target = 0
Output: ["0+0", "0-0", "0*0"]

Example 5:
Input: num = "3456237490", target = 9191
Output: []
*/

class Solution {
public:
    vector<string> addOperators(string num, int target) {
        vector<string> ans;
        helper(num, target, 0, 0, "", ans);
        return ans;
    }
private:
    void helper(string num, int target, long diff, long curNum, string out, vector<string>& ans) {
        if (num.size() == 0 && curNum == target) {
            ans.push_back(out); return;
        }
        for (int i = 1; i <= num.size(); ++i) {
            string cur = num.substr(0, i);
            if (cur.size() > 1 && cur[0] == '0')
                return;
            string next = num.substr(i);
            if (out.size() > 0) {
                helper(next, target, stoll(cur), curNum + stoll(cur), out + "+" + cur, ans);
                helper(next, target, -stoll(cur), curNum - stoll(cur), out + "-" + cur, ans);
                helper(next, target, diff * stoll(cur), (curNum - diff) + diff * stoll(cur), out + "*" + cur, ans);
            } else {
                helper(next, target, stoll(cur), stoll(cur), cur, ans);
            }
        }
    }
};
