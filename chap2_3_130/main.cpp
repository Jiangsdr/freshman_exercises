#include "Queue.h"

int main()
{
	int cur_time, en_time, de_time;		//��ǰʱ��, ����ʱ��, ����ʱ��
	const int en_t = 8;	//����ƽ��ÿ8����һ�˽���
	const int de_t = 25;	//����ƽ��ÿ25����һ�˳���

	Queue q;

	int tmp, i, j;
	cur_time = 0;	//���ڿ�ʼ����	
	en_time = 0;	//��һλ�򷹵����ѵ��ﴰ��
	de_time = de_t;	//25����һλ��÷����˽��뿪����
	i = j = 0;	//i, j�ֱ��¼���������ͳ�������

	cout << "\t\t" << "ʳ��ĳ�����ڸ߷��ڵ��Ŷ�״��ģ��:"<< endl;
	while(!q.isFull()){
		if(cur_time == en_time){
			q.enQueue(en_time);
			cout << en_time << "s: " << "��" << ++i << "�˽���" << endl;
			en_time += en_t;		//��һ�ν���ʱ��
		}
		if(cur_time == de_time){
			q.deQueue(tmp);
			cout << "\t\t" << de_time << "s: " << "��" << ++j << "�˳���" << endl;
			de_time += de_t;		//��һ�γ���ʱ��
		}
		cur_time++;	//ʱ��һ��������...
	}

	cout << "\t\t" << "�ô����Ŷ������Ѵﵽ"<< QUEUE_SIZE <<"��! �����!" << endl;

	cout<<"���������н�һ���¶��У��¶��м�¼�Ľ���ʱ������"<<endl;
	Queue p(q);
	p.output();

	getchar();
	getchar();

	return 0;
}
