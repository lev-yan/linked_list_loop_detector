#include <iostream>

struct Node{
	int data;
	Node* next;
};

class List : public Node{
private:
	Node *m_head, *m_tail;
public:
	List() : m_head(nullptr), 
				m_tail(nullptr){};
	Node * get_head();
	Node * get_tail();
	void create_node(int);
	void display_node();
};

Node* List::get_head()
{
	return m_head;
}

Node* List::get_tail()
{
	return m_tail;
}

void List::display_node()
{
	Node *temp;
	temp = m_head;
	while(temp != nullptr){
		std::cout << temp->data << std::endl;
		temp = temp->next;
	}
}

void List::create_node(int value)
{
	Node *temp = new Node;
	temp->data = value;
	temp->next = nullptr;
	if(m_head == nullptr){
		m_head = temp;
		m_tail = temp;
		temp = nullptr;
	} else {
		m_tail->next = temp;
		m_tail = temp;
	}
}

void loop_address(Node* slow_ptr, Node* fast_ptr, List list)
{
	slow_ptr = list.get_head();
	while(slow_ptr != fast_ptr){
		slow_ptr = slow_ptr->next;
		fast_ptr = fast_ptr->next;
	}
	std::cout << "Loop started from address " << slow_ptr 
		<< std::endl;
}


int detect_loop(List list)
{
	Node *slow_ptr = list.get_head(), *fast_ptr = list.get_head();
	while(slow_ptr && fast_ptr && fast_ptr->next){
		slow_ptr = slow_ptr->next;
		fast_ptr = fast_ptr->next->next;
		if(slow_ptr == fast_ptr){
			std::cout << "Loop detected " << std::endl;
			loop_address(slow_ptr, fast_ptr, list);
			return 1;
		}
	}
	std::cout << "There is no loop in list " << std::endl;
	return 0;
}




int main()
{
	List L;
	L.create_node(3);
	L.create_node(7);
	L.create_node(4);
	L.create_node(2);
	L.create_node(8);
	L.create_node(9);
	L.create_node(1);
	L.display_node();
	//detect_loop(L);
	return 0;
}









/*void loop_address(Node* slow_ptr, Node* fast_ptr, Node* list)
{
	slow_ptr = list;
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
			loop_address(slow_ptr, fast_ptr, list);
			return 1;
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
	fifth->next = third;

	std::cout << "address of head " << head << std::endl;
	std::cout << "address of second " << second << std::endl;
	std::cout << "address of third " << third << std::endl;
	std::cout << "address of forth " << forth << std::endl;
	std::cout << "address of fifth " << fifth << std::endl;
	//head->next->next->next->next = head;
	detect_loop(head);
	return 0;
}*/
