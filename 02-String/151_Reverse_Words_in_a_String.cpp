/*
Given an input string, reverse the string word by word.

Example 1:
Input: "the sky is blue"
Output: "blue is sky the"

Example 2:
Input: "  hello world!  "
Output: "world! hello"
Explanation: Your reversed string should not contain leading or trailing spaces.

Example 3:
Input: "a good   example"
Output: "example good a"
Explanation: You need to reduce multiple spaces between two words to a single space in the reversed string.

Note:
A word is defined as a sequence of non-space characters.
Input string may contain leading or trailing spaces. However, your reversed
string should not contain leading or trailing spaces.
You need to reduce multiple spaces between two words to a single space in the
reversed string.

Follow up:
For C programmers, try to solve it in-place in O(1) extra space.
*/

// Solution:
//   To do this in-place, first reverse each word then reverse the whole string.
// Time Complexity: O(N)
// Space Complexity: O(1)
class Solution {
public:
    // O(1) space, in place
    string reverseWords(string s) {
        int i = 0; // the pointer idx that scan through the original string
        int j = 0; // the pointer idx to the new str with correct amount of space
        int start = 0;
        int n = s.length();
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
        s.resize(j); // resize result string
        reverseString(s, 0, j - 1); // reverse whole string
        return s;
    }
private:
    void reverseString(string &s, int i, int j) {
        while (i < j) {
          char t = s[i];
          s[i++] = s[j];
          s[j--] = t;
        }
    }
};

/*
// this solution is not in-place, and requires multiple moves of the string.
class Solution {
public:
    string reverseWords(string s) {
        if (s.size() == 0)
            return "";

        std::istringstream iss(s);
        string result = "";
        string w;

        while (iss >> w)
           result.insert(0, w + ' '); // multiple move
        if (result.size() > 0)
            result.pop_back();
        return result;
    }
};
*/
