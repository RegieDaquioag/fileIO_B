// Name: Regie Daquioag
// Date: October 23, 2015
// Project: File IO B

#include <fstream>
#include <iostream>
#include <cctype>
#include <cstdlib>
#include<string>
#include <iomanip>
using namespace std;

int main()
{
    ifstream fin;
    ofstream fout;
    string winner;
    string firstName, lastName;
    double num;
    double s1, s2, s3, s4, s5, s6;
    double highestScore = 0;
    double avg;
    char userFile[12];
    
    cout << "Please enter the file name." << endl;
    cin >> userFile;

    fin.open(userFile);
    fout.open("results.txt");

    if(fin.fail())
    {
        cout << "Error on input file" << endl;
        exit(1);
    }
    
    if( fout.fail())
    {
        cout << "Error on output file" << endl;
        exit(1);
    }
    
    while(fin >> firstName >> lastName >> s1 >> s2 >> s3 >> s4 >> s5 >> s6)
    {
        fout.setf(ios::fixed);
        fout.setf(ios::showpoint);
        fout.precision(1);
        fout.setf(ios::left);
        
        avg = (s1 + s2 + s3 + s4 + s5 ) / 5; 
         
        if(avg >= highestScore)
        {
            winner = firstName + " " + lastName;
            highestScore = avg;
        }
        
        fout << setw(12) << firstName << setw(12) << lastName << setw(8) << s1 << setw(8) << s2 << setw(8) 
             << s3 << setw(8) << s4 << setw(8) << s5 << setw(8) << setw(8);
        
        fout.precision(2);     
             
        fout << avg << endl;   
             
    }
 
    fout << setw(10) << "\nHighest score: " << winner  << endl;
    
    fout.close();
    fin.close();

    return 0;
}
