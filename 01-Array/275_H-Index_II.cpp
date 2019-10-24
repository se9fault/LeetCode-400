// vector citations is given in ascending order, find h-index in O(logN)
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int len = citations.size(), left = 0, right = len - 1,  mid;
        while (left <= right) {
            mid = left + (right - left) / 2;
            if (citations[mid] >= (len - mid))
                right = mid - 1;
            else
                left = mid + 1;
        }
        return len - left;
    }
};