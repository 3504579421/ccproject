#define _CRT_SECURE_NO_WARNINGS 1
 //game����������Ϸ
//��ϷҪ�󣺵����Զ�����1-100�������
//��Ҳ����֣������ֵĹ����У����ݲ²����ݵĴ�С�������˻���С�˵ķ�������Ϸ����

//������������������
//α��������룺rand  int rand (void);
//�˺�����ʹ����Ҫ����ͷ�ļ� stdlib.h
//========================================================
//������Σ�������������:
//#include <stdio.h>
//#include <stdlib.h>
//int main()
//{
//	printf("%d\n", rand());
//	printf("%d\n", rand());
//	printf("%d\n", rand());
//	printf("%d\n", rand());
//	printf("%d\n", rand());
//	//�����м��λ���ͬ���������
//	return 0;
//}
//===========================================================
//srand���� ������ʼ��������������ģ�void srand (unsigned int seed);
//time����  ������ȡʱ�䣺time_t time (time_t* timer);
//�ɴ˸�д ����������Ĵ��룺
//#include <stdio.h>
//#include <stdlib.h>
//#include <time.h>
//
//int main()
//{
//	//ʹ��time�����ķ���ֵ��������
//	//��Ϊsrand�Ĳ�����unsigned int���ͣ����ǽ�time�����ķ���ֵǹ֧����ת��
//	srand((unsigned int)time(NULL));
//	printf("%d\n", rand());
//	printf("%d\n", rand());
//	printf("%d\n", rand());
//	printf("%d\n", rand());
//	printf("%d\n", rand());
//	//�����м��λ���ͬ���������
//	return 0;
//}
//���ǻ�д ����������󣬽�����������������ķ�Χ
//�������Ҫ����0-99֮������������������:
//rand() % 100;//������Χ��0-99
//�������Ҫ����1-100֮�����������������£�
//rand()%100+1;
//�������Ҫ����100-200֮�����������������£�
// 100+rand()%(200-100+1) //������Χ��10100����100�����100-200
//�������Ҫ����a-b����������������£�
//a+rand()%(b-a+1)

//2.��������Ϸʵ��
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
		printf("\n�㻹��%d�λ���\n");
		count--;
		printf("������> :");
		scanf("%d", &guess);
		if (guess < r)
		{
			printf("��С��\n");
		}
		else if (guess > r)
		{
			printf("�´���\n");
		}
		else
		{
			printf("��ϲ�㣬�¶���\n");
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
		printf("��ѡ��>");
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
			printf("ѡ���������ѡ��\n");
			break;
		}
	} while (input);
	return 0;
}