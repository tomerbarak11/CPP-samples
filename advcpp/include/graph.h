#ifndef GRAPH_H
#define GRAPH_H
#include <vector>
#include <list>
#include <queue>
#include <algorithm>
#include <iostream>

template <typename T>
class Path{
public: 
	Path(size_t a_target)
	{	
		m_target = a_target;
	}
	bool operator()(size_t i, T const& t) const{		
		return i == m_target;
	}
private:
	size_t m_target;
};

template<typename T>
class Graph
{
public:
	
	typedef std::list< std::pair<size_t,double> > AdjacencyList;
	typedef std::pair<T, AdjacencyList> Vertex;
	typedef std::vector<Vertex> type_container;
	typedef std::pair<std::list<size_t>,double > iner_type2;
	typedef std::list<size_t > iner_type;	
	typedef std::pair<T, std::list<size_t> > type_pair;
	
public:
	bool hasEdge(T const & a, T const & b) const;
	void addIf(T const& a, T const& b,double a_weight);
	void addIf(T const& a);
	int isConnectedBFS(T const& v, T const& w) const;
	Graph<T> KruskalCreate(Graph<T> const& originalGraph);
private:

	void insertEdgeIf(AdjacencyList& a_neighborsContainer, T const& a_ptrVal,double a_weight); 
	bool indesIfExist(T const & a_val, size_t & a_index);
	int BFS(T const& v, Path<T> const& process) const;
	size_t find() const;
	bool indexOf(T const & a, size_t & a_size) const;
	void addAllNodesTokruskalTree(Graph<T>& kruskalTree);

private:
	type_container m_graphContainer;
};

template<typename T>
bool Graph<T>::indesIfExist(T const & a_val, size_t & a_index)
{
	typename type_container::const_iterator it = m_graphContainer.begin(); 
	typename type_container::const_iterator end = m_graphContainer.end(); 
	while(it != end && (*it) != a_val)
	{ 
		++a_index;
		++it;
	}

	if(a_index == m_graphContainer.size())
	{
		return false;
	}
	return true;
}

template<typename T>
class findEdgeContainer
{ 
public:	
	findEdgeContainer(T const & a);
	bool operator()(std::pair<T,	std::list<	std::pair<size_t,double> > >  const & a_pair);
private: 
	T const & m_a;
};

template<typename T>
findEdgeContainer<T>::findEdgeContainer(T const & a_a)
: m_a(a_a)
{ 
}

template<typename T>
bool findEdgeContainer<T>::operator()(std::pair<T,	std::list<	std::pair<size_t,double> > >  const & a_pair)
{ 
	return (a_pair.first.getName() == m_a.getName()); 
}

template<typename T>
class findEdgeContainerSemi
{ 
public:	
	typedef std::list< std::pair<size_t,double> > AdjacencyList;
	typedef std::pair<T, AdjacencyList> Vertex;
	typedef std::vector<Vertex> type_container;
	
	
	findEdgeContainerSemi(AdjacencyList& a_adjacencyList,T const& a_check,size_t a_index);
	bool operator()(std::pair<long unsigned int, double> const& a_check);
private:
	AdjacencyList m_adjacencyList;
	T m_check; 
	size_t m_index;
};

template<typename T>
findEdgeContainerSemi<T>::findEdgeContainerSemi(AdjacencyList& a_adjacencyList,T const& a_check,size_t a_index)
: m_adjacencyList(a_adjacencyList)
, m_check(a_check)
, m_index(a_index)
{ 
}

template<typename T>
bool findEdgeContainerSemi<T>::operator()(std::pair<long unsigned int, double> const& a_check)
{
	//return (m_adjacencyList[m_index].first == a_check);
	return true;
}

