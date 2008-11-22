
                        /* Program # 2 by Waseem Ilahi */

# include "program_2.h"
# include <string>

  int main(){ 

      cout<<endl<<" Program # 2 By Waseem Ilahi."<<endl;
      cout<<" ----------------------------"<<endl;

      cout<<endl<<" The input is taken from a file named map1.txt saved in the same directory."<<endl;
      cout<<      " --------------------------------------------------------------------------"<<endl;

      FILE * fp=fopen("map1.txt","r");

      if(fp==NULL){
         printf("\n Can't open file: map1.txt.\n");
         exit(EXIT_FAILURE);
      }
        
   ch = getc( fp );
   while( ch != EOF ) {
        if(ch == '\n'){i++;j=0;ch=getc(fp);}
        else{
             g[i][j]=ch;
             j++;
             ch = getc( fp );
        }
   }      

   printf("\n The original map is as follows:");
   printf("\n -------------------------------\n");

     printf("\n ");
     for(int m=0;m<i;m++){
       for(int n=0;n<sizeof(g[m]);n++)
          printf("%c",g[m][n]);
          printf("\n ");
     }

     printf("\n ");

   //The actual computation.

    //Assigning the start and goal positions.
            start_state.x=1;
            start_state.y=1;
            start_state.obstacle=FALSE;

            goal_state.x=6;
            goal_state.y=11;
            goal_state.obstacle=FALSE;

      MapProblem *map1=new MapProblem();
      MapProblem *map2=new MapProblem();

      cout<<endl<<" First We do the Graph Search."<<endl;
      cout<<      " -----------------------------"<<endl;
      
      if(A_star_graph_search(map2->initial_state(),g,map2)){
      }
      else{
           cout<<endl<<" The graph search algorithm was not successful."<<endl;
           cout<<      " ----------------------------------------------"<<endl;
      }

      cout<<endl<<" Now We do the Tree Search."<<endl;
      cout<<      " --------------------------"<<endl;

      int a=A_star_tree_search(map1->initial_state(),g,map1);

      if(a==1){
      }
      else{
           cout<<endl<<" The tree search algorithm was not successful."<<endl;
           cout<<      " ---------------------------------------------"<<endl;
      }  

      cout<<endl<<" Thank You."<<endl<<endl;
    
      system("Pause");

      fclose(fp);

      return 0;

  }
