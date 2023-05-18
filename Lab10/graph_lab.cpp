#include <iostream>
#include<list>
#include<vector>
using namespace std;

struct Node{
    int label;
    vector<int> neighbours;
    

};

struct Graph{
    //graph will have an array of type "node" with length specified by n
    int n=8;
    struct Node * nodes = new Node[n];

    void intializenodes(){
        //iterate through the nodes and assign labels
        // for(int i=0;i<n;i++){
        //     nodes[i].label=i+1;
        // }
        for (int i = 0; i < n; i++) {
    nodes[i].label = i + 1;
}
    }

    void addedge(int u, int v){
        //select node u and push v into u's neighbour
        nodes[u-1].neighbours.push_back(v);
        //select node v and push u into v's neighbour
        nodes[v-1].neighbours.push_back(u);
    }

    void print(){
        //lets iterate through each node and print its neighbours
         for(int i=0;i<n;i++){
            cout<<nodes[i].label<<"--";
            for(int j : nodes[i].neighbours){
                cout<<j<<", ";
                
            }
            cout<<endl;
        }
    }
};

int main() {
    struct Graph * g = new Graph;
    g->intializenodes();
    //add edges for the graphs here.
     g->addedge(4,7);
    g->addedge(7,5);
    g->addedge(1,2);
    g->addedge(2,3);
    g->addedge(3,1);
    g->addedge(1,4);
    g->addedge(6,2);
    g->addedge(6,4);
    g->addedge(5,8);
    g->addedge(5,6);
    g->addedge(1,5);
    g->addedge(4,8);
    //print the graph adjaceny list
    g->print();
}