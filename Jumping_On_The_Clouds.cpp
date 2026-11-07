int jumpingOnClouds(vector<int> c) {
    int jumpCount = 0;
    int i = 0;
    int size = c.size();

    while (i < size - 1) {
        if (i + 2 < size && c[i + 2] == 0) {
            i += 2;
        }
        else {
            i++;
        }
        jumpCount++;
    }

    return jumpCount;
}
