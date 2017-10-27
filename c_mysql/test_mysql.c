/*************************************************************************
	> File Name: mysql.c
	> Author: 
	> Mail: 
	> Created Time: 2017年10月25日 星期三 23时59分37秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<mysql/include/mysql.h>

int main()
{
    MYSQL *conn;
    MYSQL_RES *res;
    MYSQL_ROW row;
    char *server = "127.0.0.1";
    char *user = "root";
    char *password = "yongheng123.";
    char *database = "mysql";
    char *query = "select Host,User,Password from user";

    int t,r;
    conn = mysql_init(NULL);
    if(!mysql_real_connect(conn,server,user,password,database,0,NULL,0))
    {
        printf("Error connecting to database:%s\n",mysql_error(conn));
    }
    else
    {
        printf("Connected....\n");
    }

    t = mysql_query(conn,query);
    if(t)
    {
        printf("Error making query:%s\n",mysql_error(conn));
    }
    else
    {
        printf("query mading..\n");
    }
    res = mysql_use_result(conn);
    if(res)
    {
        for(r = 0;r <= mysql_field_count(conn);r++)
        {
            row = mysql_fetch_row(res);
            if(row < 0)
            {
                break;
            }
        }
        for(t = 0;t < mysql_num_fields(res);t++)
        {
            printf("%s\n",row[t]);
        }
    }
    mysql_close(conn);
    return 0;
}
