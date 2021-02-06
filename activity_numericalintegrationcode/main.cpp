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

int index,functionid,n,intensity;
float integral,diff,function=0,a,b,c;

int main (int argc, char* argv[]) 
{
	if(argc < 6) 
	{
		std::cerr<<"usage: "<<argv[0]<<" <functionid> <a> <b> <n> <intensity>"<<std::endl;
		return -1;
	}

	functionid=atoi(argv[1]);
	a=strtof(argv[2],NULL);
	b=strtof(argv[3],NULL);
	n=atoi(argv[4]);
	intensity=atoi(argv[5]);

	auto starttime=std::chrono::system_clock::now();

	diff=(b-a);
	c=diff/n;
	
	for(index=0;index<=n-1;index++)
	{
		integral=(a+((index+0.5)*c));
		if(functionid==1)
			function=function+f1(integral,intensity);
		else if(functionid==2)
			function=function+f2(integral,intensity);
		else if(functionid==3)
		  function=function+f3(integral,intensity);
		else if(functionid==4)
			function=function+f4(integral,intensity);
		else
			std::cout<<"ERROR!!\n";
	}
	function=function*c;

	auto endtime=std::chrono::system_clock::now();
	
	std::chrono::duration<float> timetaken=endtime-starttime;
	std::cout<<function<<"\n";
	std::cerr<<timetaken.count()<<"\n";
	return 0;
}




