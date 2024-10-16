#include <stdio.h>
#include <string.h>

int main() {
    struct hotel {
        int items;
        char name[10];
    } a;
    strcpy(a.name, "CIS 1201");
    a.items=10;
    printf("%s", a.name);
    return 0;
}
