long pcount_do(unsigned long x)
{
    long res = 0;
    while (x)
    {
        res += x & 0x1;
        x >>= 1;
    }
    return res;
}
