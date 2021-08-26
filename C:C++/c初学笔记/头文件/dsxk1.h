#ifndef _STUDENT_H_
#define _STUDENT_H_


int STR_LEN = 20;

typedef struct _student {
	char name[sizeof STR_LEN];
	int gender;
	int age;
}Student;
#endif