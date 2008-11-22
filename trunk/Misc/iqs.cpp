//Program # 2 by Waseem Ilahi.
//This program uses a template-class to do some actions on storing and maintaining iqs. 

# include "dynamiclist.h"

int main(){

   DynamicList<int> *iqs;
   iqs=new DynamicList<int>();
   
   DynamicList<float> *halfiqs;
   halfiqs=new DynamicList<float>();

   float mean=0.0;
   float halfinputiq;
   int min=2000;
   int max=0;
   int inputiq;
   int index=0;
   int i=0;
   int j=0;
   int k=0;     
   
   cout<<endl<<" Hello. This program records the iqs and stores them."<<endl;
   cout<<" It also finds the minimum , maximum and average iqs."<<endl;
   cout<<" ----------------------------------------------------"<<endl;
   
   cout<<" Enter an iq or -1 to exit: ";
   cin>>inputiq;
   
   while(inputiq>=0){
	    j=1; // For dealing with the special case to avoid {mean/0} problem.
		  
        iqs->set(index,inputiq);
		
        index++;
        
		cout<<endl<<" Enter an iq or -1 to exit: ";
		cin>>inputiq;
	}
	
	if(j==1){
//Now to check get method.    
    cout<<endl<<" The last score entered is: "<<iqs->get(index-1)<<endl;

//Calculating min,max,mean:    
	  for(i=0;i<iqs->getsize();i++){
	     mean+=iqs->get(i);
	     if(iqs->get(i)<min){
		   min=iqs->get(i);
	     }
	     if(iqs->get(i)>max){
		   max=iqs->get(i);
	     }
	  }

	  mean=(int)mean/iqs->getsize();
  }  
	
//Outputs.

    cout<<endl<<" *************************"<<endl;
	cout<<" There is/are "<<iqs->getsize()<<" score(s)."<<endl;
	cout<<" Minimum score = "<<min<<endl;
	cout<<" Maximum score = "<<max<<endl;
	cout<<" Average score = "<<mean<<endl;
	cout<<" *************************"<<endl<<endl;
	
//Checking insert and remove methods.

 if(j==1){  
   cout<<" The scores are: {";
   for(i=0;i<iqs->getsize();i++){
      cout<<"  "<<iqs->get(i);
   }
   cout<<"  }"<<endl;
   
   cout<<endl<<" Enter the position where you want to insert another score: ";
   cin>>k;
   cout<<endl<<" Now enter the score you want to insert: ";
   cin>>inputiq;
   
   iqs->insert(k-1,inputiq);
   
   cout<<endl<<" Scores after insertion of one more score: {";
   for(i=0;i<iqs->getsize();i++){
      cout<<"  "<<iqs->get(i);
   }
   cout<<"  }"<<endl;
   
   cout<<endl<<" Enter the position from where you want to remove the score: ";
   cin>>k;
   
   iqs->remove(k-1);
   
   cout<<endl<<" Scores after removal of one score: {";
   for(i=0;i<iqs->getsize();i++){
      cout<<"  "<<iqs->get(i);
   }
   cout<<"  }"<<endl;
   
//To check whether the template for float type works or not
   cout<<endl<<" **********************************************************"<<endl;
   cout<<endl<<" The half-iqs are: {";

   for(i=0;i<iqs->getsize();i++){
      halfiqs->set(i,iqs->get(i)/2.0);
      cout<<"  "<<halfiqs->get(i);
   }
   cout<<"  }"<<endl;
   
//Checking insert method for floats.
   cout<<endl<<" Enter the position where you want to insert another half-iq: ";
   cin>>k;
   cout<<endl<<" Now enter the half-iq you want to insert: ";
   cin>>halfinputiq;
   
   halfiqs->insert(k-1,halfinputiq);
   
   cout<<endl<<" Half-iqs after insertion of one score: {";
   
   for(i=0;i<halfiqs->getsize();i++){
      cout<<"  "<<halfiqs->get(i);
   }
   cout<<"  }"<<endl;

//Checking remove method for floats.   
   cout<<endl<<" Enter the position from where you want to remove the half-iq: ";
   cin>>k;
   
   halfiqs->remove(k-1);
   
   cout<<endl<<" Half-iqs after removal of one score: {";
   
   for(i=0;i<halfiqs->getsize();i++){
      cout<<"  "<<halfiqs->get(i);
   }
   cout<<"  }"<<endl;
       
 }
   cout<<endl<<" Good Bye."<<endl<<endl;
   
   system("Pause");
   
   return 0;
   
}

