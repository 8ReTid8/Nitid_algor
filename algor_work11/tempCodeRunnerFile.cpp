#include <iostream>
#include <cmath>

int recurrenceRelation(int n)
{
    if (n == 1)
    {
        return 1;
    }
    else
    {
        return recurrenceRelation(n - 1) + pow(3, n - 1) + n - 1;
    }
}

int main()
{
    int n;
    std::cout << "Enter the value of n: ";
    std::cin >> n;

    int result = recurrenceRelation(n);

    std::cout << "Result: " << result << std::endl;

    return 0;
}
