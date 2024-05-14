#include<iostream>
#include<array>
#include<list>
#include <unordered_set>
using namespace std;
namespace Num1158
{
	class Node
	{
	public:
		int data;
		Node* next;

		Node(int data) : data(data), next(nullptr) {}
	};

	class CMLinekedList
	{
	private:
		Node* head;
		int cursor = 0;
	public:
		int length = 0;


		CMLinekedList() : head(nullptr) {}
		void CMAddList(int _num)
		{
			Node* newNode = new Node(_num);
			if (head == nullptr)
			{
				head = newNode;
				//이게 첫번째 항
				//cout << "첫번째 추가 \n";
			}
			else
			{
				Node* current = head;
				while (current->next != nullptr)
				{
					current = current->next;// 다음 주소가 없는 곳으로 이동 
				}
				current->next = newNode; // 마지막 꼬리를 찾아서 추가 
			}
			++length;
			//cout << "배열길이  = " << length << " \n";
		}

		void PrintList()
		{
			Node* current = head;
			while (1)
			{
				//cout << current->data << " ";
				if (current->next == nullptr)
				{
					break;
				}
				else
				{
					current = current->next;
				}
			}
		}


		void CMRemoveList(int _index)
		{
			--_index;
			_index += cursor;
			
			//cout << "인덱스 " << _index;
			
			if (length < _index)
			{
				_index %= length;
			}
			//cout << "지울 항 바로 전 " << _index << "길이는 " << length;
			Node* current = head;
			if (_index == 0 || _index == length) 
			{
				//cout <<"앞에서 사라진 데이터 " << head->data;
				cout << head->data;

				head = current->next;

			}
			else 
			{
				for (int i = 1; i < _index; i++)
				{
					current = current->next;
				}
				//cout << "\n 커서데이터  " << current->data << ", \n ";

				//cout << current->next->data;

				if (_index < length - 1) 
				{
					cout << current->next->data;

					current->next = current->next->next;
					//cout << "\n" << current->data << "뒤에 연결된 데이터" << current->next->data << " \n";

				}
				else
				{
					cout << current->next->data;
					//cout << "\n" << current->data << "뒤에 " << current->next->data << "삭제 \n";
					current->next = nullptr;
				}
			}
			
			cursor = _index ;
			if (cursor >= length) 
			{
				cursor -= length;
			}

			length--;
		}
	};

	void Solve1()
	{

		CMLinekedList list;
		int inNum = 0;
		int removeNum = 0;
		cin >> inNum;
		cin >> removeNum;

		cout << "<";

		for (int i = 1; i <= inNum; i++) 
		{
			list.CMAddList(i);
		}
		for (int i = 0; i < inNum; i++) 
		{
			list.CMRemoveList(removeNum);
			if (i == inNum - 1) 
			{
				break;
			}
			cout << ", ";

			
		}
		
		cout << ">";

	}
}

int main()
{
	Num1158::Solve1();
	return 0;
}