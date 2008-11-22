//Waseem Ilahi                        /*The Crint function*/

//This method is also one of the required functions.

void Crint(long* a,long* p){

       long aa2,aa3;

  //At this point  I am saving the running job, if any?

       if(runningreg==1){
         readyqueue->push(currentlyrunning->getjobnumber());
         runningreg=0;

         jobTable->findjob(currentlyrunning->getjobnumber())->settimejobstopped(p[5]);
         jobTable->findjob(currentlyrunning->getjobnumber())->setcputimeused();
         jobTable->findjob(currentlyrunning->getjobnumber())->settimeslice();
       }

       if(p[1]>1){aa2=currentlyindrum->getjobnumber();aa3=currentlyinio->getjobnumber();}

       //The job is being added to the jobtable.
       jobTable->addjob(p[1],p[2],p[3],p[4],p[5]);

       if(p[1]>1 && drumbusy==1)if(aa2!=currentlyindrum->getjobnumber()){
         currentlyindrum=jobTable->findjob(aa2);
       }

       if(p[1]>1 && diskbusy==1)if(aa3!=currentlyinio->getjobnumber()){
         currentlyinio=jobTable->findjob(aa3);
       }

       //The swapper is being called to swap this job in the memory if possible.
       swapper(p[1]);

       //The scheduler runs the jobs at the head of the ready queue.
       scheduler(a,p);

       //The dispatcher sets the values of the control variables.
       os_dispatcher(a,p,valueofa);

   //The dummy return.
	 return ;
}