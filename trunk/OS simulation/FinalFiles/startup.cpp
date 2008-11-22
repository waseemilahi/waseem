//Waseem Ilahi                   /*The startup function*/

//This functions is called at the beginning of the simulation by SOS.
//It initializes many of the variables and data structures declared
//in the "declarations.h file.*/

void startup(){

     drumbusy=0;
     diskbusy=0;

     corememory=0;//From core to memory in this case.
     waitdrumready=0;
     readyqueuepoped=0;
     flag1=0;
     jobmoving=0;
     nospace=0;

     runningreg=0;//means there is no job to run.
     drumreg=0;

     jobTable=new JobTable();

     freespacetable=new FreeSpaceTable();

     blockedlist=new list<long>();
     waitinglist=new list<long>();

     readyqueue=new priority_queue<long,vector<long>,SortQueue>();
     drumqueue=new priority_queue<long,vector<long>,SortQueueDrum>();
     diskqueue=new priority_queue<long,vector<long>,SortQueueDisk>();

     //The trace is set to on.
     ontrace();

     return ;
}