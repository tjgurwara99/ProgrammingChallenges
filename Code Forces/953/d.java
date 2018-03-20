import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        String[] prefs = {
            "33_44_33",
            "33_44_33",
            "22_33_22",
            "22_33_22",
            "11_22_11",
            "11_22_11"
        };

        int maxPref = 0, maxI = -1, maxJ = -1;
        String[] lines = new String[6];

        for (int i = 0; i < 6; i++) {
            String line = sc.next();
            lines[i] = line;
            for (int j = 0; j < 8; j++) {
                if (line.charAt(j) == '.') {
                    int pref = prefs[i].charAt(j)-'0';
                    if (pref > maxPref) {
                        maxPref = pref;
                        maxI = i;
                        maxJ = j;
                    }
                }
            }
        }

        sc.close();

        lines[maxI] = lines[maxI].substring(0,maxJ)+"P"+lines[maxI].substring(maxJ+1);

        for (int i = 0; i < 6; i++) {
            System.out.println(lines[i]);
        }
    }
}
