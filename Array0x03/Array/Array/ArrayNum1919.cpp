#include<iostream>
#include<array>
#include <unordered_set>
using namespace std;
namespace Num1919
{
	void Solve1()
	{

		const int arraySize = 26;
		array<int, arraySize> engArray1;
		string inputString1 = "";
		array<int, arraySize> engArray2;
		string inputString2 = "";

		int count = 0;

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
		for (int i = 0; i < arraySize; i++) 
		{
			int Q = engArray1[i] - engArray2[i];
			if (Q < 0) 
			{
				Q *= -1;
			}
			count += Q;
		}
		cout << count;
	}
}


//int main()
//{
//	Num1919::Solve1();
//	return 0;
//}