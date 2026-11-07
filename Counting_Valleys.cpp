int countingValleys(int steps, string path) {
    int level = 0;
    int valleyCount = 0;

    for (int i = 0; i < steps; i++) {
        if (path[i] == 'U') {
            level++;

            if (level == 0) {
                valleyCount++;
            }
        }
        else if (path[i] == 'D') {
            level--;
        }
    }

    return valleyCount;
}
