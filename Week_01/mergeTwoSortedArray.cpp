#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(n == 0) return;        

        if(m == 0) 
        {
            nums1 = nums2;
            return;
        }

        vector<int> nums3(m+n);

        int i = 0, j = 0;
        for(int k = 0; k < (m+n) || i < m || j < n; k++)
        {
            if(i == m)
            {
                nums3[k] = nums2[j];
                j++;
            }
            else if(j == n)
            {
                nums3[k] = nums1[i];
                i++;
            }
            else if(nums1[i] <= nums2[j])
            {   
                nums3[k] = nums1[i];
                i++;
            }
            else
            {
                nums3[k] = nums2[j];
                j++;
            }
        }

        nums1 = nums3;

    }
};

int main()
{
    Solution aSolution;

    vector<int> nums1(6);
    nums1[0] = 1;
    nums1[1] = 2;
    nums1[2] = 3;

    for(int i = 0; i < nums1.size(); i++)
    {
        std::cout << nums1[i] << " ";
    }
    std::cout << "end" << std::endl;

    int m = 3;

    vector<int> nums2{2,5,6};
    int n = 3;

    aSolution.merge(nums1, 3, nums2, 3);

    for(int i = 0; i < nums1.size(); i++)
    {
        std::cout << nums1[i] << " ";
    }
    std::cout << "end" << std::endl;

    return 0;
}