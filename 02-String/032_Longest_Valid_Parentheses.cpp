/*
Given a string containing just the characters '(' and ')', find the length of
the longest valid (well-formed) parentheses substring.

Example 1:
Input: "(()"
Output: 2
Explanation: The longest valid parentheses substring is "()"

Example 2:
Input: ")()())"
Output: 4
Explanation: The longest valid parentheses substring is "()()"
*/

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st; // stores all the index of '(', except the bottom
        int maxLength = 0;
        st.push(-1);   // stack bottom stores one, for pop
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                st.push(i);
            } else {
                int top = st.top();
                st.pop();
                if (st.empty()) {
                    st.push(i); // stack bottom, never used for answer
                } else {
                    maxLength = max(maxLength, i - st.top());
                }
            }
        }
        return maxLength;
    }
};
