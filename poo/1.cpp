#include<iostream>

using namespace std;

class Point{

public:
	double x, y;
};

class Vector{
public:
	Point start, end;
};

int main(){

	//instânciando
	Vector vec1;
	
	//inicializando
	vec1.start.x = 1.0;
	vec1.start.y = 2.0;
	vec1.end.x = 3.0;
	vec1.end.y = 4.0;

	//intânciando
	Vector vec2;

	//mudando o valor
	vec1.end.x = 5.0;
	vec1.end.y = 6.0;
	
	//inicializando
	vec2.end.x = 7.0;
	vec2.end.y = 8.0;

	//mostrando os valores
	cout<< "vec1.start x:" <<vec1.start.x << " y:" << vec1.start.y << endl;
	cout<< "vec1.end x:"<<vec1.end.x <<"y: " <<vec1.end.y << endl;
	cout<<endl;

	//mostrando lixo de memoria 
	cout<<"vec2.start x:"<<vec2.start.x <<"y: "<<vec2.start.y<<endl;

	//mostrando os valores
	cout<<"vec2.end x:"<<vec2.end.x <<"y: "<<vec2.end.y << endl;
	cout<<endl;

return 0; 
}