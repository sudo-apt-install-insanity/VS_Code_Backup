void merge_sort(int *a, int n)
{
    int *b = (int *)malloc(sizeof(int) * n);
    merge_sort_rec(a, b, 0, n - 1);
    free(b);
}

void merge_sort_rec(int *a, int *b, int l, int r)
{
    if (l < r)
    {
        int m = (l + r) / 2;
        merge_sort_rec(a, b, l, m);
        merge_sort_rec(a, b, m + 1, r);
        merge(a, b, l, m, r);
    }
}

void merge(int *a, int *b, int l, int m, int r)
{
    int i, j, k;
    for (i = l, j = m + 1, k = l; i <= m && j <= r; k++)
    {
        if (a[i] < a[j])
            b[k] = a[i++];
        else
            b[k] = a[j++];
    }
    while (i <= m)
        b[k++] = a[i++];
    while (j <= r)
        b[k++] = a[j++];
    for (i = l; i <= r; i++)
        a[i] = b[i];
}