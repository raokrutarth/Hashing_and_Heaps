#include <iostream>
#include "cchash.h"

using namespace std;

CCHash::CCHash(int initial_r, int ml)
{
	table_size = initial_r;
	T1 = new int[initial_r];
	T2 = new int[initial_r];
	for(int i = 0; i < initial_r; i++)
    {
        T1[i] = -1;
        T2[i] = -1;
    }
	maxLoops = ml;	
}
int CCHash::h1(int x)
{
	return x%table_size;
}
int CCHash::h2(int x)
{
	return x%(table_size - 1);
}
bool CCHash::lookup(int x)
{
	if ( T1[h1(x)] == x )
	{
		cout << T1[h1(x)] << " at T1[" << h1(x) << "]"<<endl;
		return true;
	}
	else if ( T2[h2(x)] == x)
	{
		cout << T2[h2(x)] << " at T2[" << h2(x) << "]"<< endl;
		return true;
	}
	else
	{
		cout << "no "<< x << endl;
		return false;
	}	
}
void CCHash::rehash()
{
	//cout << "rehash reached" << endl;
	table_size *=2;
	int * temp1 = new int[table_size];
	int * temp2 = new int[table_size];
	for(int i = 0; i < table_size; i++)
    {
        temp1[i] = -1;
        temp2[i] = -1;
    }
    for(int i = 0; i < (table_size/2); i++)
	{
		
		if (T1[i] > 0)
			insert(T1[i], temp1, temp2);
		if(T2[i] > 0)
			insert(T2[i], temp1, temp2);			
	}
	int * prev_t1 = T1;
	int * prev_t2 = T2;
	T1 = temp1;
	T2 = temp2;
	delete prev_t1;
	delete prev_t2;	
}
bool CCHash::remove(int x)
{
	if ( T1[h1(x)] == x )
	{
		T1[h1(x)] = -1;
		cout << x << " out T1[" << h1(x) << "]" << endl;
		return true;
	}
	else if ( T2[h2(x)] == x )
	{
		T2[h2(x)] = -1;
		cout << x << " out T2[" << h2(x) << "]" << endl;
		return true;
	}
	else
	{
		cout << "no out "<< x << endl;
		return false;
	}
}
bool CCHash::insert(int x, int * tb1, int * tb2)
{
	//cout << "--------------inserting "<< x << endl;
	//cout << "h1-x = " << h1(x) << endl;
	//cout << (tb1[h1(x)] != NULL) << endl; ///gives 0 so it is not NULL
	//cout << (*tb1[h1(x)]) << endl;
	if ( tb1[h1(x)] == x )
	{
		//cout << 999 << endl;
		cout << tb1[h1(x)] << " already in T1[" << h1(x) << "]"<<endl;
		return true;
	}
	else if ( tb2[h2(x)] == x)
	{
		cout << tb2[h2(x)] << " already in T2[" << h2(x) << "]"<< endl;
		return true;
	}
	else
	{
		for(int i = 0; i < maxLoops; i++)
		{
			if( tb1[h1(x)] == -1) 
			{
				tb1[h1(x)] = x;//new int(x);
				cout << tb1[h1(x)] << " in T1[" << h1(x) << "]!" <<endl;
				return true;
			}
			//cout << tb1[h1(x)] << " <-> " << x << endl;
			int temp = tb1[h1(x)];
			tb1[h1(x)] = x;//new int(x);
			cout <<  tb1[h1(x)] << " in T1[" << h1(x) << "]" << endl;
			x = temp;
			if( tb2[h2(x)] == -1 )
			{	
				tb2[h2(x)] = x;//new int(x);
				cout << tb2[h2(x)] << " in T2[" << h2(x) << "]!" <<endl; 
				return true;
			}
			//cout << tb2[h2(x)] << " <-> " << x << endl;
			temp = tb2[h2(x)];
			tb2[h2(x)] = x;//new int(x);
			cout << tb2[h2(x)] << " in T2[" << h2(x) << "]" <<endl;
			x = temp;		
		}
		cout << "maxloop reached" << endl;
		rehash();
		insert(x, T1, T2);
		return false;
	}	
}
int * CCHash::get_t1()
{
	return T1;
}
int * CCHash::get_t2()
{
	return T2;
}