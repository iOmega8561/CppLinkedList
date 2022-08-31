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

	template <class TYPE>
	class node {
		public:
			typedef TYPE value_type;

			node(const value_type source = 0, node *address = NULL) {
				data = source;
				next = address;
			};

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

	template <class TYPE>
	void head_insert(node<TYPE>*& head_ptr, const typename node<TYPE>::value_type data);

	template <class TYPE>
	void insert(node<TYPE>*& previous_ptr, typename node<TYPE>::value_type data);

	template <class TYPE>
	void head_remove(node<TYPE>*& head_ptr);

	template <class TYPE>
	void remove(node<TYPE>*& previous_ptr);

	template <class TYPE>
	node<TYPE>* search_by_data(node<TYPE>* head_ptr, const typename node<TYPE>::value_type source);

	template <class TYPE>
	node<TYPE>* search_by_pos(node<TYPE>* head_ptr, const int position);

	template <class TYPE>
	void copy_linked(const node<TYPE>* source_head, node<TYPE>*& head_ptr, node<TYPE>*& tail_ptr);

	template <class TYPE>
	void delete_linked(node<TYPE>*& head_ptr);
}


#include "linkedlist.tpp"
#endif /* LINKEDLIST_H_ */
