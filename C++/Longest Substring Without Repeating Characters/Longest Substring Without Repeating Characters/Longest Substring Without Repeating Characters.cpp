/*
Given a string s, find the length of the longest
substring
 without repeating characters.

Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.

Constraints:

0 <= s.length <= 5 * 104
s consists of English letters, digits, symbols and spaces.
*/
#include <iostream>
#include <unordered_map>


class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        if (s.empty()) return 0;

        std::unordered_map<char, int> lastIndex;
        int maxLength = 0;
        int start = 0;

        for (int i = 0; i < s.length(); ++i) {
            if (lastIndex.find(s[i]) != lastIndex.end()) {
                start = std::max(start, lastIndex[s[i]] + 1);
            }
            lastIndex[s[i]] = i;
            maxLength = std::max(maxLength, i - start + 1);
        }

        return maxLength;
    }
};

int main()
{
    std::cout << std::boolalpha;

    Solution sol;

    std::cout << (sol.lengthOfLongestSubstring("abcabcbb") == 3) << "\n";
    std::cout << (sol.lengthOfLongestSubstring("b") == 1) << "\n";
    std::cout << (sol.lengthOfLongestSubstring("pwwkew") == 3) << "\n";
    std::cout << (sol.lengthOfLongestSubstring("aab") == 2) << "\n";
    std::cout << (sol.lengthOfLongestSubstring("ckilbkd") == 5) << "\n";
    std::cout << (sol.lengthOfLongestSubstring("dvdf") == 3) << "\n";

    return 0;
}
