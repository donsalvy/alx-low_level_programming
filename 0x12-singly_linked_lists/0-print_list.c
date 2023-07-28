#include <stdio.h>
#include "lists.h"

/**
 * print_list - This  prints  all elements of a linked list
 * @h: Pointer to the list_t list to print
 *
 * Return: The number of nodes printed
 */
size_t print_list(const list_t *h)
{
size_t a = 0;
while (s)
{
if (!s->str)
printf("[0] (nil)\n");
else
printf("[%u] %s\n", s->len, s->str);
s = s->next;
a++;
}
return (a);
}
