#include <stdlib.h>
#include <string.h>
#include "lists.h"

/**
 * add_node - This code adds a new node at the beginning of a linked list
 * @head: Double pointer to the list_t list
 * @str: This prints a  new string to add in the node
 *
 * Return: The address of the new element, or NULL if it fails
 */
list_t *add_node(list_t **head, const char *str)
{
list_t *man;
unsigned int len = 0;
while (str[len])
len++;
man = malloc(sizeof(list_t));
if (!man)
return (NULL);
man->str = strdup(str);
man->len = len;
man->next = (*head);
(*head) = man;
return (*head);
}
