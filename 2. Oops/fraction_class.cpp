// fraction class
#include<bits/stdc++.h>
using namespace std;
class Fraction
{
    int numerator;
    int denominator;

public:
    Fraction(int numerator, int denominator)
    {
        this->numerator = numerator;
        this->denominator = denominator;
    }
    int getnum(){
        return numerator;
    }
    int getden(){
        return denominator;
    }
    void setvalue(int numerator, int denominator)
    {
        this->numerator = numerator;
        this->denominator = denominator;
    }
    void display()
    {
        cout << numerator << "/" << denominator << endl;
    }
    void add(Fraction f2)
    {
        int lcm = this->denominator * f2.denominator;
        int x = lcm / this->denominator;
        int y = lcm / f2.denominator;
        this->numerator = (this->numerator * x) + (f2.numerator * y);
        this->denominator = lcm;
        simplify();
    }
    void multiply(Fraction f2)
    {
        this->numerator = this->numerator * f2.numerator;
        this->denominator = this->denominator * f2.denominator;
        simplify();
    }
    void simplify()
    {
        int gcd = __gcd(this->numerator, this->denominator);
        this->numerator = this->numerator / gcd;
        this->denominator = this->denominator / gcd;
    }
};
int main()
{
    Fraction f1(10, 2);
    Fraction f2(15, 4);
    cout<<"fraction class.."<<endl;
    cout<<"f1 = "<<f1.getnum()<<"/"<<f1.getden()<<endl;
    cout<<"f2 = "<<f2.getnum()<<"/"<<f2.getden()<<endl;
    cout<<"After addition.."<<endl;
    f1.add(f2);
    f1.display();
    f2.display();
    cout << "After multiplication.." << endl;
    f1.setvalue(10,2);
    f2.setvalue(15,4);
    f1.multiply(f2);
    f1.display();
    f2.display();
    return 0;
}