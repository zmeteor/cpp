/*************************************************************************
	> File Name: select_db.c
	> Author: 
	> Mail: 
	> Created Time: 2017年10月27日 星期五 13时50分00秒
 ************************************************************************/

//从一个表中检索数据

/*******************
 * 初始化一个连接句柄
 * 创建一个数据库连接
 * 执行查询语句
 * 获取结果集
 * 获取结果集中的数据
 * 释放结果集
 * *****************/

#include<stdio.h>
#include<stdlib.h>
#include<my_global.h>
#include<mysql.h>

//封装出错检验函数
void my_error(MYSQL *conn)
{
    fprintf(stderr,"%s\n",mysql_error(conn));
    mysql_close(conn);
    exit(1);
}

int main()
{
    //创建一个连接句柄并初始化
    MYSQL *conn;
    conn = mysql_init(NULL);
    if(NULL == conn)
    {
        fprintf(stderr,"mysql_init() failed\n");
        exit(1);
    }

    //创建一个连接
    if(mysql_real_connect(conn,"127.0.0.1","root","yongheng123.","testdb",0,NULL,0) == NULL)
    {
        my_error(conn);
    }

    //执行查询语句
    if(mysql_query(conn,"select * from student limit 3"))
    {
        my_error(conn);
    }

    //使用mysql_store_result()或mysql_use_result()函数获得结果集，保存在MYSQL_RES结构体中
    //MYSQL_RES *result = mysql_store_result(conn);
    MYSQL_RES *result = mysql_use_result(conn);
    if(result == NULL)
    {
        my_error(conn);
    }

    //获取字段的个数
    int num_fields = mysql_num_fields(result);

    //检索表中的数据
    MYSQL_ROW row;
    MYSQL_FIELD *field;

    while((row = mysql_fetch_row(result)))
    {
        int i;
        for(i = 0; i < num_fields; i++)
        {
            if(0 == i)
            {
                while((field = mysql_fetch_field(result)))
                {
                    printf("%s ",field->name);
                }
                
                putchar(10);
            }

            printf("%s ",row[i] ? row[i] : "NULL");
        }

    }

    putchar(10);

    //释放结果集
    mysql_free_result(result);
    
    //关闭连接
    mysql_close(conn);

    return 0;
}
