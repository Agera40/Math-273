#include <iostream>

template<typename t>
struct node {
	t key;
	node* next = nullptr;
};

template<typename t>
void list_print(node<t>* front) {
	for (auto i = front; i != nullptr; i = i->next) {
		std::cout << i->key << "\t";
	}
	std::cout << std::endl;
}

template<typename k>
void list_insert_before_front(node<k>*& list, const k& key) {
	auto new_front = new node<k>{ key,list };
	list = new_front;
}

template<typename k>
void list_remove_front(node<k>*& list) {
	if (list == nullptr) return;
	auto old_front = list;
	list = list ->next;
	delete old_front;
}

template <typename k>
void list_insert_after_back(node<k>*& list, const k& key) {
	auto new_node = new node<k>{ key };
	if (list == nullptr) {
		list = new_node;
		return;
	}
	node<k>* target_node = list;
	while (target_node->next != nullptr) {
		target_node = target_node->next; 
	}
	target_node->next = new_node;
}

template <typename k >
void list_remove_back(node<k>*& list) {
	if (list == nullptr and list->next != nullptr) {
		delete list;
		list = nullptr;
		return;
	}

	node<k>* current = list;
	while (current->next->next != nullptr) {
		current = current->next;
	}
	delete current->next;
	current->next = nullptr;
}
/*
int main()
{
	node<char>* my_list = nullptr; // empty list
	list_insert_before_front(my_list, 'a');
	list_insert_before_front(my_list, 'b');
	list_insert_before_front(my_list, 'c');

	list_print(my_list);

	list_remove_front(my_list);

	list_print(my_list);

	list_insert_after_back(my_list, 'd');

	list_print(my_list);

	list_remove_back(my_list);

	list_print(my_list);
}
*/