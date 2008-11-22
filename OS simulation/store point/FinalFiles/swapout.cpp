                               /*The swapper function*/

void swapout(long jn){

   int space_found=0;

        unsigned int k=0;

        FreeSpace tmp1;

        long j;  long a11=-1;

        int i=0,l1=-1;
      
       while(i<jobTable->getsize()){
         if( jobTable->getjobs()->at(i).getjobsize()>=jobTable->findjob(jn)->getjobsize()&& jobTable->getjobs()->at(i).getincorebit()==1
           && jobTable->getjobs()->at(i).getmemoryavailablebit()==0 ){

             if(jobTable->getjobs()->at(i).getintransitbit()==0
                && jobTable->getjobs()->at(i).getlatchedbit()==0 && jobTable->getjobs()->at(i).gettimeslice()>jobTable->findjob(jn)->gettimeslice()){

                 freespacetable->freememory(jobTable->getjobs()->at(i).getlocation(),jobTable->getjobs()->at(i).getjobsize());

                 drumqueue->push(jobTable->getjobs()->at(i).getjobnumber());

                 sortqueue(drumqueue);

                jobTable->findjob(jobTable->getjobs()->at(i).getjobnumber())->setmemoryavailablebit(1);

                 if(drumbusy==0)l1=1;
                 else l1=0;

                        drum();

                 a11=freespacetable->allocatememory(jobTable->findjob(jn)->getjobsize());

                 if(a11>=0){
                   jobTable->findjob(jn)->setlocation(a11);
                   jobTable->findjob(jn)->setmemoryavailablebit(0);
                   drumqueue->push(jn);

                   jobTable->findjob(jn)->setmemoryavailablebit(0);

                   sortqueue(drumqueue);
                 }
                 else if(a11=-1){

                        if(!diskqueue->empty()){if(jn!=diskqueue->top())waitinglist->push_front(jn);}
                        else if(diskqueue->empty()){waitinglist->push_front(jn);}
                 }

                 if(l1==1)removenotready(jobTable->getjobs()->at(i).getjobnumber());

                 sortqueue(readyqueue);
                 flag1=1; space_found=1;
               break;
             }
             else if(jobTable->getjobs()->at(i).getlatchedbit()==1 ){
                   i++; flag1=0;  space_found=0;
                    continue;

             }
         }
         else if(jobTable->getjobs()->at(i).getjobsize()<jobTable->findjob(jn)->getjobsize() && jobTable->getjobs()->at(i).getincorebit()==1
                 && jobTable->getjobs()->at(i).getmemoryavailablebit()==0 ){

                 if(jobTable->getjobs()->at(i).getintransitbit()==0
                   && jobTable->getjobs()->at(i).getlatchedbit()==0 && jobTable->getjobs()->at(i).gettimeslice()>jobTable->findjob(jn)->gettimeslice()){

                   while(k<freespacetable->getmytable()->size()){

                         tmp1=freespacetable->getmytable()->at(k);

                         if(freespacetable->getmytable()->size()==1){

                          if(tmp1.getaddress()+tmp1.getsize()==jobTable->getjobs()->at(i).getlocation()){
                             j=tmp1.getsize()+jobTable->getjobs()->at(i).getjobsize();

                           if(j>=jobTable->findjob(jn)->getjobsize()){

                           freespacetable->freememory(jobTable->getjobs()->at(i).getlocation(),jobTable->getjobs()->at(i).getjobsize());

                              drumqueue->push(jobTable->getjobs()->at(i).getjobnumber());

                                sortqueue(drumqueue);

                                jobTable->findjob(jobTable->getjobs()->at(i).getjobnumber())->setmemoryavailablebit(1);

                                if(drumbusy==0)l1=1;
                                else l1=0;

                                drum();

                                if(!diskqueue->empty()){if(jn!=diskqueue->top())waitinglist->push_front(jn);}
                                           else if(diskqueue->empty()){waitinglist->push_front(jn);}

                                 if(l1==1)removenotready(jobTable->getjobs()->at(i).getjobnumber());

                                 sortqueue(readyqueue); flag1=1; space_found=1;
                           }
                          }
                           else if(jobTable->getjobs()->at(i).getlocation()+jobTable->getjobs()->at(i).getjobsize()==tmp1.getaddress()){
                                   j=tmp1.getsize()+jobTable->getjobs()->at(i).getjobsize();

                                    if(j>=jobTable->findjob(jn)->getjobsize()){

                                         freespacetable->freememory(jobTable->getjobs()->at(i).getlocation(),jobTable->getjobs()->at(i).getjobsize());

                                          drumqueue->push(jobTable->getjobs()->at(i).getjobnumber());

                                          sortqueue(drumqueue);

                                          jobTable->findjob(jobTable->getjobs()->at(i).getjobnumber())->setmemoryavailablebit(1);

                                          if(drumbusy==0)l1=1;
                                          else l1=0;

                                             drum();

                                         if(!diskqueue->empty()){if(jn!=diskqueue->top())waitinglist->push_front(jn);}
                                           else if(diskqueue->empty()){waitinglist->push_front(jn);}

                                             if(l1==1)removenotready(jobTable->getjobs()->at(i).getjobnumber());

                                           sortqueue(readyqueue); flag1=1; space_found=1;

                                   }
                           }
                            break;
                         }

                        else if(k==freespacetable->getmytable()->size()-1){

                               if(tmp1.getaddress()+tmp1.getsize()==jobTable->getjobs()->at(i).getlocation()){
                                   j=tmp1.getsize()+jobTable->getjobs()->at(i).getjobsize();

                                  if(j>=jobTable->findjob(jn)->getjobsize()){

                                         freespacetable->freememory(jobTable->getjobs()->at(i).getlocation(),jobTable->getjobs()->at(i).getjobsize());

                                          drumqueue->push(jobTable->getjobs()->at(i).getjobnumber());

                                         sortqueue(drumqueue);

                                         jobTable->findjob(jobTable->getjobs()->at(i).getjobnumber())->setmemoryavailablebit(1);

                                         if(drumbusy==0)l1=1;
                                         else l1=0;

                                             drum();

                                    if(!diskqueue->empty()){if(jn!=diskqueue->top())waitinglist->push_front(jn);}
                                           else if(diskqueue->empty()){waitinglist->push_front(jn);}

                                    if(l1==1)removenotready(jobTable->getjobs()->at(i).getjobnumber());

                                        sortqueue(readyqueue); flag1=1;    space_found=1;

                                     }
                                 }
                                 else if(jobTable->getjobs()->at(i).getlocation()+jobTable->getjobs()->at(i).getjobsize()==tmp1.getaddress()){
                                   j=tmp1.getsize()+jobTable->getjobs()->at(i).getjobsize();

                                    if(j>=jobTable->findjob(jn)->getjobsize()){

                                         freespacetable->freememory(jobTable->getjobs()->at(i).getlocation(),jobTable->getjobs()->at(i).getjobsize());

                                          drumqueue->push(jobTable->getjobs()->at(i).getjobnumber());

                                          sortqueue(drumqueue);

                                          jobTable->findjob(jobTable->getjobs()->at(i).getjobnumber())->setmemoryavailablebit(1);

                                          if(drumbusy==0)l1=1;
                                          else l1=0;

                                              drum();

                                    if(!diskqueue->empty()){if(jn!=diskqueue->top())waitinglist->push_front(jn);}
                                           else if(diskqueue->empty()){waitinglist->push_front(jn);}

                                       if(l1==1)removenotready(jobTable->getjobs()->at(i).getjobnumber());

                                           sortqueue(readyqueue);flag1=1;  space_found=1;
                                    }
                                 }
                                   break;
                        }
                        else if(k<freespacetable->getmytable()->size()-1){

                                if(tmp1.getaddress()+tmp1.getsize()==jobTable->getjobs()->at(i).getlocation()){
                                   j=tmp1.getsize()+jobTable->getjobs()->at(i).getjobsize();

                                  if(j>=jobTable->findjob(jn)->getjobsize()){

                                         freespacetable->freememory(jobTable->getjobs()->at(i).getlocation(),jobTable->getjobs()->at(i).getjobsize());

                                          drumqueue->push(jobTable->getjobs()->at(i).getjobnumber());

                                         sortqueue(drumqueue);

                                         jobTable->findjob(jobTable->getjobs()->at(i).getjobnumber())->setmemoryavailablebit(1);

                                         if(drumbusy==0)l1=1;
                                          else l1=0;

                                            drum();

                                              if(!diskqueue->empty()){if(jn!=diskqueue->top())waitinglist->push_front(jn);}
                                              else if(diskqueue->empty()){waitinglist->push_front(jn);}

                                         if(l1==1)removenotready(jobTable->getjobs()->at(i).getjobnumber());

                                        sortqueue(readyqueue); flag1=1;  space_found=1;

                                  }
                                  else if(j<jobTable->findjob(jn)->getjobsize()){
                                         if(jobTable->getjobs()->at(i).getlocation()+jobTable->getjobs()->at(i).getjobsize()==freespacetable->getmytable()->at(k+1).getaddress()){
                                           j+=freespacetable->getmytable()->at(k+1).getsize();
                                           if(j>=jobTable->findjob(jn)->getjobsize()){

                                               freespacetable->freememory(jobTable->getjobs()->at(i).getlocation(),jobTable->getjobs()->at(i).getjobsize());

                                                drumqueue->push(jobTable->getjobs()->at(i).getjobnumber());

                                                   sortqueue(drumqueue);

                                                   jobTable->findjob(jobTable->getjobs()->at(i).getjobnumber())->setmemoryavailablebit(1);

                                                   if(drumbusy==0)l1=1;
                                                   else l1=0;

                                                  drum();

                                                if(!diskqueue->empty()){if(jn!=diskqueue->top())waitinglist->push_front(jn);}
                                                else if(diskqueue->empty()){waitinglist->push_front(jn);}

                                                if(l1==1)removenotready(jobTable->getjobs()->at(i).getjobnumber());

                                                  sortqueue(readyqueue); flag1=1;   space_found=1;
                                          }
                                         
                                         }
                                  }
                                }
                                else if(jobTable->getjobs()->at(i).getlocation()+jobTable->getjobs()->at(i).getjobsize()==tmp1.getaddress()){
                                       j=tmp1.getsize()+jobTable->getjobs()->at(i).getjobsize();

                                    if(j>=jobTable->findjob(jn)->getjobsize()){

                                         freespacetable->freememory(jobTable->getjobs()->at(i).getlocation(),jobTable->getjobs()->at(i).getjobsize());

                                          drumqueue->push(jobTable->getjobs()->at(i).getjobnumber());

                                          sortqueue(drumqueue);

                                          jobTable->findjob(jobTable->getjobs()->at(i).getjobnumber())->setmemoryavailablebit(1);

                                          if(drumbusy==0)l1=1;
                                          else l1=0;

                                              drum();


                        if(!diskqueue->empty()){if(jn!=diskqueue->top())waitinglist->push_front(jn);}
                        else if(diskqueue->empty()){waitinglist->push_front(jn);}
              
                                            if(l1==1)removenotready(jobTable->getjobs()->at(i).getjobnumber());

                                           sortqueue(readyqueue); flag1=1;     space_found=1;
                                   }
                                }

                             break;
                        }

                        k++;
                   }
                 }
                 else if(jobTable->getjobs()->at(i).getlatchedbit()==1){
                          i++; flag1=0;     space_found=0;
                             continue;

                 }
                 else if(jobTable->getjobs()->at(i).getincorebit()==0){
                          i++;flag1=0; space_found=0;
                             continue;

                 }
                 else if(jobTable->getjobs()->at(i).getmemoryavailablebit()==1){
                        i++;flag1=0;space_found=0;
                        continue;
                 }


         }
              if(space_found==1)break;

             i++;
       }

        if(flag1==0){nospace=1;

                                if(!diskqueue->empty()){if(jn!=diskqueue->top())waitinglist->push_back(jn);}
                                else if(diskqueue->empty()){waitinglist->push_back(jn);}
        }
        else if(flag1==1){nospace=0;}

       return ;
}
