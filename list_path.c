#include "simple_shell.h"
/**
 *add_node_end - append node to the list
 *@head: pointer to the first node in the linked list
 *@dir: string to initialize new node
 *Return: new or NULL
 */
void add_node_end(list_s **head, const char *dir)
{
	list_s *last_node = *head;
	list_s *new_node = malloc(sizeof(list_s));

	new_node->next = NULL;
	new_node->dir = _strdup((char *)dir);
	if (last_node)
	{
		while (last_node->next)
		last_node = last_node->next;
		last_node->next = new_node;
	}
	else
		*head = new_node;
}
/**
 *list_path - builds a linked list of the PATH directories
 *@env: environment variables
 *Return: the head of the list
 */
list_s *list_path(char **env)
{
	char *tokeniz;
	char *path;
	list_s *head;

	head = NULL;
	path = _getenv("PATH", env);
	add_node_end(&head, ".");
	tokeniz = strtok(path, ":");
	while (tokeniz != NULL)
	{
		add_node_end(&head, tokeniz);
		tokeniz = strtok(NULL, ":");
	}
	return (head);
}
