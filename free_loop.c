#include "simple_shell.h"
/**
*free_loop - free double pointer array of pointers
*@arr: double pointer array of pointers
*/
void free_loop(char **arr)
{
	int length;

	for (length = 0; arr[length]; length++)
		free(arr[length]);
	free(arr);
}

/**
 *free_list - frees a listint_t list
 *@head: pointer to the first node in the linked list
 */
void free_list(list_s *head)
{
	list_s *prev;

	while (head)
	{
		free(head->dir);
		prev = head;
		head = head->next;
		free(prev);
	}
}
