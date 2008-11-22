
								/* Make Up HomeWork # 2 by Waseem Ilahi*/

# include <vector>
# include <math>
# include <iostream>
# include <stack>
# include <deque>
# include <queue>
# include <stdio>

using namespace std;

# define FALSE   0
# define TRUE    1
# define ROWS    10
# define COLUMNS 10

char ch;
int i=0,j=0;

char g[ROWS][COLUMNS];

struct State{

              char name;

              int x;

              int y;

              vector<char> adjacent;
              

              };

vector<struct State> Vertices;

//The Node structure.
 struct Node{
            struct State m_state;

            struct Node* parent;

            int depth;

            bool visited;

            double path_cost;

            double evaluation_function;

           };

 vector<struct Node> *c=new vector<struct Node>();

 
//Variable declarations.
 struct State start_state;
 struct State goal_state;

 //The problem data structure.
class MapProblem{

      public:

             //This method checks for the goal and returns true or false
             static bool is_goal(struct State n);

             //This method returns the successors of a node
             void successor_function(struct Node* n,vector<struct Node> *v);

             //The constructor.
             MapProblem();

             //The initial state
             struct Node initial_state(void);
             
};

//Prototypes.
 double heuristic(struct State);
 double evaluation_function(struct Node);
 bool visited(struct Node,vector<struct Node>*);
 int A_star_graph_search(struct Node,char (*)[],MapProblem *);

 //The criterians for sorting the priority queue used used as fringe.

class SortQueue {

               public:
                SortQueue::~SortQueue(){}
                SortQueue::SortQueue(){}

                bool operator()(struct Node l1,struct Node l2)const{

                 int t1=l1.evaluation_function;
                 int t2=l2.evaluation_function;

                 return t1>t2;
                }
};

void sortqueue(priority_queue<struct Node,vector<struct Node>,SortQueue >*);

priority_queue<struct Node,vector<struct Node>,SortQueue > *fringe;

//Function definitions.

double heuristic(struct State n){

    return sqrt(abs((n.x - goal_state.x)*(n.x - goal_state.x)+(n.y - goal_state.y)*(n.y - goal_state.y)));
}

double evaluation_function(struct Node n){

    return n.path_cost + heuristic(n.m_state);
}

//The constructor.

MapProblem::MapProblem(){}

//IsGoal function.

bool MapProblem::is_goal(struct State n){

     return (n.x == goal_state.x && n.y == goal_state.y);
}

int A_star_graph_search(struct Node h,char g[ROWS][COLUMNS],MapProblem *map2){

    long aaa=0;

	 fringe=new priority_queue<struct Node,vector<struct Node>,SortQueue>();

            vector<struct Node> *d=new vector<struct Node>();
            vector<struct Node> *closed=new vector<struct Node>();
            

            vector<struct Node>::iterator iter;
            
            fringe->push(h);
            sortqueue(fringe);
            
            while(!fringe->empty()){

                 struct Node n=fringe->top(); 
                 
                 c->push_back(n);

                 fringe->pop();

                 if(map2->is_goal(n.m_state)){

                    return 1;
                 }

                 if(visited(n,closed))continue;
                 n.visited=TRUE;
                 closed->push_back(n); 

                 map2->successor_function(&n,d);

                 while(!d->empty()){

                       iter=d->begin();

                       fringe->push(d->front());
                       sortqueue(fringe);
                       
                       d->erase(iter);
                 }
            }

    return 0;
}

struct Node MapProblem::initial_state(void){

            struct Node n;
            vector<char> df;

            n.m_state.x=start_state.x;
            n.m_state.y=start_state.y;
            n.m_state.name=start_state.name;
            while(!start_state.adjacent.empty()){
                n.m_state.adjacent.push_back(start_state.adjacent.back());
                df.push_back(start_state.adjacent.back());
                start_state.adjacent.pop_back();
            }

            while(!df.empty()){

                 start_state.adjacent.push_back(df.back());
                 df.pop_back();
            }

            n.depth=0;

            n.visited=FALSE;

            n.path_cost=0;

            n.evaluation_function=evaluation_function(n);

            n.parent=NULL;

            return n;
}

//The sortqueue method.
void sortqueue(priority_queue<struct Node,vector<struct Node>,SortQueue >* givenqueue){

     stack<struct Node,vector<struct Node> > *tmpstk=new stack<struct Node,vector<struct Node> >();

     while(!givenqueue->empty()){
          tmpstk->push(givenqueue->top());
          givenqueue->pop();
     }

     while(!tmpstk->empty()){
          givenqueue->push(tmpstk->top());
          tmpstk->pop();
     }

     return ;

}

