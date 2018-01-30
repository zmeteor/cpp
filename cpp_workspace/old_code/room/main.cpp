#include<iostream>
#include<iomanip>
#include<fstream>
using namespace std;
#include<string.h>
#include<stdlib.h>
#include"room.h"
int N;

void Menu();


int main()
{
    Room S;

    system("color 9");
	Menu();
	do
	{
	    cout<<endl;
		cout<<"输入选项";
		int choose;
		cin>>choose;
		switch(choose)
		{
		case 1: S.Set();break;
		case 2: S.Add();break;
		case 3: S.Change();break;
		case 4: S.Del();break;
 	    case 5: S.Search();break;
	    case 6: S.Print();break;
	    case 7: S.Sort();break;
  	    case 8: S.Save();break;
		case 9: exit(1);
		}
	}while(1);
	return 0;
}

void Menu()
{
    cout<<setw(64)<<"**************宿舍管理系统***************"<<endl;
    cout<<setw(64)<<"*     1...建立学生住宿记录信息.....     *"<<endl;
    cout<<setw(64)<<"*     2...添加学生住宿记录信息.....     *"<<endl;
    cout<<setw(64)<<"*     3...编辑学生住宿记录.........     *"<<endl;
    cout<<setw(64)<<"*     4...删除学生住宿记录.........     *"<<endl;
    cout<<setw(64)<<"*     5...查询学生住宿信息.........     *"<<endl;
    cout<<setw(64)<<"*     6...学生信息浏览.............     *"<<endl;
    cout<<setw(64)<<"*     7...排序.....................     *"<<endl;
    cout<<setw(64)<<"*     8...保存.....................     *"<<endl;
    cout<<setw(64)<<"*     9...退出.....................     *"<<endl;
    cout<<setw(64)<<"*****************************************"<<endl;
}
void Room::Save()
{
    int i;
    ofstream out("student.txt",ios::app);
    if(out)
    {
        for(i=0;i<N;i++)
           out<<S[i].no<<' '<<S[i].rno<<' '<<S[i].name<<endl;
       cout<<"              保存成功！"<<endl;
    }
    cout<<endl<<endl;
    Menu();
}
void Room::Set()
{
    int i;
    cout<<"请输入学生个数"<<endl;
    cin>>N;
 	cout<<"输入学生的学号,宿舍号，姓名"<<endl;
 	for(i=0;i<N;i++){
	cin>>S[i].no>>S[i].rno>>S[i].name;
 	}
    cout<<endl<<endl;
	Menu();
}
void Room::Add()
{

    N++;
    cout<<"请输入添加学生的学号，住宿号，姓名"<<endl;
    cin>>S[N-1].no>>S[N-1].rno>>S[N-1].name;
    cout<<endl<<endl;
    Menu();

}
void Room::Print()
{
    int i;
    cout<<" *******住宿学生的信息情况*******"<<endl;
    cout<<"学号       住宿号      姓名"<<endl;
   for(i=0;i<N;i++)
    {
        cout<<S[i].no<<setw(11)<<S[i].rno<<setw(11)<<S[i].name<<endl;
    }
   cout<<endl<<endl;
   Menu();
}
void Room::Change()
{
    int i,no,f;
    cout<<"请输入修改学生的学号："<<endl;
    cin>>no;
    for(i=0;i<N;i++)
    {
        if(no==S[i].no)
        {
            f=1;
           cout<<"请输入修改后学生的学号,住宿号，姓名"<<endl;
           cin>>S[i].no>>S[i].rno>>S[i].name;
        }
    }
    if(f!=1)
      cout<<"查无此人，请重新输入"<<endl;

    cout<<endl<<endl;
    Menu();

}
void Room::Search()
{
    Room S;;
    cout<<"1.........按学号查找"<<endl;
    cout<<"2.........按姓名查找"<<endl;
    cout<<"3.........按宿舍号查找"<<endl;
    do
	{
		cout<<"输入选项";
		int choose;
		cin>>choose;
		switch(choose)
		{
		case 1: Sno();break;
		case 2: Sname();break;
		case 3: Srno();break;

		}
	}while(0);
}

