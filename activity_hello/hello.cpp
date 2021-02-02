

#include<iostream>
#include<unistd.h>
int main()
{
  char hostname[1024]="";
  int val=gethostname(hostname,sizeof hostname);
  if(val==-1)
    std::cout<<"Error!!Please Check Again\n";
  else
    std::cout<<"Host Name is:\t"<<hostname;
}
