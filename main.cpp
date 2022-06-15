// Abdullah Al Hilfi
// 1650523
// server username: cosc1635

#include <iostream>
using namespace std;
#include <stack>
#include <vector>

int prec(char operation)
{
    if (operation == '^')
        return 3;
    else if (operation == '/' || operation == '*')
        return 2;
    else if (operation == '+' || operation == '-')
        return 1;
    else
        return -1;
}

void infixToPostfix(char input[])
{

    stack<char> charactor;
    string result;

    for (int i = 0; i < 20; i++)
    {
        char charr = input[i];
        if ((charr >= '0' && charr <= '9'))
        {
            result += charr;
        }
        else if (charr == '(')
            charactor.push('(');
        else if (charr == ')')
        {
            while (charactor.top() != '(')
            {
                result += charactor.top();

                charactor.pop();
            }
            charactor.pop();
        }

        else
        {
            while (!charactor.empty() && prec(input[i]) <= prec(charactor.top()))
            {
                result += charactor.top();

                charactor.pop();
            }
            charactor.push(charr);
        }
    }

    cout << result << endl;
}
int main()
{
    // using dynamic array
    int n;
    cout << "enter your size: ";
    cin >> n;
    char *exp = new char[n];

    cout << "enter chars please: " << endl;
    for (int i = 0; i < n; i++)
    {

        cin >> exp[i];
    }
    infixToPostfix(exp);

    return 0;
}