#include "monty.h"

/**
 * delete_dnodeint_at_index - Delete a node at specified index in a linked list
 * @head: Address of the head pointer.
 * @index: Index of the node to be deleted.
 *
 * Return: 1 on success, -1 on failure.
 */
int delete_dnodeint_at_index(stack_t **head, unsigned int index)
{
stack_t *p = NULL;
unsigned int i;

if (!head || !*head)
return (-1);

/* Traverse to the node at the specified index */
for (i = 0, p = *head; i < index && p; i++, p = p->next)
;

if (!p)
return (-1);

/* Update the pointers to remove the node from the list */
if (p == *head)
*head = p->next;
if (p->prev)
p->prev->next = p->next;
if (p->next)
p->next->prev = p->prev;

/* Free the memory allocated for the node */
free(p);

return (1);
}
