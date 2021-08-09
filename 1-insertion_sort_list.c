#include "sort.h"

/**
 * swap_helperfunc- swap two nodes
 * @first: first node
 * @second: second node
 * @head: head of list
 *
 * Return: void
 */

void swap_helperfunc(listint_t *first, listint_t *second, listint_t **head)
{
	listint_t *tmp;

	tmp = first->prev;
	if (tmp)
		tmp->next = second;
	second->prev = tmp;
	first->prev = second;
	first->next = second->next;
	second->next = first;
	if (first->next != NULL)
		first->next->prev = first;
	if (second->prev == NULL)
		*head = second;
	print_list(*head);
}

/**
 * insertion_sort_list- sorts a doubly linked list of ints in ascending order
 * @head: head of the list
 *
 */

void insertion_sort_list(listint_t **head)
{
	listint_t *current, *next, *prev, *secondpre;

	if (head == NULL)
		return;

	current = next = *head;
	while (current != NULL)
	{
		while (current->prev != NULL)
		{
			prev = current->prev;
			secondpre = prev;
			if (prev->n > current->n)
				swap_helperfunc(prev, current, head);
			current = secondpre;
		}
		current = next->next;
		next = current;
	}
}
/* You are not allowed to modify the integer n of a node */
/* You have to swap the nodes themselves */

/* You’re expected to print the list after each time you swap two elements */
