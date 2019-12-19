/*
Given an integer array nums , find the sum of the elements between indices i and
j ( i ≤ j ), inclusive.

The update(i, val) function modifies nums by updating the element at index i to
val.

Example:
Given nums = [1, 3, 5]
sumRange(0, 2) -> 9
update(1, 2)
sumRange(0, 2) -> 8

Note:
The array is only modifiable by the update function.
You may assume the number of calls to update and sumRange function is
distributed evenly.
*/

class NumArray {
public:
    NumArray(vector<int> nums) {
        if (nums.empty())
            return;
        data = nums;
        double root = sqrt(data.size());
        len = ceil(data.size() / root);
        block.resize(len);
        for (int i = 0; i < data.size(); ++i) {
            block[i / len] += data[i];
        }
    }

    void update(int i, int val) {
        int idx = i / len;
        block[idx] += val - data[i];
        data[i] = val;
    }

    int sumRange(int i, int j) {
        int sum = 0;
        int start = i / len, end = j / len;
        if (start == end) {
            for (int k = i; k <= j; ++k) {
                sum += data[k];
            }
            return sum;
        }
        for (int k = i; k < (start + 1) * len; ++k) {
            sum += data[k];
        }
        for (int k = start + 1; k < end; ++k) {
            sum += block[k];
        }
        for (int k = end * len; k <= j; ++k) {
            sum += data[k];
        }
        return sum;
    }

private:
    int len;
    vector<int> data, block;
};
