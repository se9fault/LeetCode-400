/*
A character in UTF8 can be from 1 to 4 bytes long, subjected to the following
rules:
For 1-byte character, the first bit is a 0, followed by its unicode code.
For n-bytes character, the first n-bits are all one's, the n+1 bit is 0,
followed by n-1 bytes with most significant 2 bits being 10.

This is how the UTF-8 encoding would work:
    Char. number range   |        UTF-8 octet sequence
       (hexadecimal)     |              (binary)
   ----------------------+---------------------------------------------
   0000 0000 ~ 0000 007F | 0xxxxxxx
   0000 0080 ~ 0000 07FF | 110xxxxx 10xxxxxx
   0000 0800 ~ 0000 FFFF | 1110xxxx 10xxxxxx 10xxxxxx
   0001 0000 ~ 0010 FFFF | 11110xxx 10xxxxxx 10xxxxxx 10xxxxxx

Given an array of integers representing the data, return whether it is a valid
utf-8 encoding.

Note:
The input is an array of integers. Only the least significant 8 bits of each
integer is used to store the data. This means each integer represents only 1
byte of data.

Example 1:
data = [197, 130, 1], which represents the octet sequence:
11000101 10000010 00000001.
Return true.
It is a valid utf-8 encoding for a 2-bytes character followed by a 1-byte
character.

Example 2:

data = [235, 140, 4], which represented the octet sequence:
11101011 10001100 00000100.
Return false.
The first 3 bits are all one's and the 4th bit is 0 means it is a 3-bytes
character.
The next byte is a continuation byte which starts with 10 and that's correct.
But the second continuation byte does not start with 10, so it is invalid.
*/

class Solution {
public:
    bool validUtf8(vector<int>& data) {
        // Number of bytes in the current UTF-8 character
        int numberOfBytesToProcess = 0;

        // Masks to check two most significant bits in a byte.
        int mask1 = 1 << 7;
        int mask2 = 1 << 6;

        // For each integer in the data array.
        for (int i = 0; i < data.size(); i++) {
            // If this is the case then we are to start processing a new UTF-8 character.
            if (numberOfBytesToProcess == 0) {
                int mask = 1 << 7;
                 while ((mask & data[i]) != 0) {
                    numberOfBytesToProcess += 1;
                    mask = mask >> 1;
                 }

                // 1 byte characters
                if (numberOfBytesToProcess == 0) {
                    continue;
                }

                // Invalid scenarios according to the rules of the problem.
                if (numberOfBytesToProcess > 4 || numberOfBytesToProcess == 1) {
                    return false;
                }

            } else {

                // data[i] should have most significant bit set and
                // second most significant bit unset. So, we use the two masks
                // to make sure this is the case.
                if (!((data[i] & mask1) != 0 && (mask2 & data[i]) == 0)) {
                    return false;
                }
            }

            // We reduce the number of bytes to process by 1 after each integer.
            numberOfBytesToProcess -= 1;
        }

        // This is for the case where we might not have the complete data for
        // a particular UTF-8 character.
        return numberOfBytesToProcess == 0;
    }
};
