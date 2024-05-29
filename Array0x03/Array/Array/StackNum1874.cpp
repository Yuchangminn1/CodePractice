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
		queue<string> answer;

		cin >> testNum;

		for(int i =0;i<testNum;i++)
		{
			cin >> _num;
			Q1.push(_num);
		}

		
		int _S2Num = 1;
		answer.push("+\n");
		//cout << "+\n";
		//cout << "goal = " << Q1.front() << "\n";
		int maxnum = 0;
		while(Q1.empty() == false && _S2Num<=testNum)
		{
			
			//cout << "S2Num = " << _S2Num << "\n";
			if (_S2Num == testNum)
			{

				Q1.pop();
				answer.push("-\n");

				/*cout << "Q1 = ";

				while(!Q1.empty())
				{
					cout << Q1.front();
					Q1.pop();
				}
				cout << "\nS2 = ";

				while (!S2.empty())
				{
					cout << S2.top();
					S2.pop();
				}*/

				while (!Q1.empty() && !S2.empty())
				{
					//cout << "Q1 = " << Q1.front() << "S2 = " << S2.top();
					if (Q1.front() == S2.top())
					{
						answer.push("-\n");

						//cout << "-\n";
						Q1.pop();
						S2.pop();
						if(Q1.empty() == true && S2.empty() == true) 
						{

							while(!answer.empty())
							{
								

								cout << answer.front();
								answer.pop();
							}
							
							
						}
					}
					else
					{
						cout << "NO";
						return;
					}
				}
				//return;
			}

			//cout << S1.top() << "";
			else if (_S2Num == Q1.front())
			{
				//cout << "+\n";

				/*if (S2.empty()) 
					cout << "S2.empty()";
				else 
					cout << "팝 찾음 Q1 = " << Q1.front() << "S2 = " << S2.top() << "\n";*/
				if(maxnum< Q1.front())
				{
					maxnum = Q1.front();
				}
				//cout << "-\n";
				answer.push("-\n");


				Q1.pop();
				

				if (Q1.empty() == true)
					break;
				
				//cout << "goal = " << Q1.front() << "\n";

			}
			else if (_S2Num > Q1.front())
			{
				/*if (S2.empty())
					cout << "S2.empty()";
				else
					cout << "작음 팝 Q1 = " << Q1.front() << "팝 S2 = " << S2.top() << "\n";*/
				answer.push("-\n");


				//cout << "-\n";
				Q1.pop();
				
				if (Q1.empty() == true)
					break;
				//cout << "goal = " << Q1.front() << "\n";
				S2.pop();

				--_S2Num;
			}
			else 
			{
				

				if(_S2Num<=maxnum)
				{
					_S2Num = maxnum + 1;
					answer.push("+\n");


					//cout << "+\n";

				}
				//Q1.push(_S2Num);

				S2.push(_S2Num);
				++_S2Num;
				/*if (S2.empty())
					cout << "S2.empty()";
				else
					cout << "둘다 아님 Q1 = " << Q1.front() << "푸쉬 S2 = " << S2.top() << "\n";*/
				answer.push("+\n");


				//cout << "+\n";
			}
			
			
		}

	}

}

int main() 
{
	Num1874::Solve1();
	return 0;
}