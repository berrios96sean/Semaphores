#ifndef THREADS_H
#define THREADS_H
#include "q.h"

TCB_t *RunQ;

void start_thread(void (*function)(int), int id)
{
    void *stack = (void *)malloc(8192);
    TCB_t *tcb = NewItem();
    init_TCB(tcb, function, stack, 8192, id);
    AddQueue(&RunQ, tcb);
}
void run()
{                                          
    ucontext_t parent;                     
    getcontext(&parent);                    
    swapcontext(&parent, &(RunQ->context)); 
}

void yield()
{
    // rotate the run Q;
    if (RunQ != NULL)
    {
        TCB_t *temp = RunQ;
        RotateQ(&RunQ);
        swapcontext(&(temp->context), &(RunQ->context)); 
    }
    else
    {
        exit(0);
    }
}
#endif
