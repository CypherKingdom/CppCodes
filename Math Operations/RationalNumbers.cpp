#include <iostream>
using namespace std;

struct rational
{
    int num;
    int den;
};

rational add(rational r1, rational r2)
{
    rational r;
    r.num = (r1.num * r2.den) + (r2.num * r1.den);
    r.den = r1.den * r2.den;
    return r;
}

rational div(rational r1, rational r2)
{
    rational r;
    r.num = r1.num * r2.den;
    r.den = r1.den * r2.num;
    return r;
}

rational mult(rational r1, rational r2)
{
    rational r;
    r.num = r1.num * r2.num;
    r.den = r1.den * r2.den;
    return r;
}

rational sub(rational r1, rational r2){
    rational r;
    r.num = (r1.num * r2.den) - (r2.num * r1.den);
    r.den = r1.den * r2.den;
    return r;
}

int gcd(int n, int m)
{
    int tmp;
    while (m != n)
    {
        if (m < n)
        {
            tmp = m;
            m = n;
            n = tmp;
        }
        m = m - n;
    }
    return m;
}

rational reduce(rational r)
{
    int d = gcd(r.num, r.den);
    r.num /= d;
    r.den /= d;
    return r;
}

void display(rational r)
{
    if (r.den == 1)
        cout << r.num << endl;
    else if (r.den < 0)
        cout << -r.num << "/" << -r.den << endl;
    else
        cout << r.num << "/" << r.den << endl;
}

rational input()
{
    rational r;
    cout << "Enter numerator: ";
    cin >> r.num;
    cout << "Enter denomenator: ";
    cin >> r.den;
    return r;
}

int main()
{
    rational a, b, c, d, e, f;
    a = input();
    b = input();
    c = add(a, b);
    c = reduce(c);
    d = sub(a, b);
    d = reduce(d);
    e = mult(a, b);
    e = reduce(e);
    f = div(a, b);
    f = reduce(f);
    display(c);
    display(d);
    display(e);
    display(f);
    return 0;
}