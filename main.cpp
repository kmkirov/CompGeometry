#include "vecta.h"
#include<iostream>
#include<vector>

using namespace std;
using namespace vecta;

void vector_init(vector<vec2d<> > & vector_points)
{
	//jalko che ne moga da im napravq merge
	vec2d<> a (1,1);
	vec2d<> b (3,1);
	vec2d<> c (6,1);
	vec2d<> d (4,2);
	vec2d<> e (5,3);
	vec2d<> f (4,3);
	vec2d<> g (4,4);
	vec2d<> h (3,4);
	vec2d<> i (3,3);
	vec2d<> j (2.5,2);
	vec2d<> k (2,3);
	vec2d<> l (1.5,3);

	//vec2d<> p (7,-1); test value
	vector_points.push_back(i);
	vector_points.push_back(j);
	vector_points.push_back(k);
	vector_points.push_back(l);
	vector_points.push_back(a);
	vector_points.push_back(b);
	vector_points.push_back(c);
	vector_points.push_back(d);
	vector_points.push_back(e);
	vector_points.push_back(f);
	vector_points.push_back(g);
	vector_points.push_back(h);
		

	//vector_points.push_back(p); test




}

int index_of_bottom_left_point(vector<vec2d<> > & points)
{
	int index = 0;
	double max_x = points[0].x;
	double min_y = points[0].y;
	for(int i = 1 ; i < points.size(); ++i)
	{
		if( max_x >= points[i].x && min_y <= points[i].y)
			continue;
		else 
		{
			index = i;
			max_x = points[i].x;
			min_y = points[i].y;
		}
	}
	return index;
}

vector<vec2d<>> vuje_algoritum(vector<vec2d<>> & points)
{
	vector<vec2d<>> obvivka;
	int starting_index = index_of_bottom_left_point(points);
	vec2d<> point_obvivka = points[starting_index];
	vec2d<> kandidat;
	while(true)
	{
		obvivka.push_back(point_obvivka);
		kandidat = points[2];

		for (int i = 1; i < points.size()-1 ; ++i)
		{
			if( !((kandidat - point_obvivka) <= ((points[i + 1] - point_obvivka))) )
			{
				kandidat = points[i + 1];				
			}
		}

		point_obvivka = kandidat;		
		if(( fabs(point_obvivka.x - points[0].x) <= 0.01) && ( fabs(point_obvivka.y - points[0].y )<=0.01))
			break; //ne raboti :)
	}
	return obvivka;
}
int main()
{
	
	vector<vec2d<> > points ;
	vector_init(points);
	vector<vec2d<> > ans = vuje_algoritum(points);
	for(int i=0 ;i<ans.size(); ++i)
		cout<< ans[i].x <<" "<<ans[i].y<<endl;

	//cout<< ((points[1] - points[0]) <= (points[2] - points[0]))<<endl; // predshesvane na 1voto sprqmo vtoroto 
	

	//int starting_index = index_of_bottom_left_point(points);
	//vec2d<> p (1,1);
}