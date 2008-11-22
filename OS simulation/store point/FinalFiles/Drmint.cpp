                          /*The Drmint function*/

void Drmint(long*a, long* p){

         if(runningreg==1){
         readyqueue->push(currentlyrunning->getjobnumber());
         runningreg=0;

         jobTable->findjob(currentlyrunning->getjobnumber())->settimejobstopped(p[5]);
         jobTable->findjob(currentlyrunning->getjobnumber())->setcputimeused();
         jobTable->findjob(currentlyrunning->getjobnumber())->settimeslice();
         sortqueue(readyqueue);
       }

       jobTable->findjob(currentlyindrum->getjobnumber())->setintransitbit(0);
       drumbusy=0;

          if(corememory==0){
             jobTable->findjob(currentlyindrum->getjobnumber())->setincorebit(1);
             if(currentlyindrum->getblockedbit()==0){
              readyqueue->push(currentlyindrum->getjobnumber());

             sortqueue(readyqueue);
             }     disk();
          }
          else if(corememory==1){

                 jobTable->findjob(currentlyindrum->getjobnumber())->setincorebit(0);
                 
                  if(!diskqueue->empty()){if(currentlyindrum->getjobnumber()!=diskqueue->top())waitinglist->push_back(currentlyindrum->getjobnumber());}
                  else if(diskqueue->empty()){waitinglist->push_back(currentlyindrum->getjobnumber());}

                  removenotready(currentlyindrum->getjobnumber());

                if(jobmoving==1){
                  jobmoving=0;readyqueue->push(currentlyindrum->getjobnumber());

                    sortqueue(readyqueue);
                }
          }
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

       long aaaa;

       if(!waitinglist->empty()){ 
        aaaa=waitinglist->front();
         waitinglist->pop_front();
          if(jobTable->findjob(aaaa)->getincorebit()==0){
           swapper(aaaa);
         }
       }

       scheduler(a,p);

       os_dispatcher(a,p,valueofa);

     return ;
}