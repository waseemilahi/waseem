# ifndef JOB_H
# define JOB_H

# include <stdio.h>

//Declaration of the class Job.

class Job{

		public:
             //The constructors
				 Job();
             Job(long jobnum,long prty,long size,long maxtime,long currenttime);

      		 // The accessors and mutators.

             long getjobsize();
             void setjobsize(long size);

             long getjobnumber();
             void setjobnumber(long jbnumber);

             long getpriority();
             void setpriority(long prty);

             long getlocation();
             void setlocation(long location);

             long getmaxcputime();
             void setmaxcputime(long cputime);

             long getiopending();
             void setiopending(long iopending);

             long gettimearrived();
             void settimearrived(long currenttime);

             long getcputimeused();
             void setcputimeused();

             long gettimejobstopped();
             void settimejobstopped(long currenttime);

             long gettimejobran();
             void settimejobran(long currenttime);

             long gettimeslice();
             void settimeslice();

             unsigned getincorebit();
             void setincorebit(unsigned incore);

             unsigned getlatchedbit();
             void setlatchedbit(unsigned latch);

             unsigned getblockedbit();
             void setblockedbit(unsigned blocked);

             unsigned getterminatebit();
             void setterminatebit(unsigned term);

             unsigned getreadybit();
             void setreadybit(unsigned ry);

             unsigned getwaitingbit();
             void setwaitingbit(unsigned waiting);

             unsigned getintransitbit();
             void setintransitbit(unsigned moving);

              void incrementiopending();
              void decrementiopending();

              void setmemoryavailablebit(unsigned mab);
              unsigned getmemoryavailablebit();


      private:

             // The fields.

             long size;
             long jobnumber;
             long priority;
             long location_in_memory;
             long max_cpu_time;
             long io_pending;
             long time_arrived; //First time in the system.
             long cpu_time_used;
             long time_slice;

             long time_job_ran;
             long time_job_stopped;

             struct flags{
                          unsigned incore: 1;
                          unsigned memoryavailable: 1;
                          unsigned latched: 1;
                          unsigned blocked: 1;
                          unsigned term: 1;
                          unsigned ready: 1;
                          unsigned wait_io: 1;
                          unsigned intransit: 1;

                          }flagbits;
};//end of class declaration.

/*Methods definitions.
  --------------------*/

/*The constructors*/

Job::Job(){

       Job(-1,0,0,0,0);
}

Job::Job(long jn,long prty,long size,long maxtime,long currenttime){

        setjobsize(size);
        setjobnumber(jn);
        setpriority(prty);
        setmaxcputime(maxtime); 
        settimearrived(currenttime);
        this->cpu_time_used=0;

}

/*The accessors.
  --------------*/
long Job::getjobsize(){ return this->size; }

long Job::getjobnumber(){ return this->jobnumber; }

long Job::getpriority(){ return this->priority; }

long Job::getlocation(){ return this->location_in_memory; }

long Job::getmaxcputime(){ return this->max_cpu_time; }

long Job::gettimearrived(){ return this->time_arrived; }

long Job::getiopending(){ return this->io_pending; }

long Job::gettimejobran(){ return this->time_job_ran; }

long Job::gettimejobstopped(){ return this->time_job_stopped; }

long Job::getcputimeused(){ return this->cpu_time_used; }

long Job::gettimeslice(){ return this->time_slice; }

unsigned Job::getincorebit(){ return this->flagbits.incore; }

unsigned Job::getlatchedbit(){ return this->flagbits.latched; }

unsigned Job::getblockedbit(){ return this->flagbits.blocked; }

unsigned Job::getterminatebit(){ return this->flagbits.term; }

unsigned Job::getreadybit(){ return this->flagbits.ready; }

unsigned Job::getwaitingbit(){ return this->flagbits.wait_io; }

unsigned Job::getintransitbit(){ return this->flagbits.intransit; }

unsigned Job::getmemoryavailablebit(){ return this->flagbits.memoryavailable; }

/*The mutators.
  -------------*/

void Job::setjobnumber(long jbnumber){

			this->jobnumber=jbnumber;

         return ;
}
void Job::setjobsize(long jbsize){

			this->size=jbsize;

         return ;
}
void Job::setpriority(long prty){

			this->priority=prty;

         return ;
}
void Job::setlocation(long location){

			this->location_in_memory=location;

         return ;
}
void Job::setmaxcputime(long maxcpu){

			this->max_cpu_time=maxcpu;

         return ;
}
void Job::setiopending(long iop){

			this->io_pending=iop;

         return ;
}
void Job::settimearrived(long currenttime){

			this->time_arrived=currenttime;

         return ;
}

void Job::settimejobstopped(long currenttime){

           this->time_job_stopped=currenttime;

           return ;
}

void Job::settimejobran(long currenttime){

           this->time_job_ran=currenttime;

           return ;
}

void Job::setcputimeused(){

			this->cpu_time_used=this->cpu_time_used+(this->time_job_stopped-time_job_ran);

         return ;
}
void Job::settimeslice(){

			this->time_slice=(this->max_cpu_time)-(this->cpu_time_used);;

         return ;
}
void Job::setincorebit(unsigned icb){

			this->flagbits.incore=icb;

         return ;
}
void Job::setlatchedbit(unsigned lb){

			this->flagbits.latched=lb;

         return ;
}
void Job::setblockedbit(unsigned bb){

			this->flagbits.blocked=bb;

         return ;
}
void Job::setterminatebit(unsigned tb){

			this->flagbits.term=tb;

         return ;
}
void Job::setreadybit(unsigned rdy){

     this->flagbits.ready=rdy;

     return ;
}
void Job::setmemoryavailablebit(unsigned mab){

       this->flagbits.memoryavailable=mab;

       return ;
}
void Job::setwaitingbit(unsigned wiob){

       this->flagbits.wait_io=wiob;

       return ;
}
void Job::setintransitbit(unsigned intb){

       this->flagbits.intransit=intb;

       return ;
}

void Job::incrementiopending(){this->io_pending++;}

void Job::decrementiopending(){this->io_pending--;}

# endif