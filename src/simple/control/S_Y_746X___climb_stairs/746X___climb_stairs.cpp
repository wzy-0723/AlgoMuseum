#include "common.h"

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> totalCost = { 0,0 };
        int len = (int)cost.size();
        for (int i = 2; i < len+1; i++)
        {
            int totalCost1 = totalCost[i - 2] + cost[i - 2];
            int totalCost2 = totalCost[i - 1] + cost[i - 1];
            totalCost.push_back(min(totalCost1, totalCost2));
        }
        return totalCost[len];
    }
};
Solution solution;

int main() {
    //vector<int> test = { 10,15,20 };
    vector<int> test = { 1, 100, 1, 1, 1, 100, 1, 1, 100, 1 };
    
    cout << "minCostClimbingStairs:" << solution.minCostClimbingStairs(test);
}

/*
*
*
*/