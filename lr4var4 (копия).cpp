#include <iostream>
#include <ctime>
#include <vector>
using namespace std;

void swap (int& a, int& b) {
    int c = a;
    a = b;
    b = c;
}

void cocktail (vector<int>& vec) {  //аналогично бабл сорту, только в две стороны
    int left = 0;
    int right = vec.size()-1;
    int size = vec.size();
    do {
        for (int i = left; i < right; i++) {
           if (vec[i] > vec[i+1])
               swap (vec[i], vec[i+1]);
           size = i;
        }
        right = size;
        for (int i = right; i > left; i--) {
            if (vec[i] < vec[i-1])
                swap(vec[i], vec[i-1]);
            size = i;
        }
        left = size;
    }
    while (left < right);
}

void quick(vector<int>& vec, int begin, int end)
{
    int i = begin;
    int j = end;
    int pivot = vec[(i + j) / 2];
    while (i <= j)
    {
        while (vec[i] < pivot)
            i++;
        while (vec[j] > pivot)
            j--;
        if (i <= j)
        {
            swap(vec[i], vec[j]);
            i++;
            j--;
        }
    }
    if (j > begin)
        quick(vec, begin, j);
    if (i < end)
        quick(vec, i, end);
}

void merge (vector<int>& vec2, int first, int last, bool flag) {
    if (first == last)
        return;
    for (int i = 0; i <= (last - first) / 2; i++) {
        if (flag) {
            if (vec2[first + i] > vec2[(first + last) / 2 + i + 1])
                swap(vec2[first + i], vec2[(first + last) / 2 + i + 1]);
        } else {
            if (vec2[first + i] < vec2[(first + last) / 2 + i + 1]) {
                swap(vec2[first + i], vec2[(first + last) / 2 + i + 1]);
            }
        }
    }
    merge(vec2, first, (last + first) / 2, flag);
    merge(vec2, (last + first) / 2 + 1, last, flag);
}

void bitonic (vector<int>& vec2, int first, int last, bool flag) {
    if (first == last)
        return;
    bitonic(vec2, first, (first+last)/2, true);
    bitonic(vec2, (first+last)/2 + 1, last,  false);
    merge (vec2, first, last, flag);
}
void print(vector <int>& vec) {
    for (int i = 0; i < vec.size(); i++)
        cout << vec[i] << " ";
    cout << std::endl;
}

bool PowerOfTwo(int& Value)
{
    int InitValue = 1;
    while (InitValue < Value)
        InitValue *= 2;
    if (InitValue == Value)
        return true;
    return false;
}

int main() {
    string s;
    int a;
    cout << "\nEnter your length, and if you want to see bitonic sort, please, enter a number that is a power of two: "
              << endl;
    cin >> a;
    if (PowerOfTwo(a)) {
        cout << "Thank u for the right number" << endl;
    }
    else {
        cout << "Bitonic sort won't work with this number of elements. Please, rerun the program and enter another one" << endl ;
        return 0;
    }
    vector<int> vec(a);
    srand(std::time(nullptr));
    cout << "\nYour random vector for cocktail sort is:" << endl;
    for (int i = 0; i < a; i++) {
        vec[i] = rand() % 201 - 100;
        cout << vec[i] << " ";
    }
    cout << endl;

    cocktail(vec);
    cout << "Your vector with cocktail sort: \n";
    print(vec);
    cout << endl;

    vector<int> vec1(a);
    cout << "\nYour random vector for quick sort is:" << endl;
    for (int i = 0; i < a; i++) {
        vec1[i] = rand() % 201 - 100;
        cout << vec1[i] << " ";
    }
    cout << endl;
    quick (vec1, 0, a-1);
    cout << "Your vector with quick sort: \n";
    print(vec1);
    cout << endl;

    vector<int> vec2(a);
    cout << "\nYour random vector for bitonic sort is:" << endl;
    for (int i = 0; i < a; i++) {
        vec2[i] = rand() % 201 - 100;
        cout << vec2[i] << " ";
    }
    cout << endl;
    bitonic(vec2, 0, a-1, true);
    cout << "Your vector with bitonic sort: \n";
    print(vec2);
    cout << endl;

    return 0;
}
