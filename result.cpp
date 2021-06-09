# include <bits/stdc++.h>

using namespace std;

#define SIZE 168
const double e = 2.7182818;
double hypo=0;
double theta[SIZE+3], feature[SIZE+3];

void readParams(char* addr){//Reads in parameters (coefficient vector)
	ifstream fin(addr,ios::in);
	int i=0;
	while(!fin.eof()){
		fin>>theta[i++];
	}
	fin.close();
}

void readFeature(char* addr){//Reads in the feature vector  极端图像会出现inf,-inf
	string temp_s;
	ifstream fin(addr,ios::in);
	int i=1;
	while(!fin.eof()){
		fin>>temp_s;
		if (temp_s=="inf" || temp_s=="-inf")
		{
			hypo=-1;return;
		}
		feature[i++]= atof(temp_s.c_str());
		//fin>>feature[i++];
	}
	fin.close();
}

double hypothesis(){
	double z=0;
	for(int i=1;i<=SIZE;i++){
		z+=(theta[i]*feature[i]);
	}
	z+=theta[0];
	z=-z;
	return (1.0/(1.0+pow(e,z)));
}




int main(int argc,char** argv){
	cout<<"Print Result\n";
	readParams(argv[1]);
	readFeature(argv[2]);
	if (hypo!=-1)
		hypo=hypothesis();

	if(hypo>=0.5) cout<<"Gradable Retinal Image\n";
        else cout<<"Ungradable Retinal Image\n";
	cout<<" Score:"; 
	cout << setprecision(3) << hypo << endl; 

	return 0;
}
