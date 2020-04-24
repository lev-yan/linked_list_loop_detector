#include <iostream>

struct Node{
	int data;
	Node* next;
	Node() : data(0), 
				next(nullptr){
					std::cout << "ctor Node" << std::endl;
				}
	~Node(){
		std::cout << "delete" << std::endl;
		delete next;

	}
};

class List{
private:
	Node *m_head, *m_tail;
public:
	List() : m_head(nullptr), 
				m_tail(nullptr){
					std::cout << "ctor List" << std::endl;
				};
	~List(){
		std::cout << "List dtor" << std::endl;
		delete m_head;

	}
	Node * get_head()const;
	Node * get_tail()const;
	void push_node(int);
	void display_node();
};

Node* List::get_head()const
{
	return m_head;
}

Node* List::get_tail()const
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

void List::push_node(int value)
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

void loop_address(Node* slow_ptr, Node* fast_ptr, const List& list)
{
	slow_ptr = list.get_head();
	while(slow_ptr != fast_ptr){
		slow_ptr = slow_ptr->next;
		fast_ptr = fast_ptr->next;
	}
	std::cout << "Loop started from address " << slow_ptr 
		<< std::endl;
}


int detect_loop(const List &list)
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
	L.push_node(3);
	L.push_node(7);
	L.push_node(4);
	L.push_node(2);
	L.push_node(8);
	L.push_node(9);
	L.push_node(1);
	L.display_node();
	detect_loop(L);
	return 0;
}

