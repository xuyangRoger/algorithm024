#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 0) return 0;

        int n = nums.size();
        int first = 0, count = 1, value = nums[0];
        for(int i = 1; i < n; i++)
        {
            if(nums[i] == value)
            {
                count++;
                if(count > 1)
                {
                    for(int j = 1; j < count; j++)
                    {
                        nums.erase(nums.begin() + first + 1);
                    }
                    n--;
                    i--;
                    count--;
                }
            }   
            else
            {            
                value = nums[i];
                count = 1;
                first = i;
            }
        }
        return nums.size();
    }

    int removeDuplicates2(vector<int>& nums) {
        if(nums.size() == 0) return 0;

        int j = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[j] != nums[i])
            {            
                if(j != i)
                {
                    j++;
                    nums[j] = nums[i];                    
                }                         
            }
        }
        return j+1;

    }

};

int main()
{
    Solution aSlu;
    vector<int> aVec{1,1,1,2};

    aSlu.removeDuplicates(aVec);

    for(auto aTmp : aVec)
    {
        cout << aTmp << endl;
    }
    cout << "size: " << aVec.size() << endl;

    aVec = vector<int>{1,1,1};

    aSlu.removeDuplicates(aVec);

    for(auto aTmp : aVec)
    {
        cout << aTmp << endl;
    }
    cout << "size: " << aVec.size() << endl;


    aVec = vector<int>{1,1,1,2};

    int aRet = aSlu.removeDuplicates2(aVec);

    cout << "aRet: " << aRet<< endl;

    for(int i = 0; i < aRet; i++)
    {
        cout << aVec[i] << endl;
    }
    cout << "size: " << aVec.size() << endl;

    return 0;
}
