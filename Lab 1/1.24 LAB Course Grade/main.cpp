#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

int main() {
/* TODO: Declare any necessary variables here. */
ifstream inFile;
ofstream outFile;
string lastName;
string firstName;
string fileName;
int midterm1;
int midterm2;
int final;
int midterm1Total = 0;
int midterm2Total = 0;
int finalTotal = 0;
int count = 0;
double avgScore;
double avgMidterm1;
double avgMidterm2;
double avgFinal;
char grade;
 
/* TODO: Read a file name from the user and read the tsv file here. */
cin >> fileName;
inFile.open(fileName);
outFile.open("report.txt");

while (inFile >> lastName >> firstName >> midterm1 >> midterm2 >> final) 
{
   midterm1Total += midterm1;
   midterm2Total += midterm2;
   finalTotal += final;
   count ++;

   /* TODO: Compute student grades and exam averages, then output results to a text file here. */
   avgScore = (double)(midterm1 + midterm2 + final)/3;
   if (avgScore >= 90)
   {
       grade = 'A';
   }
   else if (avgScore >= 80)
   {
       grade = 'B';
   }
   else if (avgScore >= 70)
   {
       grade = 'C';
   }
   else if (avgScore >= 60)
   {
       grade = 'D';
   }
   else
   {
       grade = 'F';
   }
   outFile << lastName << '\t' << firstName << '\t' << midterm1 << '\t' << midterm2 << '\t' << final << '\t' << grade << endl;
}
avgMidterm1 = (double) midterm1Total/count;
avgMidterm2 = (double) midterm2Total/count;
avgFinal = (double) finalTotal/count;

outFile << endl << "Averages: midterm1 " << fixed << setprecision(2) << avgMidterm1 << ", midterm2 " << fixed << setprecision(2) << avgMidterm2 << ", final " << fixed << setprecision(2) << avgFinal << endl;
inFile.close();
outFile.close();
   return 0;
}
