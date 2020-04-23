#include <iostream>
struct Node{
	int data;
	Node* next;
};
void loop_address(Node* slow_ptr, Node* fast_ptr)
{
	while(slow_ptr != fast_ptr){
		slow_ptr = slow_ptr->next;
		fast_ptr = fast_ptr->next;
	}
	std::cout << "Loop started from address " << slow_ptr 
		<< std::endl;
}

int detect_loop(Node* list)
{
	Node *slow_ptr = list, *fast_ptr = list;
	while(slow_ptr && fast_ptr && fast_ptr->next){
		slow_ptr = slow_ptr->next;
		fast_ptr = fast_ptr->next->next;
		if(slow_ptr == fast_ptr){
			std::cout << "Loop detected " << std::endl;
			loop_address(slow_ptr, fast_ptr);
			exit(0);
		}
	}
	std::cout << "There is no loop " << std::endl;
	return 0;
}


int main()
{
	Node* head = nullptr;
	Node* second = nullptr;
	Node* third = nullptr;
	Node* forth = nullptr;
	Node* fifth = nullptr;

	head = new Node();
	second = new Node();
	third = new Node();
	forth = new Node();
	fifth = new Node();

	head->next = second;
	second->next = third;
	third->next = forth;
	forth->next = fifth;
	fifth->next = second;

	head->next->next->next->next = head;
	detect_loop(head);
	return 0;
}