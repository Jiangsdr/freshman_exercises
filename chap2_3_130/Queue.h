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

#define QUEUE_SIZE 50	//���е����ߴ�

using namespace std;

class Queue
{
public:
	Queue() { head = rear = NULL; size = 0; }//���캯��

	bool enQueue(int i);		//����
	bool deQueue(int &i);	//����

	bool isEmpty(void) const		//�ж϶����Ƿ�Ϊ��
	{ return size ==  0; }
	bool isFull(void) const			//�ж϶����Ƿ�����
	{ return size == QUEUE_SIZE; }

	void output(void);		//�������
	Queue(const Queue&);//�������캯��
	~Queue();//��������
private:
	struct node{
		int val;
		node *next;
	}*head, *rear;	//������βԪ��ָ��

	int size;		//���д�С
};
