/*
* C++ Program to Implement Adjacency List
*/
#include <iostream>
#include <cstdlib>
using namespace std;
/*
* Adjacency List Node
*/ 
struct AdjListNode
{
    int dest;
    struct AdjListNode* next;
};

/*
* Adjacency List
*/  
struct AdjList
{
    struct AdjListNode *head;
};

/*
* Class Graph
*/ 
class Graph
{
    private:
        int V;
        struct AdjList* array;
    public:
        Graph(int V)
        {
            this->V = V;
            array = new AdjList [V];
            for (int i = 0; i < V; ++i)
                array[i].head = NULL;
        }
        /*
        * Creating New Adjacency List Node
        */ 
        AdjListNode* newAdjListNode(int dest)
        {
            AdjListNode* newNode = new AdjListNode;
            newNode->dest = dest;
            newNode->next = NULL;
            return newNode;
        }
        /*
        * Adding Edge to Graph
        */ 
        void addEdge(int src, int dest)
        {
            AdjListNode* newNode = newAdjListNode(dest);
            newNode->next = array[src].head;
            array[src].head = newNode;
            newNode = newAdjListNode(src);
            newNode->next = array[dest].head;
            array[dest].head = newNode;
        }
        /*
        * Print the graph
        */ 
        void printGraph()
        {
            int v;
            for (v = 0; v < V; ++v)
            {
                AdjListNode* pCrawl = array[v].head;
                cout<<"\n Adjacency list of vertex "<<v<<"\n head ";
                while (pCrawl)
                {
                    cout<<"-> "<<pCrawl->dest;
                    pCrawl = pCrawl->next;
                }
                cout<<endl;
            }
        }
};

/*
* Main
*/ 
int main()
{
    int pilihan,a,b,n;
    cout<<"Banyak node : ";cin>>n;
    Graph gh(n);
    for(; ;)
    {
        cout<<"\nMenu\n"
            <<"1. Tambah edge\n"
            <<"2. Print Edge\n"
            <<"0. Exit\n\n"
            <<"Pilihan : ";cin>>pilihan;
        
        switch (pilihan)
        {
            case 1:
                cout<<"\nedge(a,b)\n"
                    <<"Input a : ";cin>>a;
                cout<<"Input b : ";cin>>b;
                gh.addEdge(a,b);
                continue;

            case 2:
                gh.printGraph();
                continue;

            case 0:
                return 0;
                break;

            default:
                continue;
        }
    }
    
    
    // Graph gh(5);
    // gh.addEdge(0, 1);
    // gh.addEdge(0, 4);
    // gh.addEdge(1, 2);
    // gh.addEdge(1, 3);
    // gh.addEdge(1, 4);
    // gh.addEdge(2, 3);
    // gh.addEdge(3, 4);

    // print the adjacency list representation of the above graph
    // gh.printGraph();

    return 0;
}