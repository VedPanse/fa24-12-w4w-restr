#include <stdio.h>

struct Point {
    int x;
    int y;
};

typedef struct Point Point;
// Typically write struct at the top


float dist(Point arg) {
    arg.x = 10;
    printf("%d\n", arg.x);
}


int main() {
    Point p = {4, 5};
    dist(p);
    printf("%d\n%d\n", p.x, p.y);
    return 0;
}