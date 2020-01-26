//Raul Garcia
//894237437
//Link List Assignment #4
#include <iostream>
#include <string>

using namespace std;

//Class 
class NodeType
{
public:
	NodeType(int = 0);
	int info;
	NodeType * nextPtr;
};

//Constructor
NodeType::NodeType(int data)
{
	info = data;
	nextPtr = 0;
}

//Prototypes for menu options
void menu();
void insertFront(NodeType *&, int , NodeType *&);
void printList(NodeType*);
void deleteFirst(NodeType *&);
void find(NodeType *, int);
void findAndDelete(NodeType *&, int);
void deleteList(NodeType *&);
// void insertEnd(Nodetype *,int);
// int deleteEnd();
void printUsingRecursion(NodeType *&);
// int findAndDeleteUsingRecursion();
// int printListBackwards();

//Main
int main()
{
	//Assigning Class Pointer Objs: NodeType 
	NodeType * head = NULL;
	NodeType * currentPtr = NULL;

	int value;
	char choice;

	//do while to retrieve menu again untill user exits
	do
	{
		//Popup menu with users option
		menu();
		cin.get(choice);
		choice = toupper(choice);

		//Switch statement will have 7 options to choose from to modify Link List
		switch (choice)
		{
		case 'A': //Asks user to input a value into a Node
			cout << "Insert a value: ";
			cin >> value;
			insertFront(currentPtr, value, head);
			break;
		case 'B': //Asks user to find a value if it exists in the list
			cout << "Find a specific value from the list: ";
			cin >> value;
			find(head,value);
			break;
		case 'C':  //Gives the user the option to delete the first node in the list 
			cout << "Deleted the first Node..." << endl;
			deleteFirst(head);
			break;
		case 'D': //Asks user to find a value and then it will delete it 
			cout << "Find and delete node: " << endl;
			cout << "Find a value to delete: ";
			cin >> value;
			findAndDelete(head, value);
			break;
		case 'E': //Prints the list
			cout << "This is the list: " << endl;
			printList(head);
			break;
		case 'F': //Deletes the list
			cout << "List has been deleted." << endl;
			deleteList(head);
			break;
		case 'G': //Print using recursion
			cout << "This is the list using recursion: " << endl;
			printUsingRecursion(head);
			break;
		}
		cin.ignore(1000, '\n');  // Sets a 1000 limit bound
	} while (choice != 'H'); // 

	system("pause");
	return 0;
}

//Menu function
void menu()
{
	cout << endl;
	cout << "Link List: Select an option" << endl;
	cout << "A) Insert a value: " << endl;
	cout << "B) Find a value: " << endl;
	cout << "C) Delete first node." << endl;
	cout << "D) Find and Delete a node/value: " << endl;
	cout << "E) Print List." << endl;
	cout << "F) Delete List. " << endl;
	cout << "G) Print list using recursion. " << endl;
	cout << "H) Quit Program. " << endl;
}

//Inserting a node function passing 3 arguments
void insertFront(NodeType *&currentPtr, int value, NodeType *&head )
{
	currentPtr = new NodeType;
	currentPtr->info = value;
	currentPtr->nextPtr = head;
	head = currentPtr;
}

//Finding a value function passing 2 arguments
void find(NodeType *head, int value)
{
	bool find = false;

	//IF stment checks if list is empty
	if (head == NULL)
	{
		cout << "List is empty. " << endl;
		return;
	}

	//Begins the value search if list is not empty
	if (head != NULL)
	{
		while (head != NULL && !find)
		{
			if (head->info == value)
			{
				find = true;
			}
			else
			{
				head = head->nextPtr;
			}
		}
	}

	//Retrieves success if value found
	if (find)
	{
		cout << "Value Found!" << endl;
	}
	else
	{
		cout << "Value not Found. " << endl;
	}
}

//Deleting first node function passing 1 argument
void deleteFirst(NodeType *&headPtr)
{
	if (headPtr != NULL)
	{
		NodeType * currentPtr;
		currentPtr = headPtr;
		headPtr = headPtr->nextPtr;
		delete currentPtr;
	}
	else
	{
		cout << "List is empty..." << endl;
	}
}

//Find a delete value function passing 2 arguments
void findAndDelete(NodeType *&head, int value)
{
	NodeType * currentPtr;
	NodeType * prevPtr;
	NodeType * temphead;

	temphead = head;

	//Checks if list is empty
	bool find = false;
	if (head == NULL)
	{
		cout << "List is empty. " << endl;
		return;
	}
	//If list is not empty, will move on through each 
	//node to find the value. After value is found, the value
	//will be deleted and the pointer will point to a new
	//node.
	if (temphead != NULL)
	{
		if (temphead->info == value)
		{
			find = true;
			deleteFirst(head);
		}
		else
		{
			prevPtr = temphead;
			temphead = temphead->nextPtr;
			currentPtr = temphead;
			while (currentPtr != NULL)
			{
				if (currentPtr->info == value)
				{
					find = true;
					temphead = currentPtr;
					currentPtr = currentPtr->nextPtr;
					prevPtr->nextPtr = currentPtr;
					delete temphead;
				}
				else
				{
					prevPtr = currentPtr;
					currentPtr = currentPtr->nextPtr;
				}
			}
		}
	}

	//Message if value was not in the list
	if (!find)
	{
		cout << "Value not found." << endl;
	}
}
  
//Function to print entire link list
void printList(NodeType *headPtr)
{
	NodeType * print = headPtr;
	if (print != NULL)
	{
		while (print != NULL)
		{
			cout << "[" << print->info << "]->";
			print = print->nextPtr;
		}
	}
	else
	{
		cout << "List is empty..." << endl;
	}
}

//Function to clear out the link list
void deleteList(NodeType *&head)
{
	NodeType * temp;
	if (head != NULL)
	{
		while (head != NULL)
		{
			temp = head->nextPtr;
			delete[] head;
			head = temp;
		}
	}
	else 
		cout << "List is empty." << endl;

}

 void printUsingRecursion(NodeType *&ptr)
{
	 if (ptr != NULL)
	 {
		 cout << ptr->info << " ";
		 printUsingRecursion(ptr->nextPtr);
	 }
}
