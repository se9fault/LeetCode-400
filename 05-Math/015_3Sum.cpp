/*
Given an array nums of n integers, are there elements a, b, c in nums such that
a + b + c = 0? Find all unique triplets in the array which gives the sum of
zero.

Note:
The solution set must not contain duplicate triplets.

Example:
Given array nums = [-1, 0, 1, 2, -1, -4],
A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]
*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int> &num) {
        vector<vector<int>> results;
        std::sort(num.begin(), num.end());

        // for each i, use front and back to traverse the parts behind it once,
        // so O(N)
        for (int i = 0; i < num.size(); i++) {
            int target = -num[i];
            int front = i + 1;
            int back = num.size() - 1;
            while (front < back) {
                int sum = num[front] + num[back];
                // Finding answer which start from number num[i]
                if (sum < target)
                    front++;
                else if (sum > target)
                    back--;
                else {
                    vector<int> result {num[i], num[front], num[back]};
                    results.push_back(result);

                    // Processing duplicates of Number 2
                    // Rolling the front pointer to the next different number
                    // forwards
                    while (front < back && num[front] == result[1])
                        front++;

                    // Processing duplicates of Number 3
                    // Rolling the back pointer to the next different number
                    // backwards
                    while (front < back && num[back] == result[2])
                        back--;
                }
            }

            // Processing duplicates of Number 1
            while (i + 1 < num.size() && num[i + 1] == num[i])
                i++;
        }
        return results;
    }
};
