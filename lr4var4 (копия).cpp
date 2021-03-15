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

void quick (vector<int>& vec, int first, int last) { // функция берет последний элемент как поворотный
    int pivot = vec[vec.size()-1];                      // все меньшие элементы перекидывает налево
    int i = first - 1;                                  // все большие направо от него
    for (int j = first; j <= last - 1; j++) {
        if (vec[j] <= pivot) {
            i++;
            swap(vec[i], vec[j]);
        }
    }
    swap(vec[i + 1], vec[last]);
}


void merge (vector<int>& vec, int first, int last, bool flag) {
    if (first == last)
        return;
    for (int i = 0; i <= (last - first) / 2; i++) {
        if (flag) {
            if (vec[first + i] > vec[(first + last) / 2 + i + 1])
                swap(vec[first + i], vec[(first + last) / 2 + i + 1]);
        } else {
            if (vec[first + i] < vec[(first + last) / 2 + i + 1]) {
                swap(vec[first + i], vec[(first + last) / 2 + i + 1]);
            }
        }
    }
    merge(vec, first, (last + first) / 2, flag);
    merge(vec, (last + first) / 2 + 1, last, flag);
}

void bitonic (vector<int>& vec, int first, int last, bool flag) {
    if (first == last)
        return;
    bitonic(vec, first, (first+last)/2, true);
    bitonic(vec, (first+last)/2 + 1, last,  false);
    merge (vec, first, last, flag);
}
void print(vector <int>& vec) {
    for (int i = 0; i < vec.size(); i++)
        cout << vec[i] << " ";
    cout << std::endl;
}

int main() {
    string s;
    int a;
    cout << "\nEnter your length, and if you want to see bitonic sort, please, enter even number of elements: "
              << endl;
    cin >> a;
    vector<int> vec(a);
    srand(std::time(nullptr));
    cout << "\nYour random vector is:" << std::endl;
    for (int i = 0; i < a; i++) {
        vec[i] = rand() % 201 - 100;
        cout << vec[i] << " ";
    }
    cout << std::endl;

    cocktail(vec);
    cout << "Your vector with cocktail sort: \n";
    print(vec);
    cout << endl;

    quick(vec, 0, vec.size()-1);
    cout << "Your vector with quick sort: \n";
    print(vec);
    cout << endl;

    bitonic(vec, 0, 15, true);
    cout << "Your vector with bitonic sort: \n";
    print(vec);
    cout << endl;

    return 0;
}
