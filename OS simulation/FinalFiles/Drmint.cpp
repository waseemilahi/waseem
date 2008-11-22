//Waseem Ilahi                     /*The Drmint function*/

//The Drmint function.

void Drmint(long*a, long* p){

    //The potential currently interrupted job is being saved.

         if(runningreg==1){
         readyqueue->push(currentlyrunning->getjobnumber());
         runningreg=0;

         jobTable->findjob(currentlyrunning->getjobnumber())->settimejobstopped(p[5]);
         jobTable->findjob(currentlyrunning->getjobnumber())->setcputimeused();
         jobTable->findjob(currentlyrunning->getjobnumber())->settimeslice();
         sortqueue(readyqueue);
       }

       //The transit bit of the job curently moved in or out of core is reset.

       jobTable->findjob(currentlyindrum->getjobnumber())->setintransitbit(0);
       //Drum is not busy.
       drumbusy=0;

       //This if else block places the job currently moved in the rightful position.
          if(corememory==0){
           //Here the job is put into the ready queue, since it was
           //brought into the memory and is not blocked.
             jobTable->findjob(currentlyindrum->getjobnumber())->setincorebit(1);
             if(currentlyindrum->getblockedbit()==0){
              readyqueue->push(currentlyindrum->getjobnumber());
             //This method sorts the ready queue.
             sortqueue(readyqueue);
             }

             //This method checks to see if there is any job that requires io
             //and also the disk is free, then it calls siodisk.
             disk();
          }
          else if(corememory==1){
            //if the job is brought out, it is placed on the waiting list.
                 jobTable->findjob(currentlyindrum->getjobnumber())->setincorebit(0);
                 
                  if(!diskqueue->empty()){if(currentlyindrum->getjobnumber()!=diskqueue->top())waitinglist->push_back(currentlyindrum->getjobnumber());}
                  else if(diskqueue->empty()){waitinglist->push_back(currentlyindrum->getjobnumber());}

                  removenotready(currentlyindrum->getjobnumber());

                if(jobmoving==1){
                  jobmoving=0;readyqueue->push(currentlyindrum->getjobnumber());

                    sortqueue(readyqueue);
                }
          }

       //This part checks and if required, does siodrum.
           int j=-1;
          stack<long,vector<long> > *tmpstk=new stack<long,vector<long> >();

      if(drumbusy==0){
       while(!drumqueue->empty()){
         if(jobTable->findjob(drumqueue->top())->getlatchedbit()==1){
           tmpstk->push(drumqueue->top());
           drumqueue->pop();j++;
         
         }
         else if(jobTable->findjob(drumqueue->top())->getlatchedbit()==0){

               if(jobTable->findjob(drumqueue->top())->getincorebit()==0 && j>=0){
               }
               else{
                 currentlyindrum=jobTable->findjob(drumqueue->top());

                 drumqueue->pop();


          jobTable->findjob(currentlyindrum->getjobnumber())->setintransitbit(1);

          if(currentlyindrum->getincorebit()==0)corememory=0;
          else corememory=1;
          drumbusy=1;

          siodrum(currentlyindrum->getjobnumber(),currentlyindrum->getjobsize(),currentlyindrum->getlocation(),corememory);
               }
               break;

         }
       }

      }

       while(!tmpstk->empty()){
            drumqueue->push(tmpstk->top());
            tmpstk->pop();
       }

       //Look for memory for the job on the head of the waiting list.

       long aaaa;

       if(!waitinglist->empty()){ 
        aaaa=waitinglist->front();
         waitinglist->pop_front();
          if(jobTable->findjob(aaaa)->getincorebit()==0){
           swapper(aaaa);
         }
       }
       //The scheduler
       scheduler(a,p);
       //The dispatcher.
       os_dispatcher(a,p,valueofa);

     return ;
}