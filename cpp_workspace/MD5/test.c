/*************************************************************************
	> File Name: test.c
	> Author: 
	> Mail: 
	> Created Time: 2018年07月20日 星期五 14时33分05秒
 ************************************************************************/
//检测MD5的32位加密

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "md5.h"
#include "md5.c"
 
int main(void)
{
	MD5_CTX md5;

	int i;
	unsigned char clearPasswd[] ="admin";
	unsigned char ciphertext[16];    

	MD5Init(&md5);         
	MD5Update(&md5,clearPasswd,strlen((char *)clearPasswd));
	MD5Final(&md5,ciphertext);        

	printf("加密前:%s\n",clearPasswd);

    printf("加密后: ");
	for(i = 0 ; i < 16;i++)
	{
		printf("%02x",ciphertext[i]);
	}
 
    putchar(10);

	return 0;
}

