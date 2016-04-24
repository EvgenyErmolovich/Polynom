//
//  main.cpp
//  Polynom
//
//  Created by Evgeny on 21.04.16.
//  Copyright © 2016 Evgeny. All rights reserved.
//

#include <iostream>
#include "CPolynom.hpp"

using namespace std;

int main()
{
    Polynom b;
    cin >> b;
    cout << b;
    cout << endl << "othr:" << endl;
    Polynom c;
    cin >> c;
    cout << c;
    cout << "Sum" << endl;
    cout << b * c;
    return 0;
}
