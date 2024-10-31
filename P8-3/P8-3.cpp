#include <iostream>
#include <string>

using namespace std;

int romanCharValue(char r)
{
    switch (r)
    {
    case 'I': return 1;
    case 'V': return 5;
    case 'X': return 10;
    case 'L': return 50;
    case 'C': return 100;
    case 'D': return 500;
    case 'M': return 1000;
    }
    return 0;
}

int convertRomanToInt(string s)
{
    int total = 0;
    int i = 0;
    int length = s.length();
    while (i < length)
    {
        int firstValue = romanCharValue(s[i]);
        int secondValue = 0;
        if (i + 1 < length)
            secondValue = romanCharValue(s[i + 1]);

        if (firstValue >= secondValue || i + 1 == length)
        {
            total = total + firstValue;
            i++;
        }
        else
        {
            total += secondValue - firstValue;
            i = i + 2;
        }
    }
    return total;
}

int main()
{
    cout << "Value of 'M': " << romanCharValue('M') << endl;
    cout << "Value of 'C': " << romanCharValue('C') << endl;
    cout << "Value of 'X': " << romanCharValue('X') << endl;
    cout << "Value of 'IX': " << convertRomanToInt("IX") << endl;
    cout << "Value of 'MCMXCIV': " << convertRomanToInt("MCMXCIV") << endl;

    return 0;
}
