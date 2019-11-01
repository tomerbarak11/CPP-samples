#include "mu_test.h"
#include "QueueTemplate.h"
#include <iostream>
#include <stdio.h>
#include <cassert>

UNIT(constructors)
	TemplateQueue <int> queue;
			queue.trace();

	ASSERT_THAT(queue.isEmpty());
	ASSERT_THAT(queue.isFull()==false);
	ASSERT_THAT(queue.size()==0);
	ASSERT_THAT(queue.capacity()==g_DEFAULT_QUEUE_SIZE);

END_UNIT

UNIT(enqueue_dequeue_print_trace)
	TemplateQueue <int> queue;
	for(int i=0;i<3;i++)
	{
		queue.enqueue(i);	
	}
	ASSERT_THAT(queue.size()==3);
	queue.print();
	std::cout<<"\n";
	queue.trace();
	int item;
	for(int i=0;i<3;i++)
	{
		queue.dequeue(item);	
	}
	ASSERT_THAT(queue.size()==0);
END_UNIT

TEST_SUITE(Stack [fixed size] of ints)
	TEST(constructors)
	TEST(enqueue_dequeue_print_trace)
END_SUITE
