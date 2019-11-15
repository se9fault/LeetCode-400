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
