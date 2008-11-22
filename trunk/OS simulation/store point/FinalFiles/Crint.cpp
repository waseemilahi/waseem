                                 /*The Crint function*/


void Crint(long* a,long* p){

       long aa2,aa3;

       if(runningreg==1){
         readyqueue->push(currentlyrunning->getjobnumber());
         runningreg=0;

         jobTable->findjob(currentlyrunning->getjobnumber())->settimejobstopped(p[5]);
         jobTable->findjob(currentlyrunning->getjobnumber())->setcputimeused();
         jobTable->findjob(currentlyrunning->getjobnumber())->settimeslice();
       }

       if(p[1]>1){aa2=currentlyindrum->getjobnumber();aa3=currentlyinio->getjobnumber();}

       jobTable->addjob(p[1],p[2],p[3],p[4],p[5]);

       if(p[1]>1 && drumbusy==1)if(aa2!=currentlyindrum->getjobnumber()){
         currentlyindrum=jobTable->findjob(aa2);
       }

       if(p[1]>1 && diskbusy==1)if(aa3!=currentlyinio->getjobnumber()){
         currentlyinio=jobTable->findjob(aa3);
       }

       swapper(p[1]);

       scheduler(a,p); 

       os_dispatcher(a,p,valueofa);

	 return ;
}