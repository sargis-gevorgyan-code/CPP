int sockMerchant(int n, vector<int> ar) {
    
    vector<int> arrPairs;
    bool flag = true;



    int pairsCount = 0;


    for (int i = 0; i < ar.size(); i++) {
        for (int j = 0; flag && j < arrPairs.size(); j += 2) {
            if (ar[i] == arrPairs[j]) {
                flag = false;
                arrPairs[j + 1] = arrPairs[j + 1] + 1;
            }
        }
        if (flag) {
            arrPairs.push_back(ar[i]);
            arrPairs.push_back(1);
        }
        flag = true;
    }

    for (int i = 1; i < arrPairs.size(); i += 2) {
        if (arrPairs[i] >= 2) {
            pairsCount += arrPairs[i] / 2;
        }
    }

    return pairsCount;
}
