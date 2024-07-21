#include<iostream>
#include<queue>
#include<stack>
#include <unordered_set>
using namespace std;
namespace Num1874
{
	void Push_I(int& i, std::stack<int>& a_Stack);
	void Pop_I(std::stack<int>& a_Stack, std::queue<int>& a_Goal);
	void Solve1()
	{
		int inputNum = 0;
		int goalNum = 0;
		string printA = "";

		stack<int> a_Stack;
		queue<int> a_Goal;

		cin >> inputNum;

		for (int i = 0; i < inputNum; i++) 
		{
			cin >> goalNum;
			a_Goal.push(goalNum);
		}

		int i = 0;
		Push_I(i,a_Stack);
		printA += "+ \n";


		while(true)
		{
			if (a_Stack.size() == 0 && i != inputNum)
			{
				Push_I(i, a_Stack);
				printA += "+ \n";


			}
			else if (i < a_Goal.front())
			{
				while (i < a_Goal.front())
				{
					Push_I(i, a_Stack);
					printA += "+ \n";

				}
			}
			else if (a_Stack.top() == a_Goal.front())
			{
				Pop_I(a_Stack, a_Goal);
				printA += "- \n";

				if (a_Goal.empty())
				{
					cout << printA;
					return;
				}
			}
			
			else 
			{
				cout << "NO";
				return;
			}
			
		}
	}

	void Pop_I(std::stack<int>& a_Stack, std::queue<int>& a_Goal)
	{
		a_Stack.pop();
		//cout << "- \n";
		a_Goal.pop();
	}

	void Push_I(int& i, std::stack<int>& a_Stack)
	{
		i++;
		a_Stack.push(i);
		//cout << "+ \n";
	}

}

int main()
{
	Num1874::Solve1();
	return 0;
}