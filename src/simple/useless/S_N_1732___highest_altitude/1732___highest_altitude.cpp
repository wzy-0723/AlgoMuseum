#include "common.h"

class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int maxA = 0;

        int altitude = 0;

        for (auto altitudeSub : gain)
        {
            altitude += altitudeSub;
            maxA = max(maxA, altitude);
        }

        return maxA;
    }
}solution;

int main() {
    vector<int> gain = { -5,1,5,0,-7 };
    cout << "largestAltitude:" << solution.largestAltitude(gain);
}

/*
*
*
*/