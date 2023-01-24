#include "sort.h"

/**
 * insertion_sort_list - dorting function based on insertion algorithm
 * @list: double poiter to head node of a doubly linked list
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *trav, *temp, *insert;

	for (trav = (*list)->next; trav != NULL; trav = temp)
	{
		if (list == NULL || *list == NULL || (*list)->next == NULL)
			return;

		/* assigns temp trav->next to help traverse the list */
		temp = trav->next;
		/* insert value serve as sorted element in insertion sort */
		insert = trav->prev;
		while (insert != NULL && trav->n < insert->n)
		{
			insert->next = trav->next;
			/**
			 * checks if trav->next is NULL before updating its
			 * next value previous link with insert value link
			 */
			if (trav->next != NULL)
				trav->next->prev = insert;
			trav->prev = insert->prev;
			trav->next = insert;
			/**
			 * condition checks if the list (head) value needs to
			 * be updated so as not to loose the head pointer
			 * NULL means its the begining of the double list
			 * if NULL, the head will be updated with new address
			 * if !NULL the insert->prev->next will be updated
			 */
			if (insert->prev != NULL)
				insert->prev->next = trav;
			else
				*list = trav;
			insert->prev = trav;
			insert = trav->prev;
			/* print the list with each swap */
			print_list((const listint_t *) *list);
		}
	}
}
