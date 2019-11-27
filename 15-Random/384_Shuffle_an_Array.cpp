/*
Shuffle a set of numbers without duplicates.
Any permutation must equally likely to be returned.

Example:
int[] nums = {1,2,3};
Solution obj = new Solution(nums);
obj.shuffle(); // Returns the random shuffling of array [1,2,3].
obj.reset();   // Return the resetted array of its original form [1,2,3].
obj.shuffle(); // Returns the random shuffling of array [1,2,3].
*/

class Solution {
private:
    vector<int> array, original;

    int randRange(int min, int max) {
        return rand() % (max - min) + min;
    }

public:
    Solution(vector<int>& nums) {
        original = nums;
        array = nums;
    }

    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        array = original;
        return original;
    }

    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        int n = array.size()
        for (int i = 0; i < n; ++i) {
            swap(array[i], array[randRange(i, n)]);
        }
        return array;
    }
};
