/*
 * linkedlist.template
 *
 *  Created on: 28 apr 2022
 *      Author: giuseppe
 */

#ifndef LINKEDLIST_TEMPLATE_
#define LINKEDLIST_TEMPLATE_

#include <cassert>
#include <cstdlib>

namespace list {

	template <class TYPE>
	void node<TYPE>::set_data(const typename node<TYPE>::value_type source) {
		data = source;
	};

	template <class TYPE>
	void node<TYPE>::set_next(node<TYPE>* address) {
		next = address;
	};

	template <class TYPE>
	void head_insert(node<TYPE>*& head_ptr, const typename node<TYPE>::value_type data) {
		node<TYPE>* old_head = head_ptr;

		head_ptr = new node<TYPE>(data, old_head);
	};

	template <class TYPE>
	void insert(node<TYPE>*& previous_ptr, const typename node<TYPE>::value_type data) {
		node<TYPE>* old_next = previous_ptr->get_next();

		previous_ptr->set_next(new node<TYPE>(data, old_next));
	};

	template <class TYPE>
	void head_remove(node<TYPE>*& head_ptr) {
		node<TYPE>* to_be_removed = head_ptr;

		head_ptr = head_ptr->get_next();
		delete to_be_removed;
	};

	template <class TYPE>
	void remove(node<TYPE>*& previous_ptr) {
		node<TYPE>* to_be_removed = previous_ptr->get_next();

		previous_ptr->set_next(to_be_removed->get_next());
		delete to_be_removed;
	};

	template <class TYPE>
	node<TYPE>* list::search_by_data(node<TYPE>* head_ptr, const typename node<TYPE>::value_type source) {
		node<TYPE>* cursor;

		for(cursor = head_ptr; cursor != NULL; cursor = cursor->get_next()) {
			if (source == cursor->get_data())
				return cursor;
		};

		return NULL;
	};

	template <class TYPE>
	node<TYPE>* list::search_by_pos(node<TYPE>* head_ptr, const int position) {
		node<TYPE>* cursor = head_ptr;

		for(int i = 0; i < position && cursor != NULL; i++)
			cursor = cursor->get_next();

		return cursor;
	};

	template <class TYPE>
	void copy_linked(const node<TYPE>* source_head, node<TYPE>*& head_ptr, node<TYPE>*& tail_ptr) {
		head_insert(head_ptr, source_head->get_data());
		tail_ptr = head_ptr;

		for(source_head = source_head->get_next(); source_head != NULL; source_head = source_head->get_next()) {
			insert(tail_ptr, source_head->get_data());
			tail_ptr = tail_ptr->get_next();
		};
	};

	template <class TYPE>
	void delete_linked(node<TYPE>*& head_ptr) {
		while(head_ptr != NULL)
			head_remove(head_ptr);
	};
}

#endif /* LINKEDLIST_TEMPLATE_ */
