#include <iostream>
#include "Vector_class/Vectorclass.h"
#include <time.h>


class Fun {
public:

    //link 1
    int hourglassSum(Vector<Vector<int>> arr);
    
    Vector<int> rotLeft_v1(Vector<int> a, int d);
    Vector<int> rotLeft_v2(Vector<int> a, int d);

    void minimumBribes(Vector<int> q);

    int minimumSwaps(Vector<int> arr);

    long arrayManipulation(int n, Vector<Vector<int>> queries);


    
    //link 2

    int findPairs(Vector<int> arr);
  
    int countingValleys(Vector<char> arr);
    
    int jumpOnClouds(Vector<int> arr);




};


int main() {
    srand(time(0));


    Fun myObj;


    std::cout << std::endl << std::endl;
    // ----------------> hourglassSum

    Vector<Vector<int>> arr;
    Vector<int> arr1;
    for (int j = 0; j < 6; j++) {
        for (int i = 0; i < 6; i++) {
            arr1.push_back(rand() % 20 - 10);
        }
        arr.push_back(arr1);
        for (int i = 0; i < 6; i++) {
            arr1.pop_back();
        }
    }
    for (int i = 0; i < 6; i++) {
        arr[i].printVector();
       // std::cout << std::endl;
    }
    std::cout << std::endl << "Max sum: " << myObj.hourglassSum(arr) << std::endl;
    std::cout << std::endl << std::endl;

    // ----------------> rotLeft_v1
    Vector<int> rotArr;
    for (int i = 0; i < 10; i++) {
        rotArr.push_back(i);
    }
    rotArr.printVector();
    myObj.rotLeft_v1(rotArr, 3).printVector();

    std::cout << std::endl << std::endl;

    // ----------------> rotLeft_v2
    Vector<int> rotArr2;
    for (int i = 0; i < 10; i++) {
        rotArr2.push_back(i);
    }
    rotArr2.printVector();
    myObj.rotLeft_v2(rotArr2, 3).printVector();

    std::cout << std::endl << std::endl;

    Vector<int> emptyArr;
    myObj.rotLeft_v2(emptyArr, 4).printVector();

    std::cout << std::endl << std::endl;

    // -----------------> minimumBribes
    Vector<int> bribesArr;
    int bribesTempValue = 0;
    bool bribesFlag = true;

    for (int i = 0; i < 5; i++) {
        bribesTempValue = rand() % 5 + 1;
        bribesFlag = true;

        for (int j = 0; j < i && bribesFlag; j++) {
            if (bribesArr[j] == bribesTempValue) {
                bribesFlag = false;
                i--;
            }
        }
        if (bribesFlag) {
            bribesArr.push_back(bribesTempValue);
        }
    }

    bribesArr.printVector();
    myObj.minimumBribes(bribesArr);

    /*
    Vector<int> allBribes;

    for (int a = 1; a < 6; a++) {
        for (int b = 1; b < 6; b++) {
            for (int c = 1; c < 6; c++) {
                for (int d = 1; d < 6; d++) {
                    for (int e = 1; e < 6; e++) {
                        if (a != b && a != c && a != d && a != e
                                   && b != c && b != d && b != e
                                             && c != d && c != e
                                                       && d != e) {

                            allBribes.push_back(a);
                            allBribes.push_back(b);
                            allBribes.push_back(c);
                            allBribes.push_back(d);
                            allBribes.push_back(e);

                            allBribes.printVector();
                            myObj.minimumBribes(allBribes);
                            std::cout << std::endl;

                            for (int i = 0; i < 5; i++) {
                                allBribes.popBack();
                            }

                        }
                    }
                }
            }
        }
    }
    */

    std::cout << std::endl << std::endl;
    // -----------------> minimumSwaps

    Vector<int> swapsArr = bribesArr;
    swapsArr.printVector();
    std::cout << "Min Swaps: " << myObj.minimumSwaps(swapsArr) << std::endl;

    


	return 0;
}


// link 1

int Fun::hourglassSum(Vector<Vector<int>> arr) {

    int maxSum = 0;
    for (int x = 0; x < 3; x++) {
        for (int y = 0; y < 3; y++) {
            maxSum += arr[x][y];
        }
    }
    maxSum -= arr[1][0];
    maxSum -= arr[1][2];

    int sum = maxSum;
    
    for (int i = 0; i < arr.size() - 2; i++) {
        for (int j = 0; j < arr[i].size() - 2; j++) {
            sum = 0;
            for (int x = 0; x < 3; x++) {
                for (int y = 0; y < 3; y++) {
                    sum += arr[i + x][j + y];
                }
            }
            sum -= arr[i + 1][j];
            sum -= arr[i + 1][j + 2];
            if (sum >= maxSum) {
                maxSum = sum;
            }
        }
    }

    return maxSum;

}

Vector<int> Fun::rotLeft_v1(Vector<int> a, int d) {
    d = d % a.size();
    for (int i = 0; i < d; i++) {
        a.push_back(a[i]);
    }
    for (int i = 0; i < a.size() - d; i++) {
        a[i] = a[i + d];
    }
    for (int i = 0; i < d; i++) {
        a.pop_back();
    }
    return a;

}

Vector<int> Fun::rotLeft_v2(Vector<int> a, int d) {
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

void Fun::minimumBribes(Vector<int> q) {
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

int Fun::minimumSwaps(Vector<int> arr) {
    size_t sizeArr = arr.size();
    int swapCount = 0;

    for (int i = 0; i < sizeArr; i++) {
        if(arr[i] - i != 1){
            int temp = arr[i];
            arr[i] = arr[temp - 1];
            arr[temp - 1] = temp;
            swapCount++;
            i--;
        }
    }

    return swapCount;
}


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

//link 2



int Fun::findPairs(Vector<int> arr) {

    Vector<int> arrPairs;
    bool flag = true;



    int pairsCount = 0;


    for (int i = 0; i < arr.size(); i++) {
        for (int j = 0; flag && j < arrPairs.size(); j += 2) {
            if (arr[i] == arrPairs[j]) {
                flag = false;
                arrPairs[j + 1] = arrPairs[j + 1] + 1;
            }
        }
        if (flag) {
            arrPairs.push_back(arr[i]);
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

int Fun::countingValleys(Vector<char> arr) {
    int level = 0;
    int valleyCount = 0;
    
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == 'U') {
            level++;
            if (level == 0) {
                valleyCount++;
            }
        } else if (arr[i] == 'D') {
            level--;
        }
        
    }

    return valleyCount;
}

int Fun::jumpOnClouds(Vector<int> arr) {
    int jumpCount = 0;
    int i = 0;
    int size = arr.size();

    while (i < size - 1) {
        if (i + 2 < size && arr[i + 2] == 0) {
            i += 2;
        } else {
            i++;
        }
        jumpCount++;
    }

    return jumpCount;
}
