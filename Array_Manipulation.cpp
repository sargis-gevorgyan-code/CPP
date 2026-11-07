long arrayManipulation(int n, Vector<Vector<int>> queries) {
    Vector<long> diff;
    long sum = 0;
    long maxSum = 0;

    for (int i = 0; i < n + 1 ; i++) {
        diff.push_back(0);
    }

    for (int i = 0; i < queries.size(); i++) {
        int a = queries[i][0];
        int b = queries[i][1];
        int k = queries[i][2];

        diff[a - 1] += k;
        diff[b] -= k;
    }

    for (int i = 0; i < n; i++) {
        sum += diff[i];

        if (sum > maxSum) {
            maxSum = sum;
        }
    }

    return maxSum;


}
