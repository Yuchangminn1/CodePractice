#include<iostream>
#include<queue>
#include<stack>
#include <unordered_set>
using namespace std;
namespace Num1874
{
	void Solve1()
	{
		int testNum = 0;
		int _num = 0;
		queue<int> Q1;
		stack<int> S2;

		cin >> testNum;

		for(int i =0;i<testNum;i++)
		{
			cin >> _num;
			Q1.push(_num);
		}


		int _S2Num = 1;
		cout << "+\n";
		//cout << "goal = " << Q1.front() << "\n";
		int maxnum = 0;
		while(Q1.empty() == false && _S2Num<=testNum)
		{
			//cout << S1.top() << "";
			if (_S2Num == Q1.front())
			{
				if(maxnum< Q1.front())
				{
					maxnum = Q1.front();
				}
				cout << "-\n";

				Q1.pop();
				if (Q1.empty() == true)
					break;
				
				//cout << "goal = " << Q1.front() << "\n";

			}
			else if (_S2Num > Q1.front())
			{
				cout << "-\n";
				Q1.pop();
				if (Q1.empty() == true)
					break;
				//cout << "goal = " << Q1.front() << "\n";

				--_S2Num;
			}
			else 
			{
				if(_S2Num<maxnum)
					_S2Num = maxnum;
				S2.push(_S2Num);
				++_S2Num;
				cout << "+\n";
			}

			
		}

	}
}

int main() 
{
	Num1874::Solve1();
	return 0;
}