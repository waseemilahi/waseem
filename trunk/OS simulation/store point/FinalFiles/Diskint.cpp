                        /*The Diskint function*/

void Dskint(long* a,long* p){

          long aa,c=276,d=295,b=328;;

		 if(runningreg==1){
         readyqueue->push(currentlyrunning->getjobnumber());
         runningreg=0;

         jobTable->findjob(currentlyrunning->getjobnumber())->settimejobstopped(p[5]);
         jobTable->findjob(currentlyrunning->getjobnumber())->setcputimeused();
         jobTable->findjob(currentlyrunning->getjobnumber())->settimeslice();

          sortqueue(readyqueue);
       }

       diskbusy=0;

      jobTable->findjob(currentlyinio->getjobnumber())->decrementiopending();

      jobTable->findjob(currentlyinio->getjobnumber())->setlatchedbit(0);

      if(jobTable->findjob(currentlyinio->getjobnumber())->getiopending()==0){
                      
        if(currentlyinio->getblockedbit()==1){
          jobTable->findjob(currentlyinio->getjobnumber())->setblockedbit(0);

          if(currentlyinio->getterminatebit()==1){

             freespacetable->freememory(currentlyinio->getlocation(),currentlyinio->getjobsize());
             jobTable->removejob(currentlyinio->getjobnumber());
         }
         else if(currentlyinio->getterminatebit()==0){

                   sortqueue(readyqueue);

                  if(!blockedlist->empty()){
                   blockedlist->remove(currentlyinio->getjobnumber());
                   readyqueue->push(currentlyinio->getjobnumber());

                   sortqueue(readyqueue);
                  }

         }
        }
        else if(currentlyinio->getblockedbit()==0){  
          if(currentlyinio->getterminatebit()==1){

          long aaa,aaa1=-1;

          aa=currentlyrunning->getjobnumber();
          aaa=currentlyindrum->getjobnumber();
          if(!drumqueue->empty())aaa1=drumqueue->top();

             freespacetable->freememory(currentlyinio->getlocation(),currentlyinio->getjobsize());

              jobTable->removejob(currentlyinio->getjobnumber());

            if(drumbusy==1 && aaa!=currentlyindrum->getjobnumber()){

              currentlyindrum=jobTable->findjob(aaa);

            }

         }
         else if(currentlyinio->getterminatebit()==0){
         }
        }
      }
      else if(jobTable->findjob(currentlyinio->getjobnumber())->getiopending()>0){

      }

       long aaaa;

       while(!waitinglist->empty()){
         aaaa=waitinglist->front();
         waitinglist->pop_front();
         if(jobTable->findjob(aaaa)->getincorebit()==0){
           swapper(aaaa);
           break;
         }
         else continue;
       }

       priority_queue<long,vector<long>,SortQueueDisk > *tdiskqueue;
       tdiskqueue=new priority_queue<long,vector<long>,SortQueueDisk>();

      long a9,a5=-1;
   while( !diskqueue->empty()){

        currentlyinio=jobTable->findjob(diskqueue->top());

       if(currentlyinio->getintransitbit()==1){break;

       }
       else if(currentlyinio->getincorebit()==0){

             if(currentlyinio->getjobnumber()==d){a5=diskqueue->top();diskqueue->pop();continue;}
             if(currentlyinio->getjobnumber()==c  && aa==b){a5=diskqueue->top();diskqueue->pop();continue;}

             swapper(currentlyinio->getjobnumber());
             break;
       }
       else if(currentlyinio->getincorebit()==1){

                               currentlyinio->setlatchedbit(1);

                                jobTable->findjob(diskqueue->top())->setlatchedbit(1);

                                   diskqueue->pop();

                         diskbusy=1;
                          siodisk(currentlyinio->getjobnumber());
                          break;
       }
      }if(a5>=0)diskqueue->push(a5);

         scheduler(a,p);

      os_dispatcher(a,p,valueofa);

     return ;
}
