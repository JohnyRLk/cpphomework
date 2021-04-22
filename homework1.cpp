#define TEST_FOR_EQL 1
#define TEST_FOR_STAR 2 
#define DO_TEST(NAME1, NAME2) DO_TEST_impl(NAME1, NAME2)
#define DO_TEST_impl(NAME1, NAME2) TEST_FOR_ ## NAME1 == TEST_FOR_ ## NAME2
#define NAME EQL
#include <iostream>
void histo(int arr[], size_t size) {

#if DO_TEST(NAME, STAR)
        int height = arr[0];
        for (int k = 0; k < size; k++) {
            if (arr[k] > height) {
                height = arr[k];
            }
}
        for (int j = height; j >= 1; j--) {
            for (int l = 0; l <= size; l++) {
                if (arr[l] >= j) {
                    std::cout << "*";
                }
                else {
                    std::cout << " ";
                }
            }
            std::cout << " " << std::endl;
        }
#elif DO_TEST(NAME, EQL)
        int height = arr[0];
        for (int k = 0; k < size; k++) {
            if (arr[k] > height) {
                height = arr[k];
}
}
        for (int j = height; j >= 1; j--) {
            for (int l = 0; l <= size; l++) {
                if (arr[l] >= j) {
                    std::cout << "=";
                }
                else {
                    std::cout << " ";
                }
            }
            std::cout << " " << std::endl;
        }
#else
        std::cout << "Mikro procesor nie zostal zdefiniowany" << std::endl;
#endif
    

}
int main() {
    int arr[]{ 2,1,0,7,1,9 };
    size_t size = sizeof(arr) / sizeof(*arr);
    histo(arr, size);

    return 0;

}