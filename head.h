#include<stdio.h>
#include<stdlib.h>
#include"acllib.h"
#include<time.h>//���������ʱ���޹�

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
}sprite;//����һ��ָ��ʹ���ֶ����������,bill�ĸ��������ֵ

typedef struct The_users //���ڴ����û��˺�����
{
	char id[11];//ID
	char pwd[20];//password
}users;
users a, b;//��Ա����,������½��ע��

FILE *fp;
FILE *fp1;