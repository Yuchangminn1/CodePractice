#include<iostream>
#include<array>
#include <unordered_set>
using namespace std;
namespace Num11328
{
	void Solve1() 
	{
		int NN = 0;
		cin >> NN;

		for (int i = 0; i < NN; i++) 
		{
			const int arraySize = 26;
			array<int, arraySize> engArray1;
			string inputString1 = "";
			array<int, arraySize> engArray2;
			string inputString2 = "";

			for (int j = 0; j < arraySize; j++)
			{
				engArray1[j] = 0;
			}

			cin >> inputString1;
			for (char var : inputString1)
			{
				engArray1[(int)var - 97] += 1;
			}

			for (int j = 0; j < arraySize; j++)
			{
				engArray2[j] = 0;
			}

			cin >> inputString2;
			for (char var : inputString2)
			{
				engArray2[(int)var - 97] += 1;
			}
			if (engArray1 == engArray2) 
			{
				cout << "Possible \n" ;
			}
			else 
			{
				cout << "Impossible\n";
			}
		}
	}
}

//int main() 
//{
//	Num11328::Solve1();
//
//	return 0;
//}