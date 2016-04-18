#include "Queue.h"

int main()
{
	int cur_time, en_time, de_time;		//当前时间, 进队时间, 出队时间
	const int en_t = 8;	//假设平均每8秒有一人进队
	const int de_t = 25;	//假设平均每25秒有一人出队

	Queue q;

	int tmp, i, j;
	cur_time = 0;	//窗口开始卖饭	
	en_time = 0;	//第一位买饭的人已到达窗口
	de_time = de_t;	//25秒后第一位买好饭的人将离开窗口
	i = j = 0;	//i, j分别记录进队人数和出队人数

	cout << "\t\t" << "食堂某个窗口高峰期的排队状况模拟:"<< endl;
	while(!q.isFull()){
		if(cur_time == en_time){
			q.enQueue(en_time);
			cout << en_time << "s: " << "第" << ++i << "人进队" << endl;
			en_time += en_t;		//下一次进队时间
		}
		if(cur_time == de_time){
			q.deQueue(tmp);
			cout << "\t\t" << de_time << "s: " << "第" << ++j << "人出队" << endl;
			de_time += de_t;		//下一次出队时间
		}
		cur_time++;	//时间一秒秒流逝...
	}

	cout << "\t\t" << "该窗口排队人数已达到"<< QUEUE_SIZE <<"人! 请分流!" << endl;

	cout<<"按上述队列建一个新队列，新队列记录的进队时间如下"<<endl;
	Queue p(q);
	p.output();

	getchar();
	getchar();

	return 0;
}
