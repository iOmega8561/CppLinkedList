/*
 * node.cpp
 *
 *  Created on: 28 apr 2022
 *      Author: giuseppe
 */


#include <cassert>
#include <cstdlib>
#include "linkedlist.h"

list::node::node(const node::value_type source, node *address) {
	data = source;
	next = address;
};

void list::node::set_data(const node::value_type source) {
	data = source;
};

void list::node::set_next(node* address) {
	next = address;
};

void list::head_insert(node*& head_ptr, const node::value_type data) {
	node* old_head = head_ptr;

	head_ptr = new node(data, old_head);
};


void list::insert(node*& previous_ptr, const node::value_type data) {
	node* old_next = previous_ptr->get_next();

	previous_ptr->set_next(new node(data, old_next));
};

void list::head_remove(node*& head_ptr) {
	node* to_be_removed = head_ptr;

	head_ptr = head_ptr->get_next();
	delete to_be_removed;
};

void list::remove(node*& previous_ptr) {
	node* to_be_removed = previous_ptr->get_next();

	previous_ptr->set_next(to_be_removed->get_next());
	delete to_be_removed;
};

list::node* list::search_by_data(node* head_ptr, const node::value_type source) {
	node* cursor;

	for(cursor = head_ptr; cursor != NULL; cursor = cursor->get_next()) {
		if (source == cursor->get_data())
			return cursor;
	};

	return NULL;
};

list::node* list::search_by_pos(node* head_ptr, const int position) {
	node* cursor = head_ptr;

	for(int i = 0; i < position && cursor != NULL; i++)
		cursor = cursor->get_next();

	return cursor;
};

void list::copy_linked(const node* source_head, node*& head_ptr, node*& tail_ptr) {
	list::head_insert(head_ptr, source_head->get_data());
	tail_ptr = head_ptr;

	for(source_head = source_head->get_next(); source_head != NULL; source_head = source_head->get_next()) {
		list::insert(tail_ptr, source_head->get_data());
		tail_ptr = tail_ptr->get_next();
	};
};

void list::delete_linked(node*& head_ptr) {
	while(head_ptr != NULL)
		list::head_remove(head_ptr);
};
