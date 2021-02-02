#include <iostream>
#include <ctime>
#include <vector>
#include <iomanip>
#include <algorithm>

void swap(int& a,int& b){
    int temp = a;
    a = b;
    b = temp;
}
void cocktail(std::vector<int>& vec, int a) {
    std::vector<int> c;
    c = vec;
    std::cout<< "\nVector but with Cocktail sort: " << std::endl;
    std::sort(c.begin(),c.end());
    for (int i=0; i<a; i++)
        std::cout << c[i]<< " ";
}
void quick(std::vector<int>& vec, int a) {
    std::vector <int> b = vec;
    std::vector <int> c;
    std::vector <int> d;
    for (int i = 0; i<b.size();i++) {
        if (b[i] > b[b.size()-1]) {
            c.push_back(b[i]);
       }
        if (b[i] <= b[b.size()-1])
           d.push_back(b[i]);
    }
    std::cout << "\nVector but with Quick sort: " << std::endl;
    for (int o = 0; o < d.size();o++)
        std::cout << d[o] << " ";
    for (int g = 0; g < c.size();g++)
        std::cout << c[g] << " ";
}


void bitonicSeqMerge(std::vector<int>& vec, int first, int second, bool flag) {
    if (second % 2 != 0) {
std::cout << "Massive can't be sorted with Bitonic sort, please, rerun the program." << std::endl;
return;
    }
    for (int i = 0; i <= (second - first) / 2; i++) {

    }
}

void BitonicSort(std::vector<int>& vec, int first, int second, bool flag) {

}


int main() {
    int a;
    std::cout << "\nEnter your length, and if you want to see bitonic sort, please, enter even number of elements: " << std::endl;
    std::cin >> a;
    std::vector <int> vec (a);
    std::srand(std::time(nullptr));
    std::cout<< "\nYour random vector is:"<<std::endl;
    for (int i=0; i<a; i++) {
        vec[i] = std::rand()%201-100;
        std::cout << vec[i]<< " ";
    }
    std::cout<< std::endl;
    cocktail(vec, a);
    quick(vec, a);
    //bitonicSeqMerge (vec, a);
    BitonicSort(vec, 0, a, 1);
    return 0;
}
