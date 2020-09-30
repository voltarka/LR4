#include <iostream>
#include <ctime>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <bits/stdc++.h>

void cocktail(std::vector<int>& vec, int a){
    std::vector<int> c;
    c = vec;
    std::cout<< "\nVector but with Cocktail sort: " << std::endl;
    std::sort(c.begin(),c.end());
    for (int i=0; i<a; i++)
    std::cout << c[i]<< " ";

}
void swap(int& a, int& i){
  int m = a;
  a = i;
  i = m;
}

void quick(std::vector<int>& vec, int a){
    int m;
    std::vector<int> b;
    b = vec;
    std::cout<< "\nVector but with Quick sort: " << std::endl;
    int f = b[a-1];
     for (int i=0; i< a; i++){
         if (b[i] < f){
             m=b[i];
             b[i]=b[a-1];
             b[a-1]=m;
 std::cout<< b[i]<<" ";
         }

     }


}


int main() {
    int a;
    std::cout << "\nEnter your length: " << std::endl;
    std::cin >> a;
        std::vector<int> vec (a);
    std::srand(std::time(nullptr));
    std::cout<< "\nYour random vector is:"<<std::endl;
    for (int i=0; i<a; i++){
        vec[i] = std::rand()%201-100;
        std::cout << vec[i]<< " ";
    }
    std::cout<< std::endl;
    cocktail(vec, a);
    quick(vec,a);

    return 0;
}

