#include "common.h"

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
		int len1 = (int)word1.size(), len2 = (int)word2.size();
		string res = "";

		for (int i = 0; i < max(len1, len2); i++)
		{
			if (i < len1)
				res += word1[i];
			if (i < len2)
				res += word2[i];
		}
		return res;
    }
};
Solution solution;


int main() {
	cout << "mergeAlternately:" << solution.mergeAlternately("ab", "pqrs") << endl;
}