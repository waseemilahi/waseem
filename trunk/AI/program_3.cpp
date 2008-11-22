
                /* Program # 3 by Waseem Ilahi */

//The includes

# include <stdio>
# include <iostream>
# include <vector>
# include <algorith>
# include <time>
# include <map>
# include <set>
# include <math>

using namespace std;

//The Point class.

class Point{
		
      private:    
		  
		     int x;

             int y;

      public: 

        void setx(int x1){ this->x=x1;}

        void sety(int y1){ this->y=y;}

        int gety(){return y;}
        int getx(){return x;}

		     Point();

			 Point Point::operator-=(Point k)const{

				    Point tmp;

					tmp.x=x+k.x;

					tmp.y=y+k.y;

					return tmp;
			}

         int Point::operator-(Point k)const{

               return (int)sqrt((x-k.x)*(x-k.x) + (y-k.y)*(y-k.y));
         }


};

//Declarations.
typedef std::vector<int> Adjacent;
typedef std::vector<Adjacent> Graph;

//The prototypes.
vector<Point> random_points(unsigned int,unsigned int);
Graph planar_short_edge(vector<Point>);
bool intersect(int,int, const vector<Point>,const Graph);
bool intersect(Point,Point,Point,Point);
int cross_sign(Point,Point,Point);
bool on_segment(Point,Point,Point);
bool on_segment_helper(Point,Point,Point);
bool color_graph(vector<int>,const Graph,int);
bool color_graph1(vector<int>,const Graph,int);


//For the extra argument in set and map template classes.
struct ltstr{

				};

//The State class.

class State{

		public:
             typedef set<size_t,ltstr> Domain;

      public:
             State(){}
             State(size_t n,size_t c);

             size_t next_variable()const;

             State extend_assignment(size_t x,size_t v,const Graph & g)const;

             int conflicts(size_t,size_t,const Graph &);

             bool complete()const{return domains_.empty();}
             bool empty()const{return assignment_.empty();}

             void complete_assignment(size_t,int);

             size_t value(size_t x)const{return assignment_.find(x)->second;}

             Domain domain(size_t x)const{ return domains_.find(x)->second;}

             bool is_solution(const Graph & g);

             bool is_assigned(size_t x)const{
                  return assignment_.find(x)!=assignment_.end();
             }
      private:
      		  map<size_t,size_t,ltstr> assignment_;
              map<size_t,Domain,ltstr> domains_;
              friend void print(const State & s);

};

//The method definitions for State Class.
//---------------------------------------

//The goal test for minconflicts.

bool State::is_solution(const Graph & g){

  int j=0;

    for(unsigned int k=0;k<g.size();k++){

		vector<int> adjacent=g[k];

     vector<int>::iterator iter1;

     iter1=adjacent.begin();

     while(iter1!=adjacent.end()){

            if(assignment_[k]==assignment_[j])
              return false;

            j++;

        iter1++;
      }
    }

    return true;

}

//Gives the number of conflicts in an assignments (for minconflicts).
int State::conflicts(size_t x,size_t v,const Graph & g){

    int i=0,j=0;

    State s(*this);
    s.assignment_[x]=v;
    s.domains_.erase(x);

    vector<int> adjacent=g[x];

    vector<int>::iterator iter1;

   iter1=adjacent.begin();

   while(iter1!=adjacent.end()){

          if((v==s.domains_[j]->find(v)))
            i++;

            j++;

        iter1++;
  }
     
    return i;

}

//Assigns some values to all the variables.

void State::complete_assignment(size_t n,int v){

     for(unsigned int i=0;i<n;i++){
        assignment_[i]=v-1;
        domains_[i].erase(v-1);
     }

     return ;
}

//The constructor.
State::State(size_t n,size_t c){

      Domain domain;

      for(size_t i=0;i<c;++i)domain.insert(i);
      for(size_t i=0;i<n;++i)domains_[i]=domain;
}

//Return the variable with smallest domain using MRV
size_t State::next_variable()const{

      unsigned int yes;
      int mrv;

      yes=domains_[0].size();

      for(unsigned int i=1;i<domains_.size();i++)
         if(yes>domains_[i].size()){yes=domains_[i].size();mrv=i;}

      return mrv;
}

//Erase values from domains using FC.
State State::extend_assignment(size_t x,size_t v,const Grapg & g)const{

  vector<int> adjacent=g[x];

  State s(*this);
  s.assignment_[x]=v;
  s.domains_.erase(x);

  vector<int>::iterator iter1;

  iter1=adjacent.begin();

  while(iter1!=adjacent.end()){

        s.domains_[iter1].erase(v);

        iter1++;
  }

  return s;
}
//Prototype for back tracking.
bool backtrack(State *,const Graph*,State);

//Declaration.
static size_t consistency_checks;

//The backtracking algorithm.

