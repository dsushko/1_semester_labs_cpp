#include <iostream>

template <typename T>

void swap(T &a, T &b){
    T temp;
    temp = a;
    a = b;
    b = temp;
}

void diagonal_max(double** &arr, const int &width){
    double current_max;
    int current_max_ind_i = 0, current_max_ind_j = 0;
    //начинаем гнать цикл где видт равен количеству элементов в диагонали попросту
    for(int c = 0; c < width; c++) {
        current_max_ind_i = 0;
        current_max_ind_j = 0;
        current_max = arr[1][0];
        //взял элемент который точно не будет в главной диагонали
        for (int i = 0; i < width; i++) {
            //здесь третий видт это вообщето хайт но мне впадлу создавать еще переменные (целую одну, а коммент писать не в падлу)
            for (int j = 0; j < width; j++) {
                bool prev_max_pos = false;
                //если наткнемся на место, в которое уже засунули какое-то максимальное - валим из цикла, берем следующую ячейку
                for (int o = 0; o < c; o++)
                    if (i == j && j == o)
                        prev_max_pos = true;
                if (prev_max_pos) continue;

                if (arr[i][j] > current_max) {
                    current_max_ind_i = i;
                    current_max_ind_j = j;
                    current_max = arr[i][j];
                }
            }
        }
        swap(arr[c][c], arr[current_max_ind_i][current_max_ind_j]);
    }

}

int main() {
    int width = -1, height = width;

    while(width < 0 || width > 11) {
        std::cout << "Enter the side of matrix (i = j) - ";
        std::cin >> width;
        height = width;
    }
    double** arr = new double*[width];
    for(int i = 0; i < width; i++){
        arr[i] = new double[width];
    }
    std::cout << "Enter your matrix :\n";
    for(int i = 0; i < height; i++){
        for(int j =0; j < width; j++){
            std::cin >> arr[i][j];
        }
    }
    std::cout << "\nYour matrix is:\n";
    for(int i = 0; i < height; i++){
        for(int j =0; j < width; j++){
            std::cout << arr[i][j] << " ";
        }
        std::cout << "\n";
    }

    diagonal_max(arr, width);

    std::cout << "\nYour reworked matrix is:\n";
    for(int i = 0; i < height; i++){
        for(int j =0; j < width; j++){
            std::cout << arr[i][j] << " ";
        }
        std::cout << "\n";
    }

    bool not_positive = false;
    int n_not_positive = -1;

    for(int i = 0; i < height; i++){
        for(int j =0; j < width; j++){
            if(arr[i][j] > 0)
                break;
            if(j == width - 1){
                not_positive = true;
                n_not_positive = i;
            }
        }
        if(not_positive) break;
    }

    if(n_not_positive == -1) std::cout << "There is no string without any positive element";
    else std::cout << "Number of string without any positive number - " << n_not_positive + 1 << " (index - " << n_not_positive << ")";

    return 0;
}