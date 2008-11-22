# ifndef FREESPACETABLE_H
# define FREESPACETABLE_H

//Including the required header files.
# include "FreeSpace.h"
# include <vector>
# include <deque>
# include <queue>

using namespace std;

//Declaration of the class.

class FreeSpaceTable{

		public:

            //The constructor.
      		FreeSpaceTable();

            long getsize();

            //takes one arguement,which is the size of the job it is looking for
            //and returns the address where in the memory where it put that job
            //or -1 if the process was unsuccessful.
            long allocatememory(long size);

            //This method frees the memory specified and resorts the free space table.
            void freememory(long address,long size);

            FreeSpace* findspace(long size);
            vector<FreeSpace> * getmytable()const;

      private:

      		  vector<FreeSpace> *mytable;
              long num_of_entries;

};





/*The method definition.
  ----------------------*/

//The constructor.

FreeSpaceTable::FreeSpaceTable(){

                this->num_of_entries=1;

                this->mytable=new vector<FreeSpace>();

                FreeSpace *newfreespace=new FreeSpace(0,100);

                this->mytable->push_back(*newfreespace);

}

//The getsize method.

long FreeSpaceTable::getsize(){ return this->num_of_entries; }

//Allocate method.

long FreeSpaceTable::allocatememory(long size){
             
               vector<FreeSpace>::iterator iter3=this->mytable->begin();

                 long address1=-1;
                 unsigned int i=0;

                 FreeSpace *tmp1,*tmp2,*tmp3;

                 while(i<this->mytable->size() && iter3!=this->mytable->end()){
                            tmp1=iter3;

                               if(size<=tmp1->getsize()){
                                 address1=tmp1->getaddress();

                                 if(tmp1->getsize()==size){
                                    mytable->erase(iter3);
                                    this->num_of_entries--;

                                 }
                                 else if(tmp1->getsize()>size){

                                      mytable->at(i).setaddress(tmp1->getaddress()+size);
                                      mytable->at(i).setsize(tmp1->getsize()-size);

                                 }
                                  break;
                               }

                     i++;

                     iter3++;
                 }
         
          return address1;

}

//Free Method.

