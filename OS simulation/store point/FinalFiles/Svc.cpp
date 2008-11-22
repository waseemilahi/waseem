                             /*The Svc function*/

void Svc(long* a,long* p){

    long abc=329;

      if(runningreg==1){
         readyqueue->push(currentlyrunning->getjobnumber());
         runningreg=0;

         jobTable->findjob(currentlyrunning->getjobnumber())->settimejobstopped(p[5]);
         jobTable->findjob(currentlyrunning->getjobnumber())->setcputimeused();
         jobTable->findjob(currentlyrunning->getjobnumber())->settimeslice();

          sortqueue(readyqueue);
       }

       if(*a==5){ long aa,aaa,aa1=-1,aaa1=-1;

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
         else if(currentlyrunning->getiopending()>0){
                readyqueue->pop();
                jobTable->findjob(currentlyrunning->getjobnumber())->setterminatebit(1);
         }

       }
       else if(*a==6){
              jobTable->findjob(currentlyrunning->getjobnumber())->incrementiopending();

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
       else if(*a==7){
              jobTable->findjob(currentlyrunning->getjobnumber())->setblockedbit(1);
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