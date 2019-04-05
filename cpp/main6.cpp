/*数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。
例如输入一个长度为9的数组{1,2,3,2,2,2,5,4,2}。
由于数字2在数组中出现了5次，超过数组长度的一半，因此输出2。如果不存在则输出0。*/

#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
using namespace std;
class Solution
{
  public:
    int MoreThanHalfNum_Solution(vector<int> numbers)
    {
        if (numbers.empty())
            return 0;

        // 遍历每个元素，并记录次数；若与前一个元素相同，则次数加1，否则次数减1
        int result = numbers[0];
        int times = 1; // 次数

        for (int i = 1; i < numbers.size(); ++i)
        {
            if (times == 0)
            {
                // 更新result的值为当前元素，并置次数为1
                result = numbers[i];
                times = 1;
            }
            else if (numbers[i] == result)
            {
                ++times; // 相同则加1
            }
            else
            {
                --times; // 不同则减1
            }
        }

        // 判断result是否符合条件，即出现次数大于数组长度的一半
        times = 0;
        for (int i = 0; i < numbers.size(); ++i)
        {
            if (numbers[i] == result)
                ++times;
        }

        return (times > numbers.size() / 2) ? result : 0;
    }
};
int main(int argc, char const *argv[])
{
    vector<int> vects = {1,  6, 7, 8, 8,8,8,8,8,8};
    Solution so;
    auto tem = so.MoreThanHalfNum_Solution(vects);

    return 0;
}
