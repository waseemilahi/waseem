//Waseem Ilahi             /*The disk function*/

//The disk function.It looks for the jobs that want to do ioand calls
// siodrum with that job.if the job is not in core then swapper id called
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
       //The job is incore.
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