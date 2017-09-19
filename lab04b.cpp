#include <iostream>
#include <string>
#include <cstdlib> 
#include <vector>
#include <map>
#include <fstream>
    
using namespace std;
    
int main() {
    map<int, vector<string>> length_words;
    
    /*length_words[1] = {"a", "i"};
    length_words[2] = {"be", "my", "of", "to"};
    length_words[3] = {"for", "ate", "bar", "may", "sit", "coo"};
    length_words[4] = {"four", "date", "bard", "leaf", "seat", "cool"};*/
    // open dictionary and read in all the words
    cout << "Reading dictionary...";
    ifstream fin("dictionary.txt");
    if (!fin) {
        cerr << "Could not open 'dictionary.txt' for reading, exiting." << endl;
        return -1;
    }//stright up taken from lab04.cpp
    
    while(!fin.eof()){
        string s;
        fin >> s;
        length_words[s.length()].push_back(s);
    }
         
    int n = 0;
    while (true) {
        cout << "What length of word do you want? ";
        cin >> n;
        if (n < 1) break;
        else if(n > length_words[n].size()){
            cout << "No words of size " << n << endl;
        }else if(length_words[n].empty()){
            cout << "No words of size " << n << endl;            
        }else{
            cout << "Here's a word: ";
            cout << length_words[n][rand() % length_words[n].size()];
            cout << endl;
        }
    }
        
    return 0;
}
