#include "sort.h"

void insertion_sort_list(listint_t **list)
{
    listint_t *j, *temp, *curr;

    curr = (*list)->next;

    while (curr)
    {
        j = curr;
        while (j->prev && j->n < j->prev->n)
        {
            temp = j->prev;
            if (temp->prev)
                temp->prev->next = j;
            j->prev = temp->prev;
            temp->prev = j;
            temp->next = j->next;
            if (j->next)
                j->next->prev = temp;
            j->next = temp;

            if (!j->prev)
                *list = j;
            print_list(*list);
        }
        curr = curr->next;
    }
}

listint_t *create_listint(const int *array, size_t size)
{
    listint_t *list;
    listint_t *node;
    int *tmp;

    list = NULL;
    while (size--)
    {
        node = malloc(sizeof(*node));
        if (!node)
            return (NULL);
        tmp = (int *)&node->n;
        *tmp = array[size];
        node->next = list;
        node->prev = NULL;
        list = node;
        if (list->next)
            list->next->prev = list;
    }
    return (list);
}

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
    listint_t *list;
    int array[] = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7};
    size_t n = sizeof(array) / sizeof(array[0]);

    list = create_listint(array, n);
    if (!list)
        return (1);
    print_list(list);
    printf("\n");
    insertion_sort_list(&list);
    printf("\n");
    print_list(list);
    return (0);
}
