#include <cstdio>
#include <fstream>
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;
int main() {
    std::unordered_map<string, unsigned> isbn_count{};
    ifstream infile;
    string isbn;

    infile.open("./input.txt");
    while (infile >> isbn) {
        // isbn_count[isbn] += 1
        if (isbn_count.find(isbn) != isbn_count.end()) {
            isbn_count[isbn]++;
        } else {
            isbn_count.insert({isbn, 1});
        }
    }

    for (const auto &elem : isbn_count) {
        cout << elem.first << ": " << elem.second << endl;
    }
    infile.close();

    cout << endl;
    return 0;
}
