#include "lists.h"
#include <stdlib.h>

/**
 * insert_dnodeint_at_index - Inserts a new node at a given position.
 * @h: Pointer to a pointer to the head of the list.
 * @idx: Index where the new node should be added.
 * @n: Value of the new node.
 *
 * Return: The address of the new node, or NULL if it failed.
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
    dlistint_t *new_node, *temp;
    unsigned int i;

    if (h == NULL)
        return (NULL);

    if (idx == 0)
        return (add_dnodeint(h, n));

    temp = *h;
    for (i = 0; i < idx - 1 && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL)
        return (NULL);

    new_node = malloc(sizeof(dlistint_t));
    if (new_node == NULL)
        return (NULL);

    new_node->n = n;
    new_node->next = temp->next;
    new_node->prev = temp;
    temp->next = new_node;

    if (new_node->next != NULL)
        new_node->next->prev = new_node;

    return (new_node);
}