void FreeSpaceTable::freememory(long address1,long size1){

               unsigned int l=0;

               vector<FreeSpace>::iterator iter3=this->mytable->begin();

              FreeSpace tmp2,tmp4;

              int aa=-1;


                               tmp2.setaddress(address1);
                               tmp2.setsize(size1);

                                if(mytable->size()==0){mytable->push_back(tmp2);return;}

                                  while(l<this->mytable->size()){

                                         tmp4=mytable->at(l);

                                         if(mytable->size()==1){
                                           if(tmp2.getaddress()<tmp4.getaddress()){

                                             if(tmp2.getaddress()+tmp2.getsize()==tmp4.getaddress()){
                                             
                                                 mytable->at(l).setaddress(tmp4.getaddress()-size1);
                                                 mytable->at(l).setsize(tmp2.getsize()+tmp4.getsize());

                                             }
                                             else if(tmp2.getaddress()+tmp2.getsize()!=tmp4.getaddress()){
                                                    mytable->insert(iter3,tmp2);

                                             }
                                           }
                                           else if(tmp2.getaddress()>tmp4.getaddress()){
                                                  if(tmp4.getaddress()+tmp4.getsize()==tmp2.getaddress()){
                                                    mytable->at(l).setsize(tmp2.getsize()+tmp4.getsize());
                                                  }
                                                  else if(tmp4.getaddress()+tmp4.getsize()<tmp2.getaddress()){
                                                          mytable->push_back(tmp2);


                                                  }
                                           }
                                           break;
                                         }

                                       

                                         if(l==0){

                                          if(tmp2.getaddress()<tmp4.getaddress()){
                                           if(tmp2.getaddress()+tmp2.getsize()==tmp4.getaddress()){

                                             mytable->at(l).setaddress(tmp4.getaddress()-size1);
                                             mytable->at(l).setsize(tmp4.getsize()+size1);

                                           }
                                           else if(tmp2.getaddress()+tmp2.getsize()!=tmp4.getaddress()){
                                                   mytable->insert(iter3,tmp2);
                                           }
                                          }
                                          else if(tmp2.getaddress()>tmp4.getaddress()){
                                                  if(tmp4.getaddress()+tmp4.getsize()==tmp2.getaddress()){
                                                     mytable->at(l).setsize(tmp4.getsize()+size1);

                                                     if(mytable->at(l).getaddress()+mytable->at(l).getsize()==mytable->at(l+1).getaddress()){
                                                         mytable->at(l).setsize(mytable->at(l).getsize()+mytable->at(l+1).getsize());
                                                         iter3++;
                                                         mytable->erase(iter3);
                                                     }

                                                  }
                                                  else if(tmp4.getaddress()+tmp4.getsize()!=tmp2.getaddress()){
                                                         if(tmp2.getaddress()+tmp2.getsize()==mytable->at(l+1).getaddress()){
                                                            mytable->at(l+1).setaddress(mytable->at(l+1).getaddress()-size1);
                                                            mytable->at(l+1).setsize(mytable->at(l+1).getsize()+size1);
                                                         }
                                                         else{
                                                          l++;
                                                          iter3++;
                                                          continue;
                                                         }
                                                  }
                                          }
                                           break;
                                         }
                                         else if(l>0 && l<mytable->size()-1){
                                          if(tmp2.getaddress()<tmp4.getaddress()){
                                           if(mytable->at(l-1).getaddress()+mytable->at(l-1).getsize()==tmp2.getaddress()){
                                             mytable->at(l-1).setsize(mytable->at(l-1).getsize()+tmp2.getsize());
                                              if(mytable->at(l-1).getaddress()+mytable->at(l-1).getsize()==mytable->at(l).getaddress()){
                                                 mytable->at(l-1).setsize(mytable->at(l-1).getsize()+mytable->at(l).getsize());
                                                 mytable->erase(iter3);
                                              }
                                           }
                                           else if(mytable->at(l-1).getaddress()+mytable->at(l-1).getsize()!=tmp2.getaddress()){
                                                   if(tmp2.getaddress()+tmp2.getsize()==tmp4.getaddress()){
                                                      mytable->at(l).setaddress(tmp4.getaddress()-size1);
                                                      mytable->at(l).setsize(tmp4.getsize()+size1);
                                                   }
                                                   else if(tmp2.getaddress()+tmp2.getsize()!=tmp4.getaddress()){
                                                          mytable->insert(iter3,tmp2);
                                                   }
                                           }
                                          }
                                          else if(tmp2.getaddress()>tmp4.getaddress()){
                                                  if(tmp4.getaddress()+tmp4.getsize()==tmp2.getaddress()){
                                                     mytable->at(l).setsize(tmp4.getsize()+size1);

                                                     if(mytable->at(l).getaddress()+mytable->at(l).getsize()==mytable->at(l+1).getaddress()){
                                                         mytable->at(l).setsize(mytable->at(l).getsize()+mytable->at(l+1).getsize());
                                                         iter3++;
                                                         mytable->erase(iter3);
                                                     }

                                                  }
                                                  else if(tmp4.getaddress()+tmp4.getsize()!=tmp2.getaddress()){
                                                         if(tmp2.getaddress()+tmp2.getsize()==mytable->at(l+1).getaddress()){
                                                            mytable->at(l+1).setaddress(mytable->at(l+1).getaddress()-size1);
                                                            mytable->at(l+1).setsize(mytable->at(l+1).getsize()+size1);
                                                         }
                                                         else{
                                                          l++;
                                                          iter3++;
                                                          continue;
                                                         }
                                                  }
                                          }
                                           break;
                                         }
                                         else if(l==mytable->size()-1){
                                          if(tmp2.getaddress()<tmp4.getaddress()){
                                                if(mytable->at(l-1).getaddress()+mytable->at(l-1).getsize()==tmp2.getaddress()){
                                                     mytable->at(l-1).setsize(mytable->at(l-1).getsize()+tmp2.getsize());
                                                   if(mytable->at(l-1).getaddress()+mytable->at(l-1).getsize()==mytable->at(l).getaddress()){
                                                     mytable->at(l-1).setsize(mytable->at(l-1).getsize()+mytable->at(l).getsize());
                                                     mytable->erase(iter3);
                                                   }
                                               }
                                               else if(mytable->at(l-1).getaddress()+mytable->at(l-1).getsize()!=tmp2.getaddress()){
                                                      if(tmp2.getaddress()+tmp2.getsize()==tmp4.getaddress()){
                                                        mytable->at(l).setaddress(tmp4.getaddress()-size1);
                                                        mytable->at(l).setsize(tmp4.getsize()+size1);
                                                      }
                                                      else if(tmp2.getaddress()+tmp2.getsize()!=tmp4.getaddress()){
                                                          mytable->insert(iter3,tmp2);
                                                      }
                                              }
                                          }
                                          else if(tmp2.getaddress()>tmp4.getaddress()){
                                                 if(tmp4.getaddress()+tmp4.getsize()==tmp2.getaddress()){
                                                    mytable->at(l).setsize(tmp2.getsize()+tmp4.getsize());
                                                  }
                                                  else if(tmp4.getaddress()+tmp4.getsize()!=tmp2.getaddress()){
                                                          mytable->push_back(tmp2);


                                                  }
                                          }
                                          break;
                                         }
                                         l++;
                                         iter3++;
                               }
                               return;
}

FreeSpace* FreeSpaceTable::findspace(long size){

                unsigned int i=0;
					 FreeSpace tmp1;

                vector<FreeSpace>::iterator iter1=this->mytable->begin();

              while(i<this->mytable->size()){
                   tmp1=this->mytable->at(i);

                   if(size<=tmp1.getsize())
                     return iter1;

                   i++;
                   iter1++;
              }

          return NULL;
}

//The "get the free space table" function.
 vector<FreeSpace> * FreeSpaceTable::getmytable()const{return this->mytable;}

# endif
