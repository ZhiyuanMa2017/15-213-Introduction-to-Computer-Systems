long pcount_do(unsigned long x)
{
    long res = 0;
    do
    {
        res += x & 0x1;
        x >>= 1;
    } while (x);
    return res;
}
