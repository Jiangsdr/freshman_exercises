/***
*
* ����Queue��ջһ��, Ҳ��һ�ּ򵥵��������ݽṹ, ���ص���: Ԫ�ذ�˳��������, ��˳���˳�����, �Ƚ���Ԫ���ȳ�, �����Ԫ�����ڶ���β��, ��ͬ��ʳ���Ŷ���. 
* ���еĻ�������ֻ������: ����, ����. ģ�¿α���ջ��ʵ�ִ��룬ʵ�ֶ���. Ҫ��: 
* 1) ���������Queue, ������ʵ�ֶ���.
* 2) �����Ӻͳ��Ӳ�������ΪQueue��ĳ�Ա����.
* 3) ��Ա����������: ��ʼ�����к���, �ж϶����Ƿ�Ϊ�պ������ж϶����Ƿ���������.
* 4) ��д����ʹ��Queue��, ģ��ʳ�ø߷����Ŷ��򷹹���: �����ٶȳ��������ٶ�, ��������������ĳ����ֵ, ����!
*
***/

#pragma once

#include <iostream>
#include <cstdlib>
#include<string>
#include<fstream>

#define QUEUE_SIZE 50	//���е����ߴ�

using namespace std;

template<class T>
class Queue
{
public:
	Queue() { head = rear = NULL; size = 0; }//���캯��

	bool enQueue(T i);		//����
	bool deQueue(T &i);	//����

	bool isEmpty(void) const		//�ж϶����Ƿ�Ϊ��
	{ return size ==  0; }
	bool isFull(void) const			//�ж϶����Ƿ�����
	{ return size == QUEUE_SIZE; }

	void output(void);		//�������
	Queue(const Queue&);//�������캯��
	~Queue();//��������
private:
	struct node{
		T val;
		node *next;
	}*head, *rear;	//������βԪ��ָ��

	int size;		//���д�С
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