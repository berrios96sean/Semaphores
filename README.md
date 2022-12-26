# Semaphores

This project uses threads to create semaphores that create a producer consumer problem with the following settings: 

There are P producers all in while loops that loop N times, each producing 1 item in one loop. 
There are C consumers all in while loops that loop N times each consuming 1 item in one loop. 
Every consumer or producer yields at the end of a loop to the next process.

Consider that the buffer size is B items.
You will be given a Queue of numbers, where positive numbers denote the producer ID and negative numbers denote consumer ID
Arrange your ready queue accordingly
Start with the first thread in the queue and run it.
At the end of each loop before yield a consumer should print the following: if consumer X is consuming an item then print
printf"\n Consumer %d is consuming item generated by Producer %d",X,Y) else print
printf("\n Consumer %d is waiting\n",X)
At the end of each loop before yield the producer should print the following:
if producer X is producing an item then print
printf("Producer %d is producing item number %d", X,Y)
else print
printf("\n Producer %d is waiting \n", X)

# Test Case

The first line of each test case file will be of the form: 

B,P,C,N

Where B is the buffer size, P is the number of producers, C is the number of consumers, and N is the number of times producers and consumers run their while loop. (Note all producers and consumers run the same number of while loop).

This line will be followed by P+C numbers (one number in each line). Each number denotes process ID. Positive numbers indicate producer process ID, while negative numbers indicate consumer process ID. 

Example test case
2,3,1,2
1
-1
2
3

Example test case output

For this particular test case we have buffer size 2, 3 producers and 1 consumer, and each producer or consumer executes their while loops 2 times.
We have two semaphores here: a) Full (for the Consumer) and b) Empty (for the Producer).

Initially the ready queue looks like the following

ReadyQ  1 -1 2 3

Our Buffer is initially empty

The Full and Empty queues remain empty

The first producer produces an item and prints

Producer 1 is producing item number 1

After this print the producer yields so the new ready queue looks like the following

ReadyQ  -1 2 3 1

Buffer  P1  __

The first consumer then executes and prints

Consumer 1 is consuming item generated by Producer 1

The ready queue now looks like the following

ReadyQ  2 3 1 -1

Buffer  __    __

The second producer then executes. 

Producer 2 is producing item number 1

Then it yields 

ReadyQ  3 1 -1 2

Buffer  P2    __

Producer 3 then executes

Producer 3 is producing item number 1

ReadyQ  1 -1 2 3
  
Buffer  P2  P3
Producer 1 then attempts to produce but the buffer is full so has to wait

Producer 1 is waiting

EmptyQ  P1

ReadyQ  -1 2 3

Consumer 1 then executes. It unblocks P1 from empty queue and hence P1 joins the end of the ready queue. It then prints: 

Consumer 1 is consuming item generated by Producer 2

After printing it exits because it is done.

EmptyQ  empty

ReadyQ  2 3 1

Buffer  P3  __

Process P2 executes

Producer 2 is producing item number 2

Then producer 2 is done so it exits
ReadyQ  3  1
Buffer  P3  P2

Producer 3 then executes but is blocked because buffer is full

Producer 3 is waiting

EmptyQ  P3

ReadyQ  1

Producer 1 then executes

Producer 1 is waiting

The Ready Q is empty so 

The program ends

SO overall output is as follows





Producer 1 is producing item number 1

 Consumer 1 is consuming item generated by Producer 1

 Producer 2 is producing item number 1

 Producer 3 is producing item number 1

 Producer 1 is waiting

 Consumer 1 is consuming item generated by Producer 2

 Producer 2 is producing item number 2

 Producer 3 is waiting

 Producer 1 is waiting
