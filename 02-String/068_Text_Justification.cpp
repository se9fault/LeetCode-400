/*
Given an array of words and a width maxWidth, format the text such that each
line has exactly maxWidth characters and is fully (left and right) justified.

You should pack your words in a greedy approach; that is, pack as many words as
you can in each line. Pad extra spaces ' ' when necessary so that each line has
exactly maxWidth characters.

Extra spaces between words should be distributed as evenly as possible. If the
number of spaces on a line do not divide evenly between words, the empty slots
on the left will be assigned more spaces than the slots on the right.

For the last line of text, it should be left justified and no extra space is
inserted between words.

Note:

A word is defined as a character sequence consisting of non-space characters
only.
Each word's length is guaranteed to be greater than 0 and not exceed maxWidth.
The input array words contains at least one word.
Example 1:

Input:
words = ["This", "is", "an", "example", "of", "text", "justification."]
maxWidth = 16
Output:
[
   "This    is    an",
   "example  of text",
   "justification.  "
]

Example 2:
Input:
words = ["What","must","be","acknowledgment","shall","be"]
maxWidth = 16
Output:
[
  "What   must   be",
  "acknowledgment  ",
  "shall be        "
]
Explanation: Note that the last line is "shall be    " instead of "shall     be",
             because the last line must be left-justified instead of
             fully-justified.
             Note that the second line is also left-justified becase it contains
             only one word.

Example 3:
Input:
words = ["Science","is","what","we","understand","well","enough","to","explain",
         "to","a","computer.","Art","is","everything","else","we","do"]
maxWidth = 20
Output:
[
  "Science  is  what we",
  "understand      well",
  "enough to explain to",
  "a  computer.  Art is",
  "everything  else  we",
  "do                  "
]
*/

// Time Complexity: O(N)
// Space Complexity: O(N)
class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int width = 0; // width of all the temp words
        vector<string> temp, result;
        for (int i = 0; i < words.size(); i++) {
            if (width + words[i].size() + temp.size()/* minimal space needed */ > maxWidth) {
                // start a new line
                string line = "";
                int totalSpace = maxWidth; // total width for space
                for (int j = 0; j < temp.size(); j++) {
                    totalSpace -= temp[j].size();
                }
                if (temp.size() == 1) {
                    line += temp[0];
                    for (int j = 0; j < maxWidth - temp[0].size(); j++)
                        line += " ";
                    result.push_back(line);
                    temp.clear();
                    temp.push_back(words[i]);
                    width = words[i].size();
                    continue;
                }


                const int averageSpace = totalSpace / (temp.size() - 1);
                const int extraSpaceCount = totalSpace % (temp.size() - 1);
                int j;
                for (j = 0; j < extraSpaceCount; j++) {
                    line += temp[j];
                    for (int k = 0; k < averageSpace + 1; k++)
                        line += " ";
                }

                for (; j < temp.size() - 1; j++) {
                    line += temp[j];
                    for (int k = 0; k < averageSpace; k++)
                        line += " ";
                }
                line += temp[temp.size() - 1];

                result.push_back(line);
                temp.clear();
                temp.push_back(words[i]);
                width = words[i].size();
            } else {
                temp.push_back(words[i]);
                width += words[i].size();
            }
        }
        // last line
        string line = temp[0];
        width = temp[0].size();
        for (int i = 1; i < temp.size(); i++) {
            line += " " + temp[i];
            width += 1 + temp[i].size();
        }
        for (int i = 0; i < maxWidth - width; i++) {
            line += " ";
        }
        result.push_back(line);

        return result;
    }
};



