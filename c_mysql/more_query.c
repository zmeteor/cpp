/*************************************************************************
	> File Name: more_query.c
	> Author: 
	> Mail: 
	> Created Time: 2017年10月27日 星期五 20时18分55秒
 ************************************************************************/

//执行多条sql语句

/*********************************************
 * 在连接的时候设置CLIENT_MULTI_STATEMENTS标志
 * *******************************************/

#include<stdio.h>
#include<stdlib.h>
#include<my_global.h>
#include<mysql.h>

void my_error(MYSQL *conn)
{
    fprintf(stderr,"%s\n",mysql_error(conn));
    mysql_close(conn);
    exit(1);
}

int main()
{
    int status = 0;
    //创建一个连接句柄
    MYSQL *conn;
    conn = mysql_init(NULL);
    if(NULL == conn)
    {
        fprintf(stderr,"exec mysql_init() failed");
        exit(1);
    }

    //创建连接
    if(mysql_real_connect(conn,"127.0.0.1","root","yongheng123.",
                "testdb",0,NULL,CLIENT_MULTI_STATEMENTS) == NULL)
    {
        mysql_error(conn);
    }

    //执行多条sql语句
    if(mysql_query(conn,"select name from student where age = 19;\
                  select name from student where no = 2"))
    {
        mysql_error(conn);
    }

    //查询结果
    do
    {
 /*       
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
*/
        
        MYSQL_RES *result = mysql_store_result(conn);
        if(NULL == result)
        {
            mysql_error(conn);
        }

        MYSQL_ROW row = mysql_fetch_row(result);
        printf("%s\n",row[0]);

        
        mysql_free_result(result);
        
        status = mysql_next_result(conn);

        if(status > 0)
        {
            my_error(conn);
        }

    }while(status == 0);

    mysql_close(conn);
    return 0;
}
