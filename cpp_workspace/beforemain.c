/*************************************************************************
	> File Name: beforemain.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年07月09日 星期一 23时07分13秒
 ************************************************************************/
#include <stdio.h>

__attribute__((constructor)) void before_main_to_run()  
{  
    printf("Hi～,i am called before the main function!\n");
    printf("%s\n",__FUNCTION__);  
}  

__attribute((constructor)) void before_main_to_run_two()  
{  
    printf("Hi～,i am called before the main function!\n");
    printf("%s\n",__FUNCTION__);  
}  
  
__attribute__((destructor)) void after_main_to_run()  
{  
    printf("%s\n",__FUNCTION__);  
    printf("Hi～,i am called after the main function!\n");
}  
  
__attribute((destructor)) void after_main_to_run_two()  
{  
    printf("%s\n",__FUNCTION__);  
    printf("Hi～,i am called after the main function!\n");
}  

int main( int argc, char ** argv )  
{  
    printf("i am main function, and i can get my name(%s) by this way.\n",__FUNCTION__);  

    return 0;  
}  