bool backtrack(State * result,const Graph & g,State s){
	  
	 typedef int Vertex;
	 typedef State::Domain Domain;

	 if(s.complete()){
		  *result=s;
		  return true;
	 }

	 Vertex x=s.next_variable();
	 Domain domain=s.domain(x);

	 for(Domain::iterator c=domain.begin();c!=domain.end();++c){
		 bool consistent=true;
		 for(unsigned int i=0;i<g[x].size();++i){
			 ++consistency_checks;
			 Vertex y=g[x][i];
			 if(s.is_assigned(y) && s.value(y)==*c){
				 consistent=false;
				 break;
			 }
		 }

		 if(!consistent)continue;

		 if(backtrack(result,g,s.extend_assignment(x,*c,g)))
			 return true;
	 }

	 return false;
}

//The graph coloring function for back tracking.

bool color_graph(vector<int> & color,const Graph & g,int chi){

	size_t n=g.size();

	State start(n,chi),result;

	if(backtrack(&result,g,start)){
		color.resize(n);

		for(size_t i=0;i<n;++i)color[i]=result.value(i);
		return true;
	}
	else return false;
}

//Prototype for minconflicts.
bool minconflicts(State *,const Graph *,State,size_t,int);

//The minconflicts algorithm.

bool minconflicts(State * result,const Graph g,State s,size_t n,int v){

		int max_steps=n*v,c=0;

      for(int i=0;i<max_steps;i++){
         if(s.is_solution(g)){
           *result=s;
           return true;
         }

         int b,a=s.conflicts(0,v,g);

         //Choosing most conflicted variable.
         for(unsigned int j=1;j<g.size();j++){
            b=s.conflicts(j,v,g);
            if(b>a){
              a=b;
              c=j;
            }
         }

         int u=0,y=0;

         int w=s.conflicts(c,0,g);

         //Choosing the best value for the chosen variable.
         for(int l=1;l<v;l++){
            u=s.conflicts(c,l,g);

            if(u<w){
              w=u;
              y=l;
            }
         }//end for

         s.extend_assignment(c,y,g);
      }//End main for.

      return false;
}

//The graph coloring function for min-conflicts.

bool color_graph1(vector<int> & color,const Graph & g,int chi){

	size_t n=g.size();

	State start(n,chi),result;

   start.complete_assignment(n,chi);

	if(minconflicts(&result,g,start,n,chi)){
		color.resize(n); 
		for(size_t i=0;i<n;++i)color[i]=result.value(i);
		return true;
	}
	else return false;
}

//The point generator function.

vector<Point> random_points(unsigned int n,unsigned int k){

                     vector<Point> points;

                     int aa=0;

                     vector<Point>::iterator iter1;

                     srand(time(NULL));

                     while(points.size()<n){
                          int x=rand()%k;
                          int y=rand()%k;

                          Point point;

                          point.setx(x);
                          point.sety(y);

                          iter1=points.begin();

                          while(iter1!=points.end()){

                                if(iter1->getx()==point.getx() && iter1->gety()==point.gety()){
                                  aa=1;;
                                  break;
                                }

                               iter1++;

                          }

                          if(aa==1)continue;

                          points.push_back(point);

                     }

                     iter1=points.begin();

                     while(iter1!=points.end()){

                          cout<<endl<<iter1->getx()<<","<<iter1->gety()<<endl;

                          iter1++;

                     }

                     return points;
}

//Structure for sorting criterian.

struct LengthCompare{

      LengthCompare(const vector<Point> & p): p_ (p){}

      bool operator ()(pair<int,int>a,pair<int,int>b)const{
           return abs(p_[a.first]-p_[a.second])<abs(p_[b.first]-p_[b.second]);
      }
      const vector<Point> & p_;

};

//Graph generator.

Graph planar_short_edge(vector<Point> points){

      int n = points.size();

      Graph graph (n);

      vector<pair<int,int> > pairs;

      for(int i = 1;i < n; ++i)
         for( int j = 0;j < i;++j)
            pairs.push_back(make_pair(i,j));

      sort(pairs.begin(),pairs.end(),LengthCompare(points));

      for(unsigned int i = 0; i < pairs.size(); ++i){
         if(!intersect(pairs[i].first,pairs[i].second,points,graph) ){
            graph[pairs[i].first].push_back(pairs[i].second);
         }
      }

      return graph;
}

//The functions used for graph generation.

bool intersect(unsigned int a,unsigned int b, const vector<Point> & points,const Graph & g){

     for(unsigned int i=0;i<g.size();++i)
        for(unsigned int k=0;k<g[i].size();++k){
           unsigned int j=g[i][k];

           if(i==a || i==b)
             if(on_segment(points[a],points[b],points[j]))
               return true;
             else
                 continue;

           if(j==a || j==b)
             if(on_segment(points[a],points[b],points[i]))
               return true;
             else
                 continue;

           if(intersect(points[a],points[b],points[i],points[j]))
             return true;

        }

        return false;
}

