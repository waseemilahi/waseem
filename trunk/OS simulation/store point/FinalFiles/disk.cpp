             /*The disk function*/

void disk(){

   long a9,a8=-1;

      if(!diskqueue->empty() && diskbusy==0){

         if(jobTable->findjob(diskqueue->top())->getmemoryavailablebit()==0){
            a8=diskqueue->top();diskqueue->pop();
         }
      if(!diskqueue->empty()){
        currentlyinio=jobTable->findjob(diskqueue->top());

       if(currentlyinio->getintransitbit()==1){

       }
       else if(currentlyinio->getincorebit()==0){

             swapper(currentlyinio->getjobnumber());

       }
       else if(currentlyinio->getincorebit()==1){

                 currentlyinio->setlatchedbit(1);

                 jobTable->findjob(diskqueue->top())->setlatchedbit(1);

                 diskqueue->pop();
                
                 diskbusy=1;
                 siodisk(currentlyinio->getjobnumber());
          }
       }
       }

       if(a8!=-1)diskqueue->push(a8);

       return ;
}