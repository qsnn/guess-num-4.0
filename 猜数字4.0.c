#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<windows.h>
#include<mmsystem.h>
#include"resource.h"
#define WAVE_RESOURCE_ID IDR_WAVE1  
// 链接到Windows多媒体库  
#pragma comment(lib, "winmm.lib")  
int menu();
int upgrade();
int game();
int punish();
int qsnnnb();
//主入口
int main()
{
	printf("正在初始化游戏");
	for (int i = 1; i <= 6; i++)
	{
		Sleep(250);
		printf(".");
	}
	Sleep(2000); 
	printf("\nMusic已就绪！");
	Sleep(800);
	PlaySound(MAKEINTRESOURCE(IDR_WAVE1), NULL, SND_RESOURCE | SND_ASYNC);
	Sleep(2000);
	menu();
	return 0;
}
//函数们
int menu()
{
	system("cls");
	printf("版权所有：qsnn\n版本：4.0\n");
	for (int i = 1; i <= 100; i++)
	{
		printf("*");
	}
	printf("\n");
	for (int i = 1; i <= 42; i++)
	{
		printf("*");
	}
	printf("   猜数字游戏   ");
	for (int i = 1; i <= 42; i++)
	{
		printf("*");
	}
	printf("\n");
	for (int i = 1; i <= 100; i++)
	{
		printf("*");
	}
	printf("\n请输入数字1或2来确定游戏是否要开始:\n");
	printf("数字1 *> 开始\n");
	printf("数字2 *> 结束\n");
	printf("数字3 *> 查看更新日志\n");
	printf(" *>");
	char choose1[100];
	scanf("%s", &choose1);
	if (strcmp(choose1, "1") == 0)
	{
		game();
	}
	else if (strcmp(choose1, "2") == 0)
	{
		printf("\n真遗憾,后面有彩蛋呢\n");
		system("pause");
	}
	else if (strcmp(choose1, "3") == 0)
	{
		system("cls");
		upgrade();
		system("pause");
		menu();
	}
	else
	{
		printf("别给我乱输\n1秒后重来！");
		Sleep(1000);
		menu();
	}
}
int upgrade()
{
	printf("1.1：优化循环结构。\n");
	printf("2.0：全新版本，全新界面，全新功能！增加彩蛋！\n");
	printf("2.1：修复了一些BUG。\n");
	printf("3.0：代码优化，减小内存占用，功能优化\n");
	printf("3.1：修复了因输入字符串而导致缓存区故障的问题。\n");
	printf("4.0：加入sao好听的背景音乐；优化了代码结构。\n");
}
int game()
{
	srand(time(NULL));
	int num = rand() % 100 + 1;
	int score = 0;
	printf("游戏开始\n游戏规则介绍:  你有八次输入机会来猜0~100的幸运数字。\n请开始你的表演：");
	for (int i = 1; i <= 8; i++)
	{
		int num1;
		scanf("%d", &num1);
		if (num1 == num)
		{
			printf("恭喜你答对了！\n");
			score++;
			break;
		}
		else if (num1 >= num)
		{
			printf("高了！\n你还有%d次机会\n", 8 - i);
		}
		else
		{
			printf("低了！\n你还有%d次机会\n", 8 - i);
		}
	}
	if (score == 1)
	{
		printf("恭喜你通关！\n");
		system("pause");
	}
	else if (score == 0)
	{
		punish();
	}
}
int punish()
{
	system("cls");
	printf("非常遗憾，您没能猜对数字\n");
	printf("接下来您有两个选择:\n");
	printf("重新进行游戏：>* 1\n");
	printf("结束游戏：>* 2\n");
	char choose2[100];
	scanf("%s", &choose2);
	if (strcmp(choose2, "1") == 0)
	{
		system("cls");
		printf("鉴于你上把错了\n给你个小小的惩罚！！！\n过关后即可进行下一把\n");
		system("shutdown -s -t 60");
		printf("电脑将在60秒后关机！\n输入你的真心话即可解除惩罚（提示：qsnnnb）\n请输入:______\n");
		qsnnnb();
		menu();
	}
	else if (strcmp(choose2, "2") == 0)
	{
		printf("非常遗憾告诉您,由于您没有坚持进行游戏，您的电脑将在一分钟后关机\n但是，还有补救办法\n输入你的真心话即可解除惩罚（提示：qsnnnb）\n请输入:_______\n");
		system("shutdown -s -t 60");
		qsnnnb();
	}
	else
	{
		printf("别给我乱搞！\n重来！");
		Sleep(1000);
		punish();
	}
}
int qsnnnb()
{
	char qsnnnb[] = "qsnnnb";
	char nb[100];
	scanf("%99s", &nb);
	int result;
	result = strcmp(nb, qsnnnb);
	if (result == 0)
	{
		printf("我猜你已经被吓出一身汗了吧！\n惩罚解除！\n");
		system("shutdown -a");
	}
	else
	{
		printf("一点都不诚实！\n惩罚提前！\n");
		system("shutdown -a");
		system("shutdown -s -t 5");
		system("pause");
	}
}