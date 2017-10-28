#include"dbi_mysql.h"
#include <iostream>
using namespace std;

int main()
{
    char buf[10];
    int columns = 0;
    char sql[] = "select * from student";

    //初始化句柄
    DBI_mysql conn;

    //建立连接
    if(conn.db_connect("127.0.0.1","testdb","root","yongheng123.",0) != DBI_SUCCESS)
    {
        conn.db_get_err_msg();
    }

    //执行sql语句
    if(conn.db_execute(sql) != DBI_SUCCESS)
    {
        conn.db_get_err_msg();
    }

    //获取结果集
    if(conn.db_result() != DBI_SUCCESS)
    {
        conn.db_get_err_msg();
    }

    dbi_prepare_t conn_prepare;
    if(conn.db_prepare_sql(&conn_prepare,sql) != DBI_SUCCESS)
    {
        conn.db_get_err_msg();
    }

    if((columns = conn.db_get_outcolumns(&conn_prepare)) == DBI_ERROR)
    {
        conn.db_get_err_msg();
    }

    //遍历结果集
    while(conn.db_fetch())
    {
        int i;
        for(i = 0;i < columns;i++)
        {
            if(conn.db_get_field(i,buf,0) != DBI_SUCCESS)
            {
                conn.db_get_err_msg();
            }
            else
            {
                cout<<buf<<"  ";
            }
        }
        cout<<endl;
    }
    //释放结果集
    conn.db_free_result();
    //关闭连接
    conn.db_disconnect();

	return 0;
}

