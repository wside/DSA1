#include "process.h"

#include <fstream>   
#include <iterator>
#include <string>
#include <list>


using namespace std;            

//define function:
void process(string word1, string word2, string word3, ofstream& outfile)   //takes a pointer to ofstream as argument
{                                                                           //so function can write to output file

  int word3_int;
  double word3_dub;
  char j = char(word2[0]); //first letter of word2 will be 'i' for int, 'd' for double, or 's' for string
                          //assigned to char j. The letter j is arbitrary. 
 
 //iterator itI through listSLi will always point to pointer pSli referring to the stack named "no match" or "word2" (whatever word2 is)
  if (j=='i')                                              
  {
    itI = search(listSLi.begin(), prev(listSLi.end()), word2);    //NOTE: see 'search' class def in classes.h for detailed 
                                                                  //explanation    
  }
  else if (j=='d')                                                //based on first letter of word2, searches through
  {                                                               //appropriate c++ list of stacks & queues
    itD = search(listSLd.begin(), prev(listSLd.end()), word2);    //if-else statements used bc MUST do a search for 
  }                                                               //each line in input file
  else if (j=='s')                                                //'search' returns iterator associated with correct stack or q
  {                                                               //named in the line if it exists, or "no match" iterator 
    itS = search(listSLs.begin(), prev(listSLs.end()), word2);    //C++11 feature 'prev' to get previous iterator     
  }


  if (word1 == "create")
  {
      if (word3 == "stack")
      {
          switch(j)
          {
              case 'i': if (((*itI)->retrieve()) == ("no match"))    //if dereferenced iterator retrieves listSLi ptr pSLi to  
                        {                                            //stack named "no match"  
                          pSLi = new Stack<int>(word2);              //then create a stack named "word2" 
                          listSLi.push_front(pSLi);  
                        }
                        else
                        {
                          outfile << "ERROR: This name already exists!" << endl;    //case-switch statements switch on class type 
                        }                                                           //provided by j
                        break; 
              case 'd': if (((*itD)->retrieve()) == ("no match"))
                        {
                          pSLd = new Stack<double>(word2);
                          listSLd.push_front(pSLd);
                        }
                        else
                        {
                          outfile << "ERROR: This name already exists!" << endl;
                        }
                        break;
              case 's': if (((*itS)->retrieve()) == ("no match"))
                        {
                          pSLs = new Stack<string>(word2);
                          listSLs.push_front(pSLs);
                        }
                        else
                        {
                          outfile << "ERROR: This name already exists!" << endl;
                        }
                        break;        
          }
      }
      else if (word3 == "queue")
      {
          switch(j)
          {
              case 'i': if (((*itI)->retrieve()) == ("no match"))
                        {
                          pSLi = new Queue<int>(word2);   
                          listSLi.push_front(pSLi); 
                        }
                        else
                        {
                          outfile << "ERROR: This name already exists!" << endl;
                        }
                        break;
              case 'd': if (((*itD)->retrieve()) == ("no match"))
                        {
                          pSLd = new Queue<double>(word2);
                          listSLd.push_front(pSLd);
                        }
                        else
                        {
                          outfile << "ERROR: This name already exists!" << endl;
                        }
                        break;
              case 's': if (((*itS)->retrieve()) == ("no match"))
                        {
                          pSLs = new Queue<string>(word2);
                          listSLs.push_front(pSLs);
                        }
                        else
                        {
                          outfile << "ERROR: This name already exists!" << endl;
                        }
                        break;
          }                
      }
  }        

  else if (word1 == "push")
  {
      switch(j)
      {  
          case 'i': if (((*itI)->retrieve()) == ("no match"))   //if try to push to a stack or q that doesn't exist
                    {
                      outfile << "ERROR: This name does not exist!" << endl;
                    }
                    else
                    {
                      word3_int = stoi(word3);   //C++11 feature to convert word 3 from a string to an int
                      (*itI)->push(word3_int);   //push word3 into stack or q (iterator itI will already be 
                    }                            //assoc. w/ appropriate stack or q named in word 2
                    break;
          case 'd': if (((*itD)->retrieve()) == ("no match"))
                    {
                      outfile << "ERROR: This name does not exist!" << endl;
                    }
                    else
                    {
                      word3_dub = stod(word3);   //C++11 feature to convert word 3 from a string to a double
                      (*itD)->push(word3_dub); 
                    }
                    break;
          case 's': if (((*itS)->retrieve()) == ("no match"))
                    {
                      outfile << "ERROR: This name does not exist!" << endl;
                    }
                    else
                    {
                      (*itS)->push(word3);   //word 3 is already a string here so no conversion needed
                    }
                    break;  
      }     
  }

  else if (word1 == "pop")
  {
      switch(j)
      {  
          case 'i': if (((*itI)->retrieve()) == ("no match"))    //if try to pop to a stack or q that doesn't exist
                    {
                      outfile << "ERROR: This name does not exist!"<< endl;
                    }
                    else 
                    {
                        if (((*itI)->is_empty()) == true)     //if the stack or q is empty then output error mssg
                        {
                        outfile << "ERROR: This list is empty!" << endl;
                        }
                        else
                        { 
                        outfile << "Value popped: " << (*itI)-> pop() << endl; //if not, pop it!        
                        } 
                    }
                    break;
          case 'd': if (((*itD)->retrieve()) == ("no match"))
                    {
                      outfile << "ERROR: This name does not exist!"<< endl;
                    }
                    else 
                    {
                        if (((*itD)->is_empty()) == true)
                        {
                        outfile << "ERROR: This list is empty!" << endl;
                        }
                        else
                        { 
                        outfile << "Value popped: " << (*itD)-> pop() << endl;         
                        } 
                    }
                    break;
          case 's': if (((*itS)->retrieve()) == ("no match"))
                    {
                      outfile << "ERROR: This name does not exist!"<< endl;
                    }
                    else 
                    {
                        if (((*itS)->is_empty()) == true)
                        {
                        outfile << "ERROR: This list is empty!" << endl;
                        }
                        else
                        { 
                        outfile << "Value popped: " << (*itS)-> pop() << endl;         
                        } 
                    }
                    break;  
      }           
  }     

  
}
