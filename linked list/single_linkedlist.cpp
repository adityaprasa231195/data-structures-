#include <iostream>
using std::cout;
using std::cin;


struct Listnode
{
	int data;
    Listnode *next;
};

int main(){
	Listnode *first=new Listnode{10,nullptr};
	Listnode *second=new Listnode{20,nullptr};
    Listnode *third=new Listnode{30,nullptr};
    
    first->next =second;
    second->next =third;

	Listnode *head = first;  // Head points to the first node

    Listnode *current = head;

     while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }

    
    delete third;
    delete second;
    delete first;



	return 0;
}
