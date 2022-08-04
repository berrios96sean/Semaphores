/**
 * @file sem.h
 * @author Sean Berrios
 * @brief
 * @version 0.1
 * @date 2022-07-29
 *
 */

#ifndef SEM_H
#define SEM_H
#include "threads.h"

typedef struct Semaphore
{
    int value;
    struct TCB_t *sQueue;
} Semaphore;

void initSem(Semaphore *semaphore, int value)
{
    semaphore->sQueue = NULL;
    semaphore->value = value;
}

void P(Semaphore *semaphore)
{
    if (semaphore->value <= 0)
    {
        if (RunQ == NULL)
        {
            exit(0);
        }

        TCB_t *tcb = DelQueue(&RunQ);

        if (tcb->thread_id < 0)
        {
            printf("\n Consumer %d is waiting\n", -tcb->thread_id);
        }
        else if (tcb->thread_id > 0)
        {
            printf("\n Producer %d is waiting\n", tcb->thread_id);
        }
        AddQueue(&(semaphore->sQueue), tcb);
        swapcontext(&(tcb->context), &(RunQ->context));
    }
    else
    {
        semaphore->value--;
    }
}
void V(Semaphore *semaphore)
{
    if (semaphore->sQueue != NULL)
    {
        TCB_t *tcb = DelQueue(&(semaphore->sQueue));
        AddQueue(&RunQ, tcb);
    }
    semaphore->value++;
}
#endif