/*
Given a string s consists of upper/lower-case alphabets and empty space
characters ' ', return the length of last word in the string.

If the last word does not exist, return 0.

Note: A word is defined as a character sequence consists of non-space
characters only.

Example:
Input: "Hello World"
Output: 5
*/

class Solution {
public:
    int lengthOfLastWord(string s) {
        string temp = "";
        istringstream stream(s);
        while (stream >> temp)
            ;
        return temp.size();
    }
};

/*
    int lengthOfLastWord(string s) {
        int length(0), last_length(0);
        for (auto ch : s) {
            if (isalpha(ch)) {
                length++;
            } else {
                last_length = length == 0 ? last_length : length;
                length = 0;
            }
        }
        last_length = length == 0 ? last_length : length;
        return last_length;
    }
*/
