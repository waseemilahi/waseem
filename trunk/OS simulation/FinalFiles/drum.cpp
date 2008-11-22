//Waseem Ilahi               /*The drum function*/

//The previously mentioned drum function.This function looks for a job that needs
// the drum/memory swap and does that, if the  drum is not busy.
void drum(){

  if(!drumqueue->empty() && drumbusy==0){    

        long aaaaa=-1;
        if(jobTable->findjob(drumqueue->top())->getlatchedbit()==1){
           aaaaa=diskqueue->top();diskqueue->pop();
        }

         if(!drumqueue->empty()){
          currentlyindrum=jobTable->findjob(drumqueue->top());
          drumqueue->pop(); 

          jobTable->findjob(currentlyindrum->getjobnumber())->setintransitbit(1);

          if(currentlyindrum->getincorebit()==0)corememory=0;
          else corememory=1;
          drumbusy=1;

          siodrum(currentlyindrum->getjobnumber(),currentlyindrum->getjobsize(),
                  currentlyindrum->getlocation(),corememory);
         }
         if(aaaaa!=-1)drumqueue->push(aaaaa);
      }
}