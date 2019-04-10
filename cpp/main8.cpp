/* 
Given an array of integers, find two numbers such that they add up to a specific target number. 
The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based. 
You may assume that each input would have exactly one solution. 
Input: numbers={2, 7, 11, 15}, target=9
Output: index1=1, index2=2
*/

/*
 
*/
#include <iostream>
#include <vector>
#include <map>
using namespace std;
class Solution
{
  public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        map<int, int> mapping;
        vector<int> res;
        for (int i = 0; i < numbers.size(); ++i)
        {
            mapping[numbers[i]] = i;
        }
        for (int i = 0; i < numbers.size(); i++)
        {
            int searched = target - numbers[i];
            if (mapping.find(searched) != mapping.end() && i != mapping[searched])
            {
                res.push_back(i + 1);
                res.push_back(mapping[searched] + 1);
                break;
            }
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{

    std::cout << "adfadfads" << '\n';
    return 0;
}
