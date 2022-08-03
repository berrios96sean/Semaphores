/**
 * @file q.h
 * @author Sean Berrios
 * @brief
 * @version 0.2
 * @date 2022-07-29
 *
 */

#ifndef Q_H
#define Q_H
#include <stdlib.h>
#include "tcb.h"

/**
 * @brief Returns a pointer to a new q-element
 *
 * @return struct TCB_t*
 */
struct TCB_t *NewItem()
{
    TCB_t *item = malloc(sizeof(TCB_t));
    return item;
}

/**
 * @brief creates an empty queue pointed to by the variable head
 *
 * @param head
 */
void InitQueue(TCB_t **head)
{
    *head = NULL;
}

/**
 * @brief Adds a queue item pointed to by "item" to the queue pointed to by head
 *
 * @param head
 * @param item
 */
void AddQueue(TCB_t **head, struct TCB_t *item)
{
    if (*head == NULL)
    {
        *head = item;
        (*head)->prev = *head;
        (*head)->next = *head;
    }
    else
    {
        TCB_t *tail = (*head)->prev;
        tail->next = item;
        item->prev = tail;
        item->next = *head;
        (*head)->prev = item;
    }
}

/**
 * @brief deletes an item from head and returns a pointer to the deleted item
 *
 * @param head
 * @return struct TCB_t*
 */
struct TCB_t *DelQueue(TCB_t **head)
{
    TCB_t *del = *head;
    if (del == NULL)
    {
        return NewItem();
    }
    else if (del->next == del)
    {
        *head = NULL;
    }
    else
    {
        *head = (*head)->next;
        del = (*head)->prev;
        (*head)->prev->prev->next = *head;
        (*head)->prev = (*head)->prev->prev;
        del->prev = del;
        del->next = del;
    }
    return del;
}

/**
 * @brief Moves the header pointer to the next element in the queue.
 * This is equivalent to AddQ(&head, DeleteQ(&head)),
 * but is simpler to use and more efficient to implement.
 *
 * @param head
 */
void RotateQ(TCB_t **head)
{
    *head = (*head)->next;
}

#endif
