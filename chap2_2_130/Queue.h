#include<iostream>
using namespace std;

#define Max_line 50

/*�ඨ��*/
class Queue
{private:
    struct Node
    {
	    int data;
	    Node* next;
    }*front,*rear;
public:
	bool setNULL();//�����г�ʼ��
	bool empty();//�ж϶����Ƿ�Ϊ��
	int getfirst();//������ͷ����һ��Ԫ�ص���
	int enqueue();//��һ��Ԫ�ز������β��
	bool full();//�ж϶����Ƿ�����
	void clear();//�����д洢�ռ����
};

bool Queue::setNULL()//�����г�ʼ��
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

bool Queue::empty()//�ж϶����Ƿ�Ϊ��
{
	if(front==rear)
		return true;
	else
		return false;
}

int Queue::getfirst()//������ͷ����һ��Ԫ�ص���
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

bool Queue::full()//�ж϶����Ƿ�����
{
	if(rear&&front&&rear->data-front->data>=Max_line-1)
		return true;
	else
		return false;
}

int Queue::enqueue()//��һ��Ԫ�ز������β��
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