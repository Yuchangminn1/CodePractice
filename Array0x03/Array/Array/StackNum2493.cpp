#include<iostream>
#include<queue>
#include<stack>
#include <unordered_set>
using namespace std;
namespace Num2493
{
	void POPSTACK(int& printNum, int i, std::stack<int>& stack_A);
	void Solve1()
	{
		int printNum = 0;
		int testNum = 0;
		int currentNum = 0;
		int topNum = 0;
		stack<int> stack_A;

		
		cin >> testNum;

		for (int i = 0; i < testNum; i++) 
		{
			cin >> currentNum;
			if (topNum < currentNum) 
			{
				topNum = currentNum;
			}
			if(!stack_A.empty())
			{
				if (topNum == currentNum)	//있던 숫자보다 더 큰 숫자 받아줄 탑이 없으므로
											// ex 11 (6 7 8 9 10)  12
				{							//printNum을 0으로 해야함
					POPSTACK(printNum, i, stack_A);
					printNum = 0;
					cout << 0;
					continue;
				}

				if (stack_A.top() > currentNum) //들어온 값이 더 작을경우
				{								// ex (6 7 8 9 10) 1
												// 스택을 털기
					POPSTACK(printNum, i, stack_A);
					printNum = i;
				}
			} 
			if (topNum == currentNum) 
			{
				printNum = 0;
				cout << 0;
				continue;
			}
			stack_A.push(currentNum);

		}
		while (!stack_A.empty())				// 남으면 조건이 전에 들어온 수 보다 작다는거 
		{
			cout << testNum - stack_A.size();
			stack_A.pop();
		}

		return;
	}
	void POPSTACK(int& printNum, int i, std::stack<int>& stack_A)
	{
		printNum = i - stack_A.size();
		while (!stack_A.empty())
		{
			cout << printNum;
			stack_A.pop();
		}
	}

}

int main()
{
	Num2493::Solve1();
	return 0;
}