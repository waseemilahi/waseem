//Waseem Ilahi              /*The Removenot ready function.*/

//Removes the job from the ready queue that matches the given job number.
//It also uses a stack.
void removenotready(long jn){

     stack<long,vector<long> > *tmpstk=new stack<long,vector<long> >();

     while(!readyqueue->empty()){

          if(readyqueue->top()!=jn){
            tmpstk->push(readyqueue->top());
            readyqueue->pop();
          }
          else if(readyqueue->top()==jn){
                
                 readyqueue->pop();
          }
     }
     while(!tmpstk->empty()){
          readyqueue->push(tmpstk->top());
          tmpstk->pop();
     }

     return;
}
