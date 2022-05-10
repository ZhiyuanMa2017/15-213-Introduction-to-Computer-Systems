long absdiff(long x, long y) {
    long res;
    if(x > y) {
        res = x - y;
    } else {
        res = y - x;
    }
    return res;
}
