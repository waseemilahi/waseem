//Waseem Ilahi                        /*The Svc function*/

//The SVC function.
void Svc(long* a,long* p){

    long abc=329;

    //Bookkeeping.
      if(runningreg==1){
         readyqueue->push(currentlyrunning->getjobnumber());
         runningreg=0;

         jobTable->findjob(currentlyrunning->getjobnumber())->settimejobstopped(p[5]);
         jobTable->findjob(currentlyrunning->getjobnumber())->setcputimeused();
         jobTable->findjob(currentlyrunning->getjobnumber())->settimeslice();

          sortqueue(readyqueue);
       }
       //The terminate SVC issued.
       if(*a==5){ long aa,aaa,aa1=-1,aaa1=-1;
         //If there is no iopending then kill the job.
         if( jobTable->findjob(currentlyrunning->getjobnumber())->getiopending()<=0 ){
              readyqueue->pop();

         freespacetable->freememory(currentlyrunning->getlocation(),currentlyrunning->getjobsize());

         aa=currentlyinio->getjobnumber();aaa=currentlyindrum->getjobnumber();
         if(!diskqueue->empty())aa1=diskqueue->top();if(!drumqueue->empty())aaa1=drumqueue->top();

        jobTable->removejob(currentlyrunning->getjobnumber());

         if(diskbusy==1 && aa!=currentlyinio->getjobnumber()){
           if(currentlyinio->getiopending()>0){
             if(aa1==-1){
             }
             else if(aa1!=diskqueue->top()){
                     diskqueue->push(currentlyinio->getjobnumber());
             }
           }

           currentlyinio=jobTable->findjob(aa);

         }
             if(drumbusy==1 && aaa!=currentlyindrum->getjobnumber()){

               currentlyindrum=jobTable->findjob(aaa);

             }

         }
        //If there are iopendigs then set terminate bit.
         else if(currentlyrunning->getiopending()>0){
                readyqueue->pop();
                jobTable->findjob(currentlyrunning->getjobnumber())->setterminatebit(1);
         }

       }
    //The io SVC.
       else if(*a==6){//Increment iopending.
              jobTable->findjob(currentlyrunning->getjobnumber())->incrementiopending();
            //If the disk is not busy run the io if it is busy then
            //add the entry in the disk queue.
              if(diskbusy==0){
                 jobTable->findjob(currentlyrunning->getjobnumber())->setlatchedbit(1);
                 currentlyinio=jobTable->findjob(currentlyrunning->getjobnumber());

                 diskbusy=1;
                 siodisk(currentlyinio->getjobnumber());
              }
              else if(diskbusy==1){

                     diskqueue->push(currentlyrunning->getjobnumber());

                     if(!diskqueue->empty())if(currentlyrunning->getjobnumber()==abc){ sortqueue(diskqueue);}

              }
       }
    //The Block SVC
       else if(*a==7){//set the block bit . this request is handeled in the scheduler.
              jobTable->findjob(currentlyrunning->getjobnumber())->setblockedbit(1);
       }
       //Look for memory.
         long aaaa;

       if(!waitinglist->empty()){
         aaaa=waitinglist->front();
         waitinglist->pop_front();
          if(jobTable->findjob(aaaa)->getincorebit()==0){
           swapper(aaaa);
         }
       }
     //The scheduler.
       scheduler(a,p);
     //The dispatcher.
       os_dispatcher(a,p,valueofa);

	  return ;
}