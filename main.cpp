#include <iostream>
#include "stack.h"
#include "functions.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    
    bool menuIsActive = true;
    while (menuIsActive) {

        system("cls");

        int answer = 0;
        do {
            answer = 0;
            cout << "1. Печать чисел по любому основанию" << endl;
            cout << "2. Постфиксный калькулятор" << endl;
            cout << "3. Палиндромы" << endl;
            cout << "4. Выход" << endl;
            cout << "Выберите: ";
            cin >> answer;
        } while (answer < 1 || answer > 4);

        system("cls");

        switch (answer) {
            case 0: break;
            case 1: numbers(); break;
            case 2: calculator(); break;
            case 3: palindroms(); break;
            case 4: menuIsActive = false; break;
            default: menuIsActive = false; break;
        
        }
    }
}
