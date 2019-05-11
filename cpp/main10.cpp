/*
There are N children standing in a line. Each child is assigned a rating value.

You are giving candies to these children subjected to the following requirements:

Each child must have at least one candy.
Children with a higher rating get more candies than their neighbors.
What is the minimum candies you must give?

Example 1:

Input: [1,0,2]
Output: 5
Explanation: You can allocate to the first, second and third child with 2, 1, 2 candies respectively.
Example 2:

Input: [1,2,2]
Output: 4
Explanation: You can allocate to the first, second and third child with 1, 2, 1 candies respectively.
             The third child gets 1 candy because it satisfies the above two conditions. 

*/
#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int candy(vector<int> &ratings)
    {
        int len = ratings.size();
        vector<int> candyNum(len, 1);
        for (int i = 0; i < len; i++)
        {
            /* code */
            if (ratings[i - 1] < ratings[i])
            {
                candyNum[i] = candyNum[i - 1] + 1;
            }
        }
        for (int i = len - 2; i >= 0; i--)
        {
            /* code */
            if (ratings[i] > ratings[i + 1] && candyNum[i] < candyNum[i + 1])
            {
                candyNum[i] = candyNum[i + 1] + 1;
            }
        }
        int ret = 0;
        for (int i = 0; i < len; i++)
        {
            /* code */
            ret += candyNum[i];
            std::cout << candyNum[i] << " ,";
        }
        std::cout << endl;
        return ret;
    }
};

int main(int argc, char const *argv[])
{
    int a[3] = {1, 2, 2};
    vector<int> b(a, a + 3);
    Solution *s = new Solution();
    int re = s->candy(b);

    return 0;
}
