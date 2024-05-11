#include<iostream>
#include<array>
using namespace std;
namespace Num10808 
{
	void Solve1() 
	{
		const int ArraySize = 26;
		array<int, ArraySize> engArray;

		string Name;
		cin >> Name;

		for (int i = 0; i < ArraySize; i++) 
		{
			engArray[i] = 0;  // 배열 초기화
		}

		// 문자 'a'는 ASCII 코드 97
		for (char var : Name) 
		{
			int index = int(var) - 'a';  // 문자를 배열 인덱스로 변환
			if (index >= 0 && index < ArraySize) 
			{
				engArray[index]++;
			}
		}

		// 결과 출력
		for (int count : engArray) 
		{
			cout << count << " ";
		}
	}
}
//int main() 
//{
//	Num10808::Solve1();
//	return 0;
//}
