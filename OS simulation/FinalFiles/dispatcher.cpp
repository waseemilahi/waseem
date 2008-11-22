//Waseem Ilahi                       /*The dispatcher */

//Takes the values and sets the control variables and returns.
void os_dispatcher(long* a,long* p,long x){

     if(x==1){
       *a=x;return;
     }
     else if(x==2){ 
           *a=x;
           p[2]=currentlyrunning->getlocation();
           p[3]=currentlyrunning->getjobsize();
           p[4]=currentlyrunning->gettimeslice();
     }

     return ;
}