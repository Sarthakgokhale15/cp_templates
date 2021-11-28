// find  X^Y in (logn) time
// ******************* log(n)  case 1: if X is too big*******************//
// GENERAL USE
int powermod1(int x, int y, int p)
{
    int res = 1;
    x = x % p;
    if (x == 0)
        return 0;
    while (y > 0)
    {
        if (y & 1)
            res = (res * x) % p;
        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}

// ******************* log^2 (n)case 2: if P is too big *******************//
int powermod2(int x, int y, int p)
{
    int res = 1;
    x = x % p;
    if (x == 0)
        return 0;
    while (y > 0)
    {
        if (y & 1)
            res = binaryMultiply(res, x, p);
        y = y >> 1;
        x = binaryMultiply(x, x, p);
    }
    return res;
}

int binaryMultiply(int x, int y, int p)
{
    int res = 0;
    x = x % p;
    if (x == 0)
        return 0;
    while (y > 0)
    {
        if (y & 1)
            res = (res + x) % p;
        y = y >> 1;
        x = (x + x) % p;
    }
    return res;
}

// ******************* case 3: if Y is too big*******************//
// if y is too big then it is given in form of array or vector

// use Euler Totient Function to find (x^y)%p
// if given m is prime then phi(m)=m-1;
// else phi(m)=m(1-1/n1)(1-1/n2).......
// here p=1337 =7*191   not prime phi(1337)=1337*(1-1/7)(1-1/191)=1140
int superPow(int a, vector<int> &b)
{

    int ans = 0;
    for (int x : b)
    {
        ans = (ans * 10 + x) % 1140;
    }

    return powermod1(a, ans, 1337);
}
