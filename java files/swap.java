public class swap {
    public static void main(String[] args) {
        int a[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, };
        int start = 0;
        int end = a.length - 1;
        int temp;

        for (int i = 0; i < a.length; i++) {
            System.out.println(a[i]);
        }

        System.out.println("\n+++++++++++++++++++++++++++++++\n");

        while (start <= end) {
            temp = a[start];
            a[start] = a[end];
            a[end] = temp;

            start++;
            end--;
        }

        for (int i = 0; i < a.length; i++) {
            System.out.println(a[i]);
        }
    }
}
