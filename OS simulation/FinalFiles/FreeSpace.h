//Waseem Ilahi                  /*FreeSpace.h*/
# ifndef FREESPACE_H
# define FREESPACE_H

//Declaration of the class.

class FreeSpace{

		public:

             //The default constructor.
             FreeSpace();

             //The secong constructor.
             FreeSpace(long address,long size);

             //This method returns the size of the current freespace
      		 long getsize();
             //This method returns the address of the current space.
             long getaddress();

      //The following methods set the address and size of the current space.
             void setsize(long sizetoset);
             void setaddress(long addresstoset);

      private:

      		  long size;

              long address;

};

/*Method Definitions.
  -------------------*/

  //The constructors.

  FreeSpace::FreeSpace(){}

  FreeSpace::FreeSpace(long address,long size){

                     this->size=size;
                     this->address=address;
  }

  //The accessors.

  long FreeSpace::getsize(){ return this->size; }
  long FreeSpace::getaddress(){ return this->address; }

  //The mutators.

  void FreeSpace::setsize(long sizetoset){ this->size=sizetoset; }
  void FreeSpace::setaddress(long addresstoset){ this->address=addresstoset; }

# endif
