                       /*include header fles*/

# ifndef DECLARATIONS_H
# define DECLARATIONS_H

# include "JobTable.h"
# include "FreeSpaceTable.h"
# include <stack>
# include <list>

using namespace std;

/*prototypes for the required functions*/

void scheduler(long*,long*);
void swapout(long);
void swapper(long);
void drum(void);
void disk(void);
void ontrace();
void offtrace();
void siodisk(long);
void siodrum(long,long,long,long);
void os_dispatcher(long*,long*,long);
void removenotready(long);


//global variables.

int drumbusy;
int diskbusy;

long valueofa;

int jobmoving;
int flag1;

long runningreg;
long drumreg;
int nospace;

long readyqueuepoped;
long waitdrum;
int  waitdrumready;
long corememory;

Job* currentlyinio;
Job* jobwithnospace;
Job* currentlyindrum;
Job* currentlyrunning;

JobTable *jobTable;

FreeSpaceTable *freespacetable;

list<long> *blockedlist,*waitinglist;

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

priority_queue<long,vector<long>,SortQueue > *readyqueue;
priority_queue<long,vector<long>,SortQueueDrum > *drumqueue;
priority_queue<long,vector<long>,SortQueueDisk > *diskqueue;

void sortqueue(priority_queue<long,vector<long>,SortQueue >*);
void sortqueue(priority_queue<long,vector<long>,SortQueueDrum >*);
void sortqueue(priority_queue<long,vector<long>,SortQueueDisk >*);



# endif
