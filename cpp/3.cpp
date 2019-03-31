/*
题目描述 
Given a set of distinct integers, S, return all possible subsets. 
Note: 
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets. 
For example,
If S =[1,2,3], a solution is: 
[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution
{
  public:
    vector<vector<int>> subsets(vector<int> &S)
    {
        vector<vector<int>> rsult;
        vector<vector<int>> data;
        int n = S.size();
        int arr[2] = {0, 1};
        /*
        构建一个数组
        */
        /*
        a 1 0
        b 1 0
        c 1 0
        2*2*....*2*2*2  2的N次方
        */
        vector<vector<int>> tem;
        while (n > 0)
        {
            if (rsult.size() == 0)
            {
                for (int i = 0; i < 2; ++i)
                {
                    vector<int> d = {arr[i]};
                    tem.push_back(d);
                }
            }
            else
            {

                for (int j = 0; j < rsult.size(); ++j)
                {
                   
                    for (int i = 0; i < 2; ++i)
                    {
                        vector<int> d = rsult[j];
                        d.push_back(arr[i]);
                        tem.push_back(d);
                    }
                }
            }
         
            rsult = tem;
              tem.clear();
            n--;
        }
        for (int k = 0; k < rsult.size(); ++k)
        {
            auto temv = rsult[k];
            vector<int> vardata;

            for (int m = 0; m < temv.size(); m++)
            {
                if (temv[m] == 1)
                {
                    vardata.push_back(S[m]);
                }
            }
            data.push_back(vardata);
        }
        return data;
    }
};
class SolutionA {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        sort( S.begin(),S.end());
        for(int i = 0; i <= S.size(); ++ i)
            dfs(S,0,i);//因为标准输出是按size()大小顺序来的，所以要把size作为dfs的形参
        return result;
    }
    void dfs(vector<int> S, int start, int k){
        if(k<0) return;
        else if(k==0) result.push_back(tmp);
        else{
            for(int i = start; i < S.size(); ++ i){
                tmp.push_back(S[i]);
                dfs(S,i+1,k-1);
                tmp.pop_back();
            }
        }
    }
private:
    vector<vector<int> > result;
    vector<int> tmp;
};
int main(int argc, char **argv)
{
    vector<int> S = {1, 2, 3,4,5,6};
    SolutionA s;
    auto data = s.subsets(S);
    for (int i = 0; i < data.size(); ++i)
    {
        for (int j = 0; j < data[i].size(); ++j)
        {
            cout << data[i][j] << "  ";
        }
        cout << endl;
    }
    system("pause");
    return 0;
}
