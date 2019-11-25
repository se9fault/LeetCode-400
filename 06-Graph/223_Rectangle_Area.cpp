/*
Find the total area covered by two rectilinear rectangles in a 2D plane.
Each rectangle is defined by its bottom left corner and top right corner:
(A,B), (C,D);    (E,F), (G,H).

Example:
Input: A = -3, B = 0, C = 3, D = 4, E = 0, F = -1, G = 9, H = 2
Output: 45

Note:
Assume that the total area is never beyond the maximum possible value of int.
*/

class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int overlap_width = min(C, G) > max(A, E) ? min(C, G) - max(A, E) : 0;
        int overlap_height = min(D, H) > max(B, F) ? min(D, H) - max(B, F) : 0;
        return ((C - A) * (D - B) - overlap_width * overlap_height) + (G - E) * (H - F); // order avoids overflow
    }
};
