/*
Anna Greene - 2314663
Assignment 1
This file takes in a file via command line and generates summary statistics for the DNA strings
It then generates 1000 new DNA sequences based on a Gaussian distribution
 */

#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

int main(int argc, char **argv){

  ifstream inFS; // Declaring variables and setting default values
  ofstream outFS;
  string dnaSequence = "";
  char input = 'y';

  if(argc > 1){
    string fileName = argv[1]; // Using command line for file one

    // Opening file out stream and writing header
    outFS.open("annagreene.out");
    outFS << "Anna Greene" << endl;
    outFS << "2314663" << endl;
    outFS << "agreene@chapman.edu" << endl;
    outFS << "Assignment 1" << endl;
    outFS << endl;

    // While loop to run statistics and generate new strings while the user wants to continue
    while (input == 'y'){
      // Declaring and initializing all variables to default values
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

      int AACount = 0;
      int ACCount = 0;
      int ATCount = 0;
      int AGCount = 0;
      int CACount = 0;
      int CTCount = 0;
      int CGCount = 0;
      int CCCount = 0;
      int GGCount = 0;
      int GACount = 0;
      int GTCount = 0;
      int GCCount = 0;
      int TTCount = 0;
      int TACount = 0;
      int TGCount = 0;
      int TCCount = 0;

      float aProb = 0.0;
      float cProb = 0.0;
      float gProb = 0.0;
      float tProb = 0.0;

      // Opening input file
      inFS.open(fileName);

      // Checking if file opens properly and if not quit the program
      if(!inFS.is_open()){
        cout << "Error: Could not open file." << endl;
        return 1;
      }
      cout << "Processing file." << endl;

      // While loop to read each line of the file and count each nucleotide
      while(!inFS.eof()){
        // Read each line of the file
        inFS >> dnaSequence;
        if(!inFS.fail()){
          lineCount++; // Updating line count variable
          nucleotideCount = 0; // reseting nucleotideCount for the line to 0
          for(int i = 0; i < dnaSequence.size(); ++i){
            char currNucleotide = toupper(dnaSequence[i]); // Making all nucleotides uppercase
            nucleotideCount++; // Updating nucleotide count for number of nucleotides in the line
            switch (currNucleotide) { // Switch statement to update each nucleotides count
              case 'A':
              aCount++;
              break;
              case 'C':
              cCount++;
              break;case 'T':
              tCount++;
              break;
              case 'G':
              gCount++;
            }
          }
          totalNucleotides += nucleotideCount; // Updating total nucleotide count
        }
      }

      inFS.close();

      // Computing mean and displaying to annagreene.out file
      mean = totalNucleotides/lineCount;

      outFS << fileName << " Summary Statistics" << endl;
      outFS << endl;

      outFS << "sum: " << totalNucleotides << endl;
      outFS << "mean: " << mean << endl;

      // Re-opening file to compute variance and count bigrams
      inFS.open(fileName);

      while(!inFS.eof()){
        // Read each line of the file
        inFS >> dnaSequence;
        if(!inFS.fail()){
          float size = dnaSequence.size() - mean; // Calculating numerator for variance
          variance += pow(size, 2.0); // Continuation of calculation
          // for loop to check the bigram probabilities
          for(int i = 0; i < dnaSequence.size(); i+=2){
            char bigram1 = toupper(dnaSequence[i]); // Making each letter checked upper case
            char bigram2 = toupper(dnaSequence[i+1]);
            if (bigram1 == 'A' && bigram2 == 'A'){ // if-else statements to update bigram counts
              AACount++;
            } else if (bigram1 == 'A' && bigram2 == 'C'){
              ACCount++;
            } else if( bigram1 == 'A' && bigram2 == 'G'){
              AGCount++;
            } else if (bigram1 == 'A' && bigram2 == 'T'){
              ATCount++;
            } else if (bigram1 == 'C' && bigram2 == 'A'){
              CACount++;
            } else if( bigram1 == 'C' && bigram2 == 'G'){
              CGCount++;
            } else if (bigram1 == 'C' && bigram2 == 'T'){
              CTCount++;
            } else if (bigram1 == 'C' && bigram2 == 'C'){
              CCCount++;
            } else if (bigram1 == 'G' && bigram2 == 'G'){
              GGCount++;
            } else if (bigram1 == 'G' && bigram2 == 'T'){
              GTCount++;
            } else if (bigram1 == 'G' && bigram2 == 'A'){
              GACount++;
            } else if (bigram1 == 'G' && bigram2 == 'C'){
              GCCount++;
            } else if (bigram1 == 'T' && bigram2 == 'G'){
              TGCount++;
            } else if (bigram1 == 'T' && bigram2 == 'T'){
              TTCount++;
            } else if (bigram1 == 'T' && bigram2 == 'A'){
              TACount++;
            } else if (bigram1 == 'T' && bigram2 == 'C'){
              TCCount++;
            }
          }
        }
      }
      inFS.close();

      // Calculation of variance and standard deviation
      // Write variance and standard deviaton to annagreene.out
      variance /= (lineCount);
      stdev = sqrt(variance);

      outFS << "variance: " << variance << endl;
      outFS << "standard deviation: " << stdev << endl;

      outFS << endl;

      // Computing relative nucleotide propabilities
      // Writing the results to result file
      aProb = aCount/totalNucleotides;
      cProb = cCount/totalNucleotides;
      tProb = tCount/totalNucleotides;
      gProb = gCount/totalNucleotides;

      outFS << "Relative Nucleotide Probabilities" << endl;
      outFS << "A probability: " << aProb << endl;
      outFS << "C probability: " << cProb << endl;
      outFS << "T probability: " << tProb << endl;
      outFS << "G probability: " << gProb << endl;

      outFS << endl;

      // Computing bigram probabilities
      // Writing propbabilities to output file
      outFS << "Bigram Probabilities" << endl;
      totalNucleotides /= 2;
      outFS << "AA probability: " << AACount/totalNucleotides << endl;
      outFS << "AC probability: " << ACCount/totalNucleotides << endl;
      outFS << "AT probability: " << ATCount/totalNucleotides << endl;
      outFS << "AG probability: " << AGCount/totalNucleotides << endl;
      outFS << "TA probability: " << TACount/totalNucleotides << endl;
      outFS << "TC probability: " << TCCount/totalNucleotides << endl;
      outFS << "TT probability: " << TTCount/totalNucleotides << endl;
      outFS << "TG probability: " << TGCount/totalNucleotides << endl;
      outFS << "CA probability: " << CACount/totalNucleotides << endl;
      outFS << "CC probability: " << CCCount/totalNucleotides << endl;
      outFS << "CT probability: " << CTCount/totalNucleotides << endl;
      outFS << "CG probability: " << CGCount/totalNucleotides << endl;
      outFS << "GA probability: " << GACount/totalNucleotides << endl;
      outFS << "GC probability: " << GCCount/totalNucleotides << endl;
      outFS << "GT probability: " << GTCount/totalNucleotides << endl;
      outFS << "GG probability: " << GGCount/totalNucleotides << endl;

      outFS << endl;


      // For loop to generate 1000 new strings using a Gaussian distribution and nucleotide probability
      for(int i = 0; i < 1000; ++i){
        double a = 0.0;
        double b = 0.0;
        double e = 0.0;

        // generating two random numbers [0,1) for calculation
        a = (rand())/(double)(RAND_MAX);
        b = (rand())/(double)(RAND_MAX);

        // Computing c and d for Gaussian calculation
        c = (sqrt(-2 * log(a)) * cos(2*b*M_PI));
        d = stdev * c + mean;
        d = round(d);

        string newDNA = ""; // declaring and initializing new string of DNA to be appended

        // Generating the new nucleotide sequence using probabilities
        for(int in = 0; in < d; ++in){
          e = (rand())/(double)(RAND_MAX); // generating random number [0,1) to choose nucleotide based on probability
          if(e <= aProb){
            newDNA += "A";
          } else if (e <= (aProb + cProb)){
            newDNA += "C";
          } else if (e <= (aProb + cProb + gProb)){
            newDNA += "G";
          } else if (e <= (aProb + cProb + gProb + tProb)){
            newDNA += "T";
          }
        }
        // Writing new DNA sequence to output file
        outFS << newDNA << endl;
      }
      outFS << endl;
      cout << "Summary Statistics added to annagreene.out" << endl;

      // Asking user if they would like to process andother list
      // Using input to rerun the program or exit
      cout << "Would you like to process another list? (y/n)" << endl;
      cin >> input; // Read user input
      char in = tolower(input);
      while (in != 'n' && in != 'y'){ // While statement to check for valid input
        cout << "Invalid input." << endl;
        cout << "Would you like to process another list? (y/n)" << endl;
        cin >> input;
        in = tolower(input);
      }
      // if-else statment to break or continue
      if(in == 'n'){
        outFS.close();
        break;
      } else if(in == 'y'){
        cout << "Please enter new file name: " << endl;
        cin >> fileName;
      }
    }

    // else statement for if a text file is not given via command line
  } else{
    cout << "INVALID USAGE: please enter name of a text file" << endl;
    cout << "USAGE: ./a.out [file name]" << endl;
  }

  return 0;
}
