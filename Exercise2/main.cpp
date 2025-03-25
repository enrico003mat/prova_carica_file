#include<string>
#include<iostream>
#include<fstream>
#include<vector>
#include <iomanip>

std::vector<double> map(std::ifstream& dati)
{
		double val;
		std::vector<double> vec;
		int n=0;
		while(dati>>val)
		{
			
			//std::cout<<val<<"\n"<<std::endl;
			val=(3.0/4.0)*val -(7.0/4.0);
			//std::cout<<"trasf"<<val<<"\n"<<std::endl;
			vec.push_back(val);
			n+=1;
		}
		return vec;
}
		 
int main()
{
	std::ifstream testo("data.txt");
	if(testo.fail())
	{	std::cout<<"Errore nel'apertura del file"<<std::endl;
	}
	std::vector<double>  vect=map(testo);
	
	int  N=vect.size();
	double sum=0.0;
	double media=0.0;
	std::string scrittura="result.txt";
	std::ofstream ofs(scrittura);

		 
	for(int k=0;k<N;k+=1)
	{
		if (k==0)
		{
			 ofs<< "#  " << " N "<< " Mean " << std::endl;
		}
		sum +=vect[k];
		//std::cout<<"val "<<vect[k]<<"\n"<<std::endl;
		media=sum/(k+1);
		ofs << k + 1 << std::scientific << std::setprecision(16) << "    " << media << std::endl;

		//std::cout<<"Media "<<media<<"\n"<<std::endl;
		
	}
	ofs.close();
	
    return 0;
}
