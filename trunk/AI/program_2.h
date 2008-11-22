
							/* The Header File */

# ifndef PROGRAM_2_H
# define PROGRAM_2_H

//The includes
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
# define ROWS    100
# define COLUMNS 100

char ch;
int i=0,j=0;

char g[ROWS][COLUMNS];

//The state data structure.
 struct State{
             int x;

             int y;

             bool obstacle;

             };

//The action data structure.
 struct Action{
              int x;

              int y;

              };

//The Node structure.
 struct Node{
            struct State m_state;

            struct Node* parent;

            struct Action m_action;

            int depth;
            
            bool visited;

            int path_cost;

            int evaluation_function;

           };

 //Variable declarations.
 struct State start_state;
 struct State goal_state;

//The problem data structure.
class MapProblem{

      public:

             //This method checks for the goal and returns true or false
             static bool is_goal(struct State n);

             //This method returns the successors of a node
             void successor_function(struct Node* n,vector<struct Node> *v,char g[ROWS][COLUMNS]);

             //The constructor.
             MapProblem();

             //The initial state
             struct Node initial_state(void);

      private:

              //This method checks for the validity of the successor state
              bool is_valid(struct State n);
             
};

//Prototypes.
 int heuristic(struct State);
 int evaluation_function(struct Node);
 bool visited(struct Node,vector<struct Node>*);
 int A_star_tree_search( struct Node,char (*)[],MapProblem *);
 int A_star_graph_search(struct Node,char (*)[],MapProblem *);
 void output1(vector<struct Node>*,char (*)[]);
 void output2(vector<struct Node>*,char (*)[]);

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

priority_queue<struct Node,vector<struct Node>,SortQueue > *fringe1,*fringe2;

//Function definitions.

int heuristic(struct State n){

    return abs((n.x - goal_state.x)+(n.y - goal_state.y));
}

int evaluation_function(struct Node n){

    return n.path_cost + heuristic(n.m_state);
}

//The constructor.

MapProblem::MapProblem(){}

//IsValid function

bool MapProblem::is_valid(struct State n){

     return n.obstacle == FALSE ;
}

//IsGoal function.

bool MapProblem::is_goal(struct State n){

     return (n.x == goal_state.x && n.y == goal_state.y);
}

//Initial State method.

struct Node MapProblem::initial_state(void){

            struct Node n;

            n.m_state.x=start_state.x;
            n.m_state.y=start_state.y;
            n.m_state.obstacle=start_state.obstacle;

            n.m_action.x=0;
            n.m_action.y=0;

            n.depth=0;

            n.visited=FALSE;

            n.path_cost=0;

            n.evaluation_function=evaluation_function(n);

            n.parent=NULL;

            return n;
}

//The successor function.

void MapProblem::successor_function(struct Node* n,vector<struct Node>* v,char g[ROWS][COLUMNS]){

      struct Node r;
     
     int actions[4][2]={{0,1},{1,0},{0,-1},{-1,0}};

     for(int i=0;i<sizeof actions/sizeof *actions;i++){
        r.m_state.x=n->m_state.x+actions[i][0];
        r.m_state.y=n->m_state.y+actions[i][1];

        if(g[r.m_state.x][r.m_state.y] == '#'){
          r.m_state.obstacle=TRUE;
        }
        else{
             r.m_state.obstacle=FALSE;
        }

        r.m_action.x=actions[i][0];
        r.m_action.y=actions[i][1];

        r.depth=n->depth+1;

        r.visited=0;

        r.path_cost=n->path_cost+1;

        r.evaluation_function=evaluation_function(r);

        r.parent=n;

        if(is_valid(r.m_state)){
          if(n->parent==NULL){
            v->push_back(r);
          }
          else{
              if(n->parent->m_state.x != r.m_state.x
              || n->parent->m_state.y != r.m_state.y){
      
                    v->push_back(r);
              }//end if
          }//end else
        }//end if
     } //end for }

     return ;
}

