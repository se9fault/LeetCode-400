/*
Given an input string, reverse the string word by word.

Example:

Input:  ["t","h","e"," ","s","k","y"," ","i","s"," ","b","l","u","e"]
Output: ["b","l","u","e"," ","i","s"," ","s","k","y"," ","t","h","e"]
Note:

A word is defined as a sequence of non-space characters.
The input string does not contain leading or trailing spaces.
The words are always separated by a single space.
Follow up: Could you do it in-place without allocating extra space?
*/

// Solution:
//   exactly the same in-place solution from LC151.
// Note: method signature may not be accurate.
// Time Complexity: O(N)
// Space Complexity: O(1)
class Solution {
public:
    vector<char> reverseWords(const vector<char>& str) {
        vector<char> s = str; // get a non-const version
        int i = 0; // the pointer idx that scan through the original string
        int j = 0; // the pointer idx to the new str with correct amount of space
        int start = 0;
        int n = s.size();
        int wordcount = 0;

        while (true) {
            while (i < n && s[i] == ' ')
                i++;  // skip spaces in front of the word
            if (i == n)
                break;
            if (wordcount)
                s[j++] = ' '; // put one space between previous word and this
            start = j;
            while (i < n && s[i] !=  ' ') { // move the word: "    ab" -> " ab"
                s[j] = s[i];
                j++;
                i++;
            }
            reverseString(s, start, j - 1); // reverse word in place
            wordcount++;
        }
        s.resize(j); // resize result
        reverseString(s, 0, j - 1); // reverse whole string
        return s;
    }
private:
    void reverseString(vector<char> &s, int i, int j) {
        while (i < j) {
          char t = s[i];
          s[i++] = s[j];
          s[j--] = t;
        }
    }
};