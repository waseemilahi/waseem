 //Waseem Ilahi
/*This files includes the files that declare and define the Job Table and the
  FreeSpace Table for the simulation. It also declares the global variables used
  and the queues as well as the function prototypes.*/

# ifndef DECLARATIONS_H
# define DECLARATIONS_H

# include "JobTable.h"
# include "FreeSpaceTable.h"
# include <stack>
# include <list>

using namespace std;

/*prototypes for the required functions*/

//Prototype for the CPU scheduler
void scheduler(long*,long*);
//Prototype for the swapper
void swapper(long);
//Prototype for the 2nd level swapper.
void swapout(long);
//Prototype for the method used to manipulate the drum at occasions.
void drum(void);
//Prototype for function used to call siodisk.
void disk(void);
//Prototype for the dispatcher that sets the control variables.
void os_dispatcher(long*,long*,long);
//Prototype for the method used to remove the jobs from the ready queue.
void removenotready(long);

//Prototypes for the SOS functions called by the OS.
void ontrace(void);
void offtrace(void);
void siodrum(long,long,long,long);
void siodisk(long);

//global variables.

//The flags used in the simulation.
int drumbusy;
int diskbusy;
int jobmoving;
int flag1;
long runningreg;
long drumreg;
int nospace;
long readyqueuepoped;
long waitdrum;
int  waitdrumready;
long corememory;

//variable used to set the value of control variable a.
long valueofa;

//The registers used for the jobs that are currently manipulated.
Job* currentlyinio;
Job* jobwithnospace;
Job* currentlyindrum;
Job* currentlyrunning;

//Declaration of job table.
JobTable *jobTable;

//The free space table.
FreeSpaceTable *freespacetable;

//The extras.
list<long> *blockedlist,*waitinglist;

//The criterians for sorting the priority queues used in the simulation.

class SortQueue {

               public:
                SortQueue::~SortQueue(){}
                SortQueue::SortQueue(){}

                bool operator()(long l1,long l2)const{

                 long t1=(jobTable->findjob(l1))->gettimeslice();
                 long t2=(jobTable->findjob(l2))->gettimeslice();

                 return t1>t2;
                }
};

class SortQueueDrum {

               public:
                SortQueueDrum::~SortQueueDrum(){}
                SortQueueDrum::SortQueueDrum(){}

                bool operator()(long l1,long l2)const{

                 unsigned t1=(jobTable->findjob(l1))->getincorebit();
                 unsigned t2=(jobTable->findjob(l2))->getincorebit();

                 return t1<t2;
                }
};

class SortQueueDisk {

               public:
                SortQueueDisk::~SortQueueDisk(){}
                SortQueueDisk::SortQueueDisk(){}

                bool operator()(long l1,long l2)const{

                 return jobTable->findjob(l1)->getincorebit()<jobTable->findjob(l2)->getincorebit();
                }
};

//The priority queues.
priority_queue<long,vector<long>,SortQueue > *readyqueue;
priority_queue<long,vector<long>,SortQueueDrum > *drumqueue;
priority_queue<long,vector<long>,SortQueueDisk > *diskqueue;

//Prototypes for the sort methods for the three queues.
void sortqueue(priority_queue<long,vector<long>,SortQueue >*);
void sortqueue(priority_queue<long,vector<long>,SortQueueDrum >*);
void sortqueue(priority_queue<long,vector<long>,SortQueueDisk >*);

# endif
