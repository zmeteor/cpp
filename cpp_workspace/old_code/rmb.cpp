#include <iostream>

using namespace std;
class RMB
{
private:
    int yuan,jiao,fen;
public:
    RMB(int y=0,int j=0,int f=0):yuan(y),jiao(j),fen(f){}
    friend RMB operator +(RMB a,RMB b);
    friend RMB operator -(RMB a,RMB b);
    void Print();
};
void RMB::Print()
{
    cout<<yuan<<"Ôª"<<jiao<<"½Ç"<<fen<<"·Ö"<<endl;
}
RMB operator +(RMB a,RMB b)
{
    RMB temp;
    temp.fen=(a.fen+b.fen)%10;
    temp.jiao=a.jiao+b.jiao+(a.fen+b.fen)/10;
    temp.yuan=a.yuan+b.yuan+temp.jiao/10;
    temp.jiao=temp.jiao/10;
    return temp;
}
RMB operator -(RMB a,RMB b)
{
    RMB temp;
    if(a.fen<b.fen){
        temp.fen=10+a.fen-b.fen;
        a.jiao--;
    }
    else
        temp.fen=a.fen-b.fen;
    if(a.jiao<b.jiao){
        temp.jiao=10+a.jiao-b.jiao;
        a.yuan--;
    }
    else
       temp.jiao=a.jiao-b.jiao;
    temp.yuan = a.yuan-b.yuan;
    return temp;


}
int main()
{
    RMB a(10,2,6),b(3,1,6),c;
    c=a+b;
    c.Print();
    c=b-a;
    c.Print();
    return 0;
}
