#include <iostream>
#include <string>
#include <stdlib.h>
#include <cmath>
#include "fence.h"

using namespace std;

void fence(){
    string user_command;
    cout << "Type: \n   1. 'RUN' to start the program \n   2. 'EXIT' to exit"  << endl;
    cin >> user_command;

    for (int i = 0; i < user_command.size(); i++){
        user_command[i] = toupper(user_command[i]);
    }

    if(user_command.compare("RUN") == 0){
        int length = 0;
        cout << "Provide length of fence: ";
        cin >> length;

        while( length < 3 || cin.fail()) {
            cout << "Your fence length must be >=3 integer, provide valid number: ";
            cin.clear();
            std::cin.ignore(256,'\n');
            cin >> length;
        };

        if(length >= 3){
            Fence_sides fence_sides = optimization(length);
            int a = fence_sides.a;
            int b = fence_sides.b;

            cout << "\n a = " << a;
            cout << "\n b = " << b;

            int area_value = area(a, b);
            cout << "\n area = " << area_value;
        }
    } else if(user_command.compare("EXIT") == 0){
        cout << "You decided to close the program" << endl;
        exit(0);
    } else {
        cout << "\nYou provided invalid input, please try again" << endl;
        fence();
    }
}

Fence_sides optimization(int length){
    int a;
    int b;

    float float_length = static_cast<float>(length);

    // 2*a+b=L => b=L-2*a
    // area = a*b = a(L-2*a)
    // f(a) = a(L-2*a)
    // this function has its max at a = L/4 (it's the average of two zero places)
    // our a value should be integer so I try whether area for a rounded up or down is bigger

    int a_1 = round(float_length/4);
    int b_1 = length - 2*a_1;
    int a_2 = floor(float_length/4);
    int b_2 = length - 2*a_2;

    if(a_1*b_1 >= a_2*b_2){
        a = a_1;
        b = b_1;
    } else {
        a = a_2;
        b = b_2;
    }

    Fence_sides fence_sides {a, b};
    return fence_sides;
}

int area(int a, int b){
    return a*b;
}








