#include<iostream>
#include<stdlib.h>
using namespace std;

int calculatePower(int base, int power)
{
    if (power == 0)
        return 1;
    else
        return (base * calculatePower(base, power-1));
}

int findGCD(int x, int y)
{
    if (x % y == 0)
        return y;
    else
        return findGCD(y, x % y);
}

int findLCM(int x, int y)
{
    static int common = 0;
    common += x;

    if((common % x == 0) && (common % y == 0)){
        return common;
    }
    return findLCM(x, y);
}

int main()
{
    int choice, base, power, x, y, result;
    while(1){
        cout << endl;
        cout << "Press 1 for Power Recursion" << endl;
        cout << "Press 2 for GCD Recursion" << endl;
        cout << "Press 3 for LCM Recursion" << endl;
        cout << "Press 4 for Exit" << endl << endl;

        cout << "Enter your Choice: ";
        cin >> choice;

        if(choice == 1){
            cout << "Enter Base and Power: ";
            cin >> base >> power;
            result = calculatePower(base, power);
            cout << endl << base << "^" << power << " = " << result << endl;
        }
        else if(choice == 2){
            cout << "Enter Two Integers: ";
            cin >> x >> y;
            result = findGCD(x, y);
            cout << endl << "The Result is: " << result << endl;
        }
        else if(choice == 3){
                cout << "Enter Two Integers: ";
                cin >> x >> y;
                if(x > y){
                    result = findLCM(x, y);
                }
                else{
                    result = findLCM(x, y);
                }
                cout << endl << "The Result is: " << result << endl;
        }
        else if(choice == 4){
            exit(1);
        }
        else{
            cout << "Wrong Choice. Try Again..." << endl;
        }
    }
    return 0;
}
