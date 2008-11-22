
                     /* Waseem Ilahi's Program # 1 */

//The Include files.

# include <iostream>
# include <queue>
# include <vector>

using namespace std;



//The State
struct State{
       
             int m[2];
       
             int c[2];
       
             bool b;
       
            };

//The Action.
struct Action{

              int m;

              int c;

             };
             
//The Node       
struct Node{

            struct State m_states;

            struct Node* parent;

            struct Action m_action;

            int depth;
            
            bool visited;

           };

//Prototypes.

struct Node initial_state(void);
int recursive_DFS(struct Node);
int BFS_SEARCH(struct Node);

bool is_goal(struct State);
bool is_valid_state(struct State);
void successors(struct Node*,vector<struct Node>*);

//Variable
vector<struct Node> *f=new vector<struct Node>();

//The main function.

int main(){
    
    cout<<endl<<" Program # 1 By Waseem Ilahi."<<endl;
    cout<<" ----------------------------"<<endl;
    
    cout<<endl<<" This Program givesthe implementation of two algorithms"<<endl;
    cout<<" for solving three missionaries problem."<<endl;
    
    cout<<endl<<endl<<" First we give the solution with Breadth First Search."<<endl;
    cout<<" -----------------------------------------------------"<<endl<<endl;
           
    int a=BFS_SEARCH(initial_state());    
    
    cout<<endl<<" "<<a<<" : Indicates that BFS was successful"<<endl<<endl;
    
    cout<<endl<<" The following is the solution using recursive Depth First Search."<<endl;
    cout<<" -----------------------------------------------------------------"<<endl<<endl;
    
    recursive_DFS(initial_state());    
    
    cout<<endl;
    
    vector<struct Node>::iterator i;   
    
    while(!f->empty()){
         
         i=f->begin();               
         
         cout<<" "<<f->front().m_states.c[1]<<","<<f->front().m_states.m[1];
         cout<<" | "<<f->front().m_states.c[0]<<","<<f->front().m_states.m[0]<<endl<<endl;              
        
         f->erase(i);
         
    }
    
    cout<<endl<<" Thank You."<<endl<<endl;
    
    system("Pause");

return 0;

}

//Function Definitions.

struct Node initial_state(void){

     struct Node a;
     
    a.m_states.m[0]=3;
    a.m_states.m[1]=0;
    a.m_states.c[0]=3;
    a.m_states.c[1]=0;
    a.m_states.b=0;
    a.m_action.c=0;
    a.m_action.m=0;
    a.depth=0;
    a.visited=0;
    a.parent=NULL;

     return a;
}

int recursive_DFS(struct Node root){

   vector<struct Node> *n=new vector<struct Node>();
   vector<struct Node>::iterator iter;
   int answer;

    if(is_goal(root.m_states)){
      f->push_back(root);
      return 1;
    }

    successors(&root,n); 
    
    while(!n->empty()){
                       
        iter=n->begin();
        
         answer=recursive_DFS(n->front());

        n->erase(iter);

         if(answer==1){
           f->push_back(root);    
           return 1;
         }
    }

    return 0;
    
}

int BFS_SEARCH(struct Node root){

            Queue<struct Node> fringe;
            
            vector<struct Node>::iterator k,j;
            
            vector<struct Node> *d=new vector<struct Node>();
            vector<struct Node> *m=new vector<struct Node>();
            vector<struct Node> *l=new vector<struct Node>();
            vector<struct Node>::iterator iter;
            struct Node tmp;
            
            fringe.insert(root);
            
            while(!fringe.empty()){
                 struct Node n=fringe.remove();
                 m->push_back(n);
                 if(is_goal(n.m_states)){                  
                                                                                
                    while(!m->empty()){ 
                          
                          j=m->end();                     
                       
                       cout<<" "<<m->back().m_states.c[0]<<","<<m->back().m_states.m[0];
                       cout<<" | "<<m->back().m_states.c[1]<<","<<m->back().m_states.m[1]<<endl<<endl;              
        
                        m->erase(j);         
                     }
                 
                    return 1;
                 }
       
                 successors(&n,d);              
                 
                 while(!d->empty()){
                       
                       iter=d->begin();
                       
                       fringe.insert(d->front());
                       
                       d->erase(iter);
                 }
            }
            
            return 0;
}

bool is_goal(struct State s){

     return s.m[1]==3 && s.c[1]==3 && s.b==1 && s.m[0]==0 && s.c[0]==0;
}

bool is_valid_state(struct State s){
     
     return (s.m[0]>=0 && s.m[0]<=3) && (s.m[1]>=0 && s.m[1]<=3)
             && (s.c[0]>=0 && s.c[0]<=3) && (s.c[1]>=0 && s.c[1]<=3)
             && (s.m[0]==0 || s.m[0]>=s.c[0]) && (s.m[1]==0 || s.m[1]>=s.c[1]);
     
}

void successors(struct Node* s, vector<struct Node> *v){

     struct Node r;
     
     int actions[5][2]={{0,2},{1,0},{1,1},{0,1},{2,0}};
     
      if(s->m_states.b==0){  
        for(int i=0;i<sizeof actions/sizeof *actions;i++){
           r.m_states.m[0]=s->m_states.m[0]-actions[i][0];
           r.m_states.c[0]=s->m_states.c[0]-actions[i][1]; 
           r.m_states.m[1]=s->m_states.m[1]+actions[i][0];
           r.m_states.c[1]=s->m_states.c[1]+actions[i][1];
           r.m_states.b=1;
           r.m_action.c=actions[i][1];
           r.m_action.m=actions[i][0];
           r.depth=s->depth+1;
           r.parent=s;
           
           if(is_valid_state(r.m_states)){                                          
             if(s->parent==NULL){v->push_back(r);}
             else{              
               if(s->parent->m_states.m[0]!=r.m_states.m[0]
                  || s->parent->m_states.m[1]!=r.m_states.m[1]
                  || s->parent->m_states.c[0]!=r.m_states.c[0]
                  || s->parent->m_states.c[1]!=r.m_states.c[1]
                  || s->parent->m_states.b!=r.m_states.b){
      
                    v->push_back(r);
               }
             }
           }
        }
      }
      else if(s->m_states.b==1){  
        for(int i=0;i<sizeof actions/sizeof *actions;i++){
           r.m_states.m[0]=s->m_states.m[0]+actions[i][0];
           r.m_states.c[0]=s->m_states.c[0]+actions[i][1]; 
           r.m_states.m[1]=s->m_states.m[1]-actions[i][0];
           r.m_states.c[1]=s->m_states.c[1]-actions[i][1];
           r.m_states.b=0;
           r.m_action.c=actions[i][1];
           r.m_action.m=actions[i][0];
           r.depth=s->depth+1;
           r.parent=s;
           
      
   
           if(is_valid_state(r.m_states)){                                         
             if(s->parent==NULL){v->push_back(r);}
             else{             
               if(s->parent->m_states.m[0]!=r.m_states.m[0]
                  || s->parent->m_states.m[1]!=r.m_states.m[1]
                  || s->parent->m_states.c[0]!=r.m_states.c[0]
                  || s->parent->m_states.c[1]!=r.m_states.c[1]
                  || s->parent->m_states.b!=r.m_states.b){
                                                               
                    v->push_back(r);
               }
             }
           }
        }
      }    
     
  return ;
}
