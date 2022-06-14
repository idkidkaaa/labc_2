#include "dll.h"
#include <stdio.h>


//initialization
list_t* init() {
	list_t* lst;
	lst = (list_t*)malloc(sizeof(list_t));
	lst->next = NULL;
	lst->prev = NULL;
	return lst;
}

//Add -> <-
list_t* addel(list_t* lst, int n) {

	list_t* new_item; 
	new_item = (list_t*)malloc(sizeof(list_t));
	if (new_item == NULL) {
		return NULL;
	}

	new_item->key = n;
	new_item->next = NULL;
	while (lst->next != NULL) {
		lst = lst->next;
	}

	lst->next = new_item;
	new_item->prev = lst;

	return new_item;
}


//delete 
list_t* delel(list_t* lst) {
	list_t* prev, * next;
	prev = lst->prev;
	next = lst->next;
	
	if (prev != NULL) {
		prev->next = lst->next;
	}
	if (next != NULL) {
		next->prev = lst->prev;
	}
	free(lst);
	
	return prev;
}

//search
list_t* findel(list_t* lst, int n) {
	if (lst == NULL) {
		return NULL;
	}
	if (n == lst->key) {
		return lst;
	}
	else {
		return findel(lst->next, n);
	}
}


list_t* add_from_file(list_t* lst, char* filename) {
	FILE* f = fopen(filename, "r");
	char s[100];
	int x;
	while (!feof(f)) {
		fscanf(f, "%d", &x);
		addel(lst, x);
	}
	fclose(f);
	
	return lst;
}
