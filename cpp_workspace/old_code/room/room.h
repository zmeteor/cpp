#define M 100
typedef struct Student
{
    int no,rno;
    char name[20];

}Stu;
class Room
{
    Stu S[M];
public:
    void Set();
    void Add();
    void Del();
    void Search();
    void Sno();
    void Sname();
    void Srno();
    void Change();
    void Save();
    void Print();
    void Sort();
    void Sort1();
    void Sort2();
    void Sort3();

};

