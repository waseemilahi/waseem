//Waseem Ilahi

# ifndef JOBTABLE_H
# define JOBTABLE_H

//Including the header file required for the job table.
# include <vector>
# include "Job.h"

using namespace std;


//Declaration of the class "JobTable".

class JobTable{

		public:
      		 /*This method is a constructor. It initiates the JobTable.
               It takes no arguements and has no return type.*/
             JobTable();

             /*This method is a destructor. It has no parameters and
               no return type. Its job is to free the memory allocated by
               JobTable.*/
             ~JobTable();

             /*get size of jobtable, meaning how many jobs are in it.*/
             long getsize();

             /*This method inserts a job into the job table*/
             void addjob(long jobnum,long prty,long size,long maxtime,long currenttime);

             /*This method removes the job from the job table. Returns 1 if
               successful and 0 if not*/
             int removejob(long jobnum);

             /*This method returns the reference to the job in the job table
               and if the job is not found it returns NULL pointer.*/
             Job* findjob(long jobnum);

             vector<Job>* getjobs();

      private:

      	     vector<Job> *jobs;
              long size;
}; //end of class declaration.

/*Methods definitions.
  --------------------*/

//The constructor.
JobTable::JobTable(){

			this->jobs=new vector<Job>();
         this->size=0;
}

//The destructor.
JobTable::~JobTable(){ delete this->jobs; }

//The getsize method.
long JobTable::getsize(){ return this->size; }

//The insert method.
void JobTable::addjob(long jobnum,long prty,long size,long maxtime,long currenttime){

          Job *newjob=new Job(jobnum,prty,size,maxtime,currenttime);

           newjob->setiopending(0);
           newjob->setmemoryavailablebit(0);
           newjob->setincorebit(0);
           newjob->setlatchedbit(0);
           newjob->setblockedbit(0);
           newjob->setterminatebit(0);
           newjob->setreadybit(1);
           newjob->setintransitbit(0);
           newjob->setwaitingbit(0);
           newjob->settimejobran(0);
           newjob->settimejobstopped(0);
           newjob->setcputimeused();
           newjob->settimeslice();

          this->jobs->push_back(*newjob);

          this->size++;

          return ;

}

//The remove method.
int JobTable::removejob(long jobnum){

               vector<Job>::iterator iter1=this->jobs->begin();

               Job *tmp1;

              while(iter1!=this->jobs->end()){
                    tmp1=iter1;
                    if(tmp1->getjobnumber()==jobnum){

                       this->jobs->erase(iter1);

                      this->size--;
                      return 1;
                    }

                   iter1++;
               }

        return -1;
}

//The find method
Job* JobTable::findjob(long jn){

              Job *tmp1;
                 
              vector<Job>::iterator iter=this->jobs->begin();

              while(iter!=this->jobs->end()){
                   tmp1=iter;

                   if(jn==tmp1->getjobnumber())
                     return iter;

               iter++;
              }
        
        return NULL;
}

//The get "jobs" method.
vector<Job>* JobTable::getjobs(){return this->jobs;}

# endif
