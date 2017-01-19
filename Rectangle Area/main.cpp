#define MAX(a, b) (a > b ? a : b)
#define MIN(a, b) (a < b ? a : b)
int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
    int t, r, b, l;
    t = MIN(D, H);
    r = MIN(C, G);
    b = MAX(B, F);
    l = MAX(A, E);
    return computeRect(A, B, C, D) + computeRect(E, F, G, H) - computeRect(l, b, r, t);
}

int computeRect(int A, int B, int C, int D) {
    int w = C > A ? C - A : 0;
    int h = D > B ? D - B : 0;
    return w * h;
}