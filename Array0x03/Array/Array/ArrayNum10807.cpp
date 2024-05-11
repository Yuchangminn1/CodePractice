#include<iostream>
#include<array>
using namespace std;
namespace Num10807
{
	void solve1() 
	{
		int arraySize =0;
		int target = 0;

		array<int, 201> intArray;

		cin >> arraySize;
		
		for (int i=0;i< 201;i++)
		{
			intArray[i] = 0;
		}
		
		for (int i = 0; i < arraySize; i++) 
		{
			int q;
			cin >> q;
			intArray[q+100] += 1;
		}

		cin >> target;

		cout << intArray[target+ 100];
		
	}
	
}

//int main() {
//
//	Num10807::solve1();
//	return 0;
//}