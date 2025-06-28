/*50. Pow(x,n)
Implement pow(x, n), which calculates x raised to the power n (i.e., x^n).*/

#include <iostream>
using namespace std;

class Solution
{
public:
    double myPow(double x, int n)
    {
        long long N = n;
        if (n < 0)
        {
            x = 1 / x;
            N = -N;
        }
        return power(x, N);
    }

private:
    double power(double x, long long n)
    {
        if (n == 0)
            return 1.0;
        double half = power(x, n / 2);
        if (n % 2 == 0)
        {
            return half * half;
        }
        else
        {
            return half * half * x;
        }
    }
};

int main()
{
    Solution s;

    // Test Case 1: Positive exponent
    double x1 = 2.0;
    int n1 = 10;
    cout << x1 << "^" << n1 << " = " << s.myPow(x1, n1) << endl;

    // Test Case 2: Negative exponent
    double x2 = 2.0;
    int n2 = -2;
    cout << x2 << "^" << n2 << " = " << s.myPow(x2, n2) << endl;

    // Test Case 3: x is 1
    double x3 = 1.0;
    int n3 = 1000;
    cout << x3 << "^" << n3 << " = " << s.myPow(x3, n3) << endl;

    // Test Case 4: x is 0 and n > 0
    double x4 = 0.0;
    int n4 = 5;
    cout << x4 << "^" << n4 << " = " << s.myPow(x4, n4) << endl;

    // Test Case 5: x is negative and n is odd
    double x5 = -2.0;
    int n5 = 3;
    cout << x5 << "^" << n5 << " = " << s.myPow(x5, n5) << endl;

    // Test Case 6: x is negative and n is even
    double x6 = -2.0;
    int n6 = 4;
    cout << x6 << "^" << n6 << " = " << s.myPow(x6, n6) << endl;

    // Test Case 7: x raised to 0
    double x7 = 5.0;
    int n7 = 0;
    cout << x7 << "^" << n7 << " = " << s.myPow(x7, n7) << endl;

    // Test Case 8: INT_MIN exponent edge case
    double x8 = 2.0;
    int n8 = INT_MIN;
    cout << x8 << "^" << n8 << " = " << s.myPow(x8, n8) << endl;

    return 0;
}