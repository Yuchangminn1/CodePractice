#include<iostream>
#include<array>
#include<list>
#include <unordered_set>
using namespace std;
namespace Num5397
{
	class Node
	{
	public:
		char data;

		Node* next;
		Node* prev;

		Node(int data) : data(data), next(nullptr), prev(nullptr) {}
	};

	class CMLinekedList
	{
	private:
		//문제점 0 int 로 커서를 해서 찾게 했는데 시간초과남  -> head tail만들고 양방향 리스트로 만들었는데 구조가 너무 복잡함 
		//문제점 1 . 헤드 데이터를 널로 설정했더니 그걸 출력해서 문제가 틀렸었음 
		//문제점 2 . 이프문을 잘못 설정해서 헤드를 지워버림 -> 널포인터 에러 
		//문제점 리스트 삭제시 소멸자를 사용하지 않아서 할당된 메모리가 지워지지 않음 
		//소멸자 사용 후 약 8만KB  약80MB  -> 2만KB 약 20MB


		Node* head;
		Node* cursor;

		//int cursorIndex = 0;
	public:
		//int length = 0;

		CMLinekedList() : head(nullptr), cursor(nullptr) {}
		void CMAddList(char _num)
		{
			Node* newNode = new Node(_num);
			if (head == nullptr)
			{
				head = new Node(NULL);

				head->next = newNode;
				newNode->prev = head;

				cursor = newNode;

				return;

			}
			else
			{

				if (cursor->next == nullptr) //추가하는 요소가 꼬리인경우
				{
					newNode->next = nullptr;
					newNode->prev = cursor;

				}
				else
				{
					newNode->prev = cursor;
					newNode->next = cursor->next;
					newNode->next->prev = newNode;

				}
				newNode->prev->next = newNode;

				cursor = newNode;
				//if (cursor->next == nullptr) //추가하는 요소가 꼬리인경우
				//{
				//	cout << cursor->prev->data << "앞 " << cursor->data << "중 \n";
				//}
				//else 
				//{
				//	cout << cursor->prev->data << "앞 " << cursor->data << "중 " << cursor->next->data << "뒤 \n";
				//}

			}
		}
		void CursorLeft()
		{
			if (cursor != nullptr && cursor != head)
			{
				cursor = cursor->prev;
				//cout << "커서 = " << cursor->data << "\n";

			}
		}
		void CursorRight()
		{
			if (cursor != nullptr && cursor->next != nullptr)
			{
				cursor = cursor->next;
				//cout << "커서 = " << cursor->data << "\n";

			}
		}
		void PrintList()
		{
			if (cursor == nullptr) //추가한 요소가 없는경우
			{
				return;
			}

			Node* currentIndex = head;
			//if(currentIndex->data == NULL) // 헤드 데이터를 NULL로 해서 다음 요소로 
			//{
			//	currentIndex = currentIndex->next;
			//}
			//cout << currentIndex->data;

			while (currentIndex != nullptr)
			{
				if(currentIndex->data!=NULL)
					cout << currentIndex->data;
				//문제점 1 . 헤드 데이터를 널로 설정했더니 그걸 출력해서 문제가 틀렸었음 
				if (currentIndex->next != nullptr)
				{
					currentIndex = currentIndex->next;

				}
				else {
					break;

				}

			}


		}


		void CMRemoveList()
		{
			//문제점 2 . 이프문을 잘못 설정해서 헤드를 지워버림 -> 널포인터 에러 

			if (cursor != head)
			{
				Node* deleteNode = cursor;
				if (cursor->next == nullptr) //삭제할 항이 꼬리일때
				{
					//cout << "꼬리\n";
					cursor = deleteNode->prev;
					cursor->next = nullptr;
				}
				else
				{
					//cout << "\n 커서 전 " << cursor->prev->data << "커서 " << cursor->data << "커서 다음 " << cursor->next->data << "\n";

					(deleteNode->prev)->next = (deleteNode->next);

					(deleteNode->next)->prev = (deleteNode->prev);

					cursor = deleteNode->prev;
				}
				delete(deleteNode);
				//cout << "커서 = " << cursor->data << "\n";
			}
		}
		~CMLinekedList() {
			Node* current = head;
			while (current != nullptr) {
				Node* temp = current;
				current = current->next;
				delete temp;
			}
		}
	};

	void Solve1()
	{
		int testNum = 0;
		string inputString = "";
		cin >> testNum;

		for (int i = 0; i < testNum; i++)
		{
			CMLinekedList list;

			cin >> inputString;
			for (char var : inputString)
			{
				if (var == '<')
				{
					list.CursorLeft();
				}
				else if (var == '>')
				{
					list.CursorRight();
				}
				else if (var == '-')
				{
					list.CMRemoveList();
				}
				else
				{
					list.CMAddList(var);
					
				}
			}
			list.PrintList();
			cout << "\n";
		}
	}
}
//
//int main()
//{
//	Num5397::Solve1();
//	return 0;
//}