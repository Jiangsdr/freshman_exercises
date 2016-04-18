#include<iostream>
using namespace std;

#define Max_line 50

/*类定义*/
class Queue
{private:
    struct Node
    {
	    int data;
	    Node* next;
    }*front,*rear;
public:
	bool setNULL();//将队列初始化
	bool empty();//判断队列是否为空
	int getfirst();//将队列头部第一个元素弹出
	int enqueue();//将一个元素插入队列尾端
	bool full();//判断队列是否已满
	void clear();//将队列存储空间清空
};

bool Queue::setNULL()//将队列初始化
{
	front=rear=new Node;
	if(front==NULL)
	{
		cout<<"Queue is overflow."<<endl;
		return false;
	}
	else
	{
		front->next=NULL;
		front->data=0;
		return true;
	}
}

bool Queue::empty()//判断队列是否为空
{
	if(front==rear)
		return true;
	else
		return false;
}

int Queue::getfirst()//将队列头部第一个元素弹出
{
	if(front==rear)
		return 0;
	else
	{
		int i=front->data;
		Node*p=front->next;
		free(front);
		front=p;
		return i;
	}
}

bool Queue::full()//判断队列是否已满
{
	if(rear&&front&&rear->data-front->data>=Max_line-1)
		return true;
	else
		return false;
}

int Queue::enqueue()//将一个元素插入队列尾端
{
	Node *p=new Node;
	if(p==NULL) return 0;
	else
	{
		p->data=rear->data+1;
	    p->next=NULL;
		rear->next=p;
		rear=p;
		return rear->data;
	}
}

void Queue::clear()
{
	Node*p=front;
	for(;;)
	{
		front=front->next;
		free(p);
		p=front;
		if(p==NULL) break;
	}
}