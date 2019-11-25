/*
Given a string containing only digits, restore it by returning all possible
valid IP address combinations.

Example:
Input: "25525511135"
Output: ["255.255.11.135", "255.255.111.35"]
*/

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        int len = s.size();
        vector<string> result;
        for (int a = 1; a <= 3; a++)
            for (int b = 1; b <= 3; b++)
                for (int c = 1; c <= 3; c++)
                    for (int d = 1; d <= 3; d++) {
                        if (a+b+c+d != len)
                            continue;
                        string aa = s.substr(0, a);
                        string bb = s.substr(a, b);
                        string cc = s.substr(a + b, c);
                        string dd = s.substr(a + b + c, d);
                        int q = std::stoi(aa);
                        int w = std::stoi(bb);
                        int e = std::stoi(cc);
                        int r = std::stoi(dd);
                        if (q < 0 || q > 255 || w < 0 || w > 255 || e < 0 ||
                            e > 255|| r < 0 || r > 255)
                            continue;
                        if ((aa.size() > 1 && aa[0] == '0') ||
                            (bb.size() > 1 && bb[0] == '0') ||
                            (cc.size() > 1 && cc[0] == '0') ||
                            (dd.size() > 1 && dd[0] == '0'))
                            continue;
                        result.push_back(aa + "." + bb + "." + cc + "." + dd);
                    }
        return result;
    }
};
