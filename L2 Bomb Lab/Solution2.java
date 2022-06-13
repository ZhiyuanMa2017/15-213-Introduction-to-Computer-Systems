class Solution2 {
    public static void main(String[] args) {
        String s = "aduiersnfotvbyl";
        String t = "flyers";
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < t.length(); i++) {
            char c = t.charAt(i);
            int index = s.indexOf(c);
            sb.append((char) ('a' + index));
        }
        System.out.println(sb);
        System.out.println(0x000001bb);
        System.out.println(0x000001dd);
        System.out.println(0x000002b3);
        System.out.println(0x0000039c);
        System.out.println(0x000000a8);
        System.out.println(0x0000014c);
    }
}
