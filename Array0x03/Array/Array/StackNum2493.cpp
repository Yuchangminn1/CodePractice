#include<iostream>
#include<queue>
#include<stack>
#include <unordered_set>
using namespace std;
namespace Num2493
{
	void Solve1()
	{
		int printNum = 0;
		int testNum = 0;
		int currentNum = 0;

		stack<int> stack_A;

		
		cin >> testNum;

		for (int i = 0; i < testNum; i++) 
		{
			cin >> currentNum;
			if(!stack_A.empty())
			{
				if (stack_A.top() > currentNum)
				{

					while (!stack_A.empty())
					{
						cout << printNum;
						stack_A.pop();
					}
					printNum = i;
				}
			} 
			
			stack_A.push(currentNum);

		}
		while (!stack_A.empty())
		{
			cout << printNum;
			stack_A.pop();
		}

		return;
	}
	/*void Solve1()
	{
		stack<int> stack_A;
		int testNum = 0;
		cin >> testNum;
		int _num = 0;
		int cursor = 1000000;
		int coutTop = 0;
		while (testNum > 0) 
		{
			--testNum;
			cin >> _num;
			stack_A.push(_num);


		}
		while(!stack_A.empty())
		{

			if (cursor < stack_A.top())
			{
				cout << stack_A.size() << "\n";

				coutTop--;

				if (coutTop > 0)
				{
					while (coutTop > 0)
					{
						cout << stack_A.size() << "\n";
						coutTop--;
					}
				}
			}

			cursor = stack_A.top();
			coutTop++;
			stack_A.pop();

		}
		while (coutTop > 0) 
		{
			cout << 0 << "\n";
			coutTop--;
		}

		return;

	}*/


}

int main()
{
	Num2493::Solve1();
	return 0;
}