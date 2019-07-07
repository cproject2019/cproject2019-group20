#include<stdio.h>
#include<stdlib.h>
#include"acllib.h"
#include<time.h>//令随机数与时间无关

//singature of function
int imageLoading();
int paint();
int timerCancel();
int timerStart();
int timerEvent(int);
int keyEvent(int, int);
int mouseEvent(int, int, int, int);
int collison(rect, rect);
int scoreSort();
int Login();
int registers();

#pragma once
typedef struct rect
{
	int x, y;
	int w, h;

}rect;

typedef struct sprite
{
	int x, y;
	int width, height;
	int dx, dy;
}sprite;//建立一个指针使出现多个，即数组,bill的个数的最大值

typedef struct The_users //用于储存用户账号密码
{
	char id[11];//ID
	char pwd[20];//password
}users;
users a, b;//成员变量,用来登陆与注册

FILE *fp;
FILE *fp1;