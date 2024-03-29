                           /*The sortqueue functions*/

void sortqueue(priority_queue<long,vector<long>,SortQueue >* givenqueue){

     stack<long,vector<long> > *tmpstk=new stack<long,vector<long> >();

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

void sortqueue(priority_queue<long,vector<long>,SortQueueDrum >* givenqueue){

     stack<long,vector<long> > *tmpstk=new stack<long,vector<long> >();

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

void sortqueue(priority_queue<long,vector<long>,SortQueueDisk >* givenqueue){

     stack<long,vector<long> > *tmpstk=new stack<long,vector<long> >();

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
