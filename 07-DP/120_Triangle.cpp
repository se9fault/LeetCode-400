/*
Given a triangle, find the minimum path sum from top to bottom. Each step you
may move to adjacent numbers on the row below.

For example, given the following triangle
[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]
The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).

Note:
Bonus point if you are able to do this using only O(n) extra space, where n is
the total number of rows in the triangle.
*/

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> mem(n, vector<int>(n, 0));
        return minimumTotal(0, 0, n, triangle, mem);
    }
private:
    int minimumTotal(int layer, int i, int n, 
                     const vector<vector<int>>& triangle,
                     vector<vector<int>>& mem) {
        if (mem[layer][i] != 0) {
            return mem[layer][i];
        }
        if (i > layer) {
            return INT_MAX;
        }
        if (layer == n - 1) {
            mem[layer][i] = triangle[layer][i];
            return mem[layer][i];
        }
            
        mem[layer][i] = triangle[layer][i] + 
                        min(minimumTotal(layer + 1, i, n, triangle, mem), 
                            minimumTotal(layer + 1, i + 1, n, triangle, mem));
        return mem[layer][i];
    }
};
