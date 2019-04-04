/*用两个栈来实现一个队列，
完成队列的Push和Pop操作。
队列中的元素为int类型。*/
#include<iostream>
#include<stack>
using namespace std;

/*
队列 先进先出
栈   先进后出
*/
class Solution
{
public:
	void push(int node) {
		stack1.push(node);

	}

	int pop() {
		int res;
		if (stack2.size() > 0) {
			res = stack2.top();
			stack2.pop();
		}
		else if (stack1.size() > 0) {
			while (stack1.size() > 0) {
				int ele = stack1.top();
				stack1.pop();
				stack2.push(ele);
			}
			res = stack2.top();
			stack2.pop();
		}
		return res;
	}

private:
	stack<int> stack1;
	stack<int> stack2;
};
int main(int argc, char **argv) {

	Solution *s = new Solution();
	s->push(1);
	s->push(2);

	cout << s->pop() << endl;
	s->push(3);
	s->push(4);  
	cout << s->pop() << endl;
	cout << s->pop() << endl; 
	cout << s->pop() << endl;


	system("pause");
	return 0;
}