void Room::Sno()
{
    int i,no,f;
    cout<<"请输入学生的学号："<<endl;
    cin>>no;
    for(i=0;i<N;i++)
    {
        if(no==S[i].no)
        {
         f=1;
         cout<<"学号       住宿号      姓名"<<endl;
         cout<<S[i].no<<setw(11)<<S[i].rno<<setw(11)<<S[i].name<<endl;
        }

    }
    if(f!=1)
      cout<<"查无此人，请重新输入"<<endl;
    cout<<endl<<endl;
    Menu();
}
void Room::Srno()
{
    int i,rno,f;
    cout<<"请输入学生的宿舍号："<<endl;
    cin>>rno;
    for(i=0;i<N;i++)
    {
        if(rno==S[i].rno)
        {
            f=1;
            cout<<"学号       住宿号      姓名"<<endl;
          cout<<S[i].no<<setw(11)<<S[i].rno<<setw(11)<<S[i].name<<endl;
        }

    }
    if(f!=1)
        cout<<"查无此人！"<<endl;
    cout<<endl<<endl;
    Menu();
}
void Room::Sname()
{
    int i,f;
    char tname[20];
    cout<<"请输入学生的姓名："<<endl;
    cin>>tname;
    for(i=0;i<N;i++)
    {
        if(strcmp(S[i].name,tname)==0)
        {
         f=1;
         cout<<"学号       住宿号      姓名"<<endl;
         cout<<S[i].no<<setw(11)<<S[i].rno<<setw(11)<<S[i].name;
        }
    }
    if(f!=1)
       cout<<"查无此人！"<<endl;
    cout<<endl<<endl;
    Menu();
}
void Room::Sort()
{
    Room S;;
    cout<<"1.........按学号排序"<<endl;
    cout<<"2.........按宿舍号排序"<<endl;
    cout<<"3.........按姓名排序"<<endl;
    do
	{
		cout<<"输入选项";
		int choose;
		cin>>choose;
		switch(choose)
		{
		case 1: Sort1();break;
		case 2: Sort2();break;
		case 3: Sort3();break;

		}
	}while(0);
}
void Room::Sort1()
{
    int i,j,f;
    Stu temp;
    for(i=0;i<N-1;i++)
    {
        f=0;
        for(j=1;j<N;j++)
        {
            if(S[j-1].no>S[j].no)
            {
                temp=S[j];
                S[j]=S[j-1];
                S[j-1]=temp;
                f=1;

        }
            }
        if(f==0)
            break;
    }
  cout<<endl<<endl;
    Menu();
}
void Room::Sort2()
{
    int i,j,f;
    Stu temp;
    for(i=0;i<N-1;i++)
    {
        f=0;
        for(j=1;j<N;j++)
        {
            if(S[j-1].rno>S[j].rno)
            {
                temp=S[j];
                S[j]=S[j-1];
                S[j-1]=temp;
                f=1;

        }
            }
        if(f==0)
            break;
    }
  cout<<endl<<endl;
    Menu();
}
void Room::Sort3()
{
    int i,j,f;
    Stu temp;
    for(i=0;i<N-1;i++)
    {
        f=0;
        for(j=1;j<N;j++)
        {
            if(S[j-1].name[0]>S[j].name[0])
            {
                temp=S[j];
                S[j]=S[j-1];
                S[j-1]=temp;
                f=1;

        }
            }
        if(f==0)
            break;
    }
  cout<<endl<<endl;
  Menu();
}
void Room::Del()
{
    int i,no,j,f;
    cout<<"请输入想删除学号："<<endl;
    cin>>no;
    for(i=0;i<N;i++)
    {
        if(no==S[i].no){
          N=N-1;
          f=1;
          for(j=i+1;j<=N;j++)
          {
              S[j-1].no=S[j].no;
              S[j-1].rno=S[j].rno;
              strcpy(S[j-1].name,S[j].name);

          }

        }
        cout<<"          删除成功"<<endl;
    }
    if(f!=1)
        cout<<"输入有误，请重新输入"<<endl;
  cout<<endl<<endl;
  Menu();
}