bool visited(struct Node n, vector<struct Node> *e){

     vector<struct Node>::iterator iter1;

     iter1=e->begin();

     while(iter1!=e->end()){

          if(iter1->m_state.x==n.m_state.x && iter1->m_state.y==n.m_state.y)return TRUE;

          iter1++;
     }

     return FALSE;
}

//The successor function.

void MapProblem::successor_function(struct Node* n,vector<struct Node>* v){

      struct Node r;
      struct State d;
      vector<char> df;

      int f=n->m_state.adjacent.size();

      vector<struct State>::iterator i1=Vertices.begin();

     for(int i=0;i<3;i++){

        while(i1!=Vertices.end()){

             if(n->m_state.adjacent.back()==i1->name){
               df.push_back(n->m_state.adjacent.back());
                n->m_state.adjacent.pop_back();
                d.x=i1->x;
                d.y=i1->y;
                d.name=i1->name;
                d.adjacent=i1->adjacent;
               
             }

            i1++;
        }
        while(!df.empty()){
             n->m_state.adjacent.push_back(df.back());
             df.pop_back();
        }
        
        r.m_state.x=d.x;
        r.m_state.y=d.y;

        r.m_state.name=d.name;

        r.m_state.adjacent=d.adjacent;

        r.depth=n->depth+1;

        r.visited=0;

        r.path_cost=n->path_cost+sqrt(fabs((r.m_state.x - n->m_state.x)*(r.m_state.x - n->m_state.x)+(r.m_state.y - n->m_state.y)*(r.m_state.y - n->m_state.y)));

        r.evaluation_function=evaluation_function(r);

        r.parent=n;

          if(n->parent==NULL){
            v->push_back(r);
          }
          else{
              if(n->parent->m_state.x != r.m_state.x
              || n->parent->m_state.y != r.m_state.y
              || n->parent->m_state.name!=r.m_state.name){
      
                    v->push_back(r);
              }//end if
          }//end else
     } //end for }

     return ;
}

//The Main Function.

int main(){

     char start, end;

     char ch;

      cout<<endl<<" HomeWork # 2 By Waseem Ilahi."<<endl;
      cout<<" -----------------------------"<<endl;

      cout<<endl<<" The input is taken from a file named input.txt saved in the same directory."<<endl;
      cout<<      " --------------------------------------------------------------------------"<<endl;

      FILE * fp=fopen("input.txt","r");

      if(fp==NULL){
         printf("\n Can't open file: input.txt.\n");
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

   start=g[0][0];
   end=g[0][1];

   start_state.name=start;

   goal_state.name=end;

   start_state.x=g[1][1]-48;
   start_state.y=g[1][2]-48;

      goal_state.x=g[i-2][1]-48;
      goal_state.y=g[i-2][2]-48;


   for(int h=1;h<i-1;h++){

      struct State tmp;

      tmp.name=g[h][0];
      tmp.x=g[h][1]-48; //char to int (ascii)
      tmp.y=g[h][2]-48;

      for(int k=3;k<sizeof(g[h]);k++){

         tmp.adjacent.push_back(g[h][k]);
         start_state.adjacent.push_back(g[1][k]);
         goal_state.adjacent.push_back(g[i-2][k]);
       
      }

      Vertices.push_back(tmp);

   }

   cout<<endl<<" The Start and the End points."<<endl;

   cout<<endl<<" "<<start<<endl;
   cout<<endl<<" "<<end<<endl;

   cout<<endl<<" The vertices with their coordinates."<<endl;

   vector<struct State>::iterator iter=Vertices.begin();

   while(iter!=Vertices.end()){

        cout<<endl<<" "<<iter->name<<" "<<iter->x<<" "<<iter->y;

        vector<char>::iterator ii=iter->adjacent.begin();

             cout<<"  "<<ii<<"  ";        

        cout<<endl;

        iter++;

   }

     MapProblem *map2=new MapProblem();

      cout<<endl<<" The Graph Search Gives:"<<endl;
      cout<<      " -----------------------"<<endl;
      
      if(A_star_graph_search(map2->initial_state(),g,map2)){

         cout<<endl<<" |   Nodes Removed   |     F(n)     |     G(n)     |     H(n)     |"<<endl;
         cout<<" ------------------------------------------------------------------"<<endl<<endl;

         vector<struct Node>::iterator i=c->begin();

         while(i!=c->end()){

              cout<<"          "<<i->m_state.name<<"                 "<<i->evaluation_function;
              cout<<"              "<<i->path_cost<<"              "<<(i->evaluation_function-i->path_cost)<<endl;

              i++;

         }
      }
      else{
           cout<<endl<<" The graph search algorithm was not successful."<<endl;
           cout<<      " ----------------------------------------------"<<endl;
      }

      cout<<endl<<" ------------------------------------------------------------------"<<endl<<endl;

      cout<<endl<<" Thank You."<<endl<<endl;

      system("Pause");

      fclose(fp);

      return 0;
}