#include<bits/stdc++.h>
using namespace std;
 
struct edge{
  	//src : source
  	//des : destination
  	int src,des, weight;
};
 
edge createEdge(int src,int des, int weight){ //(0.1.5)
  	//buat edge baru
  	edge temp;
  	temp.src = src;
  	temp.des = des;
  	temp.weight = weight;
  	return temp;
}
 
void bellmanFord(vector<edge> e, int nV, int source){
    int distance[nV];

    //inisialisasi jarak array dengan jarak tak hingga
    for (int i = 0; i < nV; i++) {
        distance[i] = INT_MAX;
    }
    distance[source] = 0; //jarak dari source ke dirinya sendiri adalah 0


    //langkah sampai n-1 (relaxation)
    for (int i = 1; i <= nV - 1; i++) {
        for (int j = 0; j < e.size(); j++) {
            int src = e[j].src;
            int des = e[j].des;

            //skip kalau src belum ada nilai distance
            if (distance[src] == INT_MAX) continue;

  
            //update distance kalauketemu yang lebih kecil 
            if (distance[src] + e[j].weight < distance[des]) {
                distance[des] = distance[src] + e[j].weight;
            }
        }
    }

	
	//print
	cout<<"Jarak terdekat dari vertex "<<source<<endl;
	for (int i=0;i<nV;i++)
	{
		if (i==source) continue;
		cout<<i<<" : "<<distance[i]<<endl;
	}
}
int main() 
{ 
	int nV = 5;
	edge temp;
    vector<edge> e;
    e.push_back(createEdge(0,1,5));
    e.push_back(createEdge(0,3,3));
    e.push_back(createEdge(1,2,2));
    e.push_back(createEdge(1,4,15));
    e.push_back(createEdge(3,0,1));
    e.push_back(createEdge(3,1,1));
    e.push_back(createEdge(4,4,3));
    bellmanFord(e,nV,0);
    return 0; 
}