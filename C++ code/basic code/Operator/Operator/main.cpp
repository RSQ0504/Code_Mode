//
//  main.cpp
//  Class/operator/const
//
//  Created by David Qian on 2021/6/15.
//

#include <iostream>
using namespace std;

class Length{
private:
    int feet;
    int inches;
public:
    Length();//初始化
    Length(const int& feet,const int& inches);//初始化
    
    friend ostream& operator<<(ostream& out,const Length& len);
    //自定义了一个可以输出class的函数-->cout<<Lenghth;
    friend istream& operator>>(istream& in,Length &len);
    //自定义了一个可以输入class的函数-->cin>>Lenghth;
    
    int getFeet() const;//养成习惯用 const修饰constant函数
    int getInch() const;//养成习惯用 const修饰constant函数
    void setInch(const int& inches);//养成习惯用（const 类型& variable）
    void setFeet(const int& feet);//养成习惯用（const 类型& variable）
    
    Length operator+(const Length& len) const;//等于（原clas+len）
    void operator+=(const Length& len);//等于（原clas+=len）
    int operator<(const Length& len) const;//等于（原clas<len）
    int operator>(const Length& len) const;
    int operator==(const Length& len) const;
    
    //Returndata Operator SYMBOL(Parameter)=（本身/Pararmeter)(SYMBOL)(Parameter)
    //如果括号里没东西=(SYMBOL)本身;符号后面一定要有东西
    
    friend Length getShortestLength(const Length* L,const int& size);
    friend Length getSum(const Length* L,const int& size);//friend函数可以调用private的东西
};

ostream& operator<<(ostream& out,const Length& len){
    out<<len.feet<<" feet and "<<len.inches<<" inches";
    return out;
}

istream& operator>>(istream& in, Length &len){
    cout<<endl;
    cout<<"\t Enter a feet";
    in >> len.feet;
    cout<<"\t Enter a inches";
    in >> len.inches;
    return in;
}

Length::Length(){
    feet=0;
    inches=0;
}
Length::Length(const int& feet,const int& inches){
    this->feet=feet;
    this->inches=inches;
}
void Length::setInch(const int& inches){
    this->inches=inches;
}
void Length::setFeet(const int& feet){
    this->feet=feet;
}
int Length::getFeet() const{
    return feet;
}
int Length::getInch() const{
    return inches;
}
Length Length::operator+(const Length& len) const{
    int newinches=this->inches+len.inches;
    int newfeet=(newinches/12)+this->feet+len.feet;
    newinches=newinches%12;
    Length ans(newfeet,newinches);
    return ans;
}
void Length::operator+=(const Length& len){
    this->feet=(this->inches+len.inches)/12+len.feet+this->feet;
    this->inches=(this->inches+len.inches)%12;
}
int Length::operator<(const Length& len) const{
    int a=this->feet*12+this->inches;
    int b=len.feet*12+len.inches;
    if(a<b) return 1;
    else return 0;
}
int Length::operator>(const Length& len) const{
    int a=this->feet*12+this->inches;
    int b=len.feet*12+len.inches;
    if(a>b) return 1;
    else return 0;
}
int Length::operator==(const Length& len) const{
    int a=this->feet*12+this->inches;
    int b=len.feet*12+len.inches;
    if(a==b) return 1;
    else return 0;
}
Length getSum(const Length* L,const int& size){
    Length ans(0,0);
    for(int i=0;i<size;i++){
        ans=ans+L[i];
    }
    return ans;
}
Length getShortestLength(const Length* L,const int& size){
    Length ans(L[0].feet,L[0].inches);
    for(int i=0;i<size;i++){
        if(ans>L[i]){
            ans.setFeet(L[i].feet);
            ans.setInch(L[i].inches);
        }
    }
    return ans;
}
int main()
{
    Length len1, len2(2, 35), len3(6, 81);
    cout << "len1 is " << len1 << endl;
    cout << "len2 is " << len2 << endl;
    cout << "len3 is " << len3 << endl;
    cout << endl;

    len1.setInch(47);
    len3.setFeet(5);
    cout<< "After modifying it, len1 is now " << len1 << endl;
    cout<< "After modifying it, len3 is now " << len3 << endl;
    cout << endl;

    const Length len4(3, 11);
    const Length len5(5, 23);
    cout << "len4 is " << len4 << endl;
    cout << "len5 is " << len5.getFeet() << " feet and " << len5.getInch() << " inches." << endl;
    cout << endl;

    Length len6 = len4 + len5;
    cout << len4 << " + " << len5 << " = " << len6 << endl;
    len2 += len4;
    cout << "len2 += len4 gives len2 which is equal to " << len2 << endl;
    cout << endl;

    if (len4 == len1)
        cout << len4 << " is equal to " << len1 << endl;
    else
        cout << len4 << " is not equal to " << len1 << endl;

    if (len1 > len5)
        cout << len1 << " is greater than " << len5 << endl;
    else
        cout << len1 << " is not greater than " << len5 << endl;

    if (len4 < len5)
        cout << len4 << " is less than " << len5 << endl;
    else
        cout << len4 << " is not less than " << len5 << endl;
    cout << endl;

    int size = rand() % 6 + 5;
    Length *L = new Length[size];
    for (int i = 0; i < size; i++)
    {
        int feet = rand() % 5;
        int inch = rand() % 20 + 10;
        L[i] = Length(feet, inch);
        cout << "Creating a length object from " << feet << " feet and " << inch << " inches." << endl;
        cout << "\tThe length object is " << L[i] << endl;
    }
    cout << endl;

    Length s1 = getSum(L, size);
    cout << "The sum of all the elements of the array is " << s1 << endl;
    Length s2 = getShortestLength(L, size);
    cout << "The shortest length among all the elements of the array is " << s2 << endl;

    delete[] L;

    system("Pause");
    return 0;
}
