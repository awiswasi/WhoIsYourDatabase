#include "dfsbfs.h"
#include "ui_dfsbfs.h"
#include <QDebug>
#include <stack>
#include <algorithm>

dfsbfs::dfsbfs(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dfsbfs)
{
    ui->setupUi(this);
//    dfsbfs airports;

//        vector<QString> titles;
//        vector<int> edges;

//        airports.addvertex("Los Angeles");
//        airports.addvertex("Denver");
//        airports.addvertex("San Francisco");
//        airports.addvertex("Seattle");
//        airports.addvertex("Kansas City");
//        airports.addvertex("Chicago");
//        airports.addvertex("Dallas");
//        airports.addvertex("Houston");
//        airports.addvertex("Boston");
//        airports.addvertex("New York");
//        airports.addvertex("Atlanta");
//        airports.addvertex("Miami");

//        titles.push_back("Los Angeles");
//        titles.push_back("Denver");
//        titles.push_back("San Francisco");
//        titles.push_back("Seattle");
//        titles.push_back("Kansas City");
//        titles.push_back("Chicago");
//        titles.push_back("Dallas");
//        titles.push_back("Houston");
//        titles.push_back("Boston");
//        titles.push_back("New York");
//        titles.push_back("Atlanta");
//        titles.push_back("Miami");

//        airports.addedge("Los Angeles", "Denver", 1015);
//        airports.addedge("Denver", "San Francisco", 1267);
//        airports.addedge("Denver", "Chicago", 1003);
//        airports.addedge("San Francisco", "Los Angeles", 381);
//        airports.addedge("Seattle", "San Francisco", 807);
//        airports.addedge("Seattle", "Denver", 1331);
//        airports.addedge("Kansas City", "Atlanta", 864);
//        airports.addedge("Kansas City", "Los Angeles", 1663);
//        airports.addedge("Kansas City", "Denver", 599);
//        airports.addedge("Kansas City", "Chicago", 533);
//        airports.addedge("Kansas City", "New York", 1260);
//        airports.addedge("Chicago", "Seattle", 2097);
//        airports.addedge("Chicago", "Boston", 983);
//        airports.addedge("Dallas", "Los Angeles", 1435);
//        airports.addedge("Dallas", "Kansas City", 496);
//        airports.addedge("Dallas", "Atlanta", 781);
//        airports.addedge("Houston", "Dallas", 239);
//        airports.addedge("Houston", "Atlanta", 810);
//        airports.addedge("Houston", "Dallas", 239);
//        airports.addedge("Boston", "New York", 214);
//        airports.addedge("New York", "Chicago", 983);
//        airports.addedge("New York", "Atlanta", 888);
//        airports.addedge("Atlanta", "Miami", 661);
//        airports.addedge("Miami", "Houston", 1187);
//        edges.push_back(381);
//        edges.push_back(807);
//        edges.push_back(1267);
//        edges.push_back(1015);
//        edges.push_back(1331);
//        edges.push_back(2097);
//        edges.push_back(1003);
//        edges.push_back(1663);
//        edges.push_back(496);
//        edges.push_back(1435);
//        edges.push_back(599);
//        edges.push_back(533);
//        edges.push_back(983);
//        edges.push_back(214);
//        edges.push_back(787);
//        edges.push_back(1260);
//        edges.push_back(888);
//        edges.push_back(864);
//        edges.push_back(239);
//        edges.push_back(781);
//        edges.push_back(810);
//        edges.push_back(661);
//        edges.push_back(1187);

 //       airports.DFS(titles, edges, "Denver");
 //       airports.BFS(titles, edges, "Denver");

}

dfsbfs::~dfsbfs()
{
    delete ui;
}
//void dfsbfs::addvertex(const string &name)
//{
//    vmap::iterator itr = work.find(name);
//    if (itr == work.end())
//    {
//        vertex *v;
//        v = new vertex(name);
//        work[name] = v;
//        return;
//    }
//    cout << "\nVertex already exists!";
//}

