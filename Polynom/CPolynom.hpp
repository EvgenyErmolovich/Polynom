//
//  CPolynom.hpp
//  Polynom
//
//  Created by Evgeny on 21.04.16.
//  Copyright © 2016 Evgeny. All rights reserved.
//

#ifndef CPolynom_hpp
#define CPolynom_hpp

#include <stdio.h>
#include <iostream>

class Polynom
{
public:
    Polynom(double* = new double[0], unsigned int = 0);
    Polynom(const Polynom & );
    Polynom& operator = (const Polynom& );
    Polynom operator + (const Polynom& ) const;
    friend Polynom Multiplication(double , Polynom& );
    friend std:: ostream& operator << (std:: ostream& , const Polynom& );
    friend std:: istream& operator >> (std:: istream& , Polynom& );
    ~Polynom();
private:
    double* a;
    unsigned int deg;
    void CorrectDeg();
};
std:: ostream& operator << (std:: ostream& , const Polynom& );
std:: istream& operator >> (std:: istream& , Polynom& );
Polynom Multiplication(double , Polynom& );
Polynom operator * (double , Polynom& );
Polynom operator * (Polynom& , double );
#endif /* CPolynom_hpp */
