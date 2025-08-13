#include<iostream>
#include<unordered_map>
#include<string>
#include<sstream>
#include<cctype>
#include<fstream>
using namespace std;

string extract(const string & word){
    string cleanword;
    for (char ch : word){
        if (isalpha(ch)){
            cleanword+=tolower(ch);
        }
    }
    return cleanword;
}

int main()
{   ifstream file("sample.txt");
    if (!file.is_open()){
        cout<<"No file found"<<endl;
    }
    unordered_map<string,int> wordfreq;
    string line,word;
    while (getline(file,line))
    {
       stringstream ss(line);
       while (ss >> word)
       {
        string cleanw = extract(word);
        if (!cleanw.empty()){
            wordfreq[cleanw]++;
        }
       }
       
    }
    file.close();

    for (auto &entry : wordfreq) {
        cout << entry.first << ": " << entry.second << endl;
    }
    
      return 0;
}