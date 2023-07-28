#include <stdlib.h>
#include "lists.h"

/**
 * list_len - This  returns the number of elements in a linked list
 * @h: Pointer to list_t list
 *
 * Return:The  number of elements in d
 */
size_t list_len(const list_t *d)
{
size_t q = 0;
while (d)
{
q++;
d = d->next;
}
return (q);
}
