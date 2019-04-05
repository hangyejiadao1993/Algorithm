/*
输入一个字符串,按字典序打印出该字符串中字符的所有排列。例如输入字符串abc,则打印出由字符a,b,c所能排列出来的所有字符串abc,acb,bac,bca,cab和cba。
*/
#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
using namespace std;
class Solution
{
  public:
    vector<string> Permutation(string str)
    {
        DFS(str, "");

        return datas;
    }

  private:
    void DFS(string str, string tem)
    {
        for (size_t i = 0; i < str.size(); i++)
        {
            string temp = str;
            string ttem = tem;

            ttem.push_back(str[i]);
            temp.erase(i, 1);
            if (temp.empty())
            {
                if (find(datas.begin(), datas.end(), ttem) == datas.end())
                {
                    datas.push_back(ttem);
                }
            }
            else
            {

                DFS(temp, ttem);
            }
        }
    }
    vector<string> datas;
};




class SolutionA {
public:
    void dfs(string s,int begin,vector<string> &result){
        if(begin==s.size()-1)
            result.push_back(s);
        for(int i=begin;i<s.size();i++){
            if(i!=begin&&s[i]==s[begin])
                continue;
            swap(s[i],s[begin]);
            dfs(s,begin+1,result);
            swap(s[i],s[begin]);
        }
    }
     
    vector<string> Permutation(string str) {
        vector<string> result;
        dfs(str,0,result);
        sort(result.begin(),result.end());//按照字典序输出
        return result;
    }
};


int main(int argc, char const *argv[])
{
    string str = "abc";
    Solution so;

    vector<string> strs = so.Permutation(str);

    for (size_t i = 0; i < strs.size(); i++)
    {
        cout << strs[i] << endl;
    }
    system("pause");
    return 0;
}
