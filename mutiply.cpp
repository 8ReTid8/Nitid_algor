#include <bits/stdc++.h>
using namespace std;

int Multiply(int a, int b)
{
    int n = log10(a) + 1;
    if (n <= 1)
    {
        return a * b;
    }
    if (n % 2 != 0)
    {
        n += 1;
    }
    int power = pow(10, n / 2);
    int a1 = a / power, a2 = a % power, b1 = b / power, b2 = b % power;
    int A = Multiply(a1, b1);
    int B = Multiply(a2, b1);
    int C = Multiply(a1, b2);
    int D = Multiply(a2, b2);
    return A * round(pow(10, n)) + (B + C) * round(pow(10, n / 2)) + D;
}

// int Multiply(string a,string b){
//     if(a.length() <= 1){
//         int temp = stoi(a);
//         int temp2 = stoi(b);
//         return temp*temp2;
//     }

//     int s = a.length();
//     int m = s/2;
//     string a1 = a.substr(0, m);
//     string a2 = a.substr(m, s);
//     string b1 = b.substr(0,m);
//     string b2 = b.substr(m,s);
//     int A = Multiply(a1,b1);
//     int B = Multiply(a2,b1);
//     int C = Multiply(a1,b2);
//     int D = Multiply(a2,b2);
//     return A*pow(10,s) + (B+C)*pow(10,s/2) + D;
// }

int main(){
    int a=4568;
    // int a=100;

    stringstream str1;
    str1 << a;
    string num1 = str1.str();

    int b=3275;
    // int b=100;

    stringstream str2;
    str2 << b;
    string num2 = str2.str();
    
    int ans = Multiply(a,b);
    cout << ans << endl;
}