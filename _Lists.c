#include "shell.h"

/**
 * add_node_start - adds a node to the start of the list
 * @hd: address of pointer to head node
 * @strctr: str field of node
 * @ni: node index used by history
 *
 * Return: size of list
 */
list_t *add_node_start(list_t **hd, const char *strctr, int ni)
{
	list_t *new_hd;

	if (!hd)
		return (NULL);
	new_hd = malloc(sizeof(list_t));
	if (!new_hd)
		return (NULL);
	_setMem((void *)new_hd, 0, sizeof(list_t));
	new_hd->ni = ni;
	if (strctr)
	{
		new_hd->strctr = _strdup(strctr);
		if (!new_hd->strctr)
		{
			free(new_hd);
			return (NULL);
		}
	}
	new_hd->next = *hd;
	*hd = new_hd;
	return (new_hd);
}

/**
 * add_node - adds a node to the end of the list
 * @hd: address of pointer to head node
 * @strctr: str field of node
 * @ni: node index used by history
 *
 * Return: size of list
 */
list_t *add_node(list_t **hd, const char *strctr, int ni)
{
	list_t *new_nd, *nd;

	if (!hd)
		return (NULL);

	nd = *hd;
	new_nd = malloc(sizeof(list_t));
	if (!new_nd)
		return (NULL);
	set_mem((void *)new_nd, 0, sizeof(list_t));
	new_nd->ni = ni;
	if (strctr)
	{
		new_nd->strctr = _strdup(strctr);
		if (!new_nd->strctr)
		{
			free(new_nd);
			return (NULL);
		}
	}
	if (nd)
	{
		while (nd->next)
			nd = nd->next;
		nd->next = new_nd;
	} else
		*hd = new_nd;
	return (new_nd);
}

/**
 * list_strPrint - prints only the str element of a list_t linked list
 * @pn: pointer to first node
 *
 * Return: size of list
 */
size_t list_strPrint(const list_t *pn)
{
	size_t i = 0;

	while (pn)
	{
		_puts(pn->strctr ? h->strctr : "(nil)");
		_puts("\n");
		pn = pn->next;
		i++;
	}
	return (i);
}

/**
 * delete_node - deletes node at given index
 * @hd: address of pointer to first node
 * @in: index of node to delete
 *
 * Return: 1 on success, 0 on failure
 */
int delete_node(list_t **hd, unsigned int in)
{
	list_t *nd, *prevent_nd;
	unsigned int i = 0;

	if (!hd || !*hd)
		return (0);

	if (!in)
	{
		nd = *hd;
		*hd = (*hd)->next;
		free(nd->strctr);
		free(nd);
		return (1);
	}
	nd = *hd;
	while (nd)
	{
		if (i == in)
		{
			prevent_nd->next = nd->next;
			free(nd->strctr);
			free(nd);
			return (1);
		}
		i++;
		prevent_nd = nd;
		nd = nd->next;
	}
	return (0);
}

/**
 * free_node_list - frees all nodes of a list
 * @hd_ptr: address of pointer to head node
 *
 * Return: void
 */
void free_node_list(list_t **hd_ptr)
{
	list_t *nd, *next_nd, *hd;

	if (!hd_ptr || !*hd_ptr)
		return;
	hd = *hd_ptr;
	nd = hd;
	while (nd)
	{
		next_nd = nd->next;
		free(nd->strctr);
		free(nd);
		nd = next_nd;
	}
	*hd_ptr = NULL;
}
