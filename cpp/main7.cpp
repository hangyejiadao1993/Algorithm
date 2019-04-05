/*
设N是一个四位数，它的9倍恰好是其反序数（例如：1234 的反序数是4321），求N的值。
*/
#include <iostream>
#include <vector>

using namespace std;
class Solution
{
  public:
    vector<int> Get()
    {
        int a, b, c, d;

        for (size_t i = 0; i < 10; i++)
        {
            for (size_t j = 0; j < 10; j++)
            {
                for (size_t k = 0; k < 10; k++)
                {
                    for (size_t m = 0; m < 10; m++)
                    {
                        auto sou = i + j * 10 + k * 100 + m * 1000;
                        auto rever = m   + k * 10 + j * 100 + i*1000;
                        if (rever != 0&&sou!=0 && rever % sou == 0 && rever / sou == 9   )
                        {
                            datas.push_back(sou);
                        }
                    }
                }
            }
        }
        return datas;
    }

  private:
    vector<int> datas;
};

int main(int argc, char const *argv[])
{
    Solution so;
    auto re = so.Get();
    return 0;
}
