/*************************************************************************
	> File Name: connect.c
	> Author: 
	> Mail: 
	> Created Time: 2017年10月25日 星期三 19时50分49秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<mysql/include/mysql.h>

int main()
{
    MYSQL sql;
    mysql_init(&sql);

    printf("Mysql client version :%lu\n",mysql_get_client_version());
    if(!mysql_real_connect(&sql,"127.0.0.1","root","yongheng123.",NULL,0,NULL,0))
    {
        puts("Error connecting");
        printf("%s\n",mysql_error(&sql));
    }
    else
    {
        puts("success connecting");
    }
    return 0;
}
