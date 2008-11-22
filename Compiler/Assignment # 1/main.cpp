
                            /*MAIN FILE*/

//This is a complete translator that works fine while 
//tranlating the integers into the Roman numerals. This 
// project basically has two main parts, 1. an analyzer and 2. a parser.
// the former just only checks the validity of the input and passes the 
//input to the later, which actually does all the work 
//and gives us the final result.

  # include "global.h"
  # include "parser.cpp"   
  
  int main(){       
  
      cout<<endl<<" Hello! This is Waseem Ilahi's Translator for Arabic Numbers";
      cout<<" to Roman Numerals."<<endl<<endl; 
      
            cout<<" Please Enter a positive integer."<<endl;
            cout<<" --------------------------------"<<endl<<" ";        
  
            parse(); //Main function only calls for the parser.
            
            cout<<endl<<" -------------------------";
            cout<<"-------------------------"<<endl;
            
      cout<<endl<<endl;           
      
      system("Pause");//to hold window open after completion of the execution
      
      return 0;
      
  }
