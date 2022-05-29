#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;

double example();
double term();
double number();

int main()
{
    double n;

    cout << "Enter example: ";

    n = example();

    cout << setprecision(12) << "Example result: " << n << endl;
    ofstream fp("results.txt");
    fp << n;
    fp.close();

    cin.get();
    cin.get();
    
    return 0;
}

double example()
{
    double result;
    char operation;

    result = term();

    while (true)
    {
        operation = cin.get();

        switch (operation)
        {
        case '+':
            result += term();
            break;
        case '-':
            result -= term();
            break;
        default:
            cin.putback(operation);
            return result;
        }
    }
}

double term()
{
    double result;
    char operation;
    double temp;

    result = number();

    while (true)
    {
        operation = cin.get();

        switch (operation)
        {
        case '*':
            result *= number();
            break;
        case '/':
            temp = number();

            if (temp == 0.0)
            {
                cout << "Division by zero!" << endl;
                exit(-1);
            }

            result /= temp;
            break;
        default:
            cin.putback(operation);
            return result;
        }
    }
}

double number()
{
    double result = 0.0;
    char digit;
    double k = 10.0;
    int sign = 1;

    digit = cin.get();

    while (digit == ' ')
        digit = cin.get();

    switch (digit)
    {
    case '-':
        sign = -1;
        break;
    default:
        if (digit != '+')
            cin.putback(digit);
        break;
    }

    while (true)
    {
        digit = cin.get();

        while (digit == ' ')
            digit = cin.get();

        if (digit >= '0' && digit <= '9')
            result = result * 10.0 + (digit - '0');
        else
        {
            cin.putback(digit);
            break;
        }
    }

    digit = cin.get();

    if (digit == '.')
    {
        while (true)
        {
            digit = cin.get();

            while (digit == ' ')
                digit = cin.get();

            if (digit >= '0' && digit <= '9')
            {
                result += (digit - '0') / k;
                k *= 10.0;
            }
            else
            {
                cin.putback(digit);
                break;
            }
        }
    }

    else
        cin.putback(digit);

    digit = cin.get();

    while (digit == ' ')
        digit = cin.get();

    cin.putback(digit);

    return sign * result;
}