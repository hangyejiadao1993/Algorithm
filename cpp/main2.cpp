/*
链接：https://www.nowcoder.com/questionTerminal/8a19cbe657394eeaac2f6ea9b0f6fcf6?orderByHotValue=1&page=1&onlyReference=false
来源：牛客网

输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。
假设输入的前序遍历和中序遍历的结果中都不含重复的数字。例如输入前序遍历序列{1,2,4,7,3,5,6,8}和中序遍历序列{4,7,2,1,5,3,8,6}，
则重建二叉树并返回。

*/

#include <iostream>
#include <vector>
using namespace std;


typedef struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> in)
{
	if (pre.size() == NULL)
		return NULL;
	TreeNode* root = new TreeNode(pre[0]);
	int i;
	for (i = 0; i < in.size() && in[i] != pre[0]; i++);
	vector<int> pre_left, in_left, pre_right, in_right;
	int pre_i = 1;
	for (int j = 0; j < in.size(); j++)
	{
		if (j < i)
		{
			in_left.push_back(in[j]);
			pre_left.push_back(pre[pre_i]);
			pre_i++;
		}
		else if (j > i)
		{
			in_right.push_back(in[j]);
			pre_right.push_back(pre[pre_i]);
			pre_i++;
		}
	}
	root->left = reConstructBinaryTree(pre_left, in_left);
	root->right = reConstructBinaryTree(pre_right, in_right);
	return root;
}



//前序遍历
void Pre(TreeNode *root) {

	if (root!=NULL)
	{
		cout << root->val << ",";
		Pre(root->left);
		Pre(root->right);
	}

}

//中序遍历
void Middle(TreeNode *root) {
	if (root!=NULL)
	{
		Middle(root->left);
		cout << root->val << ",";
		Middle(root->right);
	}


}
//后序遍历


void Last(TreeNode *root) {
	if (root!=NULL)
	{
		Last(root->left);
		Last(root->right);
		cout << root->val << ",";
	} 
}


int main()
{
	vector<int> pre = { 1, 2, 4, 7, 3, 5, 6, 8 };
	vector<int> in = { 4, 7, 2, 1, 5, 3, 8, 6 };
	TreeNode* root = reConstructBinaryTree(pre, in); 

	cout << "前序遍历" << endl;
	Pre(root);

	cout << "中序遍历" << endl;
	Middle(root);
	cout << "后序遍历" << endl;
	Last(root);

	system("pause");
	return 0;
}