#include "lists.h"
#include <stdlib.h>

/**
 * delete_dnodeint_at_index - Deletes the node at a given index
 * @head: Pointer to a pointer to the head of the list
 * @index: Index of the node that should be deleted
 * Return: 1 if it succeeded, -1 if it failed
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
    dlistint_t *current = *head;

    if (*head == NULL)
        return (-1);

    if (index == 0)
    {
        *head = (*head)->next;
        free(current);
        if (*head != NULL)
            (*head)->prev = NULL;
        return (1);
    }

    for (; index > 0 && current != NULL; index--)
        current = current->next;

    if (current == NULL)
        return (-1);

    if (current->next != NULL)
        current->next->prev = current->prev;
    current->prev->next = current->next;

    free(current);
    return (1);
}
