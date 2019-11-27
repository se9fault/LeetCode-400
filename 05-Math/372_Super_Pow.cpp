/*
Your task is to calculate a^b mod 1337 where a is a positive integer and b is an
extremely large positive integer given in the form of an array.

Example 1:    Input: a = 2, b = [3]      Output: 8
Example 2:    Input: a = 2, b = [1,0]    Output: 1024

Solution:
Background knowledge: ab % k = (a%k)(b%k)%k
So if f(a, b) calculates a^b % k, then
f(a, 123) = f(a, 120) * f(a, 3) % k = f(f(a, 12), 10) * f(a,3) % k;
*/

class Solution {
    const int base = 1337;
    // a ^ k mod 1337 where k in [0, 10]
    int powmod(int a, int k) {
        a %= base;
        int result = 1;
        for (int i = 0; i < k; ++i)
            result = (result * a) % base;
        return result;
    }
public:
    // a ^ b(form of array) mod 1337
    int superPow(int a, vector<int>& b) {
        if (b.empty())
            return 1;
        int last_digit = b.back();
        b.pop_back();
        return powmod(superPow(a, b), 10) * powmod(a, last_digit) % base;
    }
};
