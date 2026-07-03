#include "common.h"


class Solution {
public:
    string vowel = "aeiouAEIOU";
    bool checkVowel(char ch)
    {
        return vowel.find(ch) != string::npos ? true : false;
    }

    string reverseVowels(string s) {
        int len = s.size();
        int left = 0, right = len - 1;
        while (left < right)
        {
            //都找到；
            if (checkVowel(s[left]) && checkVowel(s[right]))
            {
                swap(s[left], s[right]);
                left++, right--;
            }
            // 都没找到；
            else if (!checkVowel(s[left]) && !checkVowel(s[right]))
            {
                left++, right--;
            }
            // 一个找到了；
            else if (!checkVowel(s[left]) && checkVowel(s[right]))
            {
                left++;
            }
            else if (checkVowel(s[left]) && !checkVowel(s[right]))
            {
                right--;
            }
        }
        return s;
    }
}solution;

int main() {
    cout<<"reverseVowels:"<< solution.reverseVowels("leetcode");
}

/*
*
*
*/