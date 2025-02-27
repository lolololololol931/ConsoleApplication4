#include <iostream>
#include <algorithm>
#include <string>
#include <fstream>
#include <CoreWindow.h>
#include <vector>
using namespace std;

bool startsWithOA(const string& word) {
    char firstChar = tolower(word[0]); 
    return (firstChar == 'o' || firstChar == 'a');
}
void swapFileContents(const string& file1, const string& file2, const string& tempFile) {
    vector<char> content1, content2;
    ifstream inFile1(file1);
    if (!inFile1) {
        cerr << "Помилка відкриття " << file1 << endl;
        return;
    }
    char ch;
    while (inFile1.get(ch)) {
        content1.push_back(ch);
    }
    inFile1.close();
    ifstream inFile2(file2);
    if (!inFile2) {
        cerr << "Помилка відкриття " << file2 << endl;
        return;
    }
    while (inFile2.get(ch)) {
        content2.push_back(ch);
    }
    ofstream tempOut(tempFile);
    for (char c : content1) {
        tempOut.put(c);
    }
    ofstream outFile1(file1);
    for (char c : content2) {
        outFile1.put(c);
    }
    ofstream outFile2(file2);
    for (char c : content1) {
        outFile2.put(c);
    }
    cout << "файли поміняні місцями!" << endl;
}


int main()
{
    system("chcp 1251>nul");
    //n1
    ifstream file("numbers.txt");
    ofstream file1("numbersparn.txt"), file2("numbersneparn");
    if (!file) {
        cerr << "не відкривається" << endl;
        return 1;
    }
    int num;
    while (file >> num) {
        if (num % 2 == 0) {
            file1 << num <<' ';
        }
        else {
            file2 << num <<' ';
        }
    }
    cout << "завдання 1 виконано, перевірте файли!";
    Sleep(3000);
    file.close();
    file1.close();
    file2.close();
    cout << "\033[2J\033[1;1H"; //очищення екрана
    cout << "Завдання 2";
    //n2
    ifstream fileWords("words.txt");
    ofstream fileInWords("OAletters.txt");
    if (!fileWords) {
        cerr << "pomilka" << endl;
        return 1;
    }
    vector<string> wordsAO;
    string word;
    while (fileWords >> word) {
        wordsAO.push_back(word);
    }
    for (const string& w : wordsAO) {
        if (startsWithOA(w)) {
            fileInWords << w << endl;
        }
    }
    cout << "Завдання 2 виконано, перевірте файли";
    Sleep(3000);
    cout << "\033[2J\033[1;1H"; //очищення екрана
    //n3
    swapFileContents("file1word.txt", "file2word.txt", "temp.txt"); 
    cout << "Завдання 3 виконано, перевірте файли";
    Sleep(1000);
    cout << "\033[2J\033[1;1H"; //очищення екрана
}

