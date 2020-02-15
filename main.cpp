#include <iostream>
#include <fstream>
#include <cmath>
// #include "math.h"

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
      double stdev = 0.0;
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
      variance /= (lineCount-1); // Should we account for if there is only one line
      stdev = sqrt(variance);

      outFS << "variance: " << variance << endl;
      outFS << "standard deviation: " << stdev << endl;

// RElative probablilities
      outFS << "A probability: " << aCount/totalNucleotides << endl;
      outFS << "C probability: " << cCount/totalNucleotides << endl;
      outFS << "T probability: " << tCount/totalNucleotides << endl;
      outFS << "G probability: " << gCount/totalNucleotides << endl;

// Bigram probabilities

    double a = 0.0;
    double b = 0.0;

    a = rand();
    b = rand();

    c = sqrt((-2 * log(a)) * cos(2*b*M_PI));
    d = stdev * c + mean;

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
