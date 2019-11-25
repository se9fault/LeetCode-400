/*
Given a non-negative integer numRows, generate the first numRows of Pascal's
triangle.
*/

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> results;
        for (int i = 1; i <= numRows; i++) {
            vector<int> row(i);
            row[0] = 1;
            row[i - 1] = 1;
            for (int j = 1; j < i - 1; j++) {
                row[j] = results[i-2][j-1] + results[i-2][j];
            }
            results.push_back(row);
        }
        return results;
    }
};
