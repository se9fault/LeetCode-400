/*
All DNA is composed of a series of nucleotides abbreviated as A, C, G, and T,
for example: "ACGAATTCCG". When studying DNA, it is sometimes useful to identify
repeated sequences within the DNA.
Write a function to find all the 10-letter-long sequences (substrings) that
occur more than once in a DNA molecule.

Example:
Input: s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"
Output: ["AAAAACCCCC", "CCCCCAAAAA"]

Solution:
The idea is simple: hash table for every sequence. The hard part is optimizing
for better memory usage: store the sequence in less bits (than 10 bytes).
*/

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        if (s.size() <= 10)
            return vector<string>();

        vector<string> R;
        bitset<1<<20> S1; // if the string has been seen once
        bitset<1<<20> S2; // if the string has been seen multiple times

        int val = 0;
        for (int i = 0; i < 10; i++) // calculate the hash value for s[0,10).
            val = (val << 2) | char2val(s[i]);
        S1.set(val);

        int mask = (1 << 20) - 1;
        for (int i = 10; i < s.size(); i++) {
            // calculate the hash value for the string ending at position i.
            val = ((val << 2) & mask) | char2val(s[i]);
            // move s[i-10] out, set s[i] at lowest
            if (S2[val])
                continue;
            if (S1[val]) {
                R.push_back(s.substr(i - 10 + 1, 10));
                S2.set(val);
            }
            else
                S1.set(val);
        }
        return R;
    }

private:
    int char2val(char c) {
        switch (c) {
            case 'A': return 0;
            case 'C': return 1;
            case 'G': return 2;
            case 'T': return 3;
        }
        return -1;
    }
};
