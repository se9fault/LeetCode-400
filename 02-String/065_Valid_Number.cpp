/*
Validate if a given string can be interpreted as a decimal number.
Some examples:
"0" => true
" 0.1 " => true
"abc" => false
"1 a" => false
"2e10" => true
" -90e3   " => true
" 1e" => false
"e3" => false
" 6e-1" => true
" 99e2.5 " => false
"53.5e93" => true
" --6 " => false
"-+3" => false
"95a54e53" => false

Note: It is intended for the problem statement to be ambiguous. You should
gather all requirements up front before implementing one. However, here is a
list of characters that can be in a valid decimal number:

Numbers 0-9
Exponent - "e"
Positive/negative sign - "+"/"-"
Decimal point - "."
Of course, the context of these characters also matters in the input.

Solution: Deterministic Finite Automaton!
https://leetcode.com/problems/valid-number/discuss/23725/C%2B%2B-My-thought-with-DFA
*/

class Solution {
public:
    bool isNumber(string s) {
        int state = 0, flag = 0; // flag to judge the special case "."
        while (s[0] == ' ')
            s.erase(0,1); // delete the prefix whitespace
        while (s[s.length() - 1] == ' ')
            s.erase(s.length() - 1, 1); // delete the suffix whitespace
        for (int i = 0; i < s.length (); ++i) {
            if ('0' <= s[i] && s[i] <= '9') {
                flag = 1;
                if (state <= 2)
                    state = 2;
                else
                    state = (state <= 5) ? 5 : 7;
            }
            else if ('+' == s[i] || '-' == s[i]) {
                if (state == 0 || state == 3)
                    state++;
                else
                    return false;
            }
            else if ('.' == s[i]) {
                if (state <= 2)
                    state = 6;
                else
                    return false;
            }
            else if ('e' == s[i]) {
                if (flag && (state == 2 || state == 6 || state == 7))
                    state = 3;
                else
                    return false;
            }
            else
                return false;
        }
        return (state == 2 || state == 5 || (flag && state == 6) || state == 7);
    }
};
