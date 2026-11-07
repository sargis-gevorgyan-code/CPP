Vector<int> rotLeft_v2(Vector<int> a, int d) {
    size_t sizeA = a.size();
    if (sizeA == 0) {
        return a;
    }

    d = d % sizeA;

    int temp = 0;
    for (int i = 0; i < d / 2; i++) {
        temp = a[i];
        a[i] = a[d - 1 - i];
        a[d - 1 - i] = temp;
    }

    for (int i = 0; i < (sizeA - d) / 2; i++) {
        temp = a[d + i];
        a[d + i] = a[sizeA - 1 - i];
        a[sizeA - 1 - i] = temp;
    }

    for (int i = 0; i < sizeA / 2; i++) {
        temp = a[i];
        a[i] = a[sizeA - 1 - i];
        a[sizeA - 1 - i] = temp;
    }
    return a;

}
