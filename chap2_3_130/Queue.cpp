#include "Queue.h"

bool Queue::enQueue(int i)
{
	node *p = new node;
	if (p == NULL || isFull()) {
	    cout << "Queue is full.\n";
	   return false;
	} else {	
	    p->val = i;
		p->next = NULL;
		if(isEmpty())
			head = p;
		else
			rear->next = p;	
	    rear = p;
		size++;
	    return true;
	}
}

bool Queue::deQueue(int &i)
{
	if (isEmpty()) {
	    cout << "Queue is empty.\n";
	    return false;
	} else	{	
	    node *p = head;
	    head = head->next;
	    i = p->val;
	    delete p;
		size--;
	    return true;
	}
}

void Queue::output(void)
{
	node *p;
	for(p = head; p; p = p->next)
		cout << p->val << endl;
}

Queue::Queue(const Queue&A)
{
	head=rear=new node;
	head->val=A.head->val;
	node*p;node*q=A.head->next;
	while(q!=NULL)
	{
		p=new node;
		p->val=q->val;
		p->next=NULL;
		size++;
		rear->next=p;
		rear=p;
		q=q->next;
	}
	size=A.size;
}

Queue::~Queue()
{
	node*p=head;
	for(;;)
	{
		head=head->next;
		free(p);
		size--;
		p=head;
		if(p==NULL) break;
	}
}
