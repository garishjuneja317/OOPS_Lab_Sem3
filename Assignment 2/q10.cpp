#include <iostream>
using namespace std;
void compress(const char* input, char* output) {
    const char* inPtr = input;
    char* outPtr = output;
    while (*inPtr != '\0') {
        char currentChar = *inPtr;
        int count = 0;
        while (*inPtr == currentChar && count < 9) {
            count++;
            inPtr++;
        }
        *outPtr = currentChar;
        *(outPtr + 1) = '0' + count;
        outPtr = outPtr + 2;
    }
    *outPtr = '\0';
}
void decompress(const char* input, char* output) {
    const char* inPtr = input;
    char* outPtr = output;
    while (*inPtr != '\0') {
        char currentChar = *inPtr;
        int count = *(inPtr + 1) - '0'; 
        for (int i = 0; i < count; i++) {
            *outPtr = currentChar;
            outPtr++;
        }
    }
}
int main() {
    char input[100];
    char compressed[200];
    char decompressed[200];
    cout << "Enter a string of letters to compress (e.g., AAAAABBBCC): ";
    cin >> input;
    compress(input, compressed);
    cout << "Compressed array: " << compressed << endl;
    decompress(compressed, decompressed);
    cout << "Decompressed array: " << decompressed << endl;
    return 0;
}