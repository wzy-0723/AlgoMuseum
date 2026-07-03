#include "common.h"

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int sp = 0, tp = 0;

        while (sp < s.size())
        {
            if (tp == t.size())
            {
                return false;
            }
            if (t[tp] == s[sp])
            {
                sp++;
            }
            tp++;
        }
        return true;
    }
}solution;

int main() {
    solution.isSubsequence("axc", "ahbgdc");
}

/*
*
*
*/