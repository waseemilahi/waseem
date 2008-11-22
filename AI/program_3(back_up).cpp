
                /* Program # 3 by Waseem Ilahi */

# include <stdio>
# include <iostream>
# include <vector>
# include <algorithm>
# include <time>
# include <map>
# include <set>
# include <math>

using namespace std;

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


            };

/*class State{

		public:
             typedef set<size_t> Domain;

      public:
             State(){}
             State(size_t n,size_t c);

             size_t next_variable()const;

             State extend_assignment(size_t x,size_t v,const Graph & g)const;

             bool complete()const{return domains_.empty();}
             bool empty()const{return assignment_.empty();}

             size_t value(size_t x)const{return assignment_.find(x)->second;}

             Domain domain(size_t x)const{ return domains_.find(x)->second;}

             bool is_assigned(size_t x)const{
                  return assignment_.find(x)!=assignment_.end();
             }
      private:
      		  map<size_t,size_t> assignment_;
              map<size_t,Domain> domains_;
              friend void print(const State & s);

};

//The method definitions.

State::State(size_t n,size_t c){

      Domain domain;

      for(size_t i=0;i<c;++i)domain.insert(i);
      for(size_t i=0;i<n;++i)domains_[i]=domain;
}

size_t State::next_variable()const{

 //Find variable with smallest domain using heuristic.
      return assignment_.size();
}

State State::extend_assignment(size_t x,size_t v,const Grapg & g)const{

  //Erase values from domains using FC.

  State s(*this);
  s.assignment_[x]=v;
  s.domains_.erase(x);
  return s;
} */

struct LengthCompare{

      LengthCompare(const vector<Point> & p): p_ (p){}

      bool operator ()(pair<int,int>a,pair<int,int>b)const{
           return abs(p_[a.first]-p_[a.second])<abs(p_[b.first]-p_[b.second]);
      }
      const vector<Point> & p_;

};

//Declarations.
typedef std::vector<int> Adjacent;
typedef std::vector<Adjacent> Graph;

//The prototypes.
vector<Point> random_points(int,int);
Graph planar_short_edge(vector<Point>);
bool intersect(int,int, const vector<Point>,const Graph);
bool intersect(Point,Point,Point,Point);
int cross_sign(Point,Point,Point);
bool on_segment(Point,Point,Point);
bool on_segment_helper(Point,Point,Point);
Graph symmetric_closure(Graph);

  int main(){

      int n,k,d;

      printf("\n Program # 3 by Waseem Ilahi.\n");
      printf(" ----------------------------\n");

      printf("\n Please Enter the values for n,k,d respectively.\n");
      cin>>n>>k>>d;
      cout<<endl;

      while(n>k*k){
           printf("\n ERROR! Try Again.\n");

           printf("\n Please Enter the values for n,k,d respectively.\n");
           cin>>n>>k>>d;
           printf("\n");
      }

      vector<Point> points=random_points(n,k);

      Graph h = planar_short_edge(points);

      Graph graph=symmetric_closure(h);

      vector<int>color (n);

      cout<<endl;

      system("Pause");

      return 0;

  }

//The functions.

vector<Point> random_points(int n,int k){

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

Graph planar_short_edge(vector<Point> points){

      int n = points.size();

      Graph graph (n);

      vector<pair<int,int> > pairs;

      for(int i = 1;i < n; ++i)
         for( int j = 0;j < i;++j)
            pairs.push_back(make_pair(i,j));

      sort(pairs.begin(),pairs.end(),LengthCompare(points));

      for(int i = 0; i < pairs.size(); ++i){
         if(!intersect(pairs[i].first,pairs[i].second,points,graph) ){
            graph[pairs[i].first].push_back(pairs[i].second);
         }
      }

      return graph;
}

bool intersect(int a,int b, const vector<Point> & points,const Graph & g){

     for(int i=0;i<g.size();++i)
        for(int k=0;k<g[i].size();++k){
           int j=g[i][k];

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

Graph symmetric_closure(Graph & g){

      Graph h(g.size());

      for(int i=0;i<g.size();++i)
         for(int k=0;k<g[i].size();++k){
            int j=g[i][k];
            h[i].push_back(j);
            if(std::find(g[j].begin(),g[j].end(),i)==g[j].end()){
              h[j].push_back(i);
            }
         }

      return h;

}

//The End.