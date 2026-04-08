#include <bits/stdc++.h>
using namespace std;

int packing1(int s, int k)
{
    if (k % 2 == 0) 
    {
        return (k / 2) * min(s, k - 1);
    }
    else 
    {
        return ((k - 1) / 2) * min(s, k);
    }
}

int packing2(int n)
{
    int k;
    int r = n % 6;

    if (r == 1 || r == 3)
        k = 0;
    else if (r == 5)
        k = 4;
    else if (r == 0 || r == 2)
        k = n / 2;
    else // r == 4
        k = n / 2 + 1;

    return (n * (n - 1) / 2 - k) / 3;
}

int T2(int l, int m, int xl, int xm)
{
    return m*(m-1)
         + l*(l-1)
         + m*xl
         + l*xm
         - xl*xm;
}

// ---- Packings ----

int P13(int l, int m, int xl, int xm)
{
    return packing2(m + xl)
         + packing1(xl + xm, l - xl)
         + packing1(m, m)
         + packing1(l, l);
}

int P14(int l, int m, int xl, int xm)
{
    return packing1(m, m)
         + packing1(l, l)
         + packing1((l - xl) + (m - xm), xl + xm);
}

int P15l(int l, int m, int xl, int xm)
{
    return packing2(l)
         + packing1(xl, m)
         + packing1(m, m)
         + packing1(l, l);
}

int P15m(int l, int m, int xl, int xm)
{
    return packing2(m)
         + packing1(xm, l)
         + packing1(m, m)
         + packing1(l, l);
}

int P16l(int l, int m, int xl, int xm)
{
    return packing2(2*l)
         + packing1(xl, m)
         + packing1(m, m);
}

int P16m(int l, int m, int xl, int xm)
{
    return packing2(2*m)
         + packing1(xm, l)
         + packing1(l, l);
}

int P17l(int l, int m, int xl, int xm)
{
    return packing2(2*l)
         + packing1(xl, m - 1)
         + packing1(m - 1, m+1);
}

int P17m(int l, int m, int xl, int xm)
{
    return packing2(2*m)
         + packing1(xm, l - 1)
         + packing1(l - 1, l+1);
}

// ---- MAIN ----

int main()
{
    for (int l = 1; l <= 10; l++)
    for (int m = 1; m <= 10; m++)
    for (int xl = 0; xl < l; xl++)
    for (int xm = 0; xm < m; xm++)
    {
        // restricciones del paper
        if (!(l + xm <= m + xl)) continue;
        if (!((l - xl) <= (xm + xl))) continue;

        int t2 = T2(l, m, xl, xm);

        vector<int> f;

        f.push_back(6 * P13(l,m,xl,xm) - 3 * t2);
        f.push_back(6 * P14(l,m,xl,xm) - 3 * t2);
        f.push_back(6 * P15l(l,m,xl,xm) - 3 * t2);
        f.push_back(6 * P15m(l,m,xl,xm) - 3 * t2);
        f.push_back(6 * P16l(l,m,xl,xm) - 3 * t2);
        f.push_back(6 * P16m(l,m,xl,xm) - 3 * t2);
        f.push_back(6 * P17l(l,m,xl,xm) - 3 * t2);
        f.push_back(6 * P17m(l,m,xl,xm) - 3 * t2);

        bool ok = false;
        for (int val : f)
            if (val > -3)
                ok = true;

        if (!ok)
        {
            cout << "Counterexample: "
                 << l << " " << m << " "
                 << xl << " " << xm << endl;
        }
    }

    cout << "Done." << endl;
}