template<typename T>
void Graph<T>::addIf(T const& a, T const& b,double a_weight)
{  
	typename type_container::iterator itB = std::find_if( m_graphContainer.begin(),  m_graphContainer.end(), findEdgeContainer<T>(b)); 
	
	if(itB == m_graphContainer.end())
	{
		addIf(b);
		itB = std::find_if( m_graphContainer.begin(),  m_graphContainer.end(), findEdgeContainer<T>(b)); 
	}
	
	typename type_container::iterator itA = std::find_if( m_graphContainer.begin(),  m_graphContainer.end(), findEdgeContainer<T>(a)); 
	if(itA == m_graphContainer.end())
	{
		addIf(a);
		itA = std::find_if( m_graphContainer.begin(),  m_graphContainer.end(), findEdgeContainer<T>(a)); 
	}
	insertEdgeIf((itA->second),(itB->first),a_weight);
	insertEdgeIf((itB->second),(itA->first),a_weight);
}

template<typename T>
void Graph<T>::addIf(T const& a)
{
	typename type_container::const_iterator it = std::find_if( m_graphContainer.begin(),  m_graphContainer.end(), findEdgeContainer<T>(a)); 
	if(it == m_graphContainer.end())
	{ 
		AdjacencyList inerContainer;
		m_graphContainer.push_back(std::make_pair(a,inerContainer)); 
	}
}

template<typename T>
void Graph<T>::insertEdgeIf(AdjacencyList &a_neighborsContainer, T const& a_ptrVal,double a_weight)
{
	size_t index;
	indexOf(a_ptrVal,index);

	typename AdjacencyList::const_iterator inerItr2;

	findEdgeContainerSemi<T> item(a_neighborsContainer,a_ptrVal,index);

	inerItr2 = std::find_if(a_neighborsContainer.begin(), a_neighborsContainer.end(), item);
	
	std::pair<size_t,double> newPair;
	newPair.first=index;
	newPair.second=a_weight;
	
	if(inerItr2 == a_neighborsContainer.end())
	{
		a_neighborsContainer.push_front(newPair);
	}
}

template<typename T>
bool Graph<T>::indexOf(T const & a, size_t & a_size) const
{
	a_size = 0;
	typename type_container::const_iterator it = m_graphContainer.begin();
	typename type_container::const_iterator end = m_graphContainer.end();

	for(; it != end; ++it)
	{
		if(it->first == a)
		{
			return true;
		}
		++a_size; 
	}	
	return false;
}

/**********************************************************************/
template <typename T>
size_t Graph<T>::find() const{
	return 0;
}

class QueuePusher{
	std::vector<char> const& visit;
	std::queue<size_t>& queue;
public:
	QueuePusher(std::vector<char> const& visit, std::queue<size_t>& queue)
	: visit(visit), queue(queue)
	{		
	}

	void operator()(std::pair <size_t,size_t> a_pair){
		if(!visit[a_pair.first])
		{
			queue.push(a_pair.first);
		}
	}
};

template <typename T>
int Graph<T>::isConnectedBFS(T const& v, T const& w) const
{	
	size_t index;
	indexOf(w,index);
	return BFS(v, Path<T>(index));
}

template <typename T>
int Graph<T>::BFS(T const& v, Path<T> const& process) const
{	
	if(m_graphContainer.size() == 0)
	{
		return -1;
	}
	
	size_t startIndex =  find();
	std::vector<char> visit(m_graphContainer.size());
	std::cout<<visit.size()<<"\n";
	std::queue<size_t> queue;
	queue.push(startIndex);
	while(!queue.empty())
	{
		size_t index = queue.front();
		queue.pop();
		if(process(index, m_graphContainer[index].first))
		{
			return index;
		}
		visit[index] = 1;
		AdjacencyList adj = m_graphContainer[index].second;
		for_each(adj.begin(), adj.end(), QueuePusher(visit, queue));
	}
	return -1;
}

/*
template <typename T>
Graph<T> Graph<T>::KruskalCreate(Graph<T> const& originalGraph)
{
	Graph<T> kruskalTree;
	addAllNodesTokruskalTree(kruskalTree);
	return kruskalTree;
}


template <typename T>
void Graph<T>::	addAllNodesTokruskalTree(Graph<T>& kruskalTree)
{
	typename AdjacencyList::const_iterator it;
	
}
*/

#endif
