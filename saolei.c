#define _CRT_SECURE_NO_WARNINGS 1
 //game：猜数字游戏
//游戏要求：电脑自动生成1-100的随机数
//玩家猜数字，猜数字的过程中，根据猜测数据的大小给出大了或者小了的反馈，游戏结束

//首先完成随机数的生成
//伪随机数代码：rand  int rand (void);
//此函数的使用需要包含头文件 stdlib.h
//========================================================
//调用五次，产生五个随机数:
//#include <stdio.h>
//#include <stdlib.h>
//int main()
//{
//	printf("%d\n", rand());
//	printf("%d\n", rand());
//	printf("%d\n", rand());
//	printf("%d\n", rand());
//	printf("%d\n", rand());
//	//多运行几次还是同样的随机数
//	return 0;
//}
//===========================================================
//srand函数 用来初始化随机数生成器的：void srand (unsigned int seed);
//time函数  用来获取时间：time_t time (time_t* timer);
//由此改写 生成随机数的代码：
//#include <stdio.h>
//#include <stdlib.h>
//#include <time.h>
//
//int main()
//{
//	//使用time函数的返回值设置种子
//	//因为srand的参数是unsigned int类型，我们将time函数的返回值枪支类型转换
//	srand((unsigned int)time(NULL));
//	printf("%d\n", rand());
//	printf("%d\n", rand());
//	printf("%d\n", rand());
//	printf("%d\n", rand());
//	printf("%d\n", rand());
//	//多运行几次还是同样的随机数
//	return 0;
//}
//我们会写 生成随机数后，接着设置生成随机数的范围
//如果我们要生成0-99之间的随机数，方法如下:
//rand() % 100;//余数范围是0-99
//如果我们要生成1-100之间的随机数，方法如下：
//rand()%100+1;
//如果我们要生成100-200之间的随机数，方法如下：
// 100+rand()%(200-100+1) //余数范围是10100，加100后就是100-200
//如果我们要生成a-b的随机数，方法如下：
//a+rand()%(b-a+1)

//2.猜数字游戏实现
#include<stdio.h>
#include <stdlib.h>
#include <time.h>

void game()
{
	int r = rand() % 100 + 1;
	int guess = 0;
	int count = 5;
	while (1)
	{
		printf("\n你还有%d次机会\n");
		count--;
		printf("猜数字> :");
		scanf("%d", &guess);
		if (guess < r)
		{
			printf("猜小了\n");
		}
		else if (guess > r)
		{
			printf("猜大了\n");
		}
		else
		{
			printf("恭喜你，猜对了\n");
			break;
		}
	}
}

void menu()
{
	printf("=================================\n");
	printf("============== 1.play ===========\n");
	printf("============== 2.exit ===========\n");
	printf("=================================\n");
}

int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("请选择：>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("game over!\n");
			break;
		default:
			printf("选择错误，重新选择\n");
			break;
		}
	} while (input);
	return 0;
}