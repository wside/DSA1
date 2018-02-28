//Wendy Ide

/*
-This program reads commands from an input text file (line by line), processes those commands, and writes the results to an output .txt
-Based on the commands, the program creates stacks and queues of type int, double, or string. 
-It stores pointers to all of the stacks and queues of each data type in a c++ defined list. 
-There are three of these lists (one for each data type).
-The stacks and queues themselves are made from a user defined simply linked list class.
-It pushes and pops off these stacks and queues and writes the popped values or error messages to the output file.
-All the classes are template based.
*/

#include "process.h"  //process.h includes classes.h

#include <iostream>
#include <fstream>
#include <sstream>
#include <iterator>
#include <string>
#include <list>

using namespace std;  //not best practice, but ok for .cpp files

list<SimpleList<int> *> listSLi;    // all integer stacks and queues
list<SimpleList<double> *> listSLd; // all double stacks and queues
list<SimpleList<string> *> listSLs; // all string stacks and queues

SimpleList<int> *pSLi;
SimpleList<double> *pSLd;
SimpleList<string> *pSLs;

list<SimpleList<int> *>::iterator itI;      //These iterators could have been declared inside process.cpp to minimize scope, but
list<SimpleList<double> *>::iterator itD;   //declared globally here to avoid constructing and destructing for each input file command.
list<SimpleList<string> *>::iterator itS;   //Program timed in terminal taking in 2,000 lines showed no difference in avg. runtime, 
                                            //but better to declare globally in case input file has 100,000+ lines

int main () 
{

  pSLi = new Stack<int>("no match");   //declare dummy tail node named "no match" for listSLi.
  listSLi.push_front(pSLi);            
                                                                                                                        
  pSLd = new Stack<double>("no match");   //will never populate these "no match" nodes with anything
  listSLd.push_front(pSLd);

  pSLs = new Stack<string>("no match");
  listSLs.push_front(pSLs);

  string line;
  string word1, word2, word3;
  string input_name;
  string output_name;

  cout << "Enter name of input file: ";
  cin >> input_name;                        
  cout << "Enter name of output file: ";               
  cin >> output_name;
  
  ifstream myfile;
  myfile.open(input_name.c_str());

  ofstream outfile;
  outfile.open(output_name.c_str());

  if (myfile.is_open())
  {
    while ( getline (myfile,line))          
    {
      istringstream iss(line);                         
      iss >> word1 >> word2 >> word3;          
      outfile << "PROCESSING COMMAND: " << line << endl;   //endl safer over '\n' bc endl flushes buffer
  
      process(word1, word2, word3, outfile);     //this function processes the words from each input file line
                                                //then it writes result of that process to the output file
    }
    myfile.close();
  }
  outfile.close();
  return 0;

}