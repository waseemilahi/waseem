
                              /* Assignment # 3 by Waseem Ilahi
                                 ******************************
                              */

       //The LL(1) parser (uses non-recursive top-down parsing)

# include "lexer.cpp"
# include <vector>
# include <stack>

using namespace std;

//Prototype.

void parse(void);
void setparsetable(char*[][72]);

//The main function.

int main(){

   cout<<endl<<" Hello! This is a LL(1) parser (implemented in C), by Waseem Ilahi."<<endl;
   cout<<" Please input an assignment statement to check wheather it is valid or not."<<endl;
   cout<<" --------------------------------------------------------------------------"<<endl<<endl<<" ";

   parse();

    cout<<endl<<" ----------------------------------------------------------------"<<endl;

    system("Pause");

    return 0;

}

//The code for the parser.

void parse(){

		char* i=""; //The input string.
      char* ip="";
      char* X="";
      int k=0,x=-1,p=-1;

      //It is a vector of vectors of char*.
      char* Parsing_table[11][72];

      stack<char*,vector<char*> >* Stack_used=new stack<char*,vector<char*> >();

      Stack_used->push("$");
      Stack_used->push("Assignment");

   //Implementing the Parsing Table.

      setparsetable(Parsing_table);

   //Getting the input.

      i=lexer();

      if(strcmp(i,"Invalid Input(from lexer).")==0){
        cerr<<i<<endl;
        return ;
      }

     ip[0]=i[k];

     X=Stack_used->top();

     cout<<endl<<" ip points to '"<<ip[0]<<"'"<<endl;

    while(strcmp(X,"$")!=0 || strcmp(ip,"$")!=0){

         if(strlen(X)==1){
           if(strcmp(X,ip)==0){
             Stack_used->pop();
             k++;
             ip[0]=i[k];

             cout<<endl<<" Pop: '"<<X<<"'"<<endl;
             cout<<endl<<" --------------------------"<<endl<<endl;
             cout<<endl<<" ip points to '"<<ip[0]<<"'"<<endl;
             cout<<endl<<" Top of stack is now '"<<Stack_used->top()<<"'"<<endl;
           }
           else{
                cerr<<endl<<" Invalid Input."<<endl;
                delete(Stack_used);
                return ;
           }
         }
         else if(strcmp(X,"empty")==0){
                Stack_used->pop();
                cout<<endl<<" Top of stack is now '"<<Stack_used->top()<<"'"<<endl;
         }
         else if(strcmp(X,"[Letter|Digit]*")==0){
                  while(ip[0]!='=' && i[k]!='$' && ip[0]!='+' && ip[0]!='-'
                        && ip[0]!='*' && ip[0]!=';' && ip[0]!='(' && ip[0]!=')'){
                       k++;
                       ip[0]=i[k];
                  }
                  Stack_used->pop();
                  cout<<endl<<" Top of stack is now '"<<Stack_used->top()<<"'"<<endl;
         }
         else if(strcmp(X,"Digit*")==0){
                       while((ip[0]=='0' || ip[0]=='1' || ip[0]=='2' || ip[0]=='3'
                             || ip[0]=='4' || ip[0]=='5' || ip[0]=='6' || ip[0]=='7'
                             || ip[0]=='8' || ip[0]=='9') && i[k]!='$'){

                             k++;
                             ip[0]=i[k];
                       }
                       Stack_used->pop();
                       cout<<endl<<" Top of stack is now '"<<Stack_used->top()<<"'"<<endl;
         }
         else{

              if(strcmp(X,"Assignment")==0)x=0;
              else if(strcmp(X,"Identifier")==0)x=1;
              else if(strcmp(X,"Exp")==0)x=2;
              else if(strcmp(X,"Term")==0)x=3;
              else if(strcmp(X,"Exp_")==0)x=4;
              else if(strcmp(X,"Term_")==0)x=5;
              else if(strcmp(X,"Fact")==0)x=6;
              else if(strcmp(X,"Letter")==0)x=7;
              else if(strcmp(X,"Digit")==0)x=8;
              else if(strcmp(X,"Litteral")==0)x=9;
              else if(strcmp(X,"NonZeroDigit")==0)x=10;

              if(ip[0]=='0')p=0;
              else if(ip[0]=='1')p=1;
              else if(ip[0]=='2')p=2;
              else if(ip[0]=='3')p=3;
              else if(ip[0]=='4')p=4;
              else if(ip[0]=='5')p=5;
              else if(ip[0]=='6')p=6;
              else if(ip[0]=='7')p=7;
              else if(ip[0]=='8')p=8;
              else if(ip[0]=='9')p=9;
              else if(ip[0]=='(')p=10;
              else if(ip[0]==')')p=11;
              else if(ip[0]=='+')p=12;
              else if(ip[0]=='-')p=13;
              else if(ip[0]=='*')p=14;
              else if(ip[0]=='=')p=15;
              else if(ip[0]==';')p=16;
              else if(ip[0]==NULL)p=17;
              else if(ip[0]=='$')p=18;
              else if(ip[0]=='_')p=19;

              else if(ip[0]=='a')p=20;
              else if(ip[0]=='b')p=21;
              else if(ip[0]=='c')p=22;
              else if(ip[0]=='d')p=23;
              else if(ip[0]=='e')p=24;
              else if(ip[0]=='f')p=25;
              else if(ip[0]=='g')p=26;
              else if(ip[0]=='h')p=27;
              else if(ip[0]=='i')p=28;
              else if(ip[0]=='j')p=29;
              else if(ip[0]=='k')p=30;
              else if(ip[0]=='l')p=31;
              else if(ip[0]=='m')p=32;
              else if(ip[0]=='n')p=33;
              else if(ip[0]=='o')p=34;
              else if(ip[0]=='p')p=35;
              else if(ip[0]=='q')p=36;
              else if(ip[0]=='r')p=37;
              else if(ip[0]=='s')p=38;
              else if(ip[0]=='t')p=39;
              else if(ip[0]=='u')p=40;
              else if(ip[0]=='v')p=41;
              else if(ip[0]=='w')p=42;
              else if(ip[0]=='x')p=43;
              else if(ip[0]=='y')p=44;
              else if(ip[0]=='z')p=45;

              else if(ip[0]=='A')p=46;
              else if(ip[0]=='B')p=47;
              else if(ip[0]=='C')p=48;
              else if(ip[0]=='D')p=49;
              else if(ip[0]=='E')p=50;
              else if(ip[0]=='F')p=51;
              else if(ip[0]=='G')p=52;
              else if(ip[0]=='H')p=53;
              else if(ip[0]=='I')p=54;
              else if(ip[0]=='J')p=55;
              else if(ip[0]=='K')p=56;
              else if(ip[0]=='L')p=57;
              else if(ip[0]=='M')p=58;
              else if(ip[0]=='N')p=59;
              else if(ip[0]=='O')p=60;
              else if(ip[0]=='P')p=61;
              else if(ip[0]=='Q')p=62;
              else if(ip[0]=='R')p=63;
              else if(ip[0]=='S')p=64;
              else if(ip[0]=='T')p=65;
              else if(ip[0]=='U')p=66;
              else if(ip[0]=='V')p=67;
              else if(ip[0]=='W')p=68;
              else if(ip[0]=='X')p=69;
              else if(ip[0]=='Y')p=70;
              else if(ip[0]=='Z')p=71;

              if(strcmp(Parsing_table[x][p],"Error")!=0){
                Stack_used->pop();
              
                 if(x==0){
                    Stack_used->push(";");
                    Stack_used->push("Exp");
                    Stack_used->push("=");
                    Stack_used->push("Identifier");
                    cout<<endl<<" Top of stack is now 'Identifier'"<<endl;
                 }
                 else if(x==1){
                        Stack_used->push("[Letter|Digit]*");
                        Stack_used->push("Letter");
                        cout<<endl<<" Top of stack is now 'Letter'"<<endl;
                 }
                 else if(x==2){
                        Stack_used->push("Exp_");
                        Stack_used->push("Term");
                        cout<<endl<<" Top of stack is now 'Term'"<<endl;
                 }
                 else if(x==3){
                        Stack_used->push("Term_");
                        Stack_used->push("Fact");
                        cout<<endl<<" Top os stack is now 'Fact'"<<endl;
                 }
                 else if(x==4){
                        if(p==12){
                          Stack_used->push("Exp_");
                          Stack_used->push("Term");
                          Stack_used->push("+");
                          cout<<endl<<" Top of stack is now '+'"<<endl;
                        }
                        else if(p==13){
                               Stack_used->push("Exp_");
                               Stack_used->push("Term");
                               Stack_used->push("-");
                               cout<<endl<<"Top of stack is now '-'"<<endl;
                        }
                        else if(p==16 || p==17){
                               Stack_used->push("empty");
                               cout<<endl<<" Top of stack is now 'empty'"<<endl;
                        }
                 }
                 else if(x==5){
                        if(p==11 || p==12 || p==13 || p==16 || p==17 || p==18){
                          Stack_used->push("empty");
                          cout<<endl<<" Top of stack is now 'empty'"<<endl;
                        }
                        else if(p==14){
                               Stack_used->push("Term_");
                               Stack_used->push("Fact");
                               Stack_used->push("*");
                               cout<<endl<<" Top of stack is now '*'"<<endl;
                        }
                 }
                 else if(x==6){
                        if(p>=0 && p<=9){
                          Stack_used->push("Litteral");
                          cout<<endl<<" Top of stack is now 'Litteral'"<<endl;
                        }
                        else if(p==10){
                               Stack_used->push(")");
                               Stack_used->push("Exp");
                               Stack_used->push("(");
                               cout<<endl<<" Top of stack is now '('"<<endl;
                        }
                        else if(p==12){
                               Stack_used->push("Fact");
                               Stack_used->push("+");
                               cout<<endl<<"Top of stack is now '+'"<<endl;
                        }
                        else if(p==13){
                               Stack_used->push("Fact");
                               Stack_used->push("-");
                               cout<<endl<<"Top of stack is now '-'"<<endl;
                        }
                        else if(p>=19 && p<=71){
                               Stack_used->push("Identifier");
                                cout<<endl<<" Top of stack is now 'Identifier'"<<endl;
                        }
                 }
                 else if(x==7){

                        if(p==19){Stack_used->push("_");cout<<endl<<" Top of stack is now '_'"<<endl;}
                        else if(p==20){Stack_used->push("a");cout<<endl<<" Top of stack is now 'a'"<<endl;}
                        else if(p==21){Stack_used->push("b");cout<<endl<<" Top of stack is now 'b'"<<endl;}
                        else if(p==22){Stack_used->push("c");cout<<endl<<" Top of stack is now 'c'"<<endl;}
                        else if(p==23){Stack_used->push("d");cout<<endl<<" Top of stack is now 'd'"<<endl;}
                        else if(p==24){Stack_used->push("e");cout<<endl<<" Top of stack is now 'e'"<<endl;}
                        else if(p==25){Stack_used->push("f");cout<<endl<<" Top of stack is now 'f'"<<endl;}
                        else if(p==26){Stack_used->push("g");cout<<endl<<" Top of stack is now 'g'"<<endl;}
                        else if(p==27){Stack_used->push("h");cout<<endl<<" Top of stack is now 'h'"<<endl;}
                        else if(p==28){Stack_used->push("i");cout<<endl<<" Top of stack is now 'i'"<<endl;}
                        else if(p==29){Stack_used->push("j");cout<<endl<<" Top of stack is now 'j'"<<endl;}
                        else if(p==30){Stack_used->push("k");cout<<endl<<" Top of stack is now 'k'"<<endl;}
                        else if(p==31){Stack_used->push("l");cout<<endl<<" Top of stack is now 'l'"<<endl;}
                        else if(p==32){Stack_used->push("m");cout<<endl<<" Top of stack is now 'm'"<<endl;}
                        else if(p==33){Stack_used->push("n");cout<<endl<<" Top of stack is now 'n'"<<endl;}
                        else if(p==34){Stack_used->push("o");cout<<endl<<" Top of stack is now 'o'"<<endl;}
                        else if(p==35){Stack_used->push("p");cout<<endl<<" Top of stack is now 'p'"<<endl;}
                        else if(p==36){Stack_used->push("q");cout<<endl<<" Top of stack is now 'q'"<<endl;}
                        else if(p==37){Stack_used->push("r");cout<<endl<<" Top of stack is now 'r'"<<endl;}
                        else if(p==38){Stack_used->push("s");cout<<endl<<" Top of stack is now 's'"<<endl;}
                        else if(p==39){Stack_used->push("t");cout<<endl<<" Top of stack is now 't'"<<endl;}
                        else if(p==40){Stack_used->push("u");cout<<endl<<" Top of stack is now 'u'"<<endl;}
                        else if(p==41){Stack_used->push("v");cout<<endl<<" Top of stack is now 'v'"<<endl;}
                        else if(p==42){Stack_used->push("w");cout<<endl<<" Top of stack is now 'w'"<<endl;}
                        else if(p==43){Stack_used->push("x");cout<<endl<<" Top of stack is now 'x'"<<endl;}
                        else if(p==44){Stack_used->push("y");cout<<endl<<" Top of stack is now 'y'"<<endl;}
                        else if(p==45){Stack_used->push("z");cout<<endl<<" Top of stack is now 'z'"<<endl;}

                        else if(p==46){Stack_used->push("A");cout<<endl<<" Top of stack is now 'A'"<<endl;}
                        else if(p==47){Stack_used->push("B");cout<<endl<<" Top of stack is now 'B'"<<endl;}
                        else if(p==48){Stack_used->push("C");cout<<endl<<" Top of stack is now 'C'"<<endl;}
                        else if(p==49){Stack_used->push("D");cout<<endl<<" Top of stack is now 'D'"<<endl;}
                        else if(p==50){Stack_used->push("E");cout<<endl<<" Top of stack is now 'E'"<<endl;}
                        else if(p==51){Stack_used->push("F");cout<<endl<<" Top of stack is now 'F'"<<endl;}
                        else if(p==52){Stack_used->push("G");cout<<endl<<" Top of stack is now 'G'"<<endl;}
                        else if(p==53){Stack_used->push("H");cout<<endl<<" Top of stack is now 'H'"<<endl;}
                        else if(p==54){Stack_used->push("I");cout<<endl<<" Top of stack is now 'I'"<<endl;}
                        else if(p==55){Stack_used->push("J");cout<<endl<<" Top of stack is now 'J'"<<endl;}
                        else if(p==56){Stack_used->push("K");cout<<endl<<" Top of stack is now 'K'"<<endl;}
                        else if(p==57){Stack_used->push("L");cout<<endl<<" Top of stack is now 'L'"<<endl;}
                        else if(p==58){Stack_used->push("M");cout<<endl<<" Top of stack is now 'M'"<<endl;}
                        else if(p==59){Stack_used->push("N");cout<<endl<<" Top of stack is now 'N'"<<endl;}
                        else if(p==60){Stack_used->push("O");cout<<endl<<" Top of stack is now 'O'"<<endl;}
                        else if(p==61){Stack_used->push("P");cout<<endl<<" Top of stack is now 'P'"<<endl;}
                        else if(p==62){Stack_used->push("Q");cout<<endl<<" Top of stack is now 'Q'"<<endl;}
                        else if(p==63){Stack_used->push("R");cout<<endl<<" Top of stack is now 'R'"<<endl;}
                        else if(p==64){Stack_used->push("S");cout<<endl<<" Top of stack is now 'S'"<<endl;}
                        else if(p==65){Stack_used->push("T");cout<<endl<<" Top of stack is now 'T'"<<endl;}
                        else if(p==66){Stack_used->push("U");cout<<endl<<" Top of stack is now 'U'"<<endl;}
                        else if(p==67){Stack_used->push("V");cout<<endl<<" Top of stack is now 'V'"<<endl;}
                        else if(p==68){Stack_used->push("W");cout<<endl<<" Top of stack is now 'W'"<<endl;}
                        else if(p==69){Stack_used->push("X");cout<<endl<<" Top of stack is now 'X'"<<endl;}
                        else if(p==70){Stack_used->push("Y");cout<<endl<<" Top of stack is now 'Y'"<<endl;}
                        else if(p==71){Stack_used->push("Z");cout<<endl<<" Top of stack is now 'Z'"<<endl;}

                 }
                 else if(x==8){

                 cout<<endl<<" Top of stack is now any one of '0-9'"<<endl;

                        if(p==0){Stack_used->push("0");cout<<endl<<" Top of stack is now '0'"<<endl;}
                        else if(p==1){Stack_used->push("1");cout<<endl<<" Top of stack is now '1'"<<endl;}
                        else if(p==2){Stack_used->push("2");cout<<endl<<" Top of stack is now '2'"<<endl;}
                        else if(p==3){Stack_used->push("3");cout<<endl<<" Top of stack is now '3'"<<endl;}
                        else if(p==4){Stack_used->push("4");cout<<endl<<" Top of stack is now '4'"<<endl;}
                        else if(p==5){Stack_used->push("5");cout<<endl<<" Top of stack is now '5'"<<endl;}
                        else if(p==6){Stack_used->push("6");cout<<endl<<" Top of stack is now '6'"<<endl;}
                        else if(p==7){Stack_used->push("7");cout<<endl<<" Top of stack is now '7'"<<endl;}
                        else if(p==8){Stack_used->push("8");cout<<endl<<" Top of stack is now '8'"<<endl;}
                        else if(p==9){Stack_used->push("9");cout<<endl<<" Top of stack is now '9'"<<endl;}
                 }
                 else if(x==9){
                 			if(p==0){
                          Stack_used->push("0");
                          cout<<endl<<" Top of stack is now '0'"<<endl;
                        }
                        else if(p>=1 && p<=9){
                               Stack_used->push("Digit*");
                               Stack_used->push("NonZeroDigit");
                               cout<<endl<<" Top of stack is now 'NonZeroDigit'"<<endl;
                        }
                 }
                 else if(x==10){

                 cout<<endl<<" Top of stack is now any one of '1-9'"<<endl;

                        if(p==1){Stack_used->push("1");cout<<endl<<" Top of stack is now '1'"<<endl;}
                        else if(p==2){Stack_used->push("2");cout<<endl<<" Top of stack is now '2'"<<endl;}
                        else if(p==3){Stack_used->push("3");cout<<endl<<" Top of stack is now '3'"<<endl;}
                        else if(p==4){Stack_used->push("4");cout<<endl<<" Top of stack is now '4'"<<endl;}
                        else if(p==5){Stack_used->push("5");cout<<endl<<" Top of stack is now '5'"<<endl;}
                        else if(p==6){Stack_used->push("6");cout<<endl<<" Top of stack is now '6'"<<endl;}
                        else if(p==7){Stack_used->push("7");cout<<endl<<" Top of stack is now '7'"<<endl;}
                        else if(p==8){Stack_used->push("8");cout<<endl<<" Top of stack is now '8'"<<endl;}
                        else if(p==9){Stack_used->push("9");cout<<endl<<" Top of stack is now '9'"<<endl;}
                 }
              }
              else{
                   cerr<<endl<<" Invalid Input."<<endl;
                   delete(Stack_used);
                   return ;
              }

         }

         X=Stack_used->top();
    }

    cout<<endl<<" Valid Input."<<endl;

    delete(Stack_used);

     return ;

}

