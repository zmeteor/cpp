/*************************************************************************
	> File Name: count_word.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年04月16日 星期一 16时49分07秒
 ************************************************************************/

//统计一篇文章中的英文单词出现的频率

#include <iostream>
#include <sstream>
#include <fstream>
#include "unordered_map"
#include "string"

using namespace std;

void count_word(unordered_map<string , int> &wmap , stringstream &ss);  //频率统计
void print_map(unordered_map<string , int> wamp);   //结果输出
int main()
{
    /*读取文件*/
    string wfile ,tmp;
    ifstream fp("file.txt");
    if(!fp)
    {
        cout<<"open file failed"<<endl;
    }

    while(getline(fp,tmp))
    {
        wfile.append(tmp);
        tmp.clear();
    }

    /*去除特殊符号，；等转化为空格*/
    string::iterator it;
    for(it = wfile.begin() ; it != wfile.end() ; it++ )
    {
        if(ispunct(*it)) //ispunct函数判断字符数字回车就返回true，else false
        {
            *it = ' ';
        }
    }

    /*转换为流输入*/
    //借助字符串流输入，一个一个处理单词，遇到空格读入下一个单词
    //stringstram 类实例化的对象正好可以以流的方式读出或读入一个单词，直到句子结束
    stringstream ss(wfile);

    /*统计频率*/
    //存储结果,使用unordered_map 查询和插入时间复杂度为O（1）；基于hash实现
    unordered_map<string , int> wmap;  
    count_word(wmap , ss);

    print_map(wmap);

    return 0;
}

void count_word(unordered_map<string , int> &wmap , stringstream &ss)
{
    string temp;
    unordered_map<string , int>::iterator it;
    while(ss >> temp)
    {
        it = wmap.find(temp);
        if(it == wmap.end()) //第一次出现，将其添加进map，出现次数置1
        {
            wmap.insert(make_pair(temp , 1));
        }
        else //重复出现，次数直接++
        {
            wmap[temp]++;
        }
    }
}
void print_map(unordered_map<string , int> wamp)
{
    unordered_map<string , int>::iterator it;
    for(it = wamp.begin() ; it != wamp.end() ;it++)
    {
        cout<<"word: "<<it->first<<"\tcount: "<<it->second<<endl;
    }
}

