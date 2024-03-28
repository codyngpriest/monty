#include "monty.h"

/**
 * print_dlistint - Prints all elements of a doubly linked list.
 * @h: Head of the doubly linked list.
 *
 * Return: Number of nodes in the list.
 */
size_t print_dlistint(const stack_t *h)
{
size_t num = 0;

while (h)
{
num++;
printf("%d\n", h->n);
h = h->next;
}
return (num);
}
/**
 * get_dnodeint_at_index - Retrieves the node at a specified index.
 * @head: Pointer to the head node of the doubly linked list.
 * @index: Index of the node to retrieve.
 *
 * Return: Pointer to the node at the given index, or NULL if it does not exist
 */
stack_t *get_dnodeint_at_index(stack_t *head, unsigned int index)
{
unsigned int i;

for (i = 0; i < index && head; i++)
{
head = head->next;
}

return (head);
}
/**
 * add_dnodeint - Adds a new node at the beginning of a doubly linked list.
 * @head: Pointer to the pointer to the head node of the list.
 * @n: The data to be stored in the new node.
 *
 * Return: Address of the new node, or NULL on failure.
 */
stack_t *add_dnodeint(stack_t **head, const int n)
{
stack_t *newNode = NULL;

if (head)
{
newNode = malloc(sizeof(*newNode));
if (newNode)
{
newNode->n = n;
newNode->prev = NULL;
newNode->next = *head;
if (*head)
(*head)->prev = newNode;
*head = newNode;
}
}

return (newNode);
}
/**
 * free_dlistint - Frees a doubly linked list.
 * @head: Pointer to the head node of the list.
 */
void free_dlistint(stack_t *head)
{
stack_t *current = head;
stack_t *next;

while (current)
{
next = current->next;
free(current);
current = next;
}
}
/**
 * add_dnodeint_end - Adds a new node to the end of a doubly linked list.
 * @head: Pointer to the head pointer of the list.
 * @n: Data for the new node.
 *
 * Return: Address of the new node, NULL on failure.
 */
stack_t *add_dnodeint_end(stack_t **head, const int n)
{
stack_t *newNode = NULL;

if (head)
{
newNode = malloc(sizeof(*newNode));
if (newNode)
{
newNode->n = n;
newNode->next = NULL;
newNode->prev = *head;

if (!*head)
{
/* If the list is empty new node is the head */
*head = newNode;
return (newNode);
}

/* Traverse to the last node in the list */
while (newNode->prev->next)
newNode->prev = newNode->prev->next;

/* Append the new node to the end of the list */
newNode->prev->next = newNode;
}
}

return (newNode);
}
