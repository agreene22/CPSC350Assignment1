#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

int main(int argc, char **argv){

  ifstream inFS;
  ofstream outFS;
  string dnaSequence;
  string input = "y";

  if(argc > 1){
    string fileName = argv[1];

    while (input == "y"){
      float lineCount = 0.0;
      int nucleotideCount = 0;
      float totalNucleotides = 0.0;
      int aCount = 0;
      int tCount = 0;
      int gCount = 0;
      int cCount = 0;
      double variance = 0.0;
      double mean = 0.0;
      double c = 0.0;
      double d = 0.0;

      inFS.open(fileName);

      while(!inFS.eof()){
        inFS >> dnaSequence;
        if(!inFS.fail()){
          lineCount++;
          cout << dnaSequence << endl; //WHY IS IT DOING THE LAST LINE OF THE FILE TWICE????
          cout << lineCount << endl;
          nucleotideCount = 0;
          for(int i = 0; i < dnaSequence.size(); ++i){
            char currNucleotide = toupper(dnaSequence[i]);
            nucleotideCount++;
            switch (currNucleotide) {
              case 'A':
              aCount++;
              cout << aCount << " "; // Remove these print statements later
              break;
              case 'C':
              cCount++;
              cout << cCount << " ";
              break;case 'T':
              tCount++;
              cout << tCount << " ";
              break;
              case 'G':
              gCount++;
              cout << gCount << " ";
            }
            cout << currNucleotide << endl; // Remove this later
          }
          totalNucleotides += nucleotideCount;
        }
        cout << "total " << totalNucleotides << endl;
      }

      inFS.close();
      outFS.open("annagreene.out");

      // compute sum, mean, variance, standard deviation
      outFS << "Anna Greene" << endl;
      outFS << "2314663" << endl;
      outFS << "agreene@chapman.edu" << endl;
      outFS << "Assignment 1" << endl;
      outFS << endl;

      cout << totalNucleotides << " " << lineCount << endl;
      mean = totalNucleotides/lineCount;

      outFS << "sum: " << totalNucleotides << endl;
      outFS << "mean: " << mean << endl;

      inFS.open(fileName);

      while(!inFS.eof()){
        inFS >> dnaSequence;
        if(!inFS.fail()){
          float size = dnaSequence.size() - mean;
          variance += pow(size, 2.0);
          // cout << variance << endl;
        }
      }
      inFS.close();

      // variance = ((each length - mean)^2 all added together)/lineCount
      // cout << lineCount << " ";
      variance /= (lineCount-1); //NOT WORKING, I ASSUME BECAUSE OF FLOAT/INT ERROR

      outFS << "variance: " << variance << endl;

      outFS.close();

      cout << "Would you like to process another list? (y/n)" << endl;
      cin >> input;
      if(input == "n"){
        break;
      } else{
        cout << "Please enter new file name: " << endl;
        cin >> fileName;
      }

    }

  } else{
    cout << "INVALID USAGE: lease enter name of a text file" << endl;
    cout << "USAGE: ./a.out [file name]" << endl;
  }

  return 0;
}
