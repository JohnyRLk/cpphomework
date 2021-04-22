#include<iostream>
#include<vector>
#include<math.h>
#include<functional>
using namespace std;
 
 
struct Point {
    double x;
    double y;
};
 
struct Rect {
    Point leftUp;
    Point rightDown;
};
 
std::vector<double> process(const Rect* rects, size_t sz,
    std::function<double(Rect)> f) {
    std::vector<double> result;
    for (size_t j = 0; j < sz; j++) {
        result.push_back(f(rects[j]));
    }
    return result;
}
 
double diagonal(Rect rect) {
    return sqrt(pow(rect.leftUp.y - rect.rightDown.y, 2) + pow(rect.rightDown.x - rect.leftUp.x, 2));
}
 
int main() {
    Rect arr[] = { {{0,4}, {4,1}},
                   {{-6,3}, {6, -2}},
                   {{-7,4}, {8, -4}},
                    { {12,12}, {22,4} } };
 
    std::vector<double> result = process(arr, 4, [](Rect rect) {return (rect.leftUp.y - rect.rightDown.y) * (rect.rightDown.x - rect.leftUp.x); });
 
    for (int j = 0; j < 4; j++) {
        cout << result[j] << endl;
    }
 
    if (result[0] == 12 && result[1] == 60 && result[2] == 120 && result[3] == 80) {
        cout << "Pola zostaly dobrze wyliczone" << endl;
    }
 
    double (*fun)(Rect rect) = diagonal;
 
    std::vector<double> result2 = process(arr, 4, fun);
 
    for (int j = 0; j < 4; j++) {
        cout << result2[j] << endl;
    }
 
    if (result2[0] == 5 && result2[1] == 13 && result2[2] == 17 && result2[3] == sqrt(164)) {
        cout << "Przekatne zostaly dobrze wyliczone" << endl;
    }
 
 
    }