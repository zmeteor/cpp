/*************************************************************************
	> File Name: create_db.c
	> Author: 
	> Mail: 
	> Created Time: 2017年10月27日 星期五 13时11分28秒
 ************************************************************************/

//创建一个数据库

/****************
 * 初始化一个句柄
 * 创建一个连接
 * 执行sql语句
 *关闭连接
*****************/

#include<stdio.h>
#include<stdlib.h>
#include<mysql.h>
#include<my_global.h>

int main()
{
    //查看MYSQL客户端的版本号
    printf("mysql client version: %s\n",mysql_get_client_info());

    //初始化一个连接句柄
    MYSQL *conn = mysql_init(NULL);
    if(NULL == conn)
    {
        fprintf(stderr,"%s\n",mysql_error(conn));
        exit(1);
    }

    //创建一个连接
    if((mysql_real_connect(conn,"127.0.0.1","root","yongheng123.",NULL,0,NULL,0)) == NULL)
    {
        fprintf(stderr,"Error to connecting to db: %s",mysql_error(conn));
        mysql_close(conn);
        exit(1);
    }

    //执行sql语句
    if(mysql_query(conn,"CREATE DATABASE testdb"))
    {
        fprintf(stderr,"Error when exec mysql statment: %s",mysql_error(conn));
        mysql_close(conn);
        exit(1);
    }

    //关闭连接
    mysql_close(conn);


    return 0;
}

