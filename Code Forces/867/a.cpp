#include <cstdio>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    int a = 0, b = 0;
    char current;
    scanf(" %c", &current);
    for (int i = 1; i < n; i++) {
        char n;
        scanf(" %c", &n);

        if (n != current) {
            if (n == 'S') a++;
            else b++;
        }

        current = n;
    }

    printf(b > a ? "YES\n" : "NO\n");
    return 0;
}
