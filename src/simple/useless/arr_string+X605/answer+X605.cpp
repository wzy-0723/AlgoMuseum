#include "common.h"

class Solution {
public:
    bool canPlaceFlowers(vector<int>& f, int n) {
        int cnt = 0, m = f.size();
        for (int i = 0; i < m; ++i) {
            if ((i == 0 || f[i - 1] == 0) && f[i] == 0 && (i == m - 1 || f[i + 1] == 0)) {
                cnt += 1;
                f[i] = 1;
            }
        }
        return cnt >= n;
    }
};
Solution solution;

int main() {

}

/*
*
*
*/