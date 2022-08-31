#include <iostream>
#include <cstdlib>
#include "linkedlist.h"

#define RTV 0

int main() {
	list::node* head_ptr = new list::node(5, NULL);

	list::insert(head_ptr, 12);

	std::cout << head_ptr->get_data() << std::endl;

	std::cout << head_ptr->get_next() << std::endl;

	list::node* btd = list::search_by_data(head_ptr, 12);

	std::cout << "elpuerco: " << btd->get_data() << std::endl;

	btd->set_data(32);

	std::cout << "elpuerco v2:" << btd->get_data() << std::endl;

	list::delete_linked(head_ptr);
	return RTV;
}
