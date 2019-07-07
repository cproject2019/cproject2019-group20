
#include"head.h"

int Login()//登陆账号密码
{
	fopen_s(&fp, "Users1.txt", "r");
	fscanf_s(fp, "%s%s", b.id, sizeof(b.id), b.pwd, sizeof(b.pwd));
	printf_s("Please type in your account:\n\n");
	scanf_s("%d",a.id);
	printf_s("\n");
	while (1)
	{
		if (strcmp(a.id, b.id) == 0) break;//如果找到了这个用户名
		else
		{
			if (!feof(fp))//如果文件未读完
				fscanf_s(fp, "%s%s", b.id, sizeof(b.id), b.pwd, sizeof(b.pwd));
			else
			{
				printf_s("This account doesn't exist!\n\n");
				fclose(fp);
				_getch();
				exit(0);
			}
		}
	}
	printf_s("Please type in your password:\n\n");
	scanf_s("%d",a.pwd);
	printf_s("\n");
	if (strcmp(a.pwd, b.pwd) == 0)//如果密码匹配
	{
		fclose(fp);
		printf_s("Login is successful\n\n");
		//initgraph(640, 480);
	}
	else
	{
		printf_s( "This password is not correct\n\n");
		_getch();
		exit(0);
	}
	return 0;
}
