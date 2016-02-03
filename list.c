#include <assert.h>
#include <stdlib.h>

#include "list.h"

// Takes a valid, sorted list starting at `head` and adds the element
// `new_element` to the list. The list is sorted based on the value of the
// `index` member in ascending order. Returns a pointer to the head of the list
// after the insertion of the new element.
list_t* insert_sorted(list_t* head, list_t* new_element) {
	assert(head != NULL);
	assert(new_element != NULL);

	list_t* prev = NULL;

	//new_element becomes head
	if (head->index > new_element->index){
		new_element->next = head;
		return new_element;
	}

	else{
		list_t* it = head;
		for (; it != NULL; it = it->next){
			if (it->index > new_element->index){
				prev->next = new_element;
				new_element->next = it;
				return head;
			}

			prev = it;
		}

		//new_element goes at end
		prev->next = new_element;
		return head;	
	}
}//insert_sorted

// Reverses the order of the list starting at `head` and returns a pointer to
// the resulting list. You do not need to preserve the original list.
list_t* reverse(list_t* head) {
	assert(head != NULL);

	list_t* current = head;
	list_t* prev = NULL;
	list_t* next = NULL;

	while(current != NULL){
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	
	return prev;
}