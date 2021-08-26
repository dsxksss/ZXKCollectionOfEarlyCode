#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include"dsxk1.h"

//#ifndef _STUDENT_H_
//#define _STUDENT_H_
//
//
//int STR_LEN = 20;
//
//typedef struct _student {
//	char name[sizeof STR_LEN];
//	int gender;
//	int age;
//}Student;
//#endif

void getList(Student aStu[], int number);
int save(Student aStu[], int number);

int main66(int argc,char const *argv[])
{
	int number = 0;
	printf("输入学生数量：");
	scanf_s("%d", &number);
	Student aStu[sizeof number];

	getList(aStu, number);
	if(save(aStu,number))
	{
		printf("保存成功\n");
	}
	else
	{
		printf("保存失败\n");
	}
	return 0;
}

void getList(Student aStu[],int number)
{
	char format[sizeof STR_LEN];
	sprintf(format, "%%%ds", sizeof STR_LEN - 1);

	int i;
	for(i=0;i<number;i++)
	{
		printf("第%d个学生：\n", i);
		printf("\t姓名：");
		scanf_s(format,aStu[i].name[20]);
		printf("\t性别(0-男，1-女，2-其他)：");
		scanf_s("%d", &aStu[i].gender);
		printf("\t年龄：");
		scanf_s("%d", &aStu[i].age);
	}
}

int save(Student aStu[], int number)
{
	int ret = -1;
	FILE* fp = fopen("student.data", "w");
	if (fp) {
		ret = fwrite(aStu, sizeof(Student), number, fp);
		fclose(fp);
	}
	return ret == number;
}