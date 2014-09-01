#include <iostream>
#include <fstream>
#include <cstdint>
#include <vector>
#include <string>
#include <iterator>

using namespace std;

const unsigned int memory_size = 30000;



int main(int argc, char* argv[]) {
    if(argc < 2) return -1;
    ifstream fin(argv[1]);
    vector<uint8_t> memory(memory_size);
    int ptr = 0, row = 0;
    string program((std::istreambuf_iterator<char>(fin)),
                    std::istreambuf_iterator<char>());
    while(program.size() > row) {
        switch (program.at(row)) {
        case '+':
            memory.at(ptr)++;
            break;
        case '-':
            memory.at(ptr)--;
            break;
        case '<':
            if(ptr > 0) ptr--;
            else ptr = memory_size;
            break;
        case '>':
            if(ptr < memory_size) ptr++;
            else ptr = 0;
            break;
        case '.':
            cout.put(memory.at(ptr));
            break;
        case ',':
            memory.at(ptr) = cin.get();
            break;
        case '[':
            if(memory.at(ptr) == 0) {
                int i = 1;
                do {
                    row++;
                    char c = program.at(row);
                    if(c == '[') i++;
                    if(c == ']') i--;
                } while(i);
            }
            break;
        case ']':
            if(memory.at(ptr) != 0) {
                int i = 1;
                do {
                    row--;
                    char c = program.at(row);
                    if(c == ']') i++;
                    if(c == '[') i--;
                } while(i);
            }
            break;
        }
        row++;
    }
    cout << endl;
    return 0;
}