//void dfsbfs::addedge(const string& from, const string& to, double dist)
//{
//    vertex *f = (work.find(from)->second);
//    vertex *t = (work.find(to)->second);
//    pair<int, vertex *> edge = make_pair(dist, t);
//    f->adj.push_back(edge);
//}
/*void printEdge(int distance)
{*//*
    switch (distance)
    {
    case 1015:
        cout << "Los Angeles to Denver" << endl;
        break;
    case 1267:
        cout << "Denver to San Francisco" << endl;
        break;
    case 1003:
        cout << "Denver to Chicago" << endl;
        break;
    case 381:
        cout << "San Francisco to Los Angeles" << endl;
        break;
    case 807:
        cout << "Seattle to San Francisco" << endl;
        break;
    case 1331:
        cout << "Seattle to Denver" << endl;
        break;
    case 1663:
        cout << "Kansas City to Los Angeles" << endl;
        break;
    case 599:
        cout << "Kansas City to Denver" << endl;
        break;
    case 533:
        cout << "Kansas City to Chicago" << endl;
        break;
    case 1260:
        cout << "Kansas City to New York" << endl;
        break;
    case 2097:
        cout << "Chicago to Seattle" << endl;
        break;
    case 983:
        cout << "Chicago to Boston" << endl;
        break;
    case 1435:
        cout << "Dallas to Los Angeles" << endl;
        break;
    case 496:
        cout << "Dallas to Kansas City" << endl;
        break;
    case 781:
        cout << "Dallas to Atlanta" << endl;
        break;
    case 239:
        cout << "Houston to Dallas" << endl;
        break;
    case 810:
        cout << "Houston to Atlanta" << endl;
        break;
    case 214:
        cout << "Boston to New York" << endl;
        break;
    case 787:
        cout << "New York to Chicago" << endl;
        break;
    case 888:
        cout << "New York to Atlanta" << endl;
        break;
    case 661:
        cout << "Atlanta to Miami" << endl;
        break;
    case 1187:
        cout << "Miami to Houston" << endl;
        break;
    case 864:
        cout << "Kansas City to Atlanta" << endl;
    default:
        break;
    }*/
//}
//void dfsbfs::DFS(vector<string> titles, vector<int> edges, string start)
//{
//	cout << "Depth First Search:\n";
//	vector<string> accessed;
//	vector<int> discovery;
//	string end;
//	int position = -1;
//	int accum = 0;
//	vertex *s = (work.find(start)->second);

//	//Runs a loop while the accessed locations are less than the total list
//	// of locations
//	while(accessed.size() < titles.size()) // change to while
//	{

//		vertex *next = NULL;
//		// If the item being visited has not yet been accessed then
//		// output its name
//		if (find(accessed.begin(), accessed.end(),s->name) == accessed.end())
//		{
//			cout << s->name << endl;
//			accessed.push_back(s->name);
//			position ++;
//		}

//		// Stores all of the distances for the current verticy in a vector
//		vector<int> dist;
//		for(unsigned int i = 0; i < s->adj.size(); i++)
//		{
//			dist.push_back(s->adj[i].first);
//		}
//		// Sorts the vector of distances
//		sort(dist.begin(), dist.end());
//		vector<ve> sortedPairs;
//		//Stores the stored distances back in to a pair vector that cointains
//		//The pointed verticy
//		for(unsigned int i = 0; i < dist.size(); i++)
//		{
//			unsigned int a = 0;
//			while(dist[i] != s->adj[a].first) // change to while
//			{
//				a++;
//			}
//			sortedPairs.push_back(s->adj[a]);
//		}
//		unsigned int a = 0;
//		bool escape;
//		next = sortedPairs[a].second;
//		// Will set escape based off of if the next name is in the list or not
//		escape = (find(accessed.begin(), accessed.end(),next->name) != accessed.end());

//		// Runs through a loop while the next element has not been found
//		while(escape != false)
//		{
//			a++;
//			if(a < sortedPairs.size())
//			{
//				next = sortedPairs[a].second;
//				escape = (find(accessed.begin(), accessed.end(),next->name)
//						!= accessed.end());
//			}
//			else
//			{
//				escape = false;
//			}
//		}

//		// Will check if the program needs to backtrack
//		if(a >= sortedPairs.size() && accessed.size() != titles.size())
//		{
//			if(position != -1)
//			{
//				position --;
//				s = (work.find(accessed[position])->second);
//			}
//		}
//		// Stores the next location to be visited
//		else
//		{
//			s = next;
//			if(accessed.size() != titles.size())
//			{
//				accum += sortedPairs[a].first;
//				discovery.push_back(sortedPairs[a].first);
//			}
//		}
//	}

//	cout << "This is the total trip distance: " << accum;

//	// outputs the discovery edges
//	cout << endl << endl << "The discovery edges are distances:\n";
//	for(unsigned int i = 0; i < discovery.size(); i ++)
//	{
//		vector<int>::iterator itr;
//		itr = edges.begin();
//		printEdge(discovery[i]);
//		int a = 0;
//		while(discovery[i] != edges[a])
//		{
//			a++;
//			itr++;
//		}
//		edges.erase(itr);
//	}
//	// outputs the back edges
//	cout << endl << "The back edges are distances:\n";
//	for(unsigned int i = 0; i < edges.size(); i ++)
//	{
//		printEdge(edges[i]);
//	}
//}


//void dfsbfs::BFS(vector<string> titles, vector<int> edges,
//string start)
//{

//	cout << "Breadth First Search:\n";
//	vector<visited> accessed;
//    vector<string> names;
//	vector<int> discovery;
//	vector<int> forward;
//	vector<int> cross;
//    vector<int> actualCross;
//    visited node;
//	int accum = 0;
//	vector<vector<vertex*> > tierVec;
//	vertex *s = (work.find(start)->second);
//	int tier = 0;

//    node.name = s->name;
//    node.color = "a";
//    accessed.push_back(node);
//    names.push_back(node.name);

