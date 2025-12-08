// Import library/module
#include <iostream>
#include <filesystem>
#include <list>

// Set namespaces
using namespace std;
using namespace filesystem;



list<string> files_list(string path){
    // Set variable
    list<string> files;

    // For any file in dir , 
    for (auto file : directory_iterator(path)) {
        files.push_back(file.path().filename().string());
    }

    return files;
}

int main() {

    list<string> files = files_list(".");

    for (auto file : files){
        cout << file << endl;
    }

    return 0;
}
