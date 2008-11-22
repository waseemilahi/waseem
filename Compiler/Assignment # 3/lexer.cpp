
                               /*LEXICAL ANALYZER*/
   
   //The function of this code is to accept the "string"/input from
   //the user and pass it to the parser, to be executed.
   
   # include <stdio>
   # include <ctype>
   # include <string>
   # include <iostream>
   using namespace std;
       
    //code for lexical analyzer.
     
    char* lexer(){
    
        char c; 
        int n=1;
        char* d="";
        int islitteral=-1;
        
        d=(char*)malloc(n*sizeof(char));
              
        c=getchar();
                          
        while(c!='$'){
            d=(char*)realloc(d,n*sizeof(char));

			if(c>='0' && c<='9'){
           if(islitteral!=1)
             islitteral=0;

			    d[n-1]=c;
			    n++;
			    c=getchar();
			}
			else if(c==' ' || c=='\t'){
				c=getchar();	
         }				
			else if((c>='a' && c<='z') || (c>='A' && c<='Z') || c=='_'){
			       d[n-1]=c;
			       n++;
			       c=getchar();
					 if(islitteral!=0)
                  islitteral=1;
                else return "Invalid Input(from lexer).";
			}
         else if(c=='=' || c==';' || c=='(' || c==')' || c=='+' || c=='-' || c=='*'){
                islitteral=-1;
                d[n-1]=c;                
			       n++;
			       c=getchar();
         }
		}
          d=(char*)realloc(d,n*sizeof(char));
          d[n-1]=c;
                    
          return d;     
      }