int A_star_tree_search(struct Node h,char g[ROWS][COLUMNS],MapProblem *map1){

    long aaa=0,bbb=0;

    fringe1=new priority_queue<struct Node,vector<struct Node>,SortQueue>();

            vector<struct Node> *d=new vector<struct Node>();
            vector<struct Node> *c=new vector<struct Node>();

            vector<struct Node>::iterator iter;

            fringe1->push(h);
            sortqueue(fringe1);

            while(!fringe1->empty()){

                if(fringe1->size()>bbb)bbb=fringe1->size();

                 struct Node n=fringe1->top();c->push_back(n);

                 fringe1->pop();aaa++; 

                 if(map1->is_goal(n.m_state)){

                    printf("\n Time  Complexity For Tree Search is: %ld Nodes\n",aaa);

                    printf("\n Space Complexity For Tree Search is: %ld Nodes",bbb);
                    printf("\n\n ");

                    output1(c,g);

                    return 1;
                 }

                 map1->successor_function(&n,d,g);

                 while(!d->empty()){

                       iter=d->begin();

                       fringe1->push(d->front());
                       sortqueue(fringe1);

                       d->erase(iter);
                 }
            }

    return 0;
}

int A_star_graph_search(struct Node h,char g[ROWS][COLUMNS],MapProblem *map2){

    long aaa=0,bbb=0;

	 fringe2=new priority_queue<struct Node,vector<struct Node>,SortQueue>();

            vector<struct Node> *d=new vector<struct Node>();
            vector<struct Node> *closed=new vector<struct Node>();
            vector<struct Node> *c=new vector<struct Node>();

            vector<struct Node>::iterator iter;
            
            fringe2->push(h);
            sortqueue(fringe2);
            
            while(!fringe2->empty()){

                 if(fringe2->size()>bbb)bbb=fringe2->size();

                 struct Node n=fringe2->top(); 
                 
                 c->push_back(n);

                 fringe2->pop();aaa++;

                 if(map2->is_goal(n.m_state)){

                    printf("\n Time  Complexity For Graph Search is: %ld Nodes",aaa);
                    printf("\n");

                    printf("\n Space Complexity For Graph Search is: %ld Nodes",bbb);
                    printf("\n\n ");

                    output2(closed,g);

                    return 1;
                 }

                 if(visited(n,closed))continue;
                 n.visited=TRUE;
                 closed->push_back(n);

                 map2->successor_function(&n,d,g);

                 while(!d->empty()){

                       iter=d->begin();

                       fringe2->push(d->front());
                       sortqueue(fringe2);
                       
                       d->erase(iter);
                 }
            }

    return 0;
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

void output2(vector<struct Node> *c,char g[ROWS][COLUMNS]){

           vector<struct Node>::iterator iter2;

           iter2=c->end();  

           while(iter2!=c->begin() && iter2->parent!=NULL){

                g[iter2->m_state.x][iter2->m_state.y]=='o';
             
                iter2=iter2->parent;
           }  

           printf("\n The solution for Graph search is as follows:");
           printf("\n --------------------------------------------\n");

                 printf("\n ");

                 for(int m=0;m<i;m++){
                    for(int n=0;n<strlen(g[m]);n++)
                       printf("%c",g[m][n]);
                       
                       printf("\n ");
                 }  

     return ;
}

void output1(vector<struct Node> *c,char g[ROWS][COLUMNS]){

           vector<struct Node>::iterator iter2;

           iter2=c->end();

           while(iter2!=c->begin() && iter2->parent!=NULL){

                g[iter2->m_state.x][iter2->m_state.y]=='o';

                iter2=iter2->parent;
           }

           printf("\n The solution for Tree search is as follows:");
           printf("\n -------------------------------------------\n");

                 printf("\n ");

                 for(int m=0;m<i;m++){
                    for(int n=0;n<strlen(g[m]);n++)
                       printf("%c",g[m][n]);
                       printf("\n ");
                 }

     return ;
}

# endif  