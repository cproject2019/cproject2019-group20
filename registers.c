#include"head.h"

int registers()//ע���˺�����
{
	fopen_s(&fp, "Users1.txt", "r");
	fscanf_s(fp, "%s%s", b.id, sizeof(b.id), b.pwd, sizeof(b.pwd));
	//InputBox(a.id, 11, "�������˺�"); 
	printf_s("Please type in your account:\n\n");
	scanf_s("%d", a.id);
	printf_s("\n");
	while (1)
	{
		if (strcmp(a.id, b.id) != 0)//��������ַ��������
		{
			if (!feof(fp))//���δ���ļ�ĩβ
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
	printf("Register successfully��\n\n");
	fclose(fp);
	return 0;
}