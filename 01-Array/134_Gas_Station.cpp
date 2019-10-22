class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        if (gas.size() == 0 | cost.size() == 0 || gas.size() != cost.size())
            return -1;
        int start = 0;
        int deficit = 0, tank = 0;
        // if out of gas at 'i', start at i+1, but record current deficit
        for (int i = 0; i < gas.size(); ++i) {
            int refueled = gas[i] - cost[i];
            tank += refueled;
            if (tank < 0) {
                start = i + 1;
                deficit += tank;
                tank = 0;
            }
        }
        return (deficit + tank < 0) ? -1 : start;
    }
};