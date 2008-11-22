                       /*The scheduler function*/

void scheduler(long* a,long* p){

      long a9;

      if(readyqueue->empty()){

         valueofa=1;
         
         return ;
      }
      else while(!readyqueue->empty()){

           currentlyrunning=jobTable->findjob(readyqueue->top());

           readyqueue->pop();

           if(currentlyrunning==NULL){ *a=1; return;}

      if(currentlyrunning->getintransitbit()==1){
          if(!readyqueue->empty()){
              jobmoving=1;
              continue;

            }
            else if(readyqueue->empty()){
                    readyqueue->push(currentlyrunning->getjobnumber());

                    sortqueue(readyqueue);
                   valueofa=1;

                   return;
            }
      }
      else if(currentlyrunning->getblockedbit()==1 && currentlyrunning->getiopending()>0 ){

              blockedlist->push_back(currentlyrunning->getjobnumber());

            if(!readyqueue->empty()){

              continue;

            }
            else if(readyqueue->empty()){

                   valueofa=1;

                   return ;
            }

      }
      else{

               if(currentlyrunning->getblockedbit()==1 && currentlyrunning->getiopending()==0){
                 jobTable->findjob(currentlyrunning->getjobnumber())->setblockedbit(0);
               }

           if(currentlyrunning->getincorebit()==0){

               swapper(currentlyrunning->getjobnumber());

               if(!readyqueue->empty()){

                 continue;

               }
               else if(readyqueue->empty()){

                   valueofa=1;

                   return ;
               }

           }
           else if(currentlyrunning->getincorebit()==1){

                   jobTable->findjob(currentlyrunning->getjobnumber())->settimejobran(p[5]);

                   runningreg=1;     

                   valueofa=2;

                   return ;
           }

         }

      }
      
      valueofa=1;

      return ;
}
