                                /* The Tro function*/

void Tro(long* a,long* p){

         if(runningreg==1){
         readyqueue->push(currentlyrunning->getjobnumber());
         runningreg=0;

         jobTable->findjob(currentlyrunning->getjobnumber())->settimejobstopped(p[5]);
         jobTable->findjob(currentlyrunning->getjobnumber())->setcputimeused();
         jobTable->findjob(currentlyrunning->getjobnumber())->settimeslice();

         sortqueue(readyqueue);
       }

         long aa,aaa;

         if( jobTable->findjob(currentlyrunning->getjobnumber())->getiopending()<=0 ){
              readyqueue->pop();

         freespacetable->freememory(currentlyrunning->getlocation(),currentlyrunning->getjobsize());

         aa=currentlyinio->getjobnumber();
         aaa=currentlyindrum->getjobnumber();

        jobTable->removejob(currentlyrunning->getjobnumber());

         if(diskbusy==1 && aa!=currentlyinio->getjobnumber()){
           if(currentlyinio->getiopending()>0){
             diskqueue->push(currentlyinio->getjobnumber());
           }

           currentlyinio=jobTable->findjob(aa);

         }

         if(drumbusy==1 && aaa!=currentlyindrum->getjobnumber()){

           currentlyindrum=jobTable->findjob(aaa);

         }

           long aaaa;

       if(!waitinglist->empty()){
         aaaa=waitinglist->front();
         waitinglist->pop_front();
          if(jobTable->findjob(aaaa)->getincorebit()==0){
           swapper(aaaa);
         }
       }


         }
         else if(currentlyrunning->getiopending()==1 && currentlyinio->getlatchedbit()==1){
                readyqueue->pop();
                jobTable->findjob(currentlyrunning->getjobnumber())->setterminatebit(1);
         }
         else if(currentlyrunning->getiopending()>0 && currentlyinio->getlatchedbit()==0){
                jobTable->findjob(currentlyrunning->getjobnumber())->setterminatebit(1);
         }

         scheduler(a,p);

         os_dispatcher(a,p,valueofa);

     return ;
}
