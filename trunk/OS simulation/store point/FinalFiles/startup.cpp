                        /*The startup function*/

void startup(){

     drumbusy=0;
     diskbusy=0;

     corememory=0;
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

     ontrace();

     return ;
}