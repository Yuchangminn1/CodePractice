#include<iostream>
#include<array>
using namespace std;
namespace Num10807
{
	void Solve1()
	{
		array<array<int, 2>, 6> matrix{};
		int div = 0;
		int num = 0;
		int roomNum = 0;
		cin >> num;
		cin >> div;

		for (int i = 0; i < num; i++)
		{
			int s = 1;
			int grade = 1;
			cin >> s;
			cin >> grade;

			matrix[grade - 1][s] += 1;
		}
		//cout << "\n";
		for (int i = 0; i < matrix.size(); i++)
		{
			for (int j = 0; j < matrix[i].size(); j++)
			{
				//cout << matrix[i][j] << " " << i << j;
				if (matrix[i][j] % div > 0) 
				{
					roomNum = roomNum + matrix[i][j] / div + 1;
				}
				else 
				{
					roomNum = roomNum+ matrix[i][j] / div ;
				}
			}
			//cout << endl;  // 행마다 줄바꿈
		}
		cout << roomNum;

	}

}

//int main()
//{
//
//
//	Num10807::Solve1();
//
//
//
//
//	return 0;
//}