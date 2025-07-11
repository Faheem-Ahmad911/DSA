#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Folder {
    vector<string> files;
    vector<Folder> subfolders;
};

bool searchFile(Folder folder, string fileToFind) {
    for (int i = 0; i < folder.files.size(); i++) {
        if (folder.files[i] == fileToFind) {
            return true;
        }
    }

    for (int i = 0; i < folder.subfolders.size(); i++) {
        bool found = searchFile(folder.subfolders[i], fileToFind);
        if (found) {
            return true;
        }
    }

    return false; 
}

int main() {
    Folder deepFolder;
    deepFolder.files.push_back("deepfile.txt");
    deepFolder.files.push_back("target.txt");

    Folder folder1;
    folder1.files.push_back("fA.txt");
    folder1.files.push_back("fB.txt");

    Folder folder2;
    folder2.files.push_back("fileC.txt");
    folder2.subfolders.push_back(deepFolder);

    Folder rootFolder;
    rootFolder.files.push_back("main.txt");
    rootFolder.files.push_back("notes.txt");
    rootFolder.subfolders.push_back(folder1);
    rootFolder.subfolders.push_back(folder2);

    string filename;
    cout << "Enter filename to search: ";
    cin >> filename;

    bool isFound = searchFile(rootFolder, filename);

    if (isFound) {
        cout << "File found" << endl;
    } else {
        cout << "File not found" << endl;
    }

    return 0;
}
