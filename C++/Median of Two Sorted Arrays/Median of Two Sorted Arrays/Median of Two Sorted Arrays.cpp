/*
Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

The overall run time complexity should be O(log (m+n)).

Example 1:

Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.
Example 2:

Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.


Constraints:

nums1.length == m
nums2.length == n
0 <= m <= 1000
0 <= n <= 1000
1 <= m + n <= 2000
-106 <= nums1[i], nums2[i] <= 106
*/
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        std::vector<int> tmp = nums1;
        for_each(begin(nums2), end(nums2), [&tmp](int i) {tmp.push_back(i); });
        sort(begin(tmp), end(tmp));
       
        return tmp.size() % 2 == 0 ? (static_cast<double>(tmp[(tmp.size() / 2) - 1]) + static_cast<double>(tmp[tmp.size() / 2])) / 2 : tmp[tmp.size() / 2];
    }
};

int main()
{
    cout << "4. Median of Two Sorted Arrays\n\n" << boolalpha;

    Solution sol;
    vector<int>vec1{ 1, 3 };
    vector<int>vec2{ 2 };
    cout << (sol.findMedianSortedArrays(vec1, vec2) == 2) << "\n";

    vector<int>vec3{ 1, 2 };
    vector<int>vec4{ 3, 4 };
    cout << (sol.findMedianSortedArrays(vec3, vec4) == 2.5) << "\n";

    vector<int>vec5{ 1, 3 };
    vector<int>vec6{ 2, 7 };
    cout << (sol.findMedianSortedArrays(vec5, vec6) == 2.5) << "\n";
    return 0;
}
