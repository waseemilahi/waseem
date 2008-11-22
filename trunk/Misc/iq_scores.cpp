/*
                             Final project by Waseem Ilahi.
                             ------------------------------
                             
  This program uses template classes to do some actions 
  on storing and maintaining iqs.
  It uses the DynamicList class to record the iqs and 
  after finding the frequency stores them in the 
  Priority Queue using the PriorityQueue and PriorityItem
  classes. So, it basically makes use of three classes or 
  two data structures. The selection of DynamicList class
  is due to the reason that the data entered will be of the
  reasonably normal size, and therefore the reading operations
  will be performed quickly and we will save time.
  
*/   

//This includes the header files for all the classes required.
# include "priorityqueue.h"

/*
  The main function.
  ******************
*/

int main(){

//Variable declarations.
//----------------------

//Realizing the "DynamicList" template.
   DynamicList<char*> *iqs;
   iqs=new DynamicList<char*>();
   
//Realizing the "PriorityItem" template.
   PriorityItem<char*> ti;

//Realizing the "PriorityQueue" template.   
    PriorityQueue<char*> *uniqueiq;
    uniqueiq=new PriorityQueue<char*>();
 
//Other variables.     
   char* inputiq;
   int index=0;
   int count;
 
//Welcoming the user and giving the initial prompt.   
       
   cout<<endl<<" Hello. This program records the iqs and stores them."<<endl;
   cout<<" It also prints them in order from most frequent to least."<<endl;
   cout<<" ---------------------------------------------------------"<<endl;
   
   cout<<" Enter an iq, quit to exit: "<<endl<<endl<<"   ";
   inputiq=new char[10];
   cin>>inputiq;
   
//Storing the info in the DynamicList and cheching the 'EXIT' condition.   
   
   while(strcmp(inputiq,"quit")!=0){
		  
        iqs->set(index,inputiq);
		
        index++;
        
        cout<<endl<<"   ";
        
        inputiq=new char[10];
		cin>>inputiq;
	}//end while.
		
//Storing the iqs and the frequency as a Priority Queue.

/*This part of the code checks and stores the 
  unique iq scores in the priority queue.*/
  
/*****************************************/
   for(int i=0;i<iqs->getsize();i++){
/*We need to do the following for every iteration.*/
      count=1; 
/*This loop checks for the duplicates and counts them.*/   
      for(int idx=i+1;idx<iqs->getsize();idx++){
         if(strcmp(iqs->get(idx),iqs->get(i))==0){
/*The following statement will disturb the "iqs" list but it is needed 
  to store iqs into priority queue "uniqueiqs", with out errors, as it removes 
  the dublicate iqs from the list.*/
           iqs->remove(idx);
           count++;
         }//end if.
      }//end for.
/*Using PriorityItem class as an intermediate source.*/
      ti.setvalue(iqs->get(i));
      ti.setprty(count);       
/*Assigning the Priorities and the values to the priority queue.*/
      uniqueiq->insert(ti.getprty(),ti.getvalue());                 
   } //end the "transfer process" loop.   
/*****************************************/

//Final Output.

//Total valid iqs entered by the user.
   cout<<endl<<" You Entered "<<index<<" Scores."<<endl;
   
//Handling the special case, i.e., Whether the user entered any valid iq or not.   
   if(iqs->getsize()>0){
//Total number of unique iqs, i.e., the iqs in the priority queue (uniqueiqs).
     cout<<endl<<" "<<uniqueiq->getsize()<<" unique IQ(s), most frequent to least:"<<endl;
//This prints the unique iqs and their frequencies. 
     while(!uniqueiq->empty()){
          cout<<endl<<"   "<<uniqueiq->remove()<<" - "<<uniqueiq->getfrequency()<<endl;
     }//end while.            
   }//end if.
   
   
   //Last message from the programmer.
   cout<<endl<<" Good Bye."<<endl<<endl;  
   
   system("Pause");
   
//Freeing the space allocated dynamically on the heap.   
   delete uniqueiq;
   delete iqs;
   delete inputiq;
   
   return 0;
   
}
