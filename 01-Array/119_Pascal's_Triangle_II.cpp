class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> vi(rowIndex + 1);
       	vi[0] = 1;
        for (int i = 0; i <= rowIndex; ++i) {
        	for (int j = i; j > 0; --j) {
                // update a row from right to left
                // 3 in 1 3 [3] 1 is added from 1 [2] [1]
	        	vi[j] = vi[j] + vi[j-1];
        	}
        }
        return vi;
    }
};