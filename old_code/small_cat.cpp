#include <iostream>

using namespace std;
class small_cat
{
private:
    double weight;
    static double total_weight;
    static double total_number;
public:
    small_cat(double w):weight(w)
    {
        total_weight=total_weight+weight;
        total_number=total_number+1;
    }
    void print()
    {
        cout<<"total_weight: "<<total_weight<<"       total_number"<<total_number<<endl;
    }

};
double small_cat::total_number=0;
double small_cat::total_weight=0;
int main()
{
    small_cat w1(2.2),w2(3.3),w3(4.4);
    w1.print();
    w2.print();
    w3.print();
    return 0;
}