void setparsetable(char* Parsing_table[][72]){

      int j;

      for(j=19;j<72;j++)
          Parsing_table[0][j]="Identifier=Exp;";
      for(j=0;j<19;j++)
         Parsing_table[0][j]="Error";

      for(j=0;j<11;j++)
         Parsing_table[2][j]="TermExp_";
         Parsing_table[2][11]="Error";
         Parsing_table[2][12]="TermExp_";
         Parsing_table[2][13]="TermExp_";
      for(j=14;j<19;j++)
          Parsing_table[2][j]="Error";
      for(j=19;j<72;j++)
          Parsing_table[2][j]="TermExp_";

       for(j=0;j<11;j++)
         Parsing_table[3][j]="FactTerm_";
         Parsing_table[3][11]="Error";
         Parsing_table[3][12]="FactTerm_";
         Parsing_table[3][13]="FactTerm_";
      for(j=14;j<19;j++)
         Parsing_table[3][j]="Error";
      for(j=19;j<72;j++)
          Parsing_table[3][j]="FactTerm_";

      for(j=0;j<10;j++)
         Parsing_table[6][j]="Litteral";
         Parsing_table[6][10]="(Exp)";
         Parsing_table[6][11]="Error";
         Parsing_table[6][12]="+Fact";
         Parsing_table[6][13]="-Fact";
      for(j=14;j<19;j++)
         Parsing_table[6][j]="Error";
      for(j=19;j<72;j++)
         Parsing_table[6][j]="Identifier";

      Parsing_table[8][0]="0";
      Parsing_table[8][1]="1";
      Parsing_table[8][2]="2";
      Parsing_table[8][3]="3";
      Parsing_table[8][4]="4";
      Parsing_table[8][5]="5";
      Parsing_table[8][6]="6";
      Parsing_table[8][7]="7";
      Parsing_table[8][8]="8";
      Parsing_table[8][9]="9";
      for(j=10;j<72;j++)
         Parsing_table[8][j]="Error";

      Parsing_table[10][0]="Error";
      Parsing_table[10][1]="1";
      Parsing_table[10][2]="2";
      Parsing_table[10][3]="3";
      Parsing_table[10][4]="4";
      Parsing_table[10][5]="5";
      Parsing_table[10][6]="6";
      Parsing_table[10][7]="7";
      Parsing_table[10][8]="8";
      Parsing_table[10][9]="9";
      for(j=10;j<72;j++)
         Parsing_table[10][j]="Error";

      for(j=0;j<12;j++)
         Parsing_table[4][j]="Error";
      Parsing_table[4][12]="+TermExp_";
      Parsing_table[4][13]="-TermExP_";
      for(j=14;j<16;j++)
         Parsing_table[4][j]="Error";
      Parsing_table[4][16]="empty";
      Parsing_table[4][17]="empty";
      for(j=18;j<72;j++)
         Parsing_table[4][j]="Error";

      for(j=0;j<11;j++)
         Parsing_table[5][j]="Error";
      Parsing_table[5][11]="empty";
      Parsing_table[5][12]="empty";
      Parsing_table[5][13]="empty";
      Parsing_table[5][14]="*FactTerm_";
      Parsing_table[5][15]="Error";
      Parsing_table[5][16]="empty";
      Parsing_table[5][17]="empty";
      Parsing_table[5][18]="empty";
      for(j=19;j<72;j++)
         Parsing_table[5][j]="Error";

      for(j=0;j<19;j++)
         Parsing_table[7][j]="Error";
      Parsing_table[7][19]="_";
      Parsing_table[7][20]="a";
      Parsing_table[7][21]="b";
      Parsing_table[7][22]="c";
      Parsing_table[7][23]="d";
      Parsing_table[7][24]="e";
      Parsing_table[7][25]="f";
      Parsing_table[7][26]="g";
      Parsing_table[7][27]="h";
      Parsing_table[7][28]="i";
      Parsing_table[7][29]="j";
      Parsing_table[7][30]="k";
      Parsing_table[7][31]="l";
      Parsing_table[7][32]="m";
      Parsing_table[7][33]="n";
      Parsing_table[7][34]="o";
      Parsing_table[7][35]="p";
      Parsing_table[7][36]="q";
      Parsing_table[7][37]="r";
      Parsing_table[7][38]="s";
      Parsing_table[7][39]="t";
      Parsing_table[7][40]="u";
      Parsing_table[7][41]="v";
      Parsing_table[7][42]="w";
      Parsing_table[7][43]="x";
      Parsing_table[7][44]="y";
      Parsing_table[7][45]="z";

      Parsing_table[7][46]="A";
      Parsing_table[7][47]="B";
      Parsing_table[7][48]="C";
      Parsing_table[7][49]="D";
      Parsing_table[7][50]="E";
      Parsing_table[7][51]="F";
      Parsing_table[7][52]="G";
      Parsing_table[7][53]="H";
      Parsing_table[7][54]="I";
      Parsing_table[7][55]="J";
      Parsing_table[7][56]="K";
      Parsing_table[7][57]="L";
      Parsing_table[7][58]="M";
      Parsing_table[7][59]="N";
      Parsing_table[7][60]="O";
      Parsing_table[7][61]="P";
      Parsing_table[7][62]="Q";
      Parsing_table[7][63]="R";
      Parsing_table[7][64]="S";
      Parsing_table[7][65]="T";
      Parsing_table[7][66]="U";
      Parsing_table[7][67]="V";
      Parsing_table[7][68]="W";
      Parsing_table[7][69]="X";
      Parsing_table[7][70]="Y";
      Parsing_table[7][71]="Z";

      Parsing_table[9][0]="0";
      for(j=1;j<10;j++)
      Parsing_table[9][j]="NonZeroDigitDigit*";
      for(j=10;j<72;j++)
         Parsing_table[9][j]="Error";

      for(j=0;j<19;j++)
         Parsing_table[1][j]="Error";
      for(j=19;j<72;j++)
         Parsing_table[1][j]="Letter[Letter|Digit]*";

    return ;
}