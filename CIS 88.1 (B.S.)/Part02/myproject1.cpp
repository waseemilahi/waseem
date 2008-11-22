/* The Project that implements the simulation of the Belief Revision

   Theory Presented by Prof. Chopra and the others. */

# include <stdio.h>

void combined1error(char* s)
{

  fprintf(stderr,"%s\n",s);

  return ;

}

# include "myprojectheader1.h"

# include "lex.combined1.c"

# include "combinedinput1.tab.c"

# include <list>

# include <queue>

# include <iostream>

using namespace std;

int main(int argc,char** argv){

   list<struct Sequence*> *S1=new list<struct Sequence*>();

   char R1[500],tmp1[500];

   list<char*> *tmplist1=new list<char*>();

   list<list<char*>* > *tmpqueue1=new list<list<char*>* >();

   list<struct Sequence*> *sigmaprime=new list<struct Sequence*>();

   char sigmaprime1[500][100],gammaprime1[500][100],gamma1[500][100];

   int  sigmaprime2[500][2];//index 0 for time and 1 for relevence.

   struct Sequence tmps1;

   int k,a,b;

   printf("\n Implementation by Waseem Ilahi.\n");

   printf("\n Project Supervisor: Samir Chopra.\n");

   printf(" ---------------------------------\n");

   printf("\n This Program Simulates the Intelligent Agent that \n");

   printf(" takes the belief sequence from the user as input and then \n");

   printf(" when the user queries about a sentence, the agent gives its \n");

   printf(" answer after trying to derive the query from its knowledge base.\n");

   printf("\n The answer can be Yes, No, or I don't know.\n");

   printf("\n The program requires you to read and understand the \n");

   printf(" paper that describes the theory.\n");

   printf("\n We will Begin Now.\n");

   printf(" ------------------\n");

   if(argc>1){yyin=fopen(argv[1],"r");}

   else if(argc==1){

          printf("\n Every 'sentence' is enclosed in parenthesis, except the \n");

          printf(" symbol and the negation of symbols as well as the sentences.\n");

          printf("\n The sentences are seperated by the commas.\n");

          printf("\n The capital letters 'T' and 'F' represent truth and false respectively.\n");

          printf("\n First Enter the word 'Sequence' followed by your sequence.\n");

          printf("\n Please Enter the Belief Sequence.('$' terminates the input)\n");

          printf(" -----------------------------------------------------------\n ");

   }

   b=n;

   a=combined1parse();

   while(a!=0){

        query[0]=0; querylanguage[0]=0;

        for(int j=b;j<500;j++){

           sequence[j][0]=0;

           sequencelanguage[j][0]=0;
        }

        printf("\n Input Error! Please Try Again.\n ");

        n=b;

        a=combined1parse();

   }

   for(int g=0;g<n;g++){

      tmps1.sentences=sequence[g];

      tmps1.time=g;

      S1->push_back(&tmps1);

   }

   query[0]=0;

   querylanguage[0]=0;

   printf("\n First Enter the word 'Query' followed by your Query.\n");

   printf("\n Now Please Enter The Query.\n");

   printf("\n Query is only one sentence with the same format as in the sequence itself.\n");

   printf(" --------------------------------------------------------------------------\n ");

   a=combined1parse();

   while(a!=0){

     printf("\n Input Error! Please Try Again.\n ");

      query[0]=0;querylanguage[0]=0;

     a=combined1parse();

   }

   strcat(query,"\0");

   strcat(querylanguage,"\0");

   printf("\n We also require the level of relevence from you.(>=0)\n");

   printf(" -----------------------------------------------------\n ");

   scanf("%d",&k);

   while(k<0){

        printf("\n The Degree of Relevence must be non-negative.\n");

        printf("\n Please try again.\n");

        scanf("%d",&k);

   }

   printf("\n *****************************************************\n");

   printf("\n The Belief Sequence is:\n\n {");

   for(int u=0;u<n;u++){

      printf(" %s ",sequence[u]);

      if(u<n-1)printf(",");
   }

   printf("} \n");

   printf(" \n Your Query is: %s \n",query);

   printf("\n The Level of Relevence is: %d\n",k);

   printf("\n -----------------------------------------------------\n");

   char *p;

   unsigned int t;
   int bb;

   int flag3,counter=0,e=0,level1=0,counter2=0,tmpcounter=0,acounter1=0;

   int array1[500];

   for(int r=0;r<n;r++)array1[r]=0;

   while(e==0 && level1<=k){

         e=1;

         for(int i=n-1;i>=0;i--){
                                  tmpcounter=0; acounter1++;
           if(array1[i]==1)continue;

            bb=0;

            for(t=0;t<strlen(sequencelanguage[i]);t++){

               flag3=0;

              for(unsigned int j=0;j<strlen(querylanguage);j++){

                   if(querylanguage[j]==sequencelanguage[i][t]){

                      if(bb==1){

                        flag3=1; break;

                      }

                         tmps1.sentences=sequence[i];

                         tmps1.time=i;

                         tmps1.relevence=0;

                         sigmaprime->push_back(&tmps1);

                         strcpy(sigmaprime1[counter],sequence[i]);

                         sigmaprime2[counter][0]=i+1;

                         sigmaprime2[counter][1]=0;

                         array1[i]=1;

                         counter++;

                         flag3=1;

                         bb=1;

                   }

                }//end for

                if(bb==0){

                  tmp1[tmpcounter]=sequencelanguage[i][t];

                  tmpcounter++;

                }
                else if(bb==1 && flag3==1){

                        int u=0;

                        while(u<tmpcounter){

                             R1[counter2]=tmp1[u];

                             counter2++;;

                             u++;
                        }

                        tmpcounter=0;
                }
                else if(bb==1 && flag3==0){

                        R1[counter2]=sequencelanguage[i][t];

                        counter2++; tmpcounter=0;
                }

                if(b==0 && counter2>0 && t==strlen(sequencelanguage[i])-1){

                   if(level1>k)continue;

                    int iii,iiii,aaa=0;


                   for(int ii=0;ii<tmpcounter;ii++){

                      for(int jj=0;jj<counter2;jj++){

                         if(tmp1[ii]==R1[jj]) {

                            tmps1.sentences=sequence[i];

                            tmps1.time=i;

                             level1++;

                             if(level1>k)continue;

                            tmps1.relevence=level1;

                            sigmaprime->push_back(&tmps1);

                            strcpy(sigmaprime1[counter],sequence[i]);

                            sigmaprime2[counter][0]=i+1;

                            sigmaprime2[counter][1]=level1;

                            array1[i]=1;

                            counter++;

                            iii=ii-1;

                            while(iii>=0){

                               R1[counter2]=tmp1[iii];

                               counter2++;

                               iii--;
                            }
                             for(iiii=ii+1;iiii<tmpcounter;iiii++){

                               R1[counter2]=tmp1[iiii];

                               counter2++;
                            }

                            aaa=1;

                            break;
                         }
                   }

                   if(aaa==1)break;

                }

                 tmpcounter=0;
              }
            }
         }

         if(counter2==0)break; if(acounter1>n*n)break;

         for(int s=0;s<n;s++){

            if(array1[s]==0){

              e=0;
            }
         }
     }//end while

     printf("\n Sigma Prime: (Sentence Followed by Time and Relevence Respectively.)\n");

     printf("\n ********************************************************************\n");

     for(int y=0;y<counter;y++)
        printf("\n %s   %d  %d\n",sigmaprime1[y],sigmaprime2[y][0],sigmaprime2[y][1]);

    //Getting the Gamma Set.

        int counter11=0,counters1=0,counteras1=0,nf1=0,notfinished=1,success=0,aacounter1=0;
        char* tmparray;
        char tmpsymbol1[100][1],tmpantisymbol1[100][2];

        list<char*> *tmplist2=new list<char*>();
        list<char*> *tmplist5=new list<char*>();

        while(counter11<=counter){

        while(!tmplist1->empty())tmplist1->pop_front();

         for(int h=0;h<counter11;h++)
            tmplist1->push_back(sigmaprime1[counter11]);

            tmplist2=tmplist1; tmplist5=tmplist2;

        while(notfinished){

            notfinished=0;

            while(!tmplist5->empty()){

                 if(strlen(tmplist5->front())>2){ notfinished=1;break;}

                 tmplist5->pop_front();
            }

            if(!notfinished){success=1;break;}

          tmparray=tmplist2->front();
          tmplist2->pop_front();

          if(strlen(tmparray)<=2){
            if(strlen(tmparray)==1){

              for(int f=0;f<counteras1;f++){
                 if(tmparray[0]==tmpantisymbol1[f][1]){
                   nf1=1;
                   break;
                 }
              }

                 if(nf1==1){
                    nf1=0;
                    while(!tmplist2->empty())tmplist2->pop_front();

                    if(!tmpqueue1->empty()){tmplist2=tmpqueue1->front();continue;}
                    else if(tmpqueue1->empty()){success=0;break;}
                 }
                 else if(nf1==0){

                    strcpy(tmpsymbol1[counters1],tmparray);
                    counters1++;
                    tmplist2->push_back(tmparray);
                 }
            }
            else if(strlen(tmparray)==2){

            	    for(int f=0;f<counters1;f++){
                     if(tmparray[1]==tmpsymbol1[f][0]){
                       nf1=1;
                        break;
                     }
                   }

                 if(nf1==1){
                    nf1=0;
                    while(!tmplist2->empty())tmplist2->pop_front();

                    if(!tmpqueue1->empty()){tmplist2=tmpqueue1->front();continue;}
                    else if(tmpqueue1->empty()){success=0;break;}
                 }
                 else if(nf1==0){

                   strcpy(tmpantisymbol1[counteras1],tmparray);
                   counters1++;
                    tmplist2->push_back(tmparray);
                 }
            }
            else if(strlen(tmparray)<1){}

          }
          else if(strlen(tmparray)>2){

                int openp=0,closep=0;
                char tmparray2[100]="";
                list<char*>* tmpl1=new list<char*>();

                if(tmparray[0]=='~'){
                   for(unsigned int r=1;r<strlen(tmparray);r++){
                           if(tmparray[r]=='('){
                             openp++;
                           }
                           else if(tmparray[r]==')'){
                                  closep++;
                           }

                           if(openp-1==closep && tmparray[r]=='&'){

                             tmpl1=tmplist2;
                             if(tmparray[r+1]!='~'){
                                tmparray2[0]='~';
                              tmparray2[1]=0;
                             for(unsigned int g=r+1;g<strlen(tmparray)-1;g++)strcat(tmparray2,(char*)tmparray[g]);
                             tmpl1->push_back(tmparray2);
                             tmpqueue1->push_back(tmpl1);
                             tmparray2[0]=0;
                             while(!tmpl1->empty())tmpl1->pop_front();
                             }
                             else if(tmparray[r+1]=='~'){
                                     tmparray2[0]=0;
                                     for(unsigned int g=r+2;g<strlen(tmparray)-1;g++)strcat(tmparray2,(char*)tmparray[g]);
                                     tmpl1->push_back(tmparray2);
                                     tmpqueue1->push_back(tmpl1);
                                     tmparray2[0]=0;

                                     while(!tmpl1->empty())tmpl1->pop_front();
                             }

                             if(tmparray[2]=='~'){
                                 tmparray2[0]=0;
                                 for(unsigned int f=3;f<r;f++)strcat(tmparray2,(char*)tmparray[f]);
                                 tmplist2->push_back(tmparray2);
                                 tmparray2[0]=0;
                             }
                             else if(tmparray[2]!='~'){

                                  tmparray2[0]='~';tmparray2[1]=0;
                                  for(unsigned int f=2;f<r;f++)strcat(tmparray2,(char*)tmparray[f]);
                                  tmplist2->push_back(tmparray2);
                                  tmparray2[0]=0;
                             }



                           }
                           else if(openp-1==closep && tmparray[r]=='|'){

                                 if(tmparray[2]=='~'){
                                    tmparray2[0]=0;
                                  for(unsigned int f=3;f<r;f++)strcat(tmparray2,(char*)tmparray[f]);
                                  tmplist2->push_back(tmparray2);
                                  tmparray2[0]=0;
                                 }
                                 else{
                                  tmparray2[0]='~';tmparray2[1]=0;
                                  for(unsigned int f=2;f<r;f++)strcat(tmparray2,(char*)tmparray[f]);
                                  tmplist2->push_back(tmparray2);
                                  tmparray2[0]=0;
                                 }

                                 if(tmparray[r+1]=='~'){
                                     tmparray2[0]=0;
                                  for(unsigned int g=r+2;g<strlen(tmparray)-1;g++)strcat(tmparray2,(char*)tmparray[g]);
                                  tmplist2->push_back(tmparray2);
									       tmparray2[0]=0;
                                 }
                                 else{
                                  tmparray2[0]='~';tmparray2[1]=0;
                                  for(unsigned int g=r+1;g<strlen(tmparray)-1;g++)strcat(tmparray2,(char*)tmparray[g]);
                                  tmplist2->push_back(tmparray2);
									       tmparray2[0]=0;
                                 }

                           }
                           else if(openp-1==closep && tmparray[r]=='-' && tmparray[r+1]=='>'){
                                  if(tmparray[r+1]=='~'){
                                     tmparray2[0]=0;
                                  for(unsigned int g=r+2;g<strlen(tmparray)-1;g++)strcat(tmparray2,(char*)tmparray[g]);
                                  tmplist2->push_back(tmparray2);
                                  tmparray2[0]=0;
                                  }
                                  else{
                           	    tmparray2[0]='~';tmparray2[1]=0;
                                  for(unsigned int g=r+1;g<strlen(tmparray)-1;g++)strcat(tmparray2,(char*)tmparray[g]);
                                  tmplist2->push_back(tmparray2);
                                  tmparray2[0]=0;
                                  }

                                  if(tmparray[2]=='~'){ tmparray2[0]='~';tmparray2[1]=0;
                                  for(unsigned int f=3;f<r;f++)strcat(tmparray2,(char*)tmparray[f]);
                                  tmplist2->push_back(tmparray2);
                                  tmparray2[0]=0;
                                  }
                                  else{
                                  for(unsigned int f=2;f<r;f++)strcat(tmparray2,(char*)tmparray[f]);
                                  tmplist2->push_back(tmparray2);
                                  tmparray2[0]=0;
                                  }
                           }
                           else if(openp-1==closep && tmparray[r]=='<' && tmparray[r+1]=='=' && tmparray[r+2]=='>'){

                                 if(tmparray[r+3]=='~' && tmparray[2]=='~'){
                           	    tmpl1=tmplist2; tmparray2[1]=0;
                                  for(unsigned int f=3;f<r;f++)strcat(tmparray2,(char*)tmparray[f]);
                                  tmpl1->push_back(tmparray2);
                                  tmparray2[0]=0;
                                  for(unsigned int g=r+3;g<strlen(tmparray)-1;g++)strcat(tmparray2,(char*)tmparray[g]);
                                  tmpl1->push_back(tmparray2);
                                  tmpqueue1->push_back(tmpl1);
                                  tmparray2[0]=0;
                                  while(!tmpl1->empty())tmpl1->pop_front();

                                  for(unsigned int f=2;f<r;f++)strcat(tmparray2,(char*)tmparray[f]);
                                  tmplist2->push_back(tmparray2);
                                  tmparray2[0]=0;tmparray2[1]=0;
                                  for(unsigned int g=r+4;g<strlen(tmparray)-1;g++)strcat(tmparray2,(char*)tmparray[g]);
                                  tmplist2->push_back(tmparray2);
                                  tmparray2[0]=0;
                                                                           }

                                 if(tmparray[2]=='~' && tmparray[r+3]!='~'){

                                             tmpl1=tmplist2; tmparray2[0]=0;
                                  for(unsigned int f=3;f<r;f++)strcat(tmparray2,(char*)tmparray[f]);
                                  tmpl1->push_back(tmparray2);
                                  tmparray2[0]=0;
                                  for(unsigned int g=r+3;g<strlen(tmparray)-1;g++)strcat(tmparray2,(char*)tmparray[g]);
                                  tmpl1->push_back(tmparray2);
                                  tmpqueue1->push_back(tmpl1);
                                  tmparray2[0]=0;
                                  while(!tmpl1->empty())tmpl1->pop_front();

                                  tmparray2[0]='~'; tmparray2[1]=0;
                                  for(unsigned int f=3;f<r;f++)strcat(tmparray2,(char*)tmparray[f]);
                                  tmplist2->push_back(tmparray2);


                                  tmparray2[0]=0;tmparray2[0]='~';tmparray2[1]=0;
                                  for(unsigned int g=r+4;g<strlen(tmparray)-1;g++)strcat(tmparray2,(char*)tmparray[g]);
                                  tmplist2->push_back(tmparray2);
                                  tmparray2[0]=0;
                                 }
                                  if(tmparray[2]!='~' && tmparray[r+3]=='~'){

                                             tmpl1=tmplist2;

                                             tmparray2[0]='~';tmparray2[1]=0;
                                  for(unsigned int f=3;f<r;f++)strcat(tmparray2,(char*)tmparray[f]);
                                  tmpl1->push_back(tmparray2);
                                  tmparray2[0]=0; tmparray2[0]='~';

                                  tmparray2[1]=0;
                                  for(unsigned int g=r+4;g<strlen(tmparray)-1;g++)strcat(tmparray2,(char*)tmparray[g]);
                                  tmpl1->push_back(tmparray2);
                                  tmpqueue1->push_back(tmpl1);
                                  tmparray2[0]=0;
                                  while(!tmpl1->empty())tmpl1->pop_front();

                                   tmparray2[0]=0;
                                  for(unsigned int f=2;f<r;f++)strcat(tmparray2,(char*)tmparray[f]);
                                  tmplist2->push_back(tmparray2);
                                  tmparray2[0]=0;tmparray2[1]=0;
                                  for(unsigned int g=r+4;g<strlen(tmparray)-1;g++)strcat(tmparray2,(char*)tmparray[g]);
                                  tmplist2->push_back(tmparray2);
                                  tmparray2[0]=0;
                                 }

                                  if(tmparray[r+3]!='~' && tmparray[2]!='~'){
                                     tmpl1=tmplist2;tmparray2[0]='~';

                                     tmparray2[1]=0;
                                  for(unsigned int f=2;f<r;f++)strcat(tmparray2,(char*)tmparray[f]);
                                  tmpl1->push_back(tmparray2);
                                  tmparray2[0]=0;
                                  for(unsigned int g=r+3;g<strlen(tmparray)-1;g++)strcat(tmparray2,(char*)tmparray[g]);
                                  tmpl1->push_back(tmparray2);
                                  tmpqueue1->push_back(tmpl1);
                                  tmparray2[0]=0;
                                  while(!tmpl1->empty())tmpl1->pop_front();

                                  for(unsigned int f=2;f<r;f++)strcat(tmparray2,(char*)tmparray[f]);
                                  tmplist2->push_back(tmparray2);

                                  tmparray2[0]=0;tmparray2[0]='~';tmparray2[1]=0;
                                  for(unsigned int g=r+3;g<strlen(tmparray)-1;g++)strcat(tmparray2,(char*)tmparray[g]);
                                  tmplist2->push_back(tmparray2);
                                  tmparray2[0]=0;
                                  }

                           }
                   }
                }
                else if(tmparray[0]!='~'){
                		  for(unsigned int r=0;r<strlen(tmparray);r++){
                           if(tmparray[r]=='('){
                             openp++;
                           }
                           else if(tmparray[r]==')'){
                                  closep++;
                           }

                           if(openp-1==closep && tmparray[r]=='&'){

                             for(unsigned int f=1;f<r;f++)strcat(tmparray2,(char*)tmparray[f]);
                             tmplist2->push_back(tmparray2);
                             tmparray2[0]=0;

                             for(unsigned int g=r+1;g<strlen(tmparray)-1;g++)strcat(tmparray2,(char*)tmparray[g]);
                             tmplist2->push_back(tmparray2);
									  tmparray2[0]=0;

                           }
                           else if(openp-1==closep && tmparray[r]=='|'){

                                  tmpl1=tmplist2;
                                  for(unsigned int g=r+1;g<strlen(tmparray)-1;g++)strcat(tmparray2,(char*)tmparray[g]);
                                  tmpl1->push_back(tmparray2);
                                  tmpqueue1->push_back(tmpl1);
                                  tmparray2[0]=0;
                                  while(!tmpl1->empty())tmpl1->pop_front();

                                  for(unsigned int f=1;f<r;f++)strcat(tmparray2,(char*)tmparray[f]);
                                  tmplist2->push_back(tmparray2);
                                  tmparray2[0]=0;

                           }
                           else if(openp-1==closep && tmparray[r]=='-' && tmparray[r+1]=='>'){

                           	    tmpl1=tmplist2;
                                  for(unsigned int g=r+2;g<strlen(tmparray)-1;g++)strcat(tmparray2,(char*)tmparray[g]);
                                  tmpl1->push_back(tmparray2);
                                  tmpqueue1->push_back(tmpl1);
                                  tmparray2[0]=0;
                                  while(!tmpl1->empty())tmpl1->pop_front();

                                  tmparray2[0]='~';tmparray2[1]=0;
                                  for(unsigned int f=1;f<r;f++)strcat(tmparray2,(char*)tmparray[f]);
                                  tmplist2->push_back(tmparray2);
                                  tmparray2[0]=0;

                           }
                           else if(openp-1==closep && tmparray[r]=='<' && tmparray[r+1]=='=' && tmparray[r+2]=='>'){

                           	    tmpl1=tmplist2;
                                  tmparray2[0]='~';tmparray2[1]=0;
                                  for(unsigned int f=1;f<r;f++)strcat(tmparray2,(char*)tmparray[f]);
                                  tmpl1->push_back(tmparray2);
                                  tmparray2[0]=0;tmparray2[0]='~';tmparray2[1]=0;
                                  for(unsigned int g=r+3;g<strlen(tmparray)-1;g++)strcat(tmparray2,(char*)tmparray[g]);
                                  tmpl1->push_back(tmparray2);
                                  tmpqueue1->push_back(tmpl1);
                                  tmparray2[0]=0;
                                  while(!tmpl1->empty())tmpl1->pop_front();

                                  for(unsigned int f=1;f<r;f++)strcat(tmparray2,(char*)tmparray[f]);
                                  tmplist2->push_back(tmparray2);
                                  tmparray2[0]=0;
                                  for(unsigned int g=r+3;g<strlen(tmparray)-1;g++)strcat(tmparray2,(char*)tmparray[g]);
                                  tmplist2->push_back(tmparray2);
                                  tmparray2[0]=0;

                           }

                       }
                }
          }

        }//end while

        counter11++;

        if(success==1){
           strcpy(gammaprime1[aacounter1],sigmaprime1[counter11-1]);
           aacounter1++;
           continue;
        }

        }//end while

        printf("\n --------------------------------------------------------------------\n");

        printf("\n The Maxiconsistant Subset is:\n\n {");

        for(int u=0;u<aacounter1-1;u++){

           printf(" %s",gammaprime1[u]); if(u!=aacounter1-2)printf(" ,");

        }

        printf(" }\n");

        printf("\n --------------------------------------------------------------------\n");

     //This is the derivation part.
                                                    printf("\n NO>>>>\n");
     success=0;notfinished=1;counteras1=0;counters1=0;

     while(!tmplist2->empty())tmplist2->pop_front();
      printf("\n NO>>>>\n");
     list<char*> *tmplist6=new list<char*>();
       list<char*> *tmplist7=new list<char*>();
printf("\n NO>>>>\n");

     char newquery[500]="" ;

     if(query[0]!='~' && strlen(query)>0){      printf("\n NO>>>>\n");
       newquery[0]='~';
       strcat(newquery,query);
     }
     else if(query[0]=='~'){                         printf("\n NO>>>>\n");
            for(unsigned int i=1;i<strlen(query);i++){
printf("\n NO>>>>\n");
               newquery[i-1]=query[i];   printf("\n NO>>>>\n");
            }
     }

     printf("\n not alpha== %s\n",newquery);
     printf("\n %d \n",aacounter1);
     for(int h=0;h<aacounter1-1;h++){
            tmplist2->push_back(gammaprime1[h]);printf("\n %s\n",tmplist2->back());}

     if(strlen(query)>0){tmplist2->push_front(newquery); printf("\n %s\n",tmplist2->front());}

     while(notfinished==1){  printf("\n NO>>>>\n");

             notfinished=0;nf1=0;


            while(!tmplist2->empty()){

                 tmplist6->push_back(tmplist2->front());
                 tmplist7->push_back(tmplist2->front());
                 tmplist2->pop_front();

            }

            while(!tmplist7->empty()){

                 tmplist2->push_back(tmplist7->front());
                 tmplist7->pop_front();

            }

             printf("\n %s\n",tmplist2->back());
            printf("\n success=%d\n",success);
                printf("\n %d + %d = %d\n",counters1,counteras1,tmplist2->size());

                if(notfinished==0 && (unsigned int)counteras1+counters1!=tmplist2->size())notfinished=1;
            if(!notfinished && (unsigned int)counteras1+counters1==tmplist2->size()){printf("\n yes...\n");
              success=0;break;
            }


          tmparray=tmplist2->front();
          tmplist2->pop_front();

          if(strlen(tmparray)<=2){
            if(strlen(tmparray)==1){
                                        printf("\n Symb\n");
              for(int f=0;f<counteras1;f++){
                 if(tmparray[0]==tmpantisymbol1[f][1]){
                   nf1=1;
                   break;
                 }
              }

                 if(nf1==1){
                     nf1=0;
                   while(!tmplist2->empty())tmplist2->pop_front();

if(!tmpqueue1->empty()){tmplist2=tmpqueue1->front();continue;}
                    else if(tmpqueue1->empty()){success=1;break;}
                 }
                 else if(nf1==0){

                    strcpy(tmpsymbol1[counters1],tmparray);
                    counters1++;
                    tmplist2->push_back(tmparray);
                 }

            }
            else if(strlen(tmparray)==2){
                                               printf("\n NOT Symb\n");
            	    for(int f=0;f<counters1;f++){
                     if(tmparray[1]==tmpsymbol1[f][0]){
                       nf1=1;
                        break;
                     }
                   }

                 if(nf1==1){
                    nf1=0;
                   while(!tmplist2->empty())tmplist2->pop_front();

if(!tmpqueue1->empty()){tmplist2=tmpqueue1->front();continue;}
                    else if(tmpqueue1->empty()){success=1;break;}
                 }
                 else if(nf1==0){

                   strcpy(tmpantisymbol1[counteras1],tmparray);
                   counters1++;
                    tmplist2->push_back(tmparray);printf("\n %d \n",tmplist2->size());
                 }

            }
          }
          else if(strlen(tmparray)>2){  success=0;printf("\n YES>>>>\n");

                int openp=0,closep=0;
                char tmparray2[100]="";
                list<char*>* tmpl1=new list<char*>();
                list<char*>* tmpl2=new list<char*>();
                if(tmparray[0]=='~'){   printf("\n NOT!!!!!!!!\n");
                   for(unsigned int r=1;r<strlen(tmparray);r++){
                           if(tmparray[r]=='('){
                             openp++;
                           }
                           else if(tmparray[r]==')'){
                                  closep++;
                           }

                           if(openp-1==closep && tmparray[r]=='&'){

                             tmpl1=tmplist2;
                             if(tmparray[r+1]!='~'){
                                tmparray2[0]='~';
                              tmparray2[1]=0;
                             for(unsigned int g=r+1;g<strlen(tmparray)-1;g++)strcat(tmparray2,(char*)tmparray[g]);
                             tmpl1->push_back(tmparray2);
                             tmpqueue1->push_back(tmpl1);
                             tmparray2[0]=0;
                             while(!tmpl1->empty())tmpl1->pop_front();
                             }
                             else if(tmparray[r+1]=='~'){
                                     tmparray2[0]=0;
                                     for(unsigned int g=r+2;g<strlen(tmparray)-1;g++)strcat(tmparray2,(char*)tmparray[g]);
                                     tmpl1->push_back(tmparray2);
                                     tmpqueue1->push_back(tmpl1);
                                     tmparray2[0]=0;

while(!tmpl1->empty())tmpl1->pop_front();
                             }

                             if(tmparray[2]=='~'){
                                 tmparray2[0]=0;
                                 for(unsigned int f=3;f<r;f++)strcat(tmparray2,(char*)tmparray[f]);
                                 tmplist2->push_back(tmparray2);
                                 tmparray2[0]=0;
                             }
                             else if(tmparray[2]!='~'){

                                  tmparray2[0]='~';tmparray2[1]=0;
                                  for(unsigned int f=2;f<r;f++)strcat(tmparray2,(char*)tmparray[f]);
                                  tmplist2->push_back(tmparray2);
                                  tmparray2[0]=0;
                             }



                           }
                           else if(openp-1==closep && tmparray[r]=='|'){

                                 if(tmparray[2]=='~'){
                                    tmparray2[0]=0;
                                  for(unsigned int f=3;f<r;f++)strcat(tmparray2,(char*)tmparray[f]);
                                  tmplist2->push_back(tmparray2);
                                  tmparray2[0]=0;
                                 }
                                 else{
                                  tmparray2[0]='~';tmparray2[1]=0;
                                  for(unsigned int f=2;f<r;f++)strcat(tmparray2,(char*)tmparray[f]);
                                  tmplist2->push_back(tmparray2);
                                  tmparray2[0]=0;
                                 }

                                 if(tmparray[r+1]=='~'){
                                     tmparray2[0]=0;
                                  for(unsigned int g=r+2;g<strlen(tmparray)-1;g++)strcat(tmparray2,(char*)tmparray[g]);
                                  tmplist2->push_back(tmparray2);
									       tmparray2[0]=0;
                                 }
                                 else{
                                  tmparray2[0]='~';tmparray2[1]=0;
                                  for(unsigned int g=r+1;g<strlen(tmparray)-1;g++)strcat(tmparray2,(char*)tmparray[g]);
                                  tmplist2->push_back(tmparray2);
									       tmparray2[0]=0;
                                 }

                           }
                           else if(openp-1==closep && tmparray[r]=='-' && tmparray[r+1]=='>'){
                                  if(tmparray[r+1]=='~'){
                                     tmparray2[0]=0;
                                  for(unsigned int g=r+2;g<strlen(tmparray)-1;g++)strcat(tmparray2,(char*)tmparray[g]);
                                  tmplist2->push_back(tmparray2);
                                  tmparray2[0]=0;
                                  }
                                  else{
                           	    tmparray2[0]='~';tmparray2[1]=0;
                                  for(unsigned int g=r+1;g<strlen(tmparray)-1;g++)strcat(tmparray2,(char*)tmparray[g]);
                                  tmplist2->push_back(tmparray2);
                                  tmparray2[0]=0;
                                  }

                                  if(tmparray[2]=='~'){

                                  tmparray2[0]='~';tmparray2[1]=0;
                                  for(unsigned int f=3;f<r;f++)strcat(tmparray2,(char*)tmparray[f]);
                                  tmplist2->push_back(tmparray2);
                                  tmparray2[0]=0;
                                  }
                                  else{
                                  for(unsigned int f=2;f<r;f++)strcat(tmparray2,(char*)tmparray[f]);
                                  tmplist2->push_back(tmparray2);
                                  tmparray2[0]=0;
                                  }
                           }
                           else if(openp-1==closep && tmparray[r]=='<' &&
tmparray[r+1]=='=' && tmparray[r+2]=='>'){

                                 if(tmparray[r+3]=='~' && tmparray[2]=='~'){
                           	    tmpl1=tmplist2; tmparray2[0]=0;
                                  for(unsigned int f=3;f<r;f++)strcat(tmparray2,(char*)tmparray[f]);
                                  tmpl1->push_back(tmparray2);
                                  tmparray2[0]=0;
                                  for(unsigned int g=r+3;g<strlen(tmparray)-1;g++)strcat(tmparray2,(char*)tmparray[g]);
                                  tmpl1->push_back(tmparray2);
                                  tmpqueue1->push_back(tmpl1);
                                  tmparray2[0]=0;
                                  while(!tmpl1->empty())tmpl1->pop_front();

                                  for(unsigned int f=2;f<r;f++)strcat(tmparray2,(char*)tmparray[f]);
                                  tmplist2->push_back(tmparray2);
                                  tmparray2[0]=0;tmparray2[1]=0;
                                  for(unsigned int g=r+4;g<strlen(tmparray)-1;g++)strcat(tmparray2,(char*)tmparray[g]);
                                  tmplist2->push_back(tmparray2);
                                  tmparray2[0]=0;

                                 }

                                 if(tmparray[2]=='~' && tmparray[r+3]!='~'){

                                             tmpl1=tmplist2; tmparray2[1]=0;
                                  for(unsigned int f=3;f<r;f++)strcat(tmparray2,(char*)tmparray[f]);
                                  tmpl1->push_back(tmparray2);
                                  tmparray2[0]=0;
                                  for(unsigned int g=r+3;g<strlen(tmparray)-1;g++)strcat(tmparray2,(char*)tmparray[g]);
                                  tmpl1->push_back(tmparray2);
                                  tmpqueue1->push_back(tmpl1);
                                  tmparray2[0]=0;
                                  while(!tmpl1->empty())tmpl1->pop_front();

                                  tmparray2[0]='~'; tmparray2[1]=0;
                                  for(unsigned int f=3;f<r;f++)strcat(tmparray2,(char*)tmparray[f]);
                                  tmplist2->push_back(tmparray2);
                                  tmparray2[0]=0;tmparray2[0]='~';tmparray2[1]=0;
                                  for(unsigned int g=r+4;g<strlen(tmparray)-1;g++)strcat(tmparray2,(char*)tmparray[g]);
                                  tmplist2->push_back(tmparray2);
                                  tmparray2[0]=0;
                                 }
                                  if(tmparray[2]!='~' && tmparray[r+3]=='~'){

                                  tmpl1=tmplist2;tmparray2[0]='~';tmparray2[1]=0;
                                  for(unsigned int f=3;f<r;f++)strcat(tmparray2,(char*)tmparray[f]);
                                  tmpl1->push_back(tmparray2);
                                  tmparray2[0]=0; tmparray2[0]='~';tmparray2[1]=0;
                                  for(unsigned int g=r+4;g<strlen(tmparray)-1;g++)strcat(tmparray2,(char*)tmparray[g]);
                                  tmpl1->push_back(tmparray2);
                                  tmpqueue1->push_back(tmpl1);
                                  tmparray2[0]=0;
                                  while(!tmpl1->empty())tmpl1->pop_front();

                                   tmparray2[0]=0;
                                  for(unsigned int f=2;f<r;f++)strcat(tmparray2,(char*)tmparray[f]);
                                  tmplist2->push_back(tmparray2);
                                  tmparray2[0]=0;tmparray2[1]=0;
                                  for(unsigned int g=r+4;g<strlen(tmparray)-1;g++)strcat(tmparray2,(char*)tmparray[g]);
                                  tmplist2->push_back(tmparray2);
                                  tmparray2[0]=0;
                                 }

                                  if(tmparray[r+3]!='~' &&
tmparray[2]!='~'){
                                     tmpl1=tmplist2;tmparray2[0]='~';
tmparray2[1]=0;
                                  for(unsigned int f=2;f<r;f++)strcat(tmparray2,(char*)tmparray[f]);
                                  tmpl1->push_back(tmparray2);
                                  tmparray2[0]=0;
                                  for(unsigned int g=r+3;g<strlen(tmparray)-1;g++)strcat(tmparray2,(char*)tmparray[g]);
                                  tmpl1->push_back(tmparray2);
                                  tmpqueue1->push_back(tmpl1);
                                  tmparray2[0]=0;
                                  while(!tmpl1->empty())tmpl1->pop_front();

                                  for(unsigned int f=2;f<r;f++)strcat(tmparray2,(char*)tmparray[f]);
                                  tmplist2->push_back(tmparray2);
											 tmparray2[0]=0;tmparray2[0]='~';tmparray2[1]=0;
                                  for(unsigned int g=r+3;g<strlen(tmparray)-1;g++)strcat(tmparray2,(char*)tmparray[g]);
                                  tmplist2->push_back(tmparray2);
                                  tmparray2[0]=0;
                                  }

                           }
                   }
                }
                else if(tmparray[0]!='~'){    int cc=0;  printf("\n YES>>>>2\n");
                		  for(unsigned int r=0;r<strlen(tmparray);r++){
                           if(tmparray[r]=='('){
                             openp++;
                           }
                           else if(tmparray[r]==')'){
                                  closep++;
                           }
                                           printf("\n counter=%d\n",cc++);
                           if(openp-1==closep && tmparray[r]=='&'){

                             for(unsigned int f=1;f<r;f++)strcat(tmparray2,(char*)tmparray[f]);
                             tmplist2->push_back(tmparray2);
                             tmparray2[0]=0;

                             for(unsigned int g=r+1;g<strlen(tmparray)-1;g++)strcat(tmparray2,(char*)tmparray[g]);
                             tmplist2->push_back(tmparray2);
									  tmparray2[0]=0;

                           }
                           else if(openp-1==closep && tmparray[r]=='|'){

                                  for(unsigned int g=r+1;g<strlen(tmparray)-1;g++)tmparray2[g-(r+1)]=tmparray[g];
                                  printf("\n %s\n",tmparray); printf("\n %s\n",tmparray2);

                                  tmplist2->push_back(tmparray2);    printf("\n %s\n",tmplist2->back());

            while(!tmplist2->empty()){

                 tmpl1->push_back(tmplist2->front());
                 tmpl2->push_back(tmplist2->front());
                 tmplist2->pop_front();

            }

            while(!tmpl2->empty()){

                 tmplist2->push_back(tmpl2->front());
                 tmpl2->pop_front();

            }
                                  tmpqueue1->push_back(tmpl1);
                                  printf("\n %s\n",tmplist2->back());
                                  tmplist2->pop_back();

                                  for(unsigned int f=1;f<r;f++)tmparray2[f-1]=tmparray[f];
                                     printf("\n %s\n",tmparray); printf("\n %s\n",tmparray2);
                                  tmplist2->push_back(tmparray2);
                                  printf("\n listsize=%d\n",tmplist2->size());
                                  printf("\n %s\n",tmplist2->back()); break;

                           }
                           else if(openp-1==closep && tmparray[r]=='-' && tmparray[r+1]=='>'){

                           	    tmpl1=tmplist2;
                                  for(unsigned int g=r+2;g<strlen(tmparray)-1;g++)strcat(tmparray2,(char*)tmparray[g]);
                                  tmpl1->push_back(tmparray2);
                                  tmpqueue1->push_back(tmpl1);
                                  tmparray2[0]=0;
                                  while(!tmpl1->empty())tmpl1->pop_front();

                                  tmparray2[0]='~';tmparray2[1]=0;
                                  for(unsigned int f=1;f<r;f++)strcat(tmparray2,(char*)tmparray[f]);
                                  tmplist2->push_back(tmparray2);
                                  tmparray2[0]=0;

                           }
                           else if(openp-1==closep && tmparray[r]=='<' && tmparray[r+1]=='=' && tmparray[r+2]=='>'){

                           	    tmpl1=tmplist2;tmparray2[0]='~';tmparray2[1]=0;
                                  for(unsigned int f=1;f<r;f++)strcat(tmparray2,(char*)tmparray[f]);
                                  tmpl1->push_back(tmparray2);
                                  tmparray2[0]=0; tmparray2[0]='~';tmparray2[1]=0;
                                  for(unsigned int g=r+3;g<strlen(tmparray)-1;g++)strcat(tmparray2,(char*)tmparray[g]);
                                  tmpl1->push_back(tmparray2);
                                  tmpqueue1->push_back(tmpl1);
                                  tmparray2[0]=0;
                                  while(!tmpl1->empty())tmpl1->pop_front();

                                  for(unsigned int f=1;f<r;f++)strcat(tmparray2,(char*)tmparray[f]);
                                  tmplist2->push_back(tmparray2);
                                  tmparray2[0]=0;
                                  for(unsigned int g=r+3;g<strlen(tmparray)-1;g++)strcat(tmparray2,(char*)tmparray[g]);
                                  tmplist2->push_back(tmparray2);
                                  tmparray2[0]=0;

                           }

                       }
                }
          }

        }//end while

        printf ("\n Success= %d\n",success);


        //check if gamma entails ~alpha

        notfinished=1; counteras1=0;counters1=0;

        while(!tmpqueue1->empty())tmpqueue1->pop_front();

        while(!tmplist2->empty())tmplist2->pop_front();

     list<char*> *tmplist8=new list<char*>();
     list<char*> *tmplist9=new list<char*>();
     for(int h=0;h<aacounter1-1;h++){
            tmplist2->push_back(gammaprime1[h]);printf("\n %s\n",tmplist2->back());}

     tmplist2->push_back(query); printf("\n %s\n",tmplist2->back());

     while(notfinished){

     if(success==1)break;  printf("\nls1= %d \n",tmplist2->size());

            notfinished=0; nf1=0;

            while(!tmplist2->empty()){

                 tmplist8->push_back(tmplist2->front());
                 tmplist9->push_back(tmplist2->front());
                 tmplist2->pop_front();

            }

            while(!tmplist9->empty()){

                 tmplist2->push_back(tmplist9->front()); printf("\n %s \n",tmplist2->back());
                 tmplist9->pop_front();

            }

             while(!tmplist8->empty()){      printf("\n %d \n",tmplist2->size());

                 if(strlen(tmplist8->front())>2){ notfinished=1;break;}

                 tmplist8->pop_front();
            }

            printf("\n success=%d\n",success);
                printf("\n %d + %d = %d\n",counters1,counteras1,tmplist2->size());

                if(notfinished==0 && (unsigned int)counteras1+counters1!=tmplist2->size())notfinished=1;
            if(!notfinished && (unsigned int)counteras1+counters1==tmplist2->size()){printf("\n yes...\n");
               break;}

          tmparray=tmplist2->front();
          tmplist2->pop_front();     printf("\n listsize = %d \n",tmplist2->size());
          printf("\n %s \n",tmparray);
          if(strlen(tmparray)<=2){
            if(strlen(tmparray)==1){   printf("\n ONE \n");   printf("\n %s \n",tmparray);
            printf("\n counters1=%d , counteras1=%d \n",counters1,counteras1);
              for(int f=0;f<counteras1;f++){  printf(" %c %c \n",tmparray[0],tmpsymbol1[f][1]);
                 if(tmparray[0]==tmpantisymbol1[f][1]){
                   nf1=1;   printf("\n OK\n");
                   break;
                 }
              }

                 if(nf1==1){
                     nf1=0;
                   while(!tmplist2->empty())tmplist2->pop_front();

if(!tmpqueue1->empty()){printf("\n Not empty\n");tmplist2->push_back(tmpqueue1->front()->front());continue;}
                    else if(tmpqueue1->empty()){success=2;break;}
                 }
                 else if(nf1==0){

                    strcpy(tmpsymbol1[counters1],tmparray);
                    counters1++;
                    tmplist2->push_back(tmparray);    printf("\n listsize = %d \n",tmplist2->size());
                 }
            }
            else if(strlen(tmparray)==2){   printf("\n TWO \n");
            printf("\n counters1=%d , counteras1=%d \n",counters1,counteras1);
            	    for(int f=0;f<counters1;f++){printf(" %c %c \n",tmparray[1],tmpsymbol1[f][0]);
                     if(tmparray[1]==tmpsymbol1[f][0]){
                       nf1=1;
                        break;
                     }
                   }

                 if(nf1==1){
                    nf1=0;
                   while(!tmplist2->empty())tmplist2->pop_front();

if(!tmpqueue1->empty()){tmplist2=tmpqueue1->front();continue;}
                    else if(tmpqueue1->empty()){success=2;break;}
                 }
                 else if(nf1==0){

                   strcpy(tmpantisymbol1[counteras1],tmparray);
                   counteras1++;
                    tmplist2->push_back(tmparray);
                 }
            }
          }
          else if(strlen(tmparray)>2){  printf("\n THREE \n");
                                          success=0;
                int openp=0,closep=0;
                char tmparray2[100]="";
                list<char*>* tmpl1=new list<char*>();

                if(tmparray[0]=='~'){
                   for(unsigned int r=1;r<strlen(tmparray);r++){
                           if(tmparray[r]=='('){
                             openp++;
                           }
                           else if(tmparray[r]==')'){
                                  closep++;
                           }

                           if(openp-1==closep && tmparray[r]=='&'){

                             tmpl1=tmplist2;
                             if(tmparray[r+1]!='~'){
                                tmparray2[0]='~';
                              tmparray2[0]=0;
                             for(unsigned int g=r+1;g<strlen(tmparray)-1;g++)strcat(tmparray2,(char*)tmparray[g]);
                             tmpl1->push_back(tmparray2);
                             tmpqueue1->push_back(tmpl1);
                             tmparray2[0]=0;
                             while(!tmpl1->empty())tmpl1->pop_front();
                             }
                             else if(tmparray[r+1]=='~'){
                                     tmparray2[0]=0;
                                     for(unsigned int g=r+2;g<strlen(tmparray)-1;g++)strcat(tmparray2,(char*)tmparray[g]);
                                     tmpl1->push_back(tmparray2);
                                     tmpqueue1->push_back(tmpl1);
                                     tmparray2[0]=0;

while(!tmpl1->empty())tmpl1->pop_front();
                             }

                             if(tmparray[2]=='~'){
                                 tmparray2[0]=0;
                                 for(unsigned int f=3;f<r;f++)strcat(tmparray2,(char*)tmparray[f]);
                                 tmplist2->push_back(tmparray2);
                                 tmparray2[0]=0;
                             }
                             else if(tmparray[2]!='~'){

                                  tmparray2[0]='~';tmparray2[1]=0;
                                  for(unsigned int f=2;f<r;f++)strcat(tmparray2,(char*)tmparray[f]);
                                  tmplist2->push_back(tmparray2);
                                  tmparray2[0]=0;
                             }



                           }
                           else if(openp-1==closep && tmparray[r]=='|'){

                                 if(tmparray[2]=='~'){
                                    tmparray2[0]=0;
                                  for(unsigned int f=3;f<r;f++)strcat(tmparray2,(char*)tmparray[f]);
                                  tmplist2->push_back(tmparray2);
                                  tmparray2[0]=0;
                                 }
                                 else{
                                  tmparray2[0]='~';tmparray2[1]=0;
                                  for(unsigned int f=2;f<r;f++)strcat(tmparray2,(char*)tmparray[f]);
                                  tmplist2->push_back(tmparray2);
                                  tmparray2[0]=0;
                                 }

                                 if(tmparray[r+1]=='~'){
                                     tmparray2[0]=0;
                                  for(unsigned int g=r+2;g<strlen(tmparray)-1;g++)strcat(tmparray2,(char*)tmparray[g]);
                                  tmplist2->push_back(tmparray2);
									       tmparray2[0]=0;
                                 }
                                 else{
                                  tmparray2[0]='~';tmparray2[1]=0;
                                  for(unsigned int g=r+1;g<strlen(tmparray)-1;g++)strcat(tmparray2,(char*)tmparray[g]);
                                  tmplist2->push_back(tmparray2);
									       tmparray2[0]=0;
                                 }

                           }
                           else if(openp-1==closep && tmparray[r]=='-' && tmparray[r+1]=='>'){
                                  if(tmparray[r+1]=='~'){
                                     tmparray2[0]=0;
                                  for(unsigned int g=r+2;g<strlen(tmparray)-1;g++)strcat(tmparray2,(char*)tmparray[g]);
                                  tmplist2->push_back(tmparray2);
                                  tmparray2[0]=0;
                                  }
                                  else{
                           	    tmparray2[0]='~';tmparray2[1]=0;
                                  for(unsigned int g=r+1;g<strlen(tmparray)-1;g++)strcat(tmparray2,(char*)tmparray[g]);
                                  tmplist2->push_back(tmparray2);
                                  tmparray2[0]=0;
                                  }

                                  if(tmparray[2]=='~'){tmparray2[0]='~';tmparray2[1]=0;
                                  for(unsigned int f=3;f<r;f++)strcat(tmparray2,(char*)tmparray[f]);
                                  tmplist2->push_back(tmparray2);
                                  tmparray2[0]=0;
                                  }
                                  else{
                                  for(unsigned int f=2;f<r;f++)strcat(tmparray2,(char*)tmparray[f]);
                                  tmplist2->push_back(tmparray2);
                                  tmparray2[0]=0;
                                  }
                           }
                           else if(openp-1==closep && tmparray[r]=='<' && tmparray[r+1]=='=' && tmparray[r+2]=='>'){

                                 if(tmparray[r+3]=='~' && tmparray[2]=='~'){
                           	    tmpl1=tmplist2; tmparray2[0]=0;
                                  for(unsigned int f=3;f<r;f++)strcat(tmparray2,(char*)tmparray[f]);
                                  tmpl1->push_back(tmparray2);
                                  tmparray2[0]=0;
                                  for(unsigned int g=r+3;g<strlen(tmparray)-1;g++)strcat(tmparray2,(char*)tmparray[g]);
                                  tmpl1->push_back(tmparray2);
                                  tmpqueue1->push_back(tmpl1);
                                  tmparray2[0]=0;
                                  while(!tmpl1->empty())tmpl1->pop_front();

                                  for(unsigned int f=2;f<r;f++)strcat(tmparray2,(char*)tmparray[f]);
                                  tmplist2->push_back(tmparray2);
                                  tmparray2[0]=0;tmparray2[1]=0;
                                  for(unsigned int g=r+4;g<strlen(tmparray)-1;g++)strcat(tmparray2,(char*)tmparray[g]);
                                  tmplist2->push_back(tmparray2);
                                  tmparray2[0]=0;

                                 }

                                 if(tmparray[2]=='~' && tmparray[r+3]!='~'){

                                             tmpl1=tmplist2; tmparray2[0]=0;
                                  for(unsigned int f=3;f<r;f++)strcat(tmparray2,(char*)tmparray[f]);
                                  tmpl1->push_back(tmparray2);
                                  tmparray2[0]=0;
                                  for(unsigned int g=r+3;g<strlen(tmparray)-1;g++)strcat(tmparray2,(char*)tmparray[g]);
                                  tmpl1->push_back(tmparray2);
                                  tmpqueue1->push_back(tmpl1);
                                  tmparray2[0]=0;
                                  while(!tmpl1->empty())tmpl1->pop_front();

                                  tmparray2[0]='~'; tmparray2[1]=0;
                                  for(unsigned int f=3;f<r;f++)strcat(tmparray2,(char*)tmparray[f]);
                                  tmplist2->push_back(tmparray2);tmparray2[0]=0;tmparray2[0]='~';tmparray2[1]=0;
                                  for(unsigned int g=r+4;g<strlen(tmparray)-1;g++)strcat(tmparray2,(char*)tmparray[g]);
                                  tmplist2->push_back(tmparray2);
                                  tmparray2[0]=0;
                                 }
                                  if(tmparray[2]!='~' && tmparray[r+3]=='~'){

                                             tmpl1=tmplist2;tmparray2[0]='~';tmparray2[1]=0;
                                  for(unsigned int f=3;f<r;f++)strcat(tmparray2,(char*)tmparray[f]);
                                  tmpl1->push_back(tmparray2);
                                  tmparray2[0]=0; tmparray2[0]='~'; tmparray2[1]=0;
                                  for(unsigned int g=r+4;g<strlen(tmparray)-1;g++)strcat(tmparray2,(char*)tmparray[g]);
                                  tmpl1->push_back(tmparray2);
                                  tmpqueue1->push_back(tmpl1);
                                  tmparray2[0]=0;
                                  while(!tmpl1->empty())tmpl1->pop_front();

                                   tmparray2[1]=0;
                                  for(unsigned int f=2;f<r;f++)strcat(tmparray2,(char*)tmparray[f]);
                                  tmplist2->push_back(tmparray2);
                                  tmparray2[0]=0;tmparray2[1]=0;
                                  for(unsigned int g=r+4;g<strlen(tmparray)-1;g++)strcat(tmparray2,(char*)tmparray[g]);
                                  tmplist2->push_back(tmparray2);
                                  tmparray2[0]=0;
                                 }

                                  if(tmparray[r+3]!='~' && tmparray[2]!='~'){
                                     tmpl1=tmplist2;tmparray2[0]='~';tmparray2[1]=0;
                                  for(unsigned int f=2;f<r;f++)strcat(tmparray2,(char*)tmparray[f]);
                                  tmpl1->push_back(tmparray2);
                                  tmparray2[0]=0;
                                  for(unsigned int g=r+3;g<strlen(tmparray)-1;g++)strcat(tmparray2,(char*)tmparray[g]);
                                  tmpl1->push_back(tmparray2);
                                  tmpqueue1->push_back(tmpl1);
                                  tmparray2[0]=0;
                                  while(!tmpl1->empty())tmpl1->pop_front();

                                  for(unsigned int f=2;f<r;f++)strcat(tmparray2,(char*)tmparray[f]);
                                  tmplist2->push_back(tmparray2);tmparray2[0]=0;tmparray2[0]='~';tmparray2[1]=0;
                                  for(unsigned int g=r+3;g<strlen(tmparray)-1;g++)strcat(tmparray2,(char*)tmparray[g]);
                                  tmplist2->push_back(tmparray2);
                                  tmparray2[0]=0;
                                  }

                           }
                   }
                }
                else if(tmparray[0]!='~'){
                		  for(unsigned int r=0;r<strlen(tmparray);r++){
                           if(tmparray[r]=='('){
                             openp++;
                           }
                           else if(tmparray[r]==')'){
                                  closep++;
                           }

                           if(openp-1==closep && tmparray[r]=='&'){

                             for(unsigned int f=1;f<r;f++)strcat(tmparray2,(char*)tmparray[f]);
                             tmplist2->push_back(tmparray2);
                             tmparray2[0]=0;

                             for(unsigned int g=r+1;g<strlen(tmparray)-1;g++)strcat(tmparray2,(char*)tmparray[g]);
                             tmplist2->push_back(tmparray2);
									  tmparray2[0]=0;

                           }
                           else if(openp-1==closep && tmparray[r]=='|'){

                                  tmpl1=tmplist2;  printf("\n HELLLLLLO\n");
                                  for(unsigned int g=r+1;g<strlen(tmparray)-1;g++)tmparray2[g-(r+1)]=tmparray[g];
                                  printf("\n HELLLLLLO\n");tmpl1->push_back(tmparray2);
                                  tmpqueue1->push_back(tmpl1);

                                   tmpl1->pop_back();

                                  for(unsigned int f=1;f<r;f++)tmparray2[f-1]=tmparray[f];
                                 printf("\n %s \n",tmparray2);tmplist2->push_back(tmparray2);
                                 printf("\n %s \n",tmplist2->back());
                           }
                           else if(openp-1==closep && tmparray[r]=='-' && tmparray[r+1]=='>'){

                           	    tmpl1=tmplist2;
                                  for(unsigned int g=r+2;g<strlen(tmparray)-1;g++)strcat(tmparray2,(char*)tmparray[g]);
                                  tmpl1->push_back(tmparray2);
                                  tmpqueue1->push_back(tmpl1);
                                  tmparray2[0]=0;
                                  while(!tmpl1->empty())tmpl1->pop_front();

                                  tmparray2[0]='~';tmparray2[1]=0;
                                  for(unsigned int f=1;f<r;f++)strcat(tmparray2,(char*)tmparray[f]);
                                  tmplist2->push_back(tmparray2);
                                  tmparray2[0]=0;

                           }
                           else if(openp-1==closep && tmparray[r]=='<' && tmparray[r+1]=='=' && tmparray[r+2]=='>'){

                           	    tmpl1=tmplist2; tmparray2[0]='~';tmparray2[1]=0;
                                  for(unsigned int f=1;f<r;f++)strcat(tmparray2,(char*)tmparray[f]);
                                  tmpl1->push_back(tmparray2);
                                  tmparray2[0]=0;tmparray2[0]='~';tmparray2[1]=0;
                                  for(unsigned int g=r+3;g<strlen(tmparray)-1;g++)strcat(tmparray2,(char*)tmparray[g]);
                                  tmpl1->push_back(tmparray2);
                                  tmpqueue1->push_back(tmpl1);
                                  tmparray2[0]=0;
                                  while(!tmpl1->empty())tmpl1->pop_front();

                                  for(unsigned int f=1;f<r;f++)strcat(tmparray2,(char*)tmparray[f]);
                                  tmplist2->push_back(tmparray2);
                                  tmparray2[0]=0;
                                  for(unsigned int g=r+3;g<strlen(tmparray)-1;g++)strcat(tmparray2,(char*)tmparray[g]);
                                  tmplist2->push_back(tmparray2);
                                  tmparray2[0]=0;

                           }

                       }
                }
          }

        }//end while

  //Final Result
        if(success==1){

          printf("\n Your Final Answer: YES!!!\n");
        }
        else if(success==2){

               printf("\n Your Final Answer: NO!!!\n");
        }
        else if(success==0){

               printf("\n Your Final Answer: DON'T KNOW!!!\n");
        }

  //Naive Way of doing the same.
                                          printf("\n NO>>>>\n");
     success=0;notfinished=1;counteras1=0;counters1=0;

     while(!tmplist2->empty())tmplist2->pop_front();
      printf("\n NO>>>>\n");
     list<char*> *tmplists6=new list<char*>();
       list<char*> *tmplists7=new list<char*>();
printf("\n NO>>>>\n");

     char newquerys[500]="" ;

     if(query[0]!='~' && strlen(query)>0){      printf("\n NO>>>>\n");
       newquerys[0]='~';
       strcat(newquerys,query);
     }
     else if(query[0]=='~'){                         printf("\n NO>>>>\n");
            for(unsigned int i=1;i<strlen(query);i++){
printf("\n NO>>>>\n");
               newquerys[i-1]=query[i];   printf("\n NO>>>>\n");
            }
     }

     printf("\n not alpha== %s\n",newquerys);
     printf("\n %d \n",aacounter1);
     for(int h=0;h<counter;h++){
            tmplist2->push_back(sigmaprime1[h]);printf("\n %s\n",tmplist2->back());}

     if(strlen(query)>0){tmplist2->push_back(newquerys); printf("\n %s\n",tmplist2->back());}

     while(notfinished==1){  printf("\n NO>>>>\n");

             notfinished=0;nf1=0;


            while(!tmplist2->empty()){

                 tmplists6->push_back(tmplist2->front());
                 tmplists7->push_back(tmplist2->front());
                 tmplist2->pop_front();

            }

            while(!tmplists7->empty()){

                 tmplist2->push_back(tmplists7->front());
                 tmplists7->pop_front();

            }

             printf("\n %s\n",tmplist2->back());
            printf("\n success=%d\n",success);
                printf("\n %d + %d = %d\n",counters1,counteras1,tmplist2->size());

                if(notfinished==0 && (unsigned int)counteras1+counters1!=tmplist2->size())notfinished=1;
            if(!notfinished && (unsigned int)counteras1+counters1==tmplist2->size()){printf("\n yes...\n");
               break;}


          tmparray=tmplist2->front();
          tmplist2->pop_front();

          if(strlen(tmparray)<=2){
            if(strlen(tmparray)==1){
                                        printf("\n Symb\n");
              for(int f=0;f<counteras1;f++){
                 if(tmparray[0]==tmpantisymbol1[f][1]){
                   nf1=1;
                   break;
                 }
              }

                 if(nf1==1){
                     nf1=0;
                   while(!tmplist2->empty())tmplist2->pop_front();

if(!tmpqueue1->empty()){tmplist2=tmpqueue1->front();continue;}
                    else if(tmpqueue1->empty()){success=1;break;}
                 }
                 else if(nf1==0){

                    strcpy(tmpsymbol1[counters1],tmparray);
                    counters1++;
                    tmplist2->push_back(tmparray);
                 }

            }
            else if(strlen(tmparray)==2){
                                               printf("\n NOT Symb\n");
            	    for(int f=0;f<counters1;f++){
                     if(tmparray[1]==tmpsymbol1[f][0]){
                       nf1=1;
                        break;
                     }
                   }

                 if(nf1==1){
                    nf1=0;
                   while(!tmplist2->empty())tmplist2->pop_front();

if(!tmpqueue1->empty()){tmplist2=tmpqueue1->front();continue;}
                    else if(tmpqueue1->empty()){success=1;break;}
                 }
                 else if(nf1==0){

                   strcpy(tmpantisymbol1[counteras1],tmparray);
                   counters1++;
                    tmplist2->push_back(tmparray);printf("\n %d \n",tmplist2->size());
                 }

            }
          }
          else if(strlen(tmparray)>2){  success=0;printf("\n YES>>>>\n");

                int openp=0,closep=0;
                char tmparray2[100]="";
                list<char*>* tmpl1=new list<char*>();
                list<char*>* tmpl2=new list<char*>();
                if(tmparray[0]=='~'){   printf("\n NOT!!!!!!!!\n");
                   for(unsigned int r=1;r<strlen(tmparray);r++){
                           if(tmparray[r]=='('){
                             openp++;
                           }
                           else if(tmparray[r]==')'){
                                  closep++;
                           }

                           if(openp-1==closep && tmparray[r]=='&'){

                             tmpl1=tmplist2;
                             if(tmparray[r+1]!='~'){
                                tmparray2[0]='~';
                              tmparray2[1]=0;
                             for(unsigned int g=r+1;g<strlen(tmparray)-1;g++)strcat(tmparray2,(char*)tmparray[g]);
                             tmpl1->push_back(tmparray2);
                             tmpqueue1->push_back(tmpl1);
                             tmparray2[0]=0;
                             while(!tmpl1->empty())tmpl1->pop_front();
                             }
                             else if(tmparray[r+1]=='~'){
                                     tmparray2[0]=0;
                                     for(unsigned int g=r+2;g<strlen(tmparray)-1;g++)strcat(tmparray2,(char*)tmparray[g]);
                                     tmpl1->push_back(tmparray2);
                                     tmpqueue1->push_back(tmpl1);
                                     tmparray2[0]=0;
                                     while(!tmpl1->empty())tmpl1->pop_front();
                             }

                             if(tmparray[2]=='~'){
                                 tmparray2[0]=0;
                                 for(unsigned int f=3;f<r;f++)strcat(tmparray2,(char*)tmparray[f]);
                                 tmplist2->push_back(tmparray2);
                                 tmparray2[0]=0;
                             }
                             else if(tmparray[2]!='~'){

                                  tmparray2[0]='~';tmparray2[1]=0;
                                  for(unsigned int f=2;f<r;f++)strcat(tmparray2,(char*)tmparray[f]);
                                  tmplist2->push_back(tmparray2);
                                  tmparray2[0]=0;
                             }



                           }
                           else if(openp-1==closep && tmparray[r]=='|'){

                                 if(tmparray[2]=='~'){
                                    tmparray2[0]=0;
                                  for(unsigned int f=3;f<r;f++)strcat(tmparray2,(char*)tmparray[f]);
                                  tmplist2->push_back(tmparray2);
                                  tmparray2[0]=0;
                                 }
                                 else{
                                  tmparray2[0]='~';tmparray2[1]=0;
                                  for(unsigned int f=2;f<r;f++)strcat(tmparray2,(char*)tmparray[f]);
                                  tmplist2->push_back(tmparray2);
                                  tmparray2[0]=0;
                                 }

                                 if(tmparray[r+1]=='~'){
                                     tmparray2[0]=0;
                                  for(unsigned int g=r+2;g<strlen(tmparray)-1;g++)strcat(tmparray2,(char*)tmparray[g]);
                                  tmplist2->push_back(tmparray2);
									       tmparray2[0]=0;
                                 }
                                 else{
                                  tmparray2[0]='~';tmparray2[1]=0;
                                  for(unsigned int g=r+1;g<strlen(tmparray)-1;g++)strcat(tmparray2,(char*)tmparray[g]);
                                  tmplist2->push_back(tmparray2);
									       tmparray2[0]=0;
                                 }

                           }
                           else if(openp-1==closep && tmparray[r]=='-' && tmparray[r+1]=='>'){
                                  if(tmparray[r+1]=='~'){
                                     tmparray2[0]=0;
                                  for(unsigned int g=r+2;g<strlen(tmparray)-1;g++)strcat(tmparray2,(char*)tmparray[g]);
                                  tmplist2->push_back(tmparray2);
                                  tmparray2[0]=0;
                                  }
                                  else{
                           	    tmparray2[0]='~';tmparray2[1]=0;
                                  for(unsigned int g=r+1;g<strlen(tmparray)-1;g++)strcat(tmparray2,(char*)tmparray[g]);
                                  tmplist2->push_back(tmparray2);
                                  tmparray2[0]=0;
                                  }

                                  if(tmparray[2]=='~'){ tmparray2[0]='~';tmparray2[1]=0;
                                  for(unsigned int f=3;f<r;f++)strcat(tmparray2,(char*)tmparray[f]);
                                  tmplist2->push_back(tmparray2);
                                  tmparray2[0]=0;
                                  }
                                  else{
                                  for(unsigned int f=2;f<r;f++)strcat(tmparray2,(char*)tmparray[f]);
                                  tmplist2->push_back(tmparray2);
                                  tmparray2[0]=0;
                                  }
                           }
                           else if(openp-1==closep && tmparray[r]=='<' && tmparray[r+1]=='=' && tmparray[r+2]=='>'){

                                 if(tmparray[r+3]=='~' && tmparray[2]=='~'){
                           	    tmpl1=tmplist2; tmparray2[0]=0;
                                  for(unsigned int f=3;f<r;f++)strcat(tmparray2,(char*)tmparray[f]);
                                  tmpl1->push_back(tmparray2);
                                  tmparray2[0]=0;
                                  for(unsigned int g=r+3;g<strlen(tmparray)-1;g++)strcat(tmparray2,(char*)tmparray[g]);
                                  tmpl1->push_back(tmparray2);
                                  tmpqueue1->push_back(tmpl1);
                                  tmparray2[0]=0;
                                  while(!tmpl1->empty())tmpl1->pop_front();

                                  for(unsigned int f=2;f<r;f++)strcat(tmparray2,(char*)tmparray[f]);
                                  tmplist2->push_back(tmparray2);
                                  tmparray2[0]=0;tmparray2[1]=0;
                                  for(unsigned int g=r+4;g<strlen(tmparray)-1;g++)strcat(tmparray2,(char*)tmparray[g]);
                                  tmplist2->push_back(tmparray2);
                                  tmparray2[0]=0;

                                 }

                                 if(tmparray[2]=='~' && tmparray[r+3]!='~'){

                                             tmpl1=tmplist2; tmparray2[1]=0;
                                  for(unsigned int f=3;f<r;f++)strcat(tmparray2,(char*)tmparray[f]);
                                  tmpl1->push_back(tmparray2);
                                  tmparray2[0]=0;
                                  for(unsigned int g=r+3;g<strlen(tmparray)-1;g++)strcat(tmparray2,(char*)tmparray[g]);
                                  tmpl1->push_back(tmparray2);
                                  tmpqueue1->push_back(tmpl1);
                                  tmparray2[0]=0;
                                  while(!tmpl1->empty())tmpl1->pop_front();

                                  tmparray2[0]='~'; tmparray2[1]=0;
                                  for(unsigned int f=3;f<r;f++)strcat(tmparray2,(char*)tmparray[f]);
                                  tmplist2->push_back(tmparray2);tmparray2[0]=0;tmparray2[0]='~';tmparray2[1]=0;
                                  for(unsigned int g=r+4;g<strlen(tmparray)-1;g++)strcat(tmparray2,(char*)tmparray[g]);
                                  tmplist2->push_back(tmparray2);
                                  tmparray2[0]=0;
                                 }
                                  if(tmparray[2]!='~' && tmparray[r+3]=='~'){

                                  tmpl1=tmplist2;tmparray2[0]='~';tmparray2[1]=0;
                                  for(unsigned int f=3;f<r;f++)strcat(tmparray2,(char*)tmparray[f]);
                                  tmpl1->push_back(tmparray2);
                                  tmparray2[0]=0; tmparray2[0]='~';tmparray2[1]=0;
                                  for(unsigned int g=r+4;g<strlen(tmparray)-1;g++)strcat(tmparray2,(char*)tmparray[g]);
                                  tmpl1->push_back(tmparray2);
                                  tmpqueue1->push_back(tmpl1);
                                  tmparray2[0]=0;
                                  while(!tmpl1->empty())tmpl1->pop_front();

                                   tmparray2[0]=0;
                                  for(unsigned int f=2;f<r;f++)strcat(tmparray2,(char*)tmparray[f]);
                                  tmplist2->push_back(tmparray2);
                                  tmparray2[0]=0;tmparray2[1]=0;
                                  for(unsigned int g=r+4;g<strlen(tmparray)-1;g++)strcat(tmparray2,(char*)tmparray[g]);
                                  tmplist2->push_back(tmparray2);
                                  tmparray2[0]=0;
                                 }

                                  if(tmparray[r+3]!='~' && tmparray[2]!='~'){
                                     tmpl1=tmplist2;tmparray2[0]='~'; tmparray2[1]=0;
                                  for(unsigned int f=2;f<r;f++)strcat(tmparray2,(char*)tmparray[f]);
                                  tmpl1->push_back(tmparray2);
                                  tmparray2[0]=0;
                                  for(unsigned int g=r+3;g<strlen(tmparray)-1;g++)strcat(tmparray2,(char*)tmparray[g]);
                                  tmpl1->push_back(tmparray2);
                                  tmpqueue1->push_back(tmpl1);
                                  tmparray2[0]=0;
                                  while(!tmpl1->empty())tmpl1->pop_front();

                                  for(unsigned int f=2;f<r;f++)strcat(tmparray2,(char*)tmparray[f]);
                                  tmplist2->push_back(tmparray2);
                                  tmparray2[0]=0;tmparray2[0]='~';tmparray2[1]=0;
                                  for(unsigned int g=r+3;g<strlen(tmparray)-1;g++)strcat(tmparray2,(char*)tmparray[g]);
                                  tmplist2->push_back(tmparray2);
                                  tmparray2[0]=0;
                                  }

                           }
                   }
                }
                else if(tmparray[0]!='~'){    int cc=0;  printf("\n YES>>>>2\n");
                		  for(unsigned int r=0;r<strlen(tmparray);r++){
                           if(tmparray[r]=='('){
                             openp++;
                           }
                           else if(tmparray[r]==')'){
                                  closep++;
                           }
                                           printf("\n counter=%d\n",cc++);
                           if(openp-1==closep && tmparray[r]=='&'){

                             for(unsigned int f=1;f<r;f++)strcat(tmparray2,(char*)tmparray[f]);
                             tmplist2->push_back(tmparray2);
                             tmparray2[0]=0;

                             for(unsigned int g=r+1;g<strlen(tmparray)-1;g++)strcat(tmparray2,(char*)tmparray[g]);
                             tmplist2->push_back(tmparray2);
									  tmparray2[0]=0;

                           }
                           else if(openp-1==closep && tmparray[r]=='|'){
                                 unsigned int g;
                                  for(g=r+1;g<strlen(tmparray)-1;g++)tmparray2[g-(r+1)]=tmparray[g];
                                  printf("\n %s\n",tmparray); printf("\n %s\n",tmparray2);
                                  tmparray[g]=0;
                                  tmplist2->push_back(tmparray2);    printf("\n %s\n",tmplist2->back());

            while(!tmplist2->empty()){

                 tmpl1->push_back(tmplist2->front());
                 tmpl2->push_back(tmplist2->front());
                 tmplist2->pop_front();

            }

            while(!tmpl2->empty()){

                 tmplist2->push_back(tmpl2->front());
                 tmpl2->pop_front();

            }
                                  tmpqueue1->push_back(tmpl1);
                                  tmparray2[0]=0;     printf("\n %s\n",tmplist2->back());
                                  tmplist2->pop_back();

                                  for(unsigned int f=1;f<r;f++)tmparray2[f-1]=tmparray[f];
                                     printf("\n %s\n",tmparray); printf("\n %s\n",tmparray2);
                                  tmplist2->push_back(tmparray2);
                                  tmparray2[0]=0;  printf("\n listsize=%d\n",tmplist2->size());
                                  printf("\n %s\n",tmplist2->back()); break;

                           }
                           else if(openp-1==closep && tmparray[r]=='-' && tmparray[r+1]=='>'){

                           	    tmpl1=tmplist2;
                                  for(unsigned int g=r+2;g<strlen(tmparray)-1;g++)strcat(tmparray2,(char*)tmparray[g]);
                                  tmpl1->push_back(tmparray2);
                                  tmpqueue1->push_back(tmpl1);
                                  tmparray2[0]=0;
                                  while(!tmpl1->empty())tmpl1->pop_front();

                                  tmparray2[0]='~';tmparray2[1]=0;
                                  for(unsigned int f=1;f<r;f++)strcat(tmparray2,(char*)tmparray[f]);
                                  tmplist2->push_back(tmparray2);
                                  tmparray2[0]=0;

                           }
                           else if(openp-1==closep && tmparray[r]=='<' && tmparray[r+1]=='=' && tmparray[r+2]=='>'){

                           	    tmpl1=tmplist2;tmparray2[0]='~';tmparray2[1]=0;
                                  for(unsigned int f=1;f<r;f++)strcat(tmparray2,(char*)tmparray[f]);
                                  tmpl1->push_back(tmparray2);
                                  tmparray2[0]=0; tmparray2[0]='~';tmparray2[1]=0;
                                  for(unsigned int g=r+3;g<strlen(tmparray)-1;g++)strcat(tmparray2,(char*)tmparray[g]);
                                  tmpl1->push_back(tmparray2);
                                  tmpqueue1->push_back(tmpl1);
                                  tmparray2[0]=0;
                                  while(!tmpl1->empty())tmpl1->pop_front();

                                  for(unsigned int f=1;f<r;f++)strcat(tmparray2,(char*)tmparray[f]);
                                  tmplist2->push_back(tmparray2);
                                  tmparray2[0]=0;
                                  for(unsigned int g=r+3;g<strlen(tmparray)-1;g++)strcat(tmparray2,(char*)tmparray[g]);
                                  tmplist2->push_back(tmparray2);
                                  tmparray2[0]=0;

                           }

                       }
                }
          }

        }//end while

        printf ("\n Success= %d\n",success);


        //check if gamma entails ~alpha

        notfinished=1; counteras1=0;counters1=0;

        while(!tmpqueue1->empty())tmpqueue1->pop_front();

        while(!tmplist2->empty())tmplist2->pop_front();

     list<char*> *tmplists8=new list<char*>();
     list<char*> *tmplists9=new list<char*>();
     for(int h=0;h<counter;h++){
            tmplist2->push_back(sigmaprime1[h]);printf("\n %s\n",tmplist2->back());}

     tmplist2->push_back(query); printf("\n %s\n",tmplist2->back());

     while(notfinished){

     if(success==1)break;

            notfinished=0; nf1=0;

            while(!tmplist2->empty()){

                 tmplists8->push_back(tmplist2->front());
                 tmplists9->push_back(tmplist2->front());
                 tmplist2->pop_front();

            }

            while(!tmplists9->empty()){

                 tmplist2->push_back(tmplists9->front());
                 tmplists9->pop_front();

            }

             while(!tmplists8->empty()){      printf("\n %d \n",tmplist2->size());

                 if(strlen(tmplists8->front())>2){ notfinished=1;break;}

                 tmplists8->pop_front();
            }

            printf("\n success=%d\n",success);
                printf("\n %d + %d = %d\n",counters1,counteras1,tmplist2->size());

                if(notfinished==0 && (unsigned int)counteras1+counters1!=tmplist2->size())notfinished=1;
            if(!notfinished && (unsigned int)counteras1+counters1==tmplist2->size()){printf("\n yes...\n");
               break;}

          tmparray=tmplist2->front();
          tmplist2->pop_front();     printf("\n listsize = %d \n",tmplist2->size());

          if(strlen(tmparray)<=2){
            if(strlen(tmparray)==1){   printf("\n ONE \n");   printf("\n %s \n",tmparray);

              for(int f=0;f<counteras1;f++){
                 if(tmparray[0]==tmpantisymbol1[f][1]){
                   nf1=1;
                   break;
                 }
              }

                 if(nf1==1){
                     nf1=0;
                   while(!tmplist2->empty())tmplist2->pop_front();

if(!tmpqueue1->empty()){tmplist2=tmpqueue1->front();continue;}
                    else if(tmpqueue1->empty()){success=2;break;}
                 }
                 else if(nf1==0){

                    strcpy(tmpsymbol1[counters1],tmparray);
                    counters1++;
                    tmplist2->push_back(tmparray);    printf("\n listsize = %d \n",tmplist2->size());
                 }
            }
            else if(strlen(tmparray)==2){   printf("\n TWO \n");

            	    for(int f=0;f<counters1;f++){
                     if(tmparray[1]==tmpsymbol1[f][0]){
                       nf1=1;
                        break;
                     }
                   }

                 if(nf1==1){
                    nf1=0;
                   while(!tmplist2->empty())tmplist2->pop_front();

if(!tmpqueue1->empty()){tmplist2=tmpqueue1->front();continue;}
                    else if(tmpqueue1->empty()){success=2;break;}
                 }
                 else if(nf1==0){

                   strcpy(tmpantisymbol1[counteras1],tmparray);
                   counters1++;
                    tmplist2->push_back(tmparray);
                 }
            }
          }
          else if(strlen(tmparray)>2){  printf("\n THREE \n");
                                          success=0;
                int openp=0,closep=0;
                char tmparray2[100]="";
                list<char*>* tmpl1=new list<char*>();

                if(tmparray[0]=='~'){
                   for(unsigned int r=1;r<strlen(tmparray);r++){
                           if(tmparray[r]=='('){
                             openp++;
                           }
                           else if(tmparray[r]==')'){
                                  closep++;
                           }

                           if(openp-1==closep && tmparray[r]=='&'){

                             tmpl1=tmplist2;
                             if(tmparray[r+1]!='~'){
                                tmparray2[0]='~';
                              tmparray2[0]=0;
                             for(unsigned int g=r+1;g<strlen(tmparray)-1;g++)strcat(tmparray2,(char*)tmparray[g]);
                             tmpl1->push_back(tmparray2);
                             tmpqueue1->push_back(tmpl1);
                             tmparray2[0]=0;
                             while(!tmpl1->empty())tmpl1->pop_front();
                             }
                             else if(tmparray[r+1]=='~'){
                                     tmparray2[0]=0;
                                     for(unsigned int g=r+2;g<strlen(tmparray)-1;g++)strcat(tmparray2,(char*)tmparray[g]);
                                     tmpl1->push_back(tmparray2);
                                     tmpqueue1->push_back(tmpl1);
                                     tmparray2[0]=0;while(!tmpl1->empty())tmpl1->pop_front();
                             }

                             if(tmparray[2]=='~'){
                                 tmparray2[0]=0;
                                 for(unsigned int f=3;f<r;f++)strcat(tmparray2,(char*)tmparray[f]);
                                 tmplist2->push_back(tmparray2);
                                 tmparray2[0]=0;
                             }
                             else if(tmparray[2]!='~'){

                                  tmparray2[0]='~';tmparray2[1]=0;
                                  for(unsigned int f=2;f<r;f++)strcat(tmparray2,(char*)tmparray[f]);
                                  tmplist2->push_back(tmparray2);
                                  tmparray2[0]=0;
                             }



                           }
                           else if(openp-1==closep && tmparray[r]=='|'){

                                 if(tmparray[2]=='~'){
                                    tmparray2[0]=0;
                                  for(unsigned int f=3;f<r;f++)strcat(tmparray2,(char*)tmparray[f]);
                                  tmplist2->push_back(tmparray2);
                                  tmparray2[0]=0;
                                 }
                                 else{
                                  tmparray2[0]='~';tmparray2[1]=0;
                                  for(unsigned int f=2;f<r;f++)strcat(tmparray2,(char*)tmparray[f]);
                                  tmplist2->push_back(tmparray2);
                                  tmparray2[0]=0;
                                 }

                                 if(tmparray[r+1]=='~'){
                                     tmparray2[0]=0;
                                  for(unsigned int g=r+2;g<strlen(tmparray)-1;g++)strcat(tmparray2,(char*)tmparray[g]);
                                  tmplist2->push_back(tmparray2);
									       tmparray2[0]=0;
                                 }
                                 else{
                                  tmparray2[0]='~';tmparray2[1]=0;
                                  for(unsigned int g=r+1;g<strlen(tmparray)-1;g++)strcat(tmparray2,(char*)tmparray[g]);
                                  tmplist2->push_back(tmparray2);
									       tmparray2[0]=0;
                                 }

                           }
                           else if(openp-1==closep && tmparray[r]=='-' && tmparray[r+1]=='>'){
                                  if(tmparray[r+1]=='~'){
                                     tmparray2[0]=0;
                                  for(unsigned int g=r+2;g<strlen(tmparray)-1;g++)strcat(tmparray2,(char*)tmparray[g]);
                                  tmplist2->push_back(tmparray2);
                                  tmparray2[0]=0;
                                  }
                                  else{
                           	    tmparray2[0]='~';tmparray2[1]=0;
                                  for(unsigned int g=r+1;g<strlen(tmparray)-1;g++)strcat(tmparray2,(char*)tmparray[g]);
                                  tmplist2->push_back(tmparray2);
                                  tmparray2[0]=0;
                                  }

                                  if(tmparray[2]=='~'){ tmparray2[0]='~';tmparray2[1]=0;
                                  for(unsigned int f=3;f<r;f++)strcat(tmparray2,(char*)tmparray[f]);
                                  tmplist2->push_back(tmparray2);
                                  tmparray2[0]=0;
                                  }
                                  else{
                                  for(unsigned int f=2;f<r;f++)strcat(tmparray2,(char*)tmparray[f]);
                                  tmplist2->push_back(tmparray2);
                                  tmparray2[0]=0;
                                  }
                           }
                           else if(openp-1==closep && tmparray[r]=='<' && tmparray[r+1]=='=' && tmparray[r+2]=='>'){

                                 if(tmparray[r+3]=='~' && tmparray[2]=='~'){
                           	    tmpl1=tmplist2; tmparray2[0]=0;
                                  for(unsigned int f=3;f<r;f++)strcat(tmparray2,(char*)tmparray[f]);
                                  tmpl1->push_back(tmparray2);
                                  tmparray2[0]=0;
                                  for(unsigned int g=r+3;g<strlen(tmparray)-1;g++)strcat(tmparray2,(char*)tmparray[g]);
                                  tmpl1->push_back(tmparray2);
                                  tmpqueue1->push_back(tmpl1);
                                  tmparray2[0]=0;
                                  while(!tmpl1->empty())tmpl1->pop_front();

                                  for(unsigned int f=2;f<r;f++)strcat(tmparray2,(char*)tmparray[f]);
                                  tmplist2->push_back(tmparray2);
                                  tmparray2[0]=0;tmparray2[1]=0;
                                  for(unsigned int g=r+4;g<strlen(tmparray)-1;g++)strcat(tmparray2,(char*)tmparray[g]);
                                  tmplist2->push_back(tmparray2);
                                  tmparray2[0]=0;

                                 }

                                 if(tmparray[2]=='~' && tmparray[r+3]!='~'){

                                             tmpl1=tmplist2; tmparray2[0]=0;
                                  for(unsigned int f=3;f<r;f++)strcat(tmparray2,(char*)tmparray[f]);
                                  tmpl1->push_back(tmparray2);
                                  tmparray2[0]=0;
                                  for(unsigned int g=r+3;g<strlen(tmparray)-1;g++)strcat(tmparray2,(char*)tmparray[g]);
                                  tmpl1->push_back(tmparray2);
                                  tmpqueue1->push_back(tmpl1);
                                  tmparray2[0]=0;
                                  while(!tmpl1->empty())tmpl1->pop_front();

                                  tmparray2[0]='~'; tmparray2[1]=0;
                                  for(unsigned int f=3;f<r;f++)strcat(tmparray2,(char*)tmparray[f]);
                                  tmplist2->push_back(tmparray2);

tmparray2[0]=0;tmparray2[0]='~';tmparray2[1]=0;
                                  for(unsigned int g=r+4;g<strlen(tmparray)-1;g++)strcat(tmparray2,(char*)tmparray[g]);
                                  tmplist2->push_back(tmparray2);
                                  tmparray2[0]=0;
                                 }
                                  if(tmparray[2]!='~' &&
tmparray[r+3]=='~'){

                                             tmpl1=tmplist2;
tmparray2[0]='~';tmparray2[1]=0;
                                  for(unsigned int f=3;f<r;f++)strcat(tmparray2,(char*)tmparray[f]);
                                  tmpl1->push_back(tmparray2);
                                  tmparray2[0]=0; tmparray2[0]='~';
tmparray2[1]=0;
                                  for(unsigned int g=r+4;g<strlen(tmparray)-1;g++)strcat(tmparray2,(char*)tmparray[g]);
                                  tmpl1->push_back(tmparray2);
                                  tmpqueue1->push_back(tmpl1);
                                  tmparray2[0]=0;
                                  while(!tmpl1->empty())tmpl1->pop_front();

                                   tmparray2[1]=0;
                                  for(unsigned int f=2;f<r;f++)strcat(tmparray2,(char*)tmparray[f]);
                                  tmplist2->push_back(tmparray2);
                                  tmparray2[0]=0;tmparray2[1]=0;
                                  for(unsigned int g=r+4;g<strlen(tmparray)-1;g++)strcat(tmparray2,(char*)tmparray[g]);
                                  tmplist2->push_back(tmparray2);
                                  tmparray2[0]=0;
                                 }

                                  if(tmparray[r+3]!='~' &&
tmparray[2]!='~'){
                                     tmpl1=tmplist2;tmparray2[0]='~';
tmparray2[1]=0;
                                  for(unsigned int f=2;f<r;f++)strcat(tmparray2,(char*)tmparray[f]);
                                  tmpl1->push_back(tmparray2);
                                  tmparray2[0]=0;
                                  for(unsigned int g=r+3;g<strlen(tmparray)-1;g++)strcat(tmparray2,(char*)tmparray[g]);
                                  tmpl1->push_back(tmparray2);
                                  tmpqueue1->push_back(tmpl1);
                                  tmparray2[0]=0;
                                  while(!tmpl1->empty())tmpl1->pop_front();

                                  for(unsigned int f=2;f<r;f++)strcat(tmparray2,(char*)tmparray[f]);
                                  tmplist2->push_back(tmparray2);

tmparray2[0]=0;tmparray2[0]='~';tmparray2[1]=0;
                                  for(unsigned int g=r+3;g<strlen(tmparray)-1;g++)strcat(tmparray2,(char*)tmparray[g]);
                                  tmplist2->push_back(tmparray2);
                                  tmparray2[0]=0;
                                  }

                           }
                   }
                }
                else if(tmparray[0]!='~'){
                		  for(unsigned int r=0;r<strlen(tmparray);r++){
                           if(tmparray[r]=='('){
                             openp++;
                           }
                           else if(tmparray[r]==')'){
                                  closep++;
                           }

                           if(openp-1==closep && tmparray[r]=='&'){

                             for(unsigned int f=1;f<r;f++)strcat(tmparray2,(char*)tmparray[f]);
                             tmplist2->push_back(tmparray2);
                             tmparray2[0]=0;

                             for(unsigned int g=r+1;g<strlen(tmparray)-1;g++)strcat(tmparray2,(char*)tmparray[g]);
                             tmplist2->push_back(tmparray2);
									  tmparray2[0]=0;

                           }
                           else if(openp-1==closep && tmparray[r]=='|'){

                                  tmpl1=tmplist2;
                                  for(unsigned int g=r+1;g<strlen(tmparray)-1;g++)strcat(tmparray2,(char*)tmparray[g]);
                                  tmpl1->push_back(tmparray2);
                                  tmpqueue1->push_back(tmpl1);
                                  tmparray2[0]=0;
                                  while(!tmpl1->empty())tmpl1->pop_front();

                                  for(unsigned int f=1;f<r;f++)strcat(tmparray2,(char*)tmparray[f]);
                                  tmplist2->push_back(tmparray2);
                                  tmparray2[0]=0;

                           }
                           else if(openp-1==closep && tmparray[r]=='-' &&
tmparray[r+1]=='>'){

                           	    tmpl1=tmplist2;
                                  for(unsigned int g=r+2;g<strlen(tmparray)-1;g++)strcat(tmparray2,(char*)tmparray[g]);
                                  tmpl1->push_back(tmparray2);
                                  tmpqueue1->push_back(tmpl1);
                                  tmparray2[0]=0;
                                  while(!tmpl1->empty())tmpl1->pop_front();

                                  tmparray2[0]='~';tmparray2[1]=0;
                                  for(unsigned int f=1;f<r;f++)strcat(tmparray2,(char*)tmparray[f]);
                                  tmplist2->push_back(tmparray2);
                                  tmparray2[0]=0;

                           }
                           else if(openp-1==closep && tmparray[r]=='<' &&
tmparray[r+1]=='=' && tmparray[r+2]=='>'){

                           	    tmpl1=tmplist2;
tmparray2[0]='~';tmparray2[1]=0;
                                  for(unsigned int f=1;f<r;f++)strcat(tmparray2,(char*)tmparray[f]);
                                  tmpl1->push_back(tmparray2);
                                  tmparray2[0]=0;
tmparray2[0]='~';tmparray2[1]=0;
                                  for(unsigned int g=r+3;g<strlen(tmparray)-1;g++)strcat(tmparray2,(char*)tmparray[g]);
                                  tmpl1->push_back(tmparray2);
                                  tmpqueue1->push_back(tmpl1);
                                  tmparray2[0]=0;
                                  while(!tmpl1->empty())tmpl1->pop_front();

                                  for(unsigned int f=1;f<r;f++)strcat(tmparray2,(char*)tmparray[f]);
                                  tmplist2->push_back(tmparray2);
                                  tmparray2[0]=0;
                                  for(unsigned int g=r+3;g<strlen(tmparray)-1;g++)strcat(tmparray2,(char*)tmparray[g]);
                                  tmplist2->push_back(tmparray2);
                                  tmparray2[0]=0;

                           }

                       }
                }
          }

        }//end while

    //Result with Naive way.

    printf("\n -----------------------------------------------------------\n");
    printf("\n The Result with 'Naive' Way (without considering relevance).\n");
    printf("\n ***********************************************************\n");

           if(success==1){

          printf("\n Your Final Answer: YES!!!\n");
        }
        else if(success==2){

               printf("\n Your Final Answer: NO!!!\n");
        }
        else if(success==0){

               printf("\n Your Final Answer: DON'T KNOW!!!\n");
        }

   printf("\n Thank You.\n");

   return 0;

}

