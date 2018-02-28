#ifndef PROCESS            //header guards
#define PROCESS

#include "classes.h"     
								
#include <fstream>     //note: this header file could have stood alone with just #include <string> and <list>
#include <iterator>    //good practice to include all STLs needed in .cpp in the corresponding .h file
#include <string>      //(not necessary in this specific case bc main.cpp has all the needed STLs of process.cpp)
#include <list>        //did anyway because header guards prevent double inclusion
					   //'using namespace std' not good for header files bc pollutes the global namespace
				
extern std::list<SimpleList<int> *> listSLi; 
extern std::list<SimpleList<double> *> listSLd;
extern std::list<SimpleList<std::string> *> listSLs; 

extern SimpleList<int> *pSLi;
extern SimpleList<double> *pSLd;                             //'extern' keyword globalizes the class instantiations 
extern SimpleList<std::string> *pSLs;                        //declared in main.cpp across process.cpp 

extern std::list<SimpleList<int> *>::iterator itI;
extern std::list<SimpleList<double> *>::iterator itD;
extern std::list<SimpleList<std::string> *>::iterator itS;


void process(std::string word1, std::string word2, std::string word3, std::ofstream& outfile);   //declare function


#endif 