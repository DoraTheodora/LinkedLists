#include <iostream>
// Theodora Tataru
// C00231174
// Singly Linked List

class Item
{
public:
	int data;
	Item* nextItemPointer;
	Item()
	{
	}
	Item(int data, Item* nextItemPointer)
	{
		this->data = data;
		this->nextItemPointer = nextItemPointer;
	}
};

class List
{
public:
	Item* frontPointer;

	List()
	{
		this->frontPointer = NULL;
	}

	~List()
	{
		DeleteAll();
	}

	void pushFront(int data)
	{
		Item* newNode = new Item(data, frontPointer);
		frontPointer = newNode;
	}
	void pushBack(int data)
	{
		Item* curr = frontPointer;
		if (frontPointer != NULL)
		{
			while (curr->nextItemPointer != NULL)
			{
				curr = curr->nextItemPointer;
			}
			Item* newNode = new Item(data, NULL);
			curr->nextItemPointer = newNode;
		}
		else
		{
			Item* newNode = new Item(data, NULL);
			frontPointer = newNode;
		}
	}
	Item* search(int data)
	{
		if (frontPointer != NULL)
		{ 
			Item* curr = frontPointer;
				while (curr->data != data)
				{
					curr = curr->nextItemPointer;
					if (curr == NULL)
					{
						return NULL;
					}
				}
				return curr;
		}
		else
		{
			return NULL;
		}
	}
	void Erase(Item* loc)
	{
		if (frontPointer != NULL)
		{
			Item* prev = NULL;
			Item* curr = frontPointer;

			if (loc != NULL)
			{
				if (loc == frontPointer)
				{
					frontPointer = frontPointer->nextItemPointer;
					delete curr;
				}
				else
				{
					while (curr != loc && curr != NULL)
					{
						prev = curr;
						curr = curr->nextItemPointer;

					}
					prev->nextItemPointer = curr->nextItemPointer;
					delete curr;
				}
			}
		}
	}
	void InsertBefore(Item* loc, int data)
	{
		Item* newNode = new Item(data,NULL);
		if (loc != NULL)
		{
			if (loc == frontPointer)
			{
				newNode->nextItemPointer = frontPointer;
				frontPointer = newNode;
			}
			else
			{
				Item* curr = new Item();
				Item* prev = new Item();
				curr = frontPointer;
				prev = NULL;
				while (curr != loc)
				{
					prev = curr;
					curr = curr->nextItemPointer;
				}
				prev->nextItemPointer = newNode;
				newNode->nextItemPointer = curr;
			}
		}
		else 
		{
			std::cout << "Node not found! List was not modified!" << std::endl;
		}
	}
	void InsertAfter(Item * loc, int data)
	{
		if (loc != NULL)
		{
			Item* newNode = new Item(data,NULL);
			if (loc == frontPointer)
			{
				newNode->nextItemPointer = frontPointer->nextItemPointer;
				frontPointer->nextItemPointer = newNode;
			}
			else
			{
				Item* curr = frontPointer;
				while (curr != loc)
				{
					curr = curr->nextItemPointer;
				}
				if (curr->nextItemPointer == NULL)
				{
					curr->nextItemPointer = newNode;
					newNode->nextItemPointer = NULL;
				}
				else
				{
					newNode->nextItemPointer = curr->nextItemPointer;
					curr->nextItemPointer = newNode;
				}
			}
		}
		else
		{
			std::cout << "Node not found! List was not modified!" << std::endl;
		}
	}
	void DeleteFront()
	{
		if (frontPointer != NULL)
		{
			Item* temp = frontPointer;
			frontPointer = frontPointer->nextItemPointer;
			delete temp;
		}
	}
	bool PopBack(int& data)
	{
		Item* curr = frontPointer;
		if (frontPointer != NULL)
		{
			while (curr->nextItemPointer!= NULL)
			{
				curr = curr->nextItemPointer;
			}
			data = curr->data;
			Erase(curr);
			return true;
		}
		else
		{
			return false;
		}
	}
	bool PopFront(int& data)
	{
		if (frontPointer != NULL)
		{
			Item* temp = frontPointer;
			data = frontPointer->data;
			frontPointer = frontPointer->nextItemPointer;
			delete temp;
			return true;
		}
		else
		{
			return false;
		}

	}
	void DeleteAll()
	{
		Item* curr = new Item();
		Item* prev = new Item();
		curr = frontPointer;
		while (curr != NULL)
		{
			prev = curr;
			curr = curr->nextItemPointer;
			Erase(prev);
		}
	}
	void Display()
	{
		for (Item* curItemPointer = frontPointer; curItemPointer != NULL; curItemPointer = curItemPointer->nextItemPointer)
		{
			std::cout << curItemPointer->data << "->";
		}
		std::cout << "NULL" << std::endl;
	}
};
int main()
{
	List myList;
	myList.pushFront(1);
	myList.pushFront(2);
	myList.pushFront(3);
	myList.pushFront(4);
	myList.pushFront(5);
	myList.pushFront(6);
	std::cout << "###############################" << std::endl;
	std::cout << "Using:\t .pushFront(element)" << std::endl;
	std::cout << "\nAdd the node '7' at the front: \n" << std::endl;
	std::cout << "Before:\t";
	myList.Display();
	myList.pushFront(7);
	std::cout << "After:\t";
	myList.Display();
	std::cout << "\n###############################" << std::endl;
	std::cout << "Using:\t .pushBack(element)" << std::endl;
	std::cout << "\nAdd the node '10' at the back: \n" << std::endl;
	std::cout << "Before:\t";
	myList.Display();
	myList.pushBack(10);
	std::cout << "After:\t";
	myList.Display();
	std::cout << "\n###############################" << std::endl;
	std::cout << "Using:\t .Search(element)" << std::endl;
	std::cout << "\nThe List:\t";
	myList.Display();
	std::cout << "\nSearch nodes: " << std::endl;
	std::cout << "Existing node: The address of node '10': " << myList.search(10) << std::endl;
	std::cout << "Non-existent node: The address of node '9': " << myList.search(9) << std::endl;
	std::cout << "\n###############################" << std::endl;
	std::cout << "Using:\t .Erase(address)" << std::endl;
	std::cout << "\nErase the node '2': " << std::endl;
	std::cout << "Before:\t";
	myList.Display();
	myList.Erase(myList.search(2));
	std::cout << "After:\t";
	myList.Display();
	std::cout << "\nErase the node '9' which doesn't exists: " << std::endl;
	std::cout << "Before:\t";
	myList.Display();
	myList.Erase(myList.search(9));
	std::cout << "After:\t";
	myList.Display();
	std::cout << "\nErase first node '7': " << std::endl;
	std::cout << "Before:\t";
	myList.Display();
	myList.Erase(myList.search(7));
	std::cout << "After:\t";
	myList.Display();
	std::cout << "\nErase last node '10': " << std::endl;
	std::cout << "Before:\t";
	myList.Display();
	myList.Erase(myList.search(10));
	std::cout << "After:\t";
	myList.Display();
	std::cout << "\nTry to erase with a NULL parameter: " << std::endl;
	std::cout << "Before:\t";
	myList.Display();
	myList.Erase(NULL);
	std::cout << "After:\t";
	myList.Display();
	std::cout << "\n###############################" << std::endl;
	std::cout << "Using:\t .InsertBefore(address, element)" << std::endl;
	std::cout << "\nInsert new node before '3': " << std::endl;
	std::cout << "Before:\t";
	myList.Display();
	myList.InsertBefore(myList.search(3), 100);
	std::cout << "After:\t";
	myList.Display();
	std::cout << "\nInsert new node before front node '6' : " << std::endl;
	std::cout << "Before:\t";
	myList.Display();
	myList.InsertBefore(myList.search(6), 999);
	std::cout << "After:\t";
	myList.Display();
	std::cout << "\nInsert new node before last node '1' : " << std::endl;
	std::cout << "Before:\t";
	myList.Display();
	myList.InsertBefore(myList.search(1), 555);
	std::cout << "After:\t";
	myList.Display();
	std::cout << "\nInsert new node before a node that doesn't exists '888' : " << std::endl;
	std::cout << "Before:\t";
	myList.Display();
	myList.InsertBefore(myList.search(888), 777);
	std::cout << "After:\t";
	myList.Display();
	std::cout << "\n###############################" << std::endl;
	std::cout << "Using:\t .InsertAfter(address, element)" << std::endl;
	std::cout << "\nInsert new node after node '3': " << std::endl;
	std::cout << "Before:\t";
	myList.Display();
	myList.InsertAfter(myList.search(3), 1000);
	std::cout << "After:\t";
	myList.Display();
	std::cout << "\nInsert new node after front node '999': " << std::endl;
	std::cout << "Before:\t";
	myList.Display();
	myList.InsertAfter(myList.search(999), 1111);
	std::cout << "After:\t";
	myList.Display();
	std::cout << "\nInsert new node after last node '1': " << std::endl;
	std::cout << "Before:\t";
	myList.Display();
	myList.InsertAfter(myList.search(1), 2222);
	std::cout << "After:\t";
	myList.Display();
	std::cout << "\nInsert new node after a node that does not exist '888': " << std::endl;
	std::cout << "Before:\t";
	myList.Display();
	myList.InsertAfter(myList.search(888), 7777);
	std::cout << "After:\t";
	myList.Display();
	std::cout << "\n###############################" << std::endl;
	std::cout << "Using:\t .DeleteFront()" << std::endl;
	std::cout << "\nDelete first node: " << std::endl;
	std::cout << "Before:\t";
	myList.Display();
	myList.DeleteFront();
	std::cout << "After:\t";
	myList.Display();
	std::cout << "\n###############################" << std::endl;
	std::cout << "Using:\t .PopBack(data)" << std::endl;
	std::cout << "\nPop Back: " << std::endl;
	int data;
	std::cout << "Before:\t";
	myList.Display();
	if (myList.PopBack(data))
	{
		std::cout << "The last node with the value: " << data << " was deleted!" << std::endl;
	}
	else
	{
		std::cout << "The linked list was empty!" << std::endl;
	}
	std::cout << "After:\t";
	myList.Display();
	std::cout << "\n###############################" << std::endl;
	std::cout << "Using:\t .PopFront(element)" << std::endl;
	std::cout << "\nPop Front: " << std::endl;
	std::cout << "Before:\t";
	myList.Display();
	if (myList.PopFront(data))
	{
		std::cout << "The first node with the value: " << data << " was deleted!" << std::endl;
	}
	else
	{
		std::cout << "The linked list was empty!" << std::endl;
	}
	std::cout << "After:\t";
	myList.Display();
	std::cout << "\n###############################" << std::endl;
	std::cout << "Using:\t .DeleteAll()" << std::endl;
	std::cout << "\nDelete All: " << std::endl;
	std::cout << "Before:\t";
	myList.Display();
	myList.DeleteAll();
	std::cout << "After:\t";
	myList.Display();
	std::cout << "\n###############################" << std::endl;
	std::cout << "Using:\t .PopBack(data)" << std::endl;
	std::cout << "\nPop Back from an empty list: " << std::endl;
	std::cout << "Before:\t";
	myList.Display();
	if (myList.PopBack(data))
	{
		std::cout << "The last node with the value: " << data << "was deleted!" << std::endl;
	}
	else
	{
		std::cout << "The linked list was empty!" << std::endl;
	}
	std::cout << "After:\t";
	myList.Display();
	std::cout << "\n###############################" << std::endl;
	std::cout << "Using:\t .PopFront(data)" << std::endl;
	std::cout << "\nPop Front from an empty list: " << std::endl;
	std::cout << "Before:\t";
	myList.Display();
	if (myList.PopFront(data))
	{
		std::cout << "The first node with the value: " << data << "was deleted!" << std::endl;
	}
	else
	{
		std::cout << "The linked list was empty!" << std::endl;
	}
	std::cout << "After:\t";
	myList.Display();
	std::cout << "\n###############################" << std::endl;
	std::cout << "Using:\t .Search(element)" << std::endl;
	std::cout << "\nSearch the adress of '2' in an empty list: " << myList.search(2) << std::endl;
	std::cout << "\n###############################" << std::endl;
	std::cout << "Using:\t .pushBack(element)" << std::endl;
	std::cout << "\nAdd elements at the back when list is empty: " << std::endl;
	std::cout << "Before:\t";
	myList.Display();
	myList.pushBack(10);
	std::cout << "After:\t";
	myList.Display();
	myList.DeleteAll();
	std::cout << "\n###############################" << std::endl;
	std::cout << "Using:\t .DeleteFront()" << std::endl;
	std::cout << "\nTrying to delete the front element when the list is empty: " << std::endl;
	std::cout << "Before:\t";
	myList.Display();
	myList.DeleteFront();
	std::cout << "After:\t";
	myList.Display();
	std::cout << "\n###############################" << std::endl;
	std::cout << "Using:\t .InsertBefore()" << std::endl;
	std::cout << "\nInsert before an element, in an empty list: " << std::endl;
	std::cout << "Before:\t";
	myList.Display();
	myList.InsertBefore(myList.search(1), 555);
	std::cout << "After:\t";
	myList.Display();
	std::cout << "\n###############################" << std::endl;
	std::cout << "Using:\t .InsertAfter()" << std::endl;
	std::cout << "\nInsert after an element, in an empty list: " << std::endl;
	std::cout << "Before:\t";
	myList.Display();
	myList.InsertAfter(myList.search(1), 555);
	std::cout << "After:\t";
	myList.Display();
	std::cout << "\n###############################" << std::endl;
	std::cout << "Using:\t .Erase()" << std::endl;
	std::cout << "\nTrying to erase an elemnt, in an empty list: " << std::endl;
	std::cout << "Before:\t";
	myList.Display();
	myList.Erase(myList.search(3));
	std::cout << "After:\t";
	myList.Display();
	char c = getchar();
	return 0;
}