#include <iostream>
#include <fstream>
#include <vector>
#include <string>

int main() {

    std::ifstream fin("input.txt");
    std::vector<std::string> file;
    std::string curr_string;
    while (std::getline(fin, curr_string)) {
        file.push_back(curr_string);
    }
    fin.close();
    int file_lines = file.size();
    std::vector<std::pair<std::string, std::pair<int, int>>> groups_info;
    int vector_index = 0;
    for (int i = 0; i < file_lines; i++) {
        groups_info.push_back(std::make_pair(file[i], std::make_pair(0, i + 1)));
        for (int j = i; j < file_lines; j++) {
            if (file[i] == file[j]) {
                groups_info[vector_index].second.first++;
            }
            else {
                vector_index++;
                i += j - 1 - i;
                break;
            }
            if (j == file_lines - 1) i = file_lines - 1;
        }
    }
    std::ofstream fout("output.txt");
    for (int i = 0; i < groups_info.size(); i++) {
        fout << "group of " << groups_info[i].first << " string\n";
        fout << "repeats " << groups_info[i].second.first << " times\n";
        fout << "first appearance " << groups_info[i].second.second << " line\n";
        fout << "\n";
    }
    fout.close();

    return 0;
}