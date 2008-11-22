
                             /*PARSER*/

// The parser. It is the function that gives the translated output.
//It takes the integer input as a form of token from the lexer and gives out 
//(prints out, in this case) the output we desire.

# include "global.h"
# include "lexer.cpp"
# include "error.cpp"
# include "emitter.cpp"

  void len1(char);
  void len2(char,char);
  void len3(char,char,char);
  void len_more_than3(char*);
  void initfv(int*,char);
  void initdv(int*,char);

   //We will use multiple Switch statements, each covering one position/case
   //while designing the full translator. 
 
 void parse(){ 
 
      char* input="";
      char* t="0";
        
        input=lexan(); 
        
        if(strcmp(input,"Invalid Input.")==0)
          error(input);
        else if(strcmp(input,t)==0){
                 cerr<<endl<<" Invalid Number."<<endl;
                 return ;
          }
          
          cout<<endl<<" ";
          
          if(strlen(input)==1){
            
              char a;
            
            a=input[0];
            
             len1(a);// The function that prints 'ones' location
          }
          else if(strlen(input)==2){
           
                char b,c;
                
                b=input[0];
                c=input[1];
            
                len2(b,c);// The function that handles tenths location as well.                 
          }
          else if(strlen(input)==3){
             
                 char d,e,f;
                 
                 d=input[0];
                 e=input[1];
                 f=input[2];
                 
                 len3(d,e,f);// The function that handles the hundreths.
          }
          else if(strlen(input)>3){
          
                len_more_than3(input);       
          }
                     
   return ;         
 
 }
  //Handles the strings of length one
  void len1(char a){          
      
             if(a=='1')emit("I");
             else if(a=='2')emit("II");
             else if(a=='3')emit("III");
             else if(a=='4')emit("IV");
             else if(a=='5')emit("V");
             else if(a=='6')emit("VI");
             else if(a=='7')emit("VII");
             else if(a=='8')emit("VIII");
             else if(a=='9')emit("IX");
             
       return ;
             
  }
  //Handles the strings of length two
  void len2(char a,char b){           
          
                 if(a=='1')emit("X");
                 else if(a=='2')emit("XX");
                 else if(a=='3')emit("XXX");
                 else if(a=='4')emit("XL");
                 else if(a=='5')emit("L");
                 else if(a=='6')emit("LX");
                 else if(a=='7')emit("LXX");
                 else if(a=='8')emit("LXXX");
                 else if(a=='9')emit("XC");               
                 
                 len1(b);
                 
          return ;
          
  }
  //Handlesthe strings of length three
  void len3(char a,char b,char c){
  
            if(a=='1')emit("C");
            else if(a=='2')emit("CC");
            else if(a=='3')emit("CCC");
            else if(a=='4')emit("CD");
            else if(a=='5')emit("D");
            else if(a=='6')emit("DC");
            else if(a=='7')emit("DCC");
            else if(a=='8')emit("DCCC");
            else if(a=='9')emit("CM");          
  
           len2(b,c);
           
      return ;
      
  }
  // Handles the first case in the translation.
  void len_more_than3(char* input){
  
                 char g,h,k;
                 int m=0,n=1,l,l1,l2=1;  
                 int tp=1;//gives the thousandth place: e.g., 1,10,100,...
                 int f_value=0;
                 int d_value=0;
                 int t_value=0; 
                 int value_t=0; 
                 
              initfv(&f_value,input[0]); 
                                           
      //gets the digit_value and places it with the t_value.
      //It goes from right to left.           
              for(l=(strlen(input)-4);l>=1;l--){   
                 initdv(&d_value,input[l]);                 
                 t_value+=d_value*tp;                 
                 tp*=10; //indicates the next place in the string.  
              }   
                 value_t=t_value+f_value*tp;
                                  
             //This is when we are done evaluating thousandths places       
                 for(l1=1;l1<=value_t;l1++){                                                           
                    emit("M"); 
                    l2=l1;//just to add convenience.
                    if((l2%50)==0)cout<<endl<<" ";   
                 }               
                 
      // This part takes care of the hundred and lower on part. 
                 
                 g=input[strlen(input)-1];
                 h=input[strlen(input)-2];
                 k=input[strlen(input)-3];  
                                   
                 len3(k,h,g);  
                 
        return ;
  }
  //Set first value perimeter.
  void initfv(int* fv,char a){
  
             if(a=='1')*fv=1;
            else if(a=='2')*fv=2;
            else if(a=='3')*fv=3;
            else if(a=='4')*fv=4;
            else if(a=='5')*fv=5;
            else if(a=='6')*fv=6;
            else if(a=='7')*fv=7;
            else if(a=='8')*fv=8;
            else if(a=='9')*fv=9;            
  
       return ;
  }
  //Set the digit value.
  void initdv(int* dv,char a){
  
            if(a=='0')*dv=0;
            else if(a=='1')*dv=1;
            else if(a=='2')*dv=2;
            else if(a=='3')*dv=3;
            else if(a=='4')*dv=4;
            else if(a=='5')*dv=5;
            else if(a=='6')*dv=6;
            else if(a=='7')*dv=7;
            else if(a=='8')*dv=8;
            else if(a=='9')*dv=9;            
  
       return ;
  }
