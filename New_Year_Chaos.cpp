void minimumBribes(Vector<int> q) {
    size_t sizeQ = q.size();
    int bribeCount = 0;
    bool flag = true;
    for (int i = 0; i < sizeQ; i++) {
        if (q[i] - i > 3) {
            std::cout << "Too chaotic" << std::endl;
            flag = false;
            break;
        }

        int checkAt = std::max(0, q[i] - 2);

        for (int j = checkAt; j < i; j++) {
            if (q[j] > q[i]) {
                bribeCount++;
            }
        }

    }
    if (flag) {
        std::cout << bribeCount << std::endl;
    }
    

}
