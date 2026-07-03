#include "common.h"

class Solution {
public:
    int compress(vector<char>& chars) {

		int left = 0, right = 0, anchor = -1;
		while (left < chars.size())
		{
			while (++right < chars.size() && chars[left] == chars[right]);

			std::string count = std::to_string(right - left);
			chars[++anchor] = chars[left];

			if (right - left > 1)
			{
				for (size_t i = 0; i < count.size(); i++)
				{
					chars[++anchor] = count[i];
				}
			}

			left = right;
		}

		return anchor + 1;
    }
}solution;

int main() {
	//vector<char> chars = { 'a', 'a', 'b', 'b', 'c', 'c', 'c' };
	vector<char> chars = { 'a', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b' };

	
	solution.compress(chars);
}