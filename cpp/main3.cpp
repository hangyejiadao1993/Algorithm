/*
8元的5个  10元的4个  18元的6个 求共有几种可能
*/

#include<stdlib.h>
#include<memory>
#include<iostream>
using namespace std;

int main()
{

	//答案82种
	int vis[10000];
	int ans = 0;
	memset(vis, 0, sizeof(vis));
	for (int i = 0;i <= 5;i++)
		for (int j = 0;j <= 4;j++)
			for (int k = 0;k <= 6;k++)
			{
				int temp = i * 8 + j * 10 + 18 * k;
				vis[temp] = 1;
			}
	for (int i = 1;i < 10000;i++)
	{
		if (vis[i])
			ans++;
	}
	cout << ans << endl;
	return 0;
}


 
