# 02-String
Note: Click on the number to go to the source code; click on the name to go to the LeetCode website.

## Vector of chars

- [x] [006](006_ZigZag_Conversion.cpp) [ZigZag Conversion](https://leetcode.com/problems/zigzag-conversion/description/) Infrequent

- [x] [014](014_Longest_Common_Prefix.cpp) [Longest Common Prefix](https://leetcode.com/problems/longest-common-prefix/description/)

    K-way comparing K strings to check their common prefix.

- [x] [038](038_Count_and_Say.cpp) [Count and Say](https://leetcode.com/problems/count-and-say/description/)


## Basic

- [x] [028](028_Implement_strStr().cpp) [Implement strStr()](https://leetcode.com/problems/implement-strstr/description/) KMP algorithm

- [x] [058](058_Length_of_Last_Word.cpp) [Length of Last Word](https://leetcode.com/problems/length-of-last-word/description/)

    Use std::stringstream to get the last word.

- [x] [293](293_Flip_Game.cpp) [Flip Game](https://leetcode.com/problems/flip-game/description/) Premium

- [x] [294](294_Flip_Game_II.cpp) [Flip Game II](https://leetcode.com/problems/flip-game-ii/description/) Premium, Co-listed with [10](../10-Backtracking/README.md)

- [ ] [087](087_Scramble_String.cpp) [Scramble String](https://leetcode.com/problems/scramble-string/description/)

- [x] [161](161_One_Edit_Distance.cpp) [One Edit Distance](https://leetcode.com/problems/one-edit-distance/) Premium

- [ ] [358](358_Rearrange_String_k_Distance_Apart.cpp) [Rearrange String k Distance Apart](https://leetcode.com/problems/rearrange-string-k-distance-apart/description/) Premium

- [ ] [271](271_Encode_and_Decode_Strings.cpp) [Encode and Decode Strings](https://leetcode.com/problems/encode-and-decode-strings/description/) Premium


## Lexicographic Ordering

- [x] [179](179_Largest_Number.cpp) [Largest Number](https://leetcode.com/problems/largest-number/description/) Infrequent

     To get the largest number concatenated from `nums` array, sort `nums` by using the concatenation of two comparing strings. Comparing nums lexicographocally is not enough.

- [ ] [316](316_Remove_Duplicate_Letters.cpp) [Remove Duplicate Letters](https://leetcode.com/problems/remove-duplicate-letters/description/)

    Requires smallest lexicographic order. similar to Boyer-Moore majority vote algorithm, use array to count


## Converting Stuff by Detailed Rules

- [x] [168](168_Excel_Sheet_Column_Title.cpp) [Excel Sheet Column Title](https://leetcode.com/problems/excel-sheet-column-title/description/)

- [x] [171](171_Excel_Sheet_Column_Number.cpp) [Excel Sheet Column Number](https://leetcode.com/problems/excel-sheet-column-number/description/)

- [x] [013](013_Roman_to_Integer.cpp) [Roman to Integer](https://leetcode.com/problems/roman-to-integer/description/)

- [x] [012](012_Integer_to_Roman.cpp) [Integer to Roman](https://leetcode.com/problems/integer-to-roman/description/)

- [x] [273](273_Integer_to_English_Words.cpp) [Integer to English Words](https://leetcode.com/problems/integer-to-english-words/description/)

- [x] [068](068_Text_Justification.cpp) [Text Justification](https://leetcode.com/problems/text-justification/description/)

- [x] [065](065_Valid_Number.cpp) [Valid Number](https://leetcode.com/problems/valid-number/description/)

    Deterministic Finite Automaton!


## Map / `int[26]`

- [x] [387](387_First_Unique_Character_in_a_String.cpp) [First Unique Character in a String](https://leetcode.com/problems/first-unique-character-in-a-string/description/)

    Use one map `<char, appear times>` to count the appearance of each letter.

- [x] [383](383_Ransom_Note.cpp) [Ransom Note](https://leetcode.com/problems/ransom-note/description/)

    Use two maps of `<char, appear times>` to count the appearance of each letter. (Use only one map is also possible)

- [x] [205](205_Isomorphic_Strings.cpp) [Isomorphic Strings](https://leetcode.com/problems/isomorphic-strings/description/)

    Use two maps of `<char, last idx>` to determine if the two strings are isomorphic.

- [x] [290](290_Word_Pattern.cpp) [Word Pattern](https://leetcode.com/problems/word-pattern/description/)

    Similar to [205](205_Isomorphic_Strings.cpp); Use map `<char, last idx>` and `<word, last idx>` to see if the char string and the word string are isomophic.

- [x] [242](242_Valid_Anagram.cpp) [Valid Anagram](https://leetcode.com/problems/valid-anagram/description/)

    Simplified [383](383_Ransom_Note.cpp); use two maps of `<char, appear times>` to count the appearance of each letter. (Use only one map is also possible)

- [x] [049](049_Group_Anagrams.cpp) [Group Anagrams](https://leetcode.com/problems/group-anagrams/description/)

    (Not `int[26]`) Anagrams of the same group will have identical sorted output, therefore use it as key in `<sorted key, multiset<strings>>` (or `<sorted key, vector<string>>`).

- [x] [249](249_Group_Shifted_Strings.cpp) [Group Shifted Strings](https://leetcode.com/problems/group-shifted-strings/description/) Premium

    (Not `int[26]`) To group the shifted letters, note that group "abc" "bcd" "xyz" "yza" all share the key "0,1,2".


## From both sizes to the middle

- [x] [344](344_Reverse_String.cpp) [Reverse String](https://leetcode.com/problems/reverse-string/description/)

    Use double pointers moving from both sizes to the middle to swap every pair of char.

- [x] [345](345_Reverse_Vowels_of_a_String.cpp) [Reverse Vowels of a String](https://leetcode.com/problems/reverse-vowels-of-a-string/description/)

    Use double pointers moving from both sizes to the middle to find vowels and swap them.

- [x] [246](246_Strobogrammatic_Number.cpp) [Strobogrammatic Number](https://leetcode.com/problems/strobogrammatic-number/description/) Premium

    Use double pointers moving from both sizes to the middle to check if two digit are strobogrammatic (like 6 and 9).

- [x] [247](247_Strobogrammatic_Number_II.cpp) [Strobogrammatic Number II](https://leetcode.com/problems/strobogrammatic-number-ii/description/) Premium

- [x] [248](248_Strobogrammatic_Number_III.cpp) [Strobogrammatic Number III](https://leetcode.com/problems/strobogrammatic-number-iii/description/) Premium

- [x] [151](151_Reverse_Words_in_a_String.cpp) [Reverse Words in a String](https://leetcode.com/problems/reverse-words-in-a-string/description/)

    To reverse the word order in a string in-place, first reverse each word, then reverse the entire string. (hello world -> olleh dleow -> world hello)

- [x] [186](186_Reverse_Words_in_a_String_II.cpp) [Reverse Words in a String II](https://leetcode.com/problems/reverse-words-in-a-string-ii/description/) Premium

    The question and solution is the same as [151](151_Reverse_Words_in_a_String.cpp). The only difference is that the input is an array of char instead of an string.


## Palindrome

- [x] [125](125_Valid_Palindrome.cpp) [Valid Palindrome](https://leetcode.com/problems/valid-palindrome/description/)

    Palindrome is typical "From both sizes to the middle".

- [x] [266](266_Palindrome_Permutation.cpp) [Palindrome Permutation](https://leetcode.com/problems/palindrome-permutation/description/) Premium

    A permutation of a palindrome means only 0 or 1 character appeared odd number of times in the string. To save the most space, we use a `bitset` to store the odd/even times; we count by flip the bit, and use `bitset::count()` to check how many bits are set in the end.

- [x] [005](005_Longest_Palindromic_Substring.cpp) [Longest Palindromic Substring](https://leetcode.com/problems/longest-palindromic-substring/description/)

- [x] [009](009_Palindrome_Number.cpp) [Palindrome Number](https://leetcode.com/problems/palindrome-number/description/)

- [ ] [214](214_Shortest_Palindrome.cpp) [Shortest Palindrome](https://leetcode.com/problems/shortest-palindrome/description/)

- [ ] [336](336_Palindrome_Pairs.cpp) [Palindrome Pairs](https://leetcode.com/problems/palindrome-pairs/description/)

- [ ] [131](131_Palindrome_Partitioning.cpp) [Palindrome Partitioning](https://leetcode.com/problems/palindrome-partitioning/description/)

- [ ] [132](132_Palindrome_Partitioning_II.cpp) [Palindrome Partitioning II](https://leetcode.com/problems/palindrome-partitioning-ii/description/)

- [ ] [267](267_Palindrome_Permutation_II.cpp) [Palindrome Permutation II](https://leetcode.com/problems/palindrome-permutation-ii/description/) Premium


## Parentheses

- [x] [020](020_Valid_Parentheses.cpp) [Valid Parentheses](https://leetcode.com/problems/valid-parentheses/description/)

- [x] [022](022_Generate_Parentheses.cpp) [Generate Parentheses](https://leetcode.com/problems/generate-parentheses/description/) backtracking

- [x] [032](032_Longest_Valid_Parentheses.cpp) [Longest Valid Parentheses](https://leetcode.com/problems/longest-valid-parentheses/description/)

- [ ] [241](241_Different_Ways_to_Add_Parentheses.cpp) [Different Ways to Add Parentheses](https://leetcode.com/problems/different-ways-to-add-parentheses/description/)

- [ ] [301](301_Remove_Invalid_Parentheses.cpp) [Remove Invalid Parentheses](https://leetcode.com/problems/remove-invalid-parentheses/description/)


## Substring - Sliding Window

- [ ] [076](076_Minimum_Window_Substring.cpp) [Minimum Window Substring](https://leetcode.com/problems/minimum-window-substring/description/)

- [ ] [030](030_Substring_with_Concatenation_of_All_Words.cpp) [Substring with Concatenation of All Words](https://leetcode.com/problems/substring-with-concatenation-of-all-words/description/)

- [x] [003](003_Longest_Substring_Without_Repeating_Characters.cpp) [Longest Substring Without Repeating Characters](https://leetcode.com/problems/longest-substring-without-repeating-characters/description/)

- [ ] [340](340_Longest_Substring_with_At_Most_K_Distinct_Characters.cpp) [Longest Substring with At Most K Distinct Characters](https://leetcode.com/problems/longest-substring-with-at-most-k-distinct-characters/description/) Premium

- [ ] [395](395_Longest_Substring_with_At_Least_K_Repeating_Characters.cpp) [Longest Substring with At Least K Repeating Characters](https://leetcode.com/problems/longest-substring-with-at-least-k-repeating-characters/description/)

- [ ] [159](159_Longest_Substring_with_At_Most_Two_Distinct_Characters.cpp) [Longest Substring with At Most Two Distinct Characters](https://leetcode.com/problems/longest-substring-with-at-most-two-distinct-characters/description/) Premium


## Subsequence

- [x] [392](392_Is_Subsequence.cpp) [Is Subsequence](https://leetcode.com/problems/is-subsequence/description/)

- [ ] [115](115_Distinct_Subsequences.cpp) [Distinct Subsequences](https://leetcode.com/problems/distinct-subsequences/description/)

- [x] [187](187_Repeated_DNA_Sequences.cpp) [Repeated DNA Sequences](https://leetcode.com/problems/repeated-dna-sequences/description/) Infrequent


## Mimicking API

- [x] [157](157_Read_N_Characters_Given_Read4.cpp) [Read N Characters Given Read4](https://leetcode.com/problems/read-n-characters-given-read4/description/) Premium

- [x] [158](158_Read_N_Characters_Given_Read4_II-Call_multiple_times.cpp) [Read N Characters Given Read4 II - Call multiple times](https://leetcode.com/problems/read-n-characters-given-read4-ii-call-multiple-times/description/) Premium
