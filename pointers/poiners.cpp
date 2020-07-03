#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    string a1 = "mas";
    // A  pointer to the address of a variable in memory.
    string *a2 = &a1;
    cout << "a1: " << a1 << endl;
    //a2[0] = "k";
    cout << "a2: " << *(a2) << endl;


    // Create a string "Tota" and assign to var word,
    // which has one more element to end the string '\0'.
    char word[5] = "Tota";
    // Define a cont pointer, which can't modify 
    // the value of word variable.
    const char *label = word;
    char word2[5];
    const char *label2 = label;
    strcpy(word2, label2);
    cout << label << endl;
    cout << label + 1 << endl;
    cout << word2 << endl;

    char b[4] = "mas";
    cout << "b: " << b << endl;

    char c[5];
    c[0] = 'B';
    c[1] = 'o';
    c[2] = 'd';
    c[3] = 'a';
    c[4] = '\0';
    cout << "c: " << c << endl;

    return 0;
}
