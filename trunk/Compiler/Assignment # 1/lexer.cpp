
                               /*LEXICAL ANALYZER*/
   
   //The function of this code is to accept the right "string"/input from
   //the user and pass it to the parser to be executed.
   
    # include "global.h"
       
    //code for lexical analyzer. This code has some bit of memory leak.
     
    char* lexan(){
    
        char c; 
        int n=1;
        char* d;       
        
        d=(char*)malloc(n*sizeof(char));
              
        c=getchar();
                          
        while(c!='\n'){   
            d=(char*)realloc(d,n*sizeof(char));
            
			if(c>='0' && c<='9'){
			    d[n-1]=c;                
			    n++;			    
			    c=getchar();			   			    
			}
			else if(c==' ' || c=='\t'){
				c=getchar();	
            }				
			else if(!c>='0' || !c<='9'){
			    free(d);
				return "Invalid Input.";
			}
		}           
          
          return d;     
      }
