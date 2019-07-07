#include"head.h"

int registers()//注册账号密码
{
	fopen_s(&fp, "Users1.txt", "r");
	fscanf_s(fp, "%s%s", b.id, sizeof(b.id), b.pwd, sizeof(b.pwd));
	//InputBox(a.id, 11, "请输入账号"); 
	printf_s("Please type in your account:\n\n");
	scanf_s("%d", a.id);
	printf_s("\n");
	while (1)
	{
		if (strcmp(a.id, b.id) != 0)//如果两串字符串不相等
		{
			if (!feof(fp))//如果未至文件末尾
			{
				fscanf_s(fp, "%s%s", b.id, sizeof(b.id), b.pwd, sizeof(b.pwd));
			}
			else break;
		}
		else
		{
			printf("This account has already been registered\n\n");
			fclose(fp);
			_getch();
			exit(0);
		}
	}
	fclose(fp);
	printf_s("Please type in your password:\n\n");
	scanf_s("%d", a.pwd);
	printf_s("\n");
	fopen_s(&fp, "Users1.txt", "a");
	fprintf_s(fp, "%s %s", a.id, a.pwd);
	printf("Register successfully！\n\n");
	fclose(fp);
	return 0;
}