// bulls: correct in both digit and position
// cows:  correct in digit, but not in correct position
class Solution {
public:
    string getHint(string secret, string guess) {
        vector<int> vi(10, 0); // the count of each digit, + secret, - guess
        // an easier way to understand is to have counts of different digits,
        // one for secret, one for guess
        int bulls = 0, cows = 0;
        for (int i = 0; i < secret.size(); i++) {
            if (secret[i] == guess[i]) {
                bulls++;
            } else {
                if (vi[secret[i] - '0']++ < 0) // each digit appeared in secret, count++
                    cows++; // if this secret cancelled out a guess, cows++
                if (vi[guess[i] - '0']-- > 0) // each digit appeared in guess, count--
                    cows++; // if this guess cancelled out a secret, cows++
            }
        }
        return to_string(bulls) + 'A' + to_string(cows) + 'B';
    }
};