//	tierVec.push_back(vector<vertex*>());
//	tierVec.push_back(vector<vertex*>());
//	tierVec[tier].push_back(s);

//	// Runs the program while there are more items to add to the list
//	while(tierVec[tier].size() != 0)
//	{
//		vector<pair<string, int> > shortest;
//		cout << "\nTier " << tier << ":\n";
//		// outputs all of the locations in the current tier of locations
//		for(unsigned int i = 0; i < tierVec[tier].size(); i++)
//		{
//			cout << tierVec[tier][i]->name << endl;
//		}
//		// runs a for loop to the size of the current tier
//		for(unsigned int a = 0; a < tierVec[tier].size(); a++)
//		{
//			// runs a loop for the size of the array of edges in the current tier element
//			for(unsigned int i = 0; i < work.find(tierVec[tier][a]->name)->second->adj.size(); i++)
//			{
//				bool found = false;
//				unsigned int b = 0;
//				// will run while b is less than the size of the shortest distances
//				// for all of the next nodes in the list, or until a match has been
//				// found
//				while(!found && b < shortest.size())
//				{
//					// if a match has been found then enter this statement
//					if(tierVec[tier][a]->adj[i].second->name == shortest[b].first
//						&& !found)
//					{
//						// checks to see if the value stored is lower than the current
//						// value, if it is then replace the stored value
//						if(tierVec[tier][a]->adj[i].first < shortest[b].second)
//						{
//							found = true;
//							forward.push_back(tierVec[tier][a]->adj[i].first);
//							shortest[b].second = tierVec[tier][a]->adj[i].first;
//						}
//						// Otherwise the edge is a forward edge
//						else if(tierVec[tier][a]->adj[i].first > shortest[b].second)
//						{
//							found = true;
//							forward.push_back(tierVec[tier][a]->adj[i].first);
//						}
//					}
//					b++;
//				}
//				// If nothing has been found then push back the item in to the
//				// shortest list to add to the list
//				if(!found && find(names.begin(), names.end(),tierVec[tier][a]->adj[i].second->name) == names.end()) //
//				{
//					pair<string, int> store;
//					store.first = tierVec[tier][a]->adj[i].second->name;
//					store.second = tierVec[tier][a]->adj[i].first;
//					shortest.push_back(store);

//                    node.name = (tierVec[tier][a]->adj[i].second->name);
//                    if(node.name=="San Fransisco" || node.name == "Los Angeles")
//                        node.color = "pink";
//                    else
//                        node.color = "a";

//                    accessed.push_back(node);
//                    names.push_back(node.name);

//				}
//			}
//		}
//		// sort the pair vector
//		sort(shortest.begin(), shortest.end(), [](const pair<string, int>& a, const pair<string,int>& b)
//				{
//					return a.second < b.second;
//				});
//		// accumulate the total distance of the discovery edges
//		for(unsigned int i = 0; i < shortest.size(); i++)
//		{
//			tierVec[tier+1].push_back(work.find(shortest[i].first)->second);
//			accum += shortest[i].second;
//			discovery.push_back(shortest[i].second);
//		}
//		// store all of the cross edges
//		for(unsigned int a = 0; a < tierVec[tier].size(); a++)
//		{
//			for(unsigned int i = 0; i < work.find(tierVec[tier][a]->name)->second->adj.size(); i++)
//			{
//				string check = tierVec[tier][a]->adj[i].second->name;
//				auto it = find_if(shortest.begin(), shortest.end(), [&](const pair<string,int>& obj)
//						{
//							return check == obj.first;
//						});

//				if(it != shortest.end())
//				{
//					cross.push_back(tierVec[tier][a]->adj[i].first);
//				}
//			}
//		}
//		tier ++;
//		// create a new tier
//		tierVec.push_back(vector<vertex*>());
//	}
//	cout << "\n\nTotal Distance: " << accum;


//	cout << endl << endl << "The discovery edges are distances:\n";
//	for(unsigned int i = 0; i < discovery.size(); i ++)
//	{
//		vector<int>::iterator itr;
//		itr = edges.begin();
//		printEdge(discovery[i]);
//		int a = 0;
//		while(discovery[i] != edges[a])
//		{
//			a++;
//			itr++;
//		}
//		edges.erase(itr);
//	}

//	cout << endl << endl << "The forward edges are distances:\n";
//	for(unsigned int i = 0; i < forward.size(); i ++)
//	{
//		vector<int>::iterator itr;
//		itr = edges.begin();
//		printEdge(forward[i]);
//	}

//	cout << endl << endl << "The cross edges are distances:\n";
//	for(unsigned int i = 0; i < cross.size(); i ++)
//	{
//		vector<int>::iterator itr;
//		itr = edges.begin();

//		printEdge(edges[i]);
//	}
//	cout << endl << "The back edges are distances:\n";
//	for(unsigned int i = 0; i < edges.size(); i ++)
//	{
//		printEdge(edges[i]);
//	}


//}
