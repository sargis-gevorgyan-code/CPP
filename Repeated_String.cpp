long repeatedString(string s, long n) {
    long length = s.length();

    long count = 0;
    for (char c : s) {
        if (c == 'a') {
            count++;
        }
    }

    long fullRepeats = n / length;
    long remainder = n % length;

    long result = count * fullRepeats;

    for (int i = 0; i < remainder; i++) {
        if (s[i] == 'a') {
            result++;
        }
    }

    return result;
}
