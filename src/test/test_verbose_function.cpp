#include <iostream>
#include <list>


using namespace std;

// The function signature remains the same, accepting a list of strings
int is_verbose_mode(list<string> args) {
    for (auto const& arg : args) { // Use const reference for efficiency
        cout << arg << endl;
    }
    return 0;
};

int main(int argc, char* argv[]) {
    // 1. Create a container (list or vector) for the arguments.
    list<string> args_list;

    // 2. Iterate through the command-line arguments using argc and argv.
    // Loop from index 0 to argc - 1.
    for (int i = 0; i < argc; i++) {
        // 3. Convert each char* to std::string and add it to the list.
        args_list.push_back(string(argv[i]));
    }
    
    // 4. Pass the correctly populated list to the function.
    is_verbose_mode(args_list);

    return 0;
}
