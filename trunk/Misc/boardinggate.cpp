//Program # 3 by Waseem Ilahi.
/*This program uses template-classes to board passengers on the plane
  according to their priorities.*/ 
  
# include "priorityqueue.h"

int main(){

    PriorityQueue<char*> *boardingpasses;
    boardingpasses=new PriorityQueue<char*>();
    
    int p;
    int j=0;
    
    char* names;    
    
    PriorityItem<char*> ti;   
    
    cout<<endl<<" Hello! This program will get the names and ticket types."<<endl;
    cout<<endl<<" It will then print out the names of the passengers in order."<<endl;
    cout<<endl<<" First class passengers, followed by bussiness and economy class."<<endl;
    cout<<" ----------------------------------------------------------------"<<endl;   
    
      do{ 
         cout<<endl<<" Enter the priority for the passenger. It is as follows."<<endl;
         cout<<endl<<" Enter 10 for first class, 5 for bussiness and 2 for coach passenger. "<<endl;
         cout<<endl<<" Or enter 0 to stop execution: ";   
         
         cin>>p; 
         
         cout<<endl<<" --------------------------------"; 
    
         if(p!=10){
           if(p!=5){
             if(p!=2){
               continue;
             }
           }
         } 
    
         j++; //To show if there was any passenger or not. 
         
         names=new char[50];
         
         cout<<endl<<" Please enter the name of the passenger."<<endl;
         cout<<endl<<" The format of the name must be Lastname,Firstname: ";
         
         cin>>names;
         
         ti.setvalue(names);//checking whether the PriorityItem class works fine.
         ti.setprty(p);
         
         boardingpasses->insert(ti.getprty(),ti.getvalue());
         
         cout<<endl<<" --------------------------------------------------------------------"<<endl;
        
      }while(p!=0); 
     
    if(j!=0){
      cout<<endl<<" Total # of passengers: "<<j<<endl;
      cout<<endl<<" Names of passengers in the order in which";
      cout<<endl<<" they are going to get on the plane:";
      cout<<endl<<" -----------------------------------------"<<endl;     
      
      while(!boardingpasses->empty()){   
           cout<<endl<<" "<<boardingpasses->remove();
      }        
    }
    else{cout<<endl<<" There are no passengers.";}
    
    cout<<endl<<endl<<" *********";
    cout<<endl<<" Good Bye."<<endl<<endl;    
    
    delete boardingpasses;
    
    system("Pause");

    return 0;
    
}
