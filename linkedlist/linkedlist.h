/*
 * node.h
 *
 *  Created on: 28 apr 2022
 *      Author: giuseppe
 */

#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

#include <cstdlib>

namespace list {

	class node {
		public:
			typedef int value_type;
			node(const value_type source = 0, node *address = NULL);
			void set_data(value_type source);
			void set_next(node* address);
			const value_type get_data() const { return data; };
			value_type get_data() { return data; };
			const node* get_next() const { return next; };
			node* get_next() { return next; };
		private:
			value_type data;
			node *next;
	};

	void head_insert(node*& head_ptr, const node::value_type data);
	void insert(node*& previous_ptr, const node::value_type data);
	void head_remove(node*& head_ptr);
	void remove(node*& previous_ptr);
	node* search_by_data(node* head_ptr, const node::value_type source);
	node* search_by_pos(node* head_ptr, const int position);
	void copy_linked(const node* source_head, node*& head_ptr, node*& tail_ptr);
	void delete_linked(node*& head_ptr);
}



#endif /* LINKEDLIST_H_ */
