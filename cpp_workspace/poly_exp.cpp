/*************************************************************************
	> File Name: poly_exp.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年04月01日 星期日 11时27分43秒
 ************************************************************************/

/*简单的多态实现: 选手比赛*/

#include <iostream>

using namespace std;

class Player
{
public:
    Player();
    Player(int score)
    {
        this->score = score;
    }

    virtual int getscore()
    {
        return score;
    }
protected:
private:
    int score;
};

class P1:public Player
{
public:
    P1(int score):Player(10)
    {
        this->score = score;
    }
    virtual int getscore()
    {
        return score;
    }
protected:
private:
    int score;
};

class P2:public Player
{
public:
    P2(int score):Player(10)
    {
        this->score = score;
    }
    virtual int getscore()
    {
        return score;
    }
protected:
private:
    int score;
};

void compete(Player &p1,Player &p2)
{
    cout<<"score: P1: "<<p1.getscore()<<"\t P2: "<<p2.getscore()<<endl;
    if(p1.getscore() > p2.getscore())  //发生多态
    {
        cout<<"P1 win"<<endl;
    }
    else if(p1.getscore() < p2.getscore())
    {
        cout<<"P2 win"<<endl;
    }
    else
    {
        cout<<"draw"<<endl;
    }
}

int main()
{
    P1 pp1(69);
    P2 pp2(90);


    compete(pp1,pp2);

    return 0;
}

