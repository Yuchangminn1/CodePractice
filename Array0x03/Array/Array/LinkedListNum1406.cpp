#include<iostream>
#include<array>
#include<list>
#include <unordered_set>
using namespace std;
namespace Num1406
{
	

	class Node
	{
	public:

		char data;
		Node* next;
		Node* prev;
		Node(char _data) :data(_data), next(nullptr), prev(nullptr) {}

	};

	class CMLinkedList
	{
	public:
		Node* head;
		Node* cursor;
		CMLinkedList() :head(nullptr), cursor(nullptr) {}

		void AddList(char _cha)
		{
			Node* newNode = new Node(_cha);

			if (head == nullptr) //항이 없다가 만들 때
			{
				head = new Node(NULL);
				cursor = head;
			}
			if (cursor->next == nullptr) //커서가 꼬리일때
			{
				newNode->prev = cursor;
				newNode->prev->next = newNode;
			}
			else
			{
				newNode->prev = cursor;
				newNode->next = cursor->next;
				newNode->next->prev = newNode;
				newNode->prev->next = newNode;
			}

			cursor = newNode;
			/*if (cursor->next == nullptr) 
			{
				cout << "앞 = " << cursor->prev->data << "새로운 데이터 = " << cursor->data  << "\n";
			}
			else 
			{
				cout << "앞 = " << cursor->prev->data << "새로운 데이터 = " << cursor->data << "뒤 = " << cursor->next->data << "\n";
			}*/

			return;
		}
		void RemoveList()
		{
			if (cursor == head ||cursor == nullptr) 
			{
				return;
			}

			Node* deleteNode = cursor;

			if (cursor->next == nullptr)//마지막 요소일 경우
			{
				deleteNode->prev->next = nullptr;
			}
			else
			{
				deleteNode->prev->next = deleteNode->next;
				deleteNode->next->prev = deleteNode->prev;
			}
			cursor = deleteNode->prev;
			delete(deleteNode);

			return;

		}

		void CursorLeft()
		{
			if (cursor != head)  //커서가 헤드가 아닐때
			{
				cursor = cursor->prev;
			}

			return;
		}
		void CursorRight()
		{
			if (cursor->next != nullptr)  //다음 항이 있을 때 
			{
				cursor = cursor->next;
			}

			return;
		}
		void PrintList()
		{
			Node* fir = head->next;
			while(true)
			{
				cout << fir->data;
				if (fir->next != nullptr)
				{
					fir = fir->next;
				}
				else
				{
					break;

				}
			}
			return;
		}
		~CMLinkedList() {
			Node* current = head;
			while (current != nullptr) {
				Node* temp = current;
				current = current->next;
				delete temp;
			}
		}
		/*~CMLinkedList() 
		{
			Node* fir = head;
			while (true)
			{
				Node* _current = fir;
				cout << fir->data;
				if (fir->next != nullptr)
				{
					fir = fir->next;
					delete(_current);

				}
				else
				{
					delete(_current);

					break;

				}
			}
		}*/
	};

	void Solve1() 
	{
		CMLinkedList list;
		string st = "";
		int testNum = 0;
		cin >> st;

		for(char var :st)
		{
			list.AddList(var);
		}
		cin >> testNum;

		for(int i =0;i< testNum;i++)
		{
			char Q = ' ';
			cin >> Q;
			if(Q == 'L')
			{
				list.CursorLeft();
			}
			else if (Q == 'D')
			{
				list.CursorRight();

			}
			else if (Q == 'B')
			{
				list.RemoveList();
			}
			else if (Q == 'P')
			{
				char _Q = ' ';
				cin >> _Q;
				list.AddList(_Q);
			}
		}
		list.PrintList();

		
	}
}

int main()
{
	Num1406::Solve1();
	return 0;
}