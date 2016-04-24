//
//  CPolynom.cpp
//  Polynom
//
//  Created by Evgeny on 21.04.16.
//  Copyright © 2016 Evgeny. All rights reserved.
//

#include "CPolynom.hpp"
#include <iostream>

using namespace std;

Polynom:: Polynom(double* b, unsigned int n)
{
    deg = 0;
    for(int i = 0;i <= n;i++)
        if(b[i]!=0) deg = i;
    a = new double [deg+1];
    for(int i = 0; i <= deg; i++)
        a[i] = b[i];
}
Polynom:: Polynom(const Polynom& other)
{
    deg = other.deg;
    a = new double[deg+1];
    for (int i = 0; i <= deg; i++)
    a[i] = other.a[i];
}
Polynom& Polynom :: operator = (const Polynom& other)
{
    if(this != &other)
    {
        deg = other.deg;
        delete[] a;
        a = new double [deg+1];
        for (int i = 0; i < deg; i++)
            a[i] = other.a[i];
    }
    return *this;
}
Polynom Polynom:: operator + (const Polynom& other) const
{
    int i;
    Polynom *result;
    if(deg >= other.deg)
    {
        result = new Polynom(a,deg);
        for(i = 0;i <= other.deg; i++)
            result->a[i] += other.a[i];
    }
    else
    {
        result = new Polynom(other.a,other.deg);
        for(i = 0; i <= deg; i++)
            result->a[i] += a[i];
    }
    result->CorrectDeg();
    return *result;
}
void Polynom:: CorrectDeg()
{
    if(a[deg]==0)
        while(deg && a[deg]==0)
        {
            deg--;
        }
}
Polynom Multiplication(double x, Polynom &other)
{
    if(x == 0)
    {
        Polynom result;
        return result;
    }
    else
    {
        int deg = other.deg;
        double* temp = new double [deg+1];
        for(int i = 0; i <= deg; i++)
            temp[i] = x * other.a[i];
        Polynom result(temp,deg);
        delete[] temp;
        return result;
    }
}
Polynom operator * (double x, Polynom& other)
{
    return Multiplication(x, other);
}
Polynom operator * (Polynom& other, double x)
{
    return Multiplication(x,other);
}
istream& operator >> (istream& in, Polynom& other)
{
    cout << "degree: ";
    unsigned int NewDeg = 0;
    in >> NewDeg;
    double* b = new double[NewDeg+1];
    for(int i = 0; i < NewDeg; i++)
    {
        cout << "K" << i << " = ";
        in >> b[i];
    }
    while(!b[NewDeg])
    {
        cout << "K" << NewDeg << " = ";
        in >> b[NewDeg];
        if(b[NewDeg] == 0)
            cout << "K" << NewDeg << " must not be zero!!!"<< endl;
    }
    other = Polynom(b, NewDeg);
    return in;
}
ostream& operator << (ostream& out, const Polynom& other)
{
    if(other.a[other.deg]==1)
        out << "X^" << other.deg;
    else if(other.a[other.deg]==-1)
        out << "-X^" << other.deg;
    else
        out << other.a[other.deg] << "X^" << other.deg;
    for(int i = other.deg - 1; i > 0; i--)
    {
        if(other.a[i] > 0)
        {
            if(other.a[i]==1)
                out << " + " << "X^" << i;
            else
                out << " + " << other.a[i] << "X^" << i;
        }
        else if(other.a[i] < 0)
        {
           if(other.a[i] == -1)
                out << " - " << "X^" << i;
            else
                out << " - " << (-1)*other.a[i] << "X^" << i; 
        }
    }
    if(other.a[0]>0)
        out << " + " << other.a[0] << "\n";
    else if(other.a[0]<0)
        out << " - " << (-1)*other.a[0] << "\n";
    return out;
}
Polynom:: ~Polynom()
{
    delete[] a;
}