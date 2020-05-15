#include <string.h>
#include "stack.h"
#include "Calculator.h"

//����� ���������� true, ���� ����������� ������ - ����������� ("������" ��� "�����")
bool Calculator::IsDelimeter(char c)
{   
    if (string(" =").find(c) != std::string::npos)
        return true;
    return false;
}

//����� ���������� true, ���� ����������� ������ - ��������
bool Calculator::IsOperator(char c)
{    
    if (string("+-/*^()").find(c) != std::string::npos)
        return true;
    return false;
}

//����� ���������� ��������� ���������
size_t Calculator::GetPriority(char s)
{
    switch (s)
    {
    case '(': return 0;
    case ')': return 1;
    case '+': return 2;
    case '-': return 3;
    case '*': return 4;
    case '/': return 4;
    case '^': return 5;
    default: return 6;
    }
}

//"�������" ����� ������
double Calculator::Calculate(string input)
{
    //string output = GetExpression(input); //��������������� ��������� � ����������� ������
    //double result = Counting(output); //������ ���������� ���������
    double result = Counting(input); //������ ���������� ���������
    return result; //���������� ���������
}

string Calculator::GetExpression(string input)
{
    string output("");     //������ ��� �������� ���������
    Stack<char> operStack; //���� ��� �������� ����������

    for (int i = 0; i < input.size(); i++) //��� ������� ������� � ������� ������
    {
        //����������� ����������
        if (IsDelimeter(input[i]))
            continue; //��������� � ���������� �������

       //���� ������ - �����, �� ��������� ��� �����
        if (isdigit(input[i])) //���� �����
        {
            //������ �� ����������� ��� ���������, ��� �� �������� �����
            while (!IsDelimeter(input[i]) && !IsOperator(input[i]))
            {
                output += input[i]; //��������� ������ ����� ����� � ����� ������
                i++; //��������� � ���������� �������

                if (i == input.size()) break; //���� ������ - ���������, �� ������� �� �����
            }

            output += " "; //���������� ����� ����� ������ � ������ � ����������
            i--; //������������ �� ���� ������ �����, � ������� ����� ������������
        }

        //���� ������ - ��������
        if (IsOperator(input[i])) //���� ��������
        {
            if (input[i] == '(') //���� ������ - ����������� ������
                operStack.Push(input[i]); //���������� � � ����
            else if (input[i] == ')') //���� ������ - ����������� ������
            {
                //���������� ��� ��������� �� ����������� ������ � ������
                char s = operStack.Pop();

                while (s != '(')
                {
                    std::string str; 
                    str.push_back(s);
                    output += str + ' ';
                    s = operStack.Pop();
                }
            }
            else //���� ����� ������ ��������
            {
                if (operStack.size() > 0) //���� � ����� ���� ��������
                    if (GetPriority(input[i]) <= GetPriority(operStack.Peek())) { //� ���� ��������� ������ ��������� ������ ��� ����� ���������� ��������� �� ������� �����
                        string str;
                        str.push_back(operStack.Pop());
                        output += str + " "; //�� ��������� ��������� �������� �� ����� � ������ � ����������
                    }
                operStack.Push(input[i]); //���� ���� ����, ��� �� ��������� ��������� ���� - ��������� ���������� �� ������� �����

            }
        }
    }

    //����� ������ �� ���� ��������, ���������� �� ����� ��� ���������� ��� ��������� � ������
    while (operStack.size() > 0)
        output += operStack.Pop() + " ";

    return output; //���������� ��������� � ����������� ������
}

double Calculator::Counting(string input)
{
    double result = 0; //���������
    Stack<double> temp; //Dhtvtyysq ���� ��� �������

    for (int i = 0; i < input.size(); i++) //��� ������� ������� � ������
    {
        //���� ������ - �����, �� ������ ��� ����� � ���������� �� ������� �����
        if (isdigit(input[i]))
        {
            string a("");

            while (!IsDelimeter(input[i]) && !IsOperator(input[i])) //���� �� �����������
            {
                a += input[i]; //���������
                i++;
                if (i == input.size()) break;
            }
            temp.Push(stod(a)); //���������� � ����
            i--;
        }
        else if (IsOperator(input[i])) //���� ������ - ��������
        {
            //����� ��� ��������� �������� �� �����
            double a = temp.Pop();
            double b = temp.Pop();

            switch (input[i]) //� ���������� ��� ���� ��������, �������� ���������
            {
            case '+': result = b + a; break;
            case '-': result = b - a; break;
            case '*': result = b * a; break;
            case '/': result = b / a; break;
            case '^': 
                string str_a, str_b;
                str_a.push_back(a);
                str_b.push_back(b);
                result = pow(stod(str_b), stod(str_a)); 
                break;
            }
            temp.Push(result); //��������� ���������� ���������� ������� � ����
        }
    }
    return temp.Peek(); //�������� ��������� ���� ���������� �� ����� � ���������� ���
}