bool insersect(Point a,Point b,Point c,Point d){

     int s1=cross_sign(a,b,c);
     int s2=cross_sign(a,b,d);
     int s3=cross_sign(c,d,a);
     int s4=cross_sign(c,d,b);

     if(s1!=s2 && s3!=s4)return true;

     if(s1==0 && on_segment_helper(a,b,c))return true;
     if(s2==0 && on_segment_helper(a,b,d))return true;
     if(s3==0 && on_segment_helper(c,d,a))return true;
     if(s4==0 && on_segment_helper(c,d,b))return true;

     return false;
}

int cross_sign(Point a,Point b,Point c){

    b-=a;
    c-=a;
   
	int z=b.getx()*c.gety()-b.gety()*c.getx();

    if(z<0)return -1;
    if(z>0)return  1;

    return 0;
}

bool on_segment(Point a,Point b,Point c){

     return cross_sign(a,b,c)==0 && on_segment_helper(a,b,c);
}

bool on_segment_helper(Point a,Point b,Point c){

     return min(a.getx(),b.getx())<=c.getx() && c.getx()<=max(a.getx(),b.getx()) && min(a.gety(),b.gety())<=c.gety() && c.gety()<=max(a.gety(),b.gety());
}

//The reverse edges are formed with this.

Graph symmetric_closure(Graph & g){

      Graph h(g.size());

      for(unsigned int i=0;i<g.size();++i)
         for(unsigned int k=0;k<g[i].size();++k){
            int j=g[i][k];
            h[i].push_back(j);
            if(std::find(g[j].begin(),g[j].end(),i)==g[j].end()){
              h[j].push_back(i);
            }
         }

      return h;

}

//The Main Function.

 int main(){

      unsigned int k,d;

      unsigned int n;

      printf("\n Program # 3 by Waseem Ilahi.\n");
      printf(" ----------------------------\n");

      cout<<endl<<" Format of output is  Number : Color Number [X-coordinate Y-coordinate]."<<endl;
      cout<<      " -----------------------------------------------------------------------"<<endl;

      printf("\n Please Enter the values for n,k,d respectively: ");
      cin>>n>>k>>d;
      cout<<endl;

      while(n>k*k || n<1 || k<1 || d<1){
           printf("\n ERROR! Try Again.\n");

           printf("\n Please Enter the values for n,k,d respectively.\n");
           cin>>n>>k>>d;
           printf("\n");
      }

      vector<Point> points=random_points(n,k);

      Graph h = planar_short_edge(points);

      Graph graph=symmetric_closure(h);

      vector<int>color (n);

      cout<<endl<<" Following is the solution using Back Tracking."<<endl;
      cout<<      " ----------------------------------------------"<<endl;

	  if(!color_graph(color,graph,d)){
		   cerr<<endl<<" Cannot color graph with "<<d<<" colors."<<endl;
		   return 1;
	  }

	  //Print out the segments.

     cout<<endl<<" The Segments:"<<endl;

	  for(unsigned int aa=0;aa<h.size();++aa)
		  for(unsigned int bb=0;bb<h[aa].size();++bb){
			  cout<<endl<<" ["<<points[aa].getx()<<" "<<points[aa].gety()<<"]"<<" , ";
			  cout<<"["<<points[h[aa][bb]].getx()<<" "<<points[h[aa][bb]].gety()<<"]"<<endl;
		  }

	  //Separator line.

	  cout<<endl<<" --------------------------------------"<<endl;

	  //Print out the colors and coordinates of the vertices.

     cout<<endl<<" The coloring:"<<endl;

	  for(unsigned int aaa=0;aaa<points.size();++aaa)
		  cout<<endl<<" "<<(aaa+1)<<" : "<<color[aaa]<<" ,  ["<<points[aaa].getx()<<" "<<points[aaa].gety()<<"]"<<endl;

        cout<<endl<<" ----------------------------------------------------------------"<<endl;

        cout<<endl<<" Following is the solution using Min-Conflicts."<<endl;
        cout<<      " ----------------------------------------------"<<endl;

        if(!color_graph1(color,graph,d)){
		   cerr<<endl<<" Cannot color graph with "<<d<<" colors."<<endl;
		   return 1;
	  }

     //Print out the segments.

     cout<<endl<<" The Segments:"<<endl;

	  for(unsigned int aa=0;aa<h.size();++aa)
		  for(unsigned int bb=0;bb<h[aa].size();++bb){
			  cout<<endl<<" ["<<points[aa].getx()<<" "<<points[aa].gety()<<"]"<<" , ";
			  cout<<"["<<points[h[aa][bb]].getx()<<" "<<points[h[aa][bb]].gety()<<"]"<<endl;
		  }

	  //Separator line.

	  cout<<endl<<" --------------------------------------"<<endl;

	  //Print out the colors and coordinates of the vertices.

     cout<<endl<<" The coloring:"<<endl;

	  for(unsigned int aaa=0;aaa<points.size();++aaa)
		  cout<<endl<<" "<<(aaa+1)<<" : "<<color[aaa]<<" ,  ["<<points[aaa].getx()<<" "<<points[aaa].gety()<<"]"<<endl;

      cout<<endl<<" Thank You."<<endl;

      system("Pause");

      return 0;

  }

//The End.