//Waseem Ilahi
# include <iostream>
using namespace std;

# define Q  8

struct POINT {
              int x,y;
             };

POINT q[Q];

int N;

bool chkAll(int x){

     for ( int i =x ; i >=0 ; i--)
	     for(int j = i - 1; j >= 0 ; j--)
	        if(q[i].x == q[j].x || q[i].y == q[j].y ||
	           q[i].x + q[i].y == q[j].x + q[j].y ||
	           q[i].x - q[j].x == q[i].y - q[j].y)
	          return false; return true;
}

void MoveQueen(int x){
	
     if(x >= Q){

       cout<<endl<<endl<<" Solution : "<<++N<<endl<<endl<<"           ";
		 for(int j=0;j<Q;j++){
           cout<<endl<<"          |  |  |  |  |  |  |  |  |";
           cout<<endl<<"          |";
		    for(int i=0;i<Q;((q[j].x==j)
              && (q[j].y==i))?cout<<"_Q"<<"|" : cout<<"__"<<"|",i++);
       }
		       return;
     }
	
     for (int j = 0; j < Q ;q[x].x = x,j++){

         q[x].y = j;

	      if(chkAll(x))
           MoveQueen(x + 1);
     }
}
int main(){

    for (int i = 0; i < Q; q[0].x = 0,q[0].y = i,MoveQueen(1),i++);

    cout<<endl<<endl;

    system("Pause");

    cout<<endl;

    return 0;
}
