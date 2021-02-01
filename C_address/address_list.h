/**
* @file  address_list.h
* @brief 常见类型定义
* @author  gao_shou
* @date    2021-1-31
* @version  v1.0
* @copyright 随便用
*/
#pragma once
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_NAME 20
#define MAX_SEX 10
#define MAX_PHOINE 12
#define ADD_STACK 2

enum Index_Main
{
	add =1,
	delete = 2,
	show =3,
	save =4,
	exit0 = 5
};

typedef struct address_list
{
	char name[MAX_NAME];
	char age;
	char sex[MAX_SEX];
	char phone[MAX_PHOINE];
}address_list;

typedef struct Latelog_list
{
	address_list* People_List_Date; //Address People_List_Date;
	int num;
	int Masize;
}Latelog_list;


typedef void (*address_para)(Latelog_list* People);
typedef void (*address_void)(void);
typedef struct Address_list_Ob
{
	address_void Hint;
	address_para Address_List_Init;
	address_para Input_Number;
	address_para Show_Pepol;
	address_para FreeStack;
	address_para CheckUp_stack;
	address_void Address_list_main;
	address_void SaveDataFile;
}Address_list_Ob;


void Hint(void);//打印提示信息

void Address_List_Init(Latelog_list* People);//初始化结构体

void Input_Number(Latelog_list* People);//输入的信息

void Show_Pepol(Latelog_list* People);//显示联系人

void FreeStack(Latelog_list* People);//释放stack空间（相对程序退出）

void CheckUp_stack(Latelog_list* Pe);//内存检查,

void SaveDataFile(Latelog_list* People);//保存文件到windows

void ReadDate(Latelog_list* People);//读取文件数据到buffer

void Address_list_main();//通讯录主干

extern Address_list_Ob Object_AL;
//extern int main();