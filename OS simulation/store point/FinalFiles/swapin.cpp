
void swapper(long jn){

          long a9;

               a9=freespacetable->allocatememory(jobTable->findjob(jn)->getjobsize());

             if(a9>=0){

               jobTable->findjob(jn)->setlocation(a9);
               jobTable->findjob(jn)->setmemoryavailablebit(0);

                if(drumbusy==0){
                            jobTable->findjob(jn)->setintransitbit(1);
                           currentlyindrum=jobTable->findjob(jn);

                          if(currentlyindrum->getincorebit()==0)corememory=0;
                          else corememory=1;
                          drumbusy=1;

                      siodrum(currentlyindrum->getjobnumber(),currentlyindrum->getjobsize(),currentlyindrum->getlocation(),corememory);
                }
                else if(drumbusy==1){

                             drumqueue->push(jn);

                             sortqueue(drumqueue);

                }
               return;
             }
             else if(a9==-1){
              swapout(jn);
             }              

   return ;
}
