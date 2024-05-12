#include<iostream>
#include<vector>
#include <unordered_set>
using namespace std;
namespace Num3273
{
	void Solve1();
	void Solve2();
	void CMFINDING(vector<int> QQQ, int left, int right, int goal);
	void CMQuickSort(vector<int>* QQQ, int l, int r);
	int Partition1(vector<int>* QQQ, int l, int r); 

	int Partition1(vector<int>* QQQ, int l, int r)
	{
		int randomPivotIndex = l + rand() % (r - l);
		swap((*QQQ)[randomPivotIndex], (*QQQ)[r]);

		int pivot = (*QQQ)[r];

		int i = l - 1;
		for (int j = l; j < r; j++) {
			if ((*QQQ)[j] < (*QQQ)[r]) {
				++i;
				swap((*QQQ)[i], (*QQQ)[j]);
			}
		}
		swap((*QQQ)[i + 1], (*QQQ)[r]);
		return i + 1;
	}
	void CMQuickSort(vector<int>* QQQ, int l, int r) {
		if (l < r) {
			int p = Partition1(QQQ, l, r);
			CMQuickSort(QQQ, l, p - 1);
			CMQuickSort(QQQ, p + 1, r);
		}
	}
	void CMFINDING(vector<int> QQQ, int left, int right, int goal)
	{
		int count = 0;
		while (left < right) {
			int sum = QQQ[left] + QQQ[right];
			if (sum == goal) {
				count++;
				left++;
			}
			else if (sum < goal) {
				left++;
			}
			else {
				right--;
			}
		}
		cout << count;
	}
	void Solve2() {
		/*문제의 알고리즘 분류
		1 정렬 2. 두 포인터를 사용해서 해결해본 방법*/

		int arraySize = 0;
		int goal = 0;
		cin >> arraySize;
		vector<int> invec(arraySize);

		for (int i = 0; i < arraySize; i++) {
			cin >> invec[i];
		}
		cin >> goal;

		CMQuickSort(&invec, 0, arraySize - 1);
		//퀵 소트에서 랜덤 피폿이 아닐때 결과가 시간초과 퀵소트의 경우 최악의 경우 n^2
		CMFINDING(invec, 0, arraySize - 1, goal);
	}



	void Solve1()
	{
		//아이디어 
		//서로다른 양의정수 
		// a+b =c  >> a!=b 이므로  b 가 있는지 찾으면 끝 
		// 값 찾는건 해쉬 
		// 반대 조합 가능해서 /2 
		unordered_set<int> myMap;

		int arraySize = 0;
		int goalNum = 0;
		int count = 0;

		cin >> arraySize;
		vector<int> invec(arraySize);

		for (int i = 0; i < arraySize; i++)
		{
			cin >> invec[i];
			myMap.insert(invec[i]);
		}
		cin >> goalNum;
		for (int i = 0; i < arraySize; i++)
		{
			int findNum = goalNum - invec[i];
			if (findNum == invec[i])
			{
				continue;
			}
			if (myMap.find(findNum) != myMap.end())
			{
				++count;
			}
		}
		cout << count / 2;
	}
}

//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(nullptr);
//	//3273
//
//	//Solve1();
//	Num3273::Solve2();
//	return 0;
//
//}


