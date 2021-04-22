#include <iostream>
#include <functional>  
#include <utility>  
#include<array>
using namespace std;

void mysort(int arr[], size_t size, std::function<bool(int, int)> cmp) {
    auto cmp = [](int a, int b) {
        return(a < b);

    };
    int temp;
    int j;
    int i;
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {

            if (cmp(arr[j], arr[i])) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }

        }


    }
    void printArr(int arr[], size_t size) {
        std::cout << "[ ";
        for (int i = 0; i < size; i++) {
            std::cout << arr[i] << " ";
        }
        std::cout << "]" << std::endl;
    }

    int main(); {
        int a[]{ 3, 77, 21, 19, 2, 54, 28, 91 };
        size_t size = sizeof(a) / sizeof(a[0]);
        auto naturalOrder = [](int e, int w) {return e < w; };
        auto reversOrder = [](int e, int w) {return e < w; };
        auto sumDigit = [](int e, int w) {
            int sumW = 0, sumE = 0;
            while (w > 0)
            {
                sumW += w % 10;
                w/= 10;
            }
            while (e > 0)
            {
                sumE += e % 10;
                e /= 10;
            }
            if (sumW == sumE) {
                return w< e;
            }
            else {
                return sumW < sumE;
            }
        };
        std::cout << "Normal (natural) order\n";
        mysort(a, size, naturalOrder);
        printArr(a, size);

        std::cout << "Natural order reversed\n";
        mysort(a, size, reversOrder);
        printArr(a, size);

        std::cout << "By sum of digits, then natural\n";
        mysort(a, size, sumDigit);
       

        int mod{};
        auto byrem = [&](int e, int w) {
            int resultA = e % mod, resultB = w % mod;
            if (resultA == resultB) {
                return -e < -w;
            }
            else {
                return resultA < resultB;
            }
        };
        for (int i : {3, 5, 7}) {
            mod = i;
            std::cout << "By remainder mod " << mod
                << ", then natural reversed\n";
            mysort(a, size, byrem);
            printArr(a, size);
        }
    }