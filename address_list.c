#define _CRT_SECURE_NO_WARNINGS 1
#include "address_list.h"

/**
 * 提示功能函数
 * @param[in]   void  文件名长度
 * @return      void
 * @ref         address_list.c
 * @see
 * @note
 */
void Hint(void)
{
	printf("---------------------\n");
	printf("1,add--------2,delete\n");
	printf("3,show-------4,save \n");
	printf("5,exit,\n");
}

/**
 * 初始化结构体
 * @param[in]   People  通讯录结构体
 * @return      void	
 * @ref         address_list.c
 * @see
 * @note
 */
void Address_List_Init(Latelog_list * People)
{
	People->People_List_Date = (address_list*)malloc(sizeof(address_list)* ADD_STACK);//动态分配内存空间
	People->num = 0;//记录当前的用户数
	People->Masize = ADD_STACK;//堆栈大小记录参数
	ReadDate(People);
}

/**
 * 堆栈大小检查
 * @param[in]   People  通讯录结构体
 * @return      void
 * @ref         address_list.c
 * @see
 * @note
 */
void CheckUp_stack(Latelog_list* Pe)
{
	address_list* temp = NULL;//在此定义一个临时变量，防止程序野指针！but realloc创建可能返回的是一个NULL
	if (Pe->num == Pe->Masize)
	{
		temp = (address_list*)realloc(Pe->People_List_Date,(Pe->Masize+ ADD_STACK)*sizeof(address_list));//每次开辟两个人的存储空间
		if (temp != NULL)//内存开辟成功
		{
			Pe->People_List_Date = temp;
			Pe->Masize += ADD_STACK;
			printf("stact Succeed\n");//提示内存创建成功
		}
		else
		{
			printf("stack err\n");
			return 0;
		}
	}
}

/**
 * 信息输入函数
 * @param[in]   People  通讯录结构体
 * @return      void
 * @ref         address_list.c
 * @see
 * @note
 */
void Input_Number(Latelog_list* Pe)
{
	CheckUp_stack(Pe);//检查内存是否满了
	printf("input the name: ");
	scanf("%s", Pe->People_List_Date[Pe->num].name);
	printf("input the age: ");
	scanf("%c", &Pe->People_List_Date[Pe->num].age);
	printf("input the sex :");
	scanf("%s", Pe->People_List_Date[Pe->num].sex);
	printf("input the phone:");
	scanf("%s", Pe->People_List_Date[Pe->num].phone);
	Pe->num++;
	printf("List is Succeed\n");
}

/**
 * 显示通讯录对象
 * @param[in]   People  通讯录结构体
 * @return      void
 * @ref         address_list.c
 * @see
 * @note
 */
void Show_Pepol(Latelog_list* People)
{
	int i = 0;
	if (People->num == 0)
		printf("Address book is empty\n");
	else
	{
		printf("%-20s\t%-4s\t%-5s\t%-12s\t\n","name","age","sex","phone");
		for (i = 0; i <People->num; i++)
		{
			printf("%-20s\t%-4d\t%-5s\t%-12s\t\n",//就是一个printf
				People->People_List_Date[i].name,
				People->People_List_Date[i].age,
				People->People_List_Date[i].sex,
				People->People_List_Date[i].phone
			);
		}
	}
}


/**
 * 通讯录数据保存>>windows file
 * @param[in]   People  通讯录结构体
 * @return      void
 * @ref         address_list.c
 * @see
 * @note
 */
void SaveDataFile(Latelog_list* People)
{
	int i = 0;
	FILE* pf = fopen("Latelog_list.txt","wb");
	if (pf != NULL)
	{
		for (i = 0; i < People->num; i++)
		{
			fwrite(&People->People_List_Date[i], sizeof(address_list), 1, pf);
		}
		printf("save Succeed in file \n");
		fclose(pf);
		pf = NULL;
	}
	else
	{
		printf("open this file err\n");
	}
}

/**
 * windows file 读取到通讯录中
 * @param[in]   People  通讯录结构体
 * @return      void
 * @ref         address_list.c
 * @see
 * @note
 */
void ReadDate(Latelog_list* People)
{
	address_list temp = {0};
	FILE* pf = fopen("Latelog_list.txt", "rb");
	if (pf != NULL)
	{	/* see this 原文的API讲解吧,说的比我清楚
		fread returns the number of full items actually read,
		which may be less than count if an error occurs or if the end of the file is encountered before reaching count.
		Use the feof or ferror function to distinguish a read error from an end-of-file condition. If size or count is 0, 
		fread returns 0 and the buffer contents are unchanged.
		*/
		while (fread(&temp, sizeof(address_list), 1, pf))
		{
			/*程序刚开始只在堆中开辟了两个address_list[]*/
			CheckUp_stack(People);
			People->People_List_Date[People->num] = temp;//???没理解>>>>普通变量
			People->num++;
		}
	}
	fclose(pf);
	pf = NULL;

}



/**
 * 通讯录函数释放指针
 * @param[in]   People  通讯录结构体
 * @return      void
 * @ref         address_list.c
 * @see
 * @note
 */
void FreeStack(Latelog_list* People)
{
	free(People->People_List_Date);
	People->People_List_Date = NULL;
}

/**
 * 通讯录主框架函数
 * @param[in]   void  通讯录结构体
 * @return      void
 * @ref         address_list.c
 * @see
 * @note
 */
void Address_list_main(void)
{
	int coust = 0;
	Latelog_list People_List;
	Address_List_Init(&People_List);//初始化结构体

	do
	{
		Hint();//提示操作
		printf("input num :");
		scanf("%d", &coust);
		switch (coust)
		{
		case add:
			Input_Number(&People_List);
			break;
		case delete:
			break;
		case show:
			Show_Pepol(&People_List);
			break;
		case save:
			SaveDataFile(&People_List);
			break;
		case exit0:
			FreeStack(&People_List);
			return;
			break;
		default:
			printf("Fail\n");
		}
	} while (1);
}


Address_list_Ob Object_AL =
{
 Hint,
 Address_List_Init,
 Input_Number,
 Show_Pepol,
 FreeStack,
 CheckUp_stack,
 Address_list_main,
 SaveDataFile
};


/*
* 错误总结：
* 第一:使用了未初始化的值 ,						>>>>>>>>程序崩溃
* 第二:初始化输出出错，整形的数 用%s输出！！！	>>>>>>>>程序崩溃
* 第三:
	形式参数:Latelog_list* Pe
	接受参数:Latelog_list* Pe = &Pe
	&Pe是参数本身存储的地址，Pe是一个指向动态内存分配的地址 >>>程序崩溃
*/
