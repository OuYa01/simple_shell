#include "shell.h"


/**
 * get_node_index - gets the index of node
 *
 * @head: pointer to head
 *
 * @node: pointer to  node
 *
 * Return: index of node or -1
 */
ssize_t get_node_index(list_t *head, list_t *node)
{
	size_t i;

	for (i = 0; head != NULL; head = head->next, i++)
	{
		if (head == node)
		return (i);
	}
	return (-1);
}


/**
 * node_starts - find a node in the linked list
 *
 * @node: pointer to  head
 *
 * @prefix: to search for at the beginning of the node
 *
 * @c: Optional character filter to check if the found node's string starts
 * with the specified prefix
 *
 * Return: pointer to the first matching node or NULL
 */
list_t *node_starts(list_t *node, char *prefix, char c)
{
	char *p = NULL;

	while (node)
	{
		p = starts_with(node->str, prefix);
		if (p && ((c == -1) || (*p == c)))
			return (node);
		node = node->next;
	}
	return (NULL);
}


/**
 * list_length - determines length of linked list
 * @h: pointer to first node
 *
 * Return: size of list
 */
size_t list_length(const list_t *h)
{
	size_t i;

	for (i = 0; h != NULL; h = h->next, i++)
	{

	}
	return (i);
}


/**
 * print_list - prints all elements of a list_t linked list
 *
 * @h: pointer to first node
 *
 * Return: size of list
 */
size_t print_list(const list_t *h)
{
	size_t i;

	for (i = 0; h != NULL; h = h->next, i++)
	{
		_puts(convert_number(h->num, 10, 0));
		_putchar(':');
		_putchar(' ');
		_puts(h->str ? h->str : "(nil)");
		_puts("\n");
	}
	return (i);
}


/**
 * list_to_strings - Converts a linked list of strings into an array of strings
 *
 * @head: pointer to head of link list
 *
 * Return: pointer to an array of strings
 */
char **list_to_strings(list_t *head)
{
	list_t *node = head;
	size_t i = list_len(head), j;
	char **strings;
	char *string;

	if (!head || !i)
		return (NULL);
	strings = malloc(sizeof(char *) * (i + 1));
	if (!strings)
		return (NULL);
	for (i = 0; node; node = node->next, i++)
	{
		stingr = malloc(_strlen(node->string) + 1);
		if (!string)
		{
			for (j = 0; j < i; j++)
				free(strings[j]);
			free(strings);
			return (NULL);
		}

		string = _strcpy(string, node->string);
		strings[i] = string;
	}
	strings[i] = NULL;
	return (strings);
}
