#include <iostream>
#include <fstream>
#include <string>
#include <unistd.h>
#include <filesystem>
#include <sstream>
#include <vector>
#include <json/value.h>

using namespace std;

int main() {

    // Get path to the file (workdir)
    char *workdir = get_current_dir_name();
    std::cout << "Current working directory: " << workdir << std::endl;

    std::string txt_datafile = std::string(workdir) + "/data.txt";
    std::string csv_datafile = std::string(workdir) + "/data.csv";
    std::string tsv_datafile = std::string(workdir) + "/data.tsv";
    std::string json_datafile = std::string(workdir) + "/data.json";

    std::cout << "current working directory: " << workdir << std::endl;
    std::cout << "txt datafile path: " << txt_datafile << std::endl;
    std::fstream newfile;

    // writing data (.txt)
    newfile.open(txt_datafile, std::ios::out);
    if (newfile.is_open()) {
        for (int i=0; i<100; i++){
            newfile << i << "\n";
        }
        newfile.close();
    }

    // reading data (.txt)
    newfile.open(txt_datafile, std::ios::in);
    if (newfile.is_open()) {
        std::string data;
        while(std::getline(newfile, data)) {
            std::cout << data << "\n";
        }
        newfile.close();
    }

    // reading data (.csv)
    // using vector
    vector<vector<string>> content;
    vector<string> row;
    string line, word;

    // fstream file (csv_datafile, ios::in);
    std::cout << "csv datafile path: " << csv_datafile << std::endl;
    newfile.open(csv_datafile, std::ios::in);
    if (newfile.is_open()){
        while (getline(newfile, line)){
            row.clear();
            stringstream str(line);
            while (getline(str, word, ','))
                row.push_back(word);
            content.push_back(row);
        }
        newfile.close();
    }
    else {
        cout << "Could not open the file\n";
    }

    // for (vector<vector<string>>::iterator row = content.begin(); row != content.end(); row++) {
    //     for (vector<string>::iterator col = row->begin(); col != row->end(); col++) {
    //         cout << "line token: " << *col << ", ";
    //     }
    // }

    for (auto& row : content) {
        // cout << "size: " << row.size() << "\n";
        int size = row.size();
        for (int i=0; i<row.size()-1; i++){
            cout << row[i] << ", ";
        }
        cout << row[size - 1] << "\n";
    }

    // using .json data
    vector<vector<string>> json_data;


    free(workdir);
    return 0;
}