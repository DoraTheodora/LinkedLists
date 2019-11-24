# LinkedLists-Lab
Linked Lists without a tail (C++) Implementation 


..All methods must work correctly at least:

  ..when the list is Empty
  ..twhen passing a  null pointer
  ..when the frontPointer is being altered
  ..if a pointer passed as a parameter is not in the list
..Provide tests that fully test the methods including the above situations

..search for the first item with the value d as data 
..//return a pointer to the item found
..Item* Search(int data);
..// erase the item pointed to by loc
..void Erase(Item *loc);
..// insert a copy of data before or after loc
..void InsertBefore(Item *loc, int data);
..void InsertAfter(Item *loc, int data);
..//push a copy of data on to the back(end ) of the list. PushBack adds an item to the end of the list.
..void PushBack(int data);
..//returns true if  PopBack is successful. Popback removes the last item in the list.Fill data with a copy the data in the node
..bool PopBack(int &data);
..//returns true if  PopFront is successful. Pop an item from the front of the list. Fill data with a copy of the data in the node.
..bool PopFront(int &data);
..void DeleteFront();
..void DeleteAll();

