#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <ctime>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <list>
#include <set>
#include <map>
#include <iostream>
#include "dsu.h" 

using namespace std;

int main()
{
	
	//lets take n sets of n individual items, then we will keep grouping some 
	//sets together and output the result of sizeofset, numberofsets and root 
	//of set tree. This is really useful in applications such as undirected 
	//graphs and gps.
	dsubyrank dst(5);
	// we will not club 0th,1st element and 2nd , 3rd element into a disjoint 
	//sets and find the results.
	cout<<"Size of set with element 0 - "<<dst.sizeofset(0)<<endl;
	cout<<"Performing union of set with elements 0 and 1";
	dst.unionset(0,1);
	// now since both 0 and 1 are in same set , they will both have same set size
	cout<<"Size of set with element 1 - "<<dst.sizeofset(1)<<endl;
	cout<<"Number of Disjoint sets - "<<dst.disjointsets()<<endl;

	cout<<"Performing union of set with elements 2 and 3\n";
	dst.unionset(2,3);
	if(dst.issame(2,3))
		cout<<"2 and 3 are in same set\n";
	else 
		cout<<"2 and 3 are not in the same set\n";

	cout<<"Performing union of set with elements 0 and 2\n";

	dst.unionset(0,2);
	cout<<"Size of set with element 2 - "<<dst.sizeofset(2)<<endl;
	cout<<"Number of Disjoint sets - "<<dst.disjointsets()<<endl;
	return 0;


}