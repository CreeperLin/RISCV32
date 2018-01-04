#include "io.h"
int n;
int a[10000];

void exchange(int x,int y)
{
    int t=a[x];
    a[x]=a[y];
    a[y]=t;
}

int makeHeap() {
    int i;
    int t;
    int j;
    i = (n - 1) << 1;
    t = j = 0;
    while (i >= 0) {
        j = i >> 1;
        if ((i<<1)+1<n && a[(i<<1)+1]<a[i<<1]) j = (i<<2)+1;
        if (a[i] > a[j]) {
            exchange(i,j);
        }
        i = i - 1;
    }
    return 0;
}

int adjustHeap(int n) {
    int i;
    int j;
    int t;
    i = j = t = 0;
    while (i << 1 < n) {
        j = i<<1;
        if ((i<<1)+1<n && a[(i<<1)+1] < a[(i<<1)]) j = (i<<1)+1;
        if (a[i] > a[j]) {
            int t = a[i];
            a[i] = a[j];
            a[j] = t;
            i = j;
        }
        else break;
    }
    return 0;
}

int heapSort() {
    int t;
    int k;
    t = 0;
    for (k = 0; k < n; k = k + 1) {
        t = a[0];
        a[0] = a[n-k-1];
        a[n-k-1] = t;
        adjustHeap(n-k-1);
    }
    return 0;
}

int main() {
    int i;
	n = inl();

    for (i = 0; i < n; i = i + 1)
		a[i] = i;
    makeHeap();
    heapSort();
    for (i = 0; i < n; i = i + 1)
    {
        outl(a[i]);
        print(" ");
    }
	print("\n");
    return 0;
}
