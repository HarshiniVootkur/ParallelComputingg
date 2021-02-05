#include <iostream>
#include <cmath>
#include <cstdlib>
#include <chrono>

#ifdef __cplusplus
extern "C" {
#endif

float f1(float x, int intensity);
float f2(float x, int intensity);
float f3(float x, int intensity);
float f4(float x, int intensity);

#ifdef __cplusplus
}
#endif

  
int main (int argc, char* argv[]) {

  auto sample=std::chrono::system_clock::now();
  
  if (argc < 6) {
    std::cerr<<"usage: "<<argv[0]<<" <functionid> <a> <b> <n> <intensity>"<<std::endl;
    return -1;
  }
  int index,functionid,a,b,n,intensity,c;
  float integral;
  functionid=strtof(argv[1],NULL);
  a=strtof(argv[2],NULL);
  b=strtof(argv[3],NULL);
  n=strtof(argv[4],NULL);
  intensity=strtof(argv[5],NULL);

  c=(b-a)/n;
 
      for(index=0;index<=n-1;index++)
	{
	 integral=(c*((a+(index+0.5)*c))*n);
	}
      std::cout<<"Integral=\t"<<integral<<"\n";
      if(functionid==1)
	f1(integral,intensity);
      else if(functionid==2)
	f2(integral,intensity);
      else if(functionid==3)
	f3(integral,intensity);
      else if(functionid==4)
	  f4(integral,intensity);
      else
	std::cout<<"ERROR!!\n";
	     
      
  return 0;
}
