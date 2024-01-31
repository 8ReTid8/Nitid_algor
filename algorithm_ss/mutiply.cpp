#include <bits/stdc++.h>
using namespace std;

int mulcount = 0;
// int Multiply(int a, int b)
// {
//     mulcount++;
//     int n = log10(a) + 1;
//     if (n <= 1)
//     {
//         return a * b;
//     }
//     if (n % 2 != 0)
//     {
//         n += 1;
//     }
//     int power = pow(10, n / 2);
//     int a1 = a / power, a2 = a % power, b1 = b / power, b2 = b % power;
//     int A = Multiply(a1, b1);
//     int B = Multiply(a2, b1);
//     int C = Multiply(a1, b2);
//     int D = Multiply(a2, b2);
//     return A * round(pow(10, n)) + (B + C) * round(pow(10, n / 2)) + D;
// }

// int Multiply(int a, int b)
// {
//     int n = log10(a) + 1;
//     if (n <= 1)
//     {
//         return a * b;
//     }
//     if (n % 2 != 0)
//     {
//         n += 1;
//     }
//     int power = pow(10, n / 2);
//     int a1 = a / power, a2 = a % power, b1 = b / power, b2 = b % power;
//     int A = Multiply(a1, b1);
//     int B = Multiply(a2, b2);
//     int C = Multiply(a1+a2,b1+b2);
//     return A * round(pow(10, n)) + (C-A-B) * round(pow(10, n / 2)) + B;
// }

int Multiply(string a,string b){
    if(a.length() <= 1){
        int temp = stoi(a);
        int temp2 = stoi(b);
        return temp*temp2;
    }

    int s = a.length();
    int m = s/2;
    string a1 = a.substr(0, m);
    string a2 = a.substr(m, s);
    cout<<s<<" "<<m<<endl;
    cout<<a1<<" "<<a2<<endl;
    string b1 = b.substr(0,m);
    string b2 = b.substr(m,s);
    int A = Multiply(a1,b1);
    int B = Multiply(a2,b1);
    int C = Multiply(a1,b2);
    int D = Multiply(a2,b2);
    return A*pow(10,s) + (B+C)*pow(10,s/2) + D;
}
int kacount = 0;
int karatsuba(int a, int b)
{
    // kacount++;
    int n = max(trunc(log10(a)) + 1,trunc(log10(b)) + 1);
    if (n == 1)
    {
        kacount++;
        return a * b;
    }
    if (n % 2 != 0)
    {
        n++;
    }
    int a1 = a / pow(10, n / 2);
    int a2 = a % (int)round(pow(10, n / 2));
    int b1 = b / pow(10, n / 2);
    int b2 = b % (int)round(pow(10, n / 2));
    // cout<<a1<<" "<<a2<<" "<<b1" "<<
    int A = karatsuba(a1, b1);
    int B = karatsuba(a2, b2);
    int C = karatsuba(a1 + a2, b1 + b2);
    return A * pow(10, n) + (C - A - B) * pow(10, n / 2) + B;
}
int main()
{
    // int a = 4500;
    // int a=100;
    int a = 3572;
    stringstream str1;
    str1 << a;
    string num1 = str1.str();

    
    int b = 1245;
    // int b=100;
    stringstream str2;
    str2 << b;
    string num2 = str2.str();
    int ans = Multiply(num1, num2);
    cout << "mul\t" << ans << " does " << mulcount << " times" << endl;
    cout << "kara\t" << karatsuba(a, b) << " does " << kacount << " times";
}