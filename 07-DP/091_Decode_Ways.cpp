/*
A message containing letters from A-Z is being encoded to numbers using the
following mapping:
'A' -> 1
'B' -> 2
...
'Z' -> 26
Given a non-empty string containing only digits, determine the total number of
ways to decode it.

Example 1:
Input: "12"
Output: 2
Explanation: It could be decoded as "AB" (1 2) or "L" (12).

Example 2:
Input: "226"
Output: 3
Explanation: It could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" (2 2 6).
*/

class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        vector<int> mem(n+1, -1);
        mem[n] = 1;
        return s.empty() ? 0 : num(0, s, mem);
    }

    int num(int i, string &s, vector<int> &mem) {
        if (mem[i] > -1)
            return mem[i];
        if (s[i] == '0')
            return mem[i] = 0;
        int res = num(i+1, s, mem);
        if (i < s.size() - 1 && (s[i]=='1' || s[i]=='2' && s[i+1] < '7'))
            res += num(i+2, s, mem);
        return mem[i] = res;
    }
};


class Solution {
public:
    int numDecodings(string s) {
        /* f(n) = 1, n ≤ 0
                  f(n - 1) * isValid(s.substr(n, 1)) + f(n - 2) * isValid(s.substr(n - 1, 2))
        */
        int n = s.size(), prevprev = 1, prev = 1, ans = 0;
        for (int i = 0; i < n; ++i) {
            ans = prev * isValid(s, n, i, 1) +
                  prevprev * isValid(s, n, i - 1, 2);
            prevprev = prev;
            prev = ans;
        }
        return ans;
    }
private:
    bool isValid(string s, int n, int start, int length) {
        return start >= 0 &&
               start + length <= n &&
               length > 0 &&
               length <= 2 &&
               s[start] != '0' &&
               std::stoi(s.substr(start, length)) <= 26;
    }
};