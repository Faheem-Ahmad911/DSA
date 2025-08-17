#include<iostream>
#include<unordered_map>
#include<string>
#include<sstream>
#include<cctype>
#include<fstream>
using namespace std;

string cleanWord(const string &word) {
    string cleanedWord;
    for (char ch : word) {
        if (isalpha(ch)) {
            cleanedWord += tolower(ch);
        }
    }
    return cleanedWord;
}

int main() {
    ifstream inputFile("sample.txt");
    if (!inputFile.is_open()) {
        cout << "No file found" << endl;
    }

    unordered_map<string, int> wordFrequency;
    string line, rawWord;

    while (getline(inputFile, line)) {
        stringstream ss(line);
        while (ss >> rawWord) {
            string cleanedWord = cleanWord(rawWord);
            if (!cleanedWord.empty()) {
                wordFrequency[cleanedWord]++;
            }
        }
    }
    inputFile.close();

    for (auto &entry : wordFrequency) {
        cout << entry.first << ": " << entry.second << endl;
    }

    return 0;
}
