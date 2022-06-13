class Solution {
    public static int func4(int edx, int esi, int edi) {
        int eax = edx;
        eax = eax - esi;
        int ecx = eax;
        ecx = ecx >>> 31;
        eax = eax + ecx;
        eax /= 2;
        ecx = eax + esi;
        if (edi >= ecx) {
            eax = 0;
            if (edi <= ecx) {
                return eax;
            } else {
                esi = ecx + 1;
                eax = func4(edx, esi, edi);
                return eax + eax + 1;
            }
        } else {
            edx = ecx - 1;
            eax = func4(edx, esi, edi);
            eax = eax + eax;
            return eax;
        }
    }

    public static void main(String[] args) {
        for (int i = 0; i < 14; i++) {
            System.out.println(i + " " + func4(14, 0, i));
        }
    }
}
