/***
*
* 队列Queue与栈一样, 也是一种简单的线性数据结构, 其特点是: 元素按顺序进入队列, 按顺序退出队列, 先进的元素先出, 后进的元素排在队列尾部, 如同在食堂排队买饭. 
* 队列的基本操作只有两个: 进队, 出队. 模仿课本上栈的实现代码，实现队列. 要求: 
* 1) 定义队列类Queue, 用链表实现队列.
* 2) 将进队和出队操作定义为Queue类的成员函数.
* 3) 成员函数还包括: 初始化队列函数, 判断队列是否为空函数，判断队列是否已满函数.
* 4) 编写程序使用Queue类, 模拟食堂高峰期排队买饭过程: 进队速度超过出队速度, 当队列人数超出某个阈值, 报警!
*
***/

#pragma once

#include <iostream>
#include <cstdlib>
#include<string>
#include<fstream>

#define QUEUE_SIZE 50	//队列的最大尺寸

using namespace std;

template<class T>
class Queue
{
public:
	Queue() { head = rear = NULL; size = 0; }//构造函数

	bool enQueue(T i);		//进队
	bool deQueue(T &i);	//出队

	bool isEmpty(void) const		//判断队列是否为空
	{ return size ==  0; }
	bool isFull(void) const			//判断队列是否已满
	{ return size == QUEUE_SIZE; }

	void output(void);		//输出队列
	Queue(const Queue&);//拷贝构造函数
	~Queue();//析构函数
private:
	struct node{
		T val;
		node *next;
	}*head, *rear;	//队列首尾元素指针

	int size;		//队列大小
};

template<class T>
bool Queue<T>::enQueue(T i)
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

template<class T>
bool Queue<T>::deQueue(T &i)
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

template<class T>
void Queue<T>::output(void)
{
	node *p;
	for(p = head; p; p = p->next)
		cout << p->val << endl;
}

template<class T>
Queue<T>::Queue(const Queue&A)
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

template<class T>
Queue<T>::~Queue()
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