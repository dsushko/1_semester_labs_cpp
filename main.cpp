#include <iostream>
#include <vector>
#include <fstream>

int main() {
    std::ifstream fin("input.txt");
    char str[300];
    int dates_quantity = 0;
    //без 100 грамм конечно не разберешься но попробую пояснить
    //читает по одному слову и сразу его обрабатывает
    while(fin >> str){
        //проверка на формат dd/mm/yyyy
        if(std::strlen(str) == 10)
            //проверка на формат dd/mm/yyyy
            //т.е. допускаю, что год может быть ради формата прописан как 0184
            if(str[2] == '/' && str[5] == '/')
                // чтоб не было 2X-го месяца (типа 21, 27)
                if(str[3] <= '1' && str[3] >='0')
                    // чтоб не было >12-го месяца
                    if(str[4] <= '2' && str[4] >='0') {
                        //проверка по месяцам на дни, 30 или 31
                        // 30 дней
                        if ((str[4] == '4' || str[4] == '6' || str[4] == '9' || (str[3] == '1' && str[4] == '1'))){
                            if(str[0] == '3'){
                                if(str[1] == '0')
                                    dates_quantity++;
                            }
                            if(str[0] < '3' && str[0] >= '0')
                                if(str[1] >= '0' && str[1] <= '9')
                                    dates_quantity++;

                        }
                        // 31 день
                        if ((str[4] == '1' || str[4] == '3' || str[4] == '5' || str[4] == '7' || str[4] == '8' || (str[3] == '1' && str[4] == '0') || (str[3] == '1' && str[4] == '2'))) {
                            if(str[0] == '3'){
                                if(str[1] <= '1' && str[1] >= '0')
                                    dates_quantity++;
                                 }
                            if(str[0] < '3' && str[0] >= '0')
                                if(str[1] >= '0' && str[1] <= '9')
                                    dates_quantity++;

                        }
                        // февраль
                        if(str[3] == '0' && str[4] == '2'){
                            //впадлу делать проверку на високосный год но я бы перевел 4 символа в int и сделал бы через функцию проверку как положено
                            //теперь у февраля нет 29 дня никогда)))
                            if(str[0] == '2')
                                if(str[1] <= '8' && str[1] >='0') {
                                    dates_quantity++;
                                };
                                if(str[0] < '2' && str[0] >= '0')
                                    if(str[1] >= '0' && str[1] <= '9')
                                        dates_quantity++;
                        }
                    };


    }
    fin.close();
    std::ofstream fout("result.txt");
    fout << "Quantity of correct dates in given file - " << dates_quantity;
    fout.close();
    return 0;
}