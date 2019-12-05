#include <fstream>

using namespace std;

void heapify(int arr[], int n, int i) { //построение бинарного сортирующевого дерева
    int largest = i; // корень
    int l = 2 * i; //правый ребенок
    int r = 2 * i + 1; //левый ребенок
    if (l < n && arr[l] > arr[largest]) { //если левый больше, то в корень
        largest = l;
    }
    if (r < n && arr[r] > arr[largest]) { //если правый больше, то в корень
        largest = r;
    }
    if (largest != i) { // если largest не корень
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}


void heapSort(int arr[], int n) { // функция пирамидальной сортировки
    for (int i = n / 2 - 1; i >= 0; i--) { //построение кучи
        heapify(arr, n, i);
    }
    for (int i = n - 1; i >= 0; i--) { //перебираем элементы
        swap(arr[0], arr[i]); //передвигаем элемент в корень
        heapify(arr, i, 0); //вызываем функцию построения дерева от нового набора
    }
}

int main() {
    ifstream in ("sort.in");
    ofstream out ("sort.out");
    int n;
    in >> n;
    int arr[n];
    for (int i = 0; i < n; i++) { //ввели массив
        in >> arr[i];
    }
    heapSort(arr, n); //вызвали сортировку
    for (int i = 0; i < n; ++i) {
        out << arr[i] << " ";
    }
}