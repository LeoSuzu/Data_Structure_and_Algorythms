/* Program extracts from Chapter 12 of
   "Data Structures and Program Design in C++"
   by Robert L. Kruse and Alexander J. Ryba
   Copyright (C) 1999 by Prentice-Hall, Inc.  All rights reserved.
   Extracts from this file may be used in the construction of other programs,
   but this code will not compile or execute as given here. */


// Section 12.2:

template <int max_set>
struct Set {
  bool is_element[max_set];
};


template <int max_size>
class Digraph {
   int count;   //  number of vertices, at most max_size
   Set<max_size> neighbors[max_size];
};


template <int max_size>
class Digraph {
   int count;   //  number of vertices, at most max_size
   bool adjacency[max_size][max_size];
};


typedef int Vertex;
template <int max_size>
class Digraph {
   int count;   //  number of vertices, at most max_size
   List<Vertex> neighbors[max_size];
};


class Edge;             //  forward declaration
class Vertex {
   Edge *first_edge;    //  start of the adjacency list
   Vertex *next_vertex; //  next vertex on the linked list
};

class Edge {
   Vertex *end_point;  //  vertex to which the edge points
   Edge *next_edge;    //  next edge on the adjacency list
};

class Digraph {
   Vertex *first_vertex;  //  header for the list of vertices
};




// Section 12.3:

visit(v);
for (each vertex w adjacent to v)
  traverse(w);


template <int max_size>
void Digraph<max_size>::depth_first(void (*visit)(Vertex &)) const
/*
Post: The function *visit has been performed at each vertex of the
      Digraph in depth-first order.
Uses: Method traverse to produce the recursive depth-first order.
*/
{
   bool visited[max_size];
   Vertex v;
   for (all v in G) visited[v] = false;
   for (all v in G) if (!visited[v])
      traverse(v, visited, visit);
}


template <int max_size>
void Digraph<max_size>::traverse(Vertex &v, bool visited[],
                                 void (*visit)(Vertex &)) const
/*
Pre:  v is a vertex of the Digraph.
Post: The depth-first traversal, using function *visit, has been completed
      for v and for all vertices that can be reached from v.
Uses: traverse recursively.
*/
{
   Vertex w;
   visited[v] = true;
   (*visit)(v);
   for (all w adjacent to v)
     if (!visited[w])
        traverse(w, visited, visit);
}


template <int max_size>
void Digraph<max_size>::breadth_first(void (*visit)(Vertex &)) const
/*
Post: The function *visit has been performed at each vertex of the
      Digraph in breadth-first order.
Uses: Methods of class Queue.
*/
{
   Queue q;
   bool visited[max_size];
   Vertex v, w, x;
   for (all v in G) visited[v] = false;
   for (all v in G)
     if (!visited[v]) {
        q.append(v);
        while (!q.empty()){
           q.retrieve(w);
           if (!visited[w]) {
              visited[w] = true;
              (*visit)(w);
              for (all x adjacent to w)
                 q.append(x);
           }
           q.serve();
        }
     }
}




// Section 12.4:

typedef int Vertex;

template <int graph_size>
class Digraph {
public:
   Digraph();
   void read();
   void write();

//  methods to do a topological sort
   void depth_sort(List<Vertex> &topological_order);
   void breadth_sort(List<Vertex> &topological_order);

private:
   int count;
   List <Vertex> neighbors[graph_size];
   void recursive_depth_sort(Vertex v, bool visited[],
                             List<Vertex> &topological_order);
};


template <int graph_size>
void Digraph<graph_size>::depth_sort(List<Vertex> &topological_order)
/*
Post: The vertices of the Digraph are placed into
      List topological_order with a depth-first traversal
      of those vertices that do not belong to a cycle.
Uses: Methods of class List, and function recursive_depth_sort
      to perform depth-first traversal.
*/
{
   bool visited[graph_size];
   Vertex v;
   for (v = 0; v < count; v++) visited[v] = false;
   topological_order.clear();
   for (v = 0; v < count; v++)
      if (!visited[v])  //  Add v and its successors into topological order.
         recursive_depth_sort(v, visited, topological_order);
}


template <int graph_size>
void Digraph<graph_size>::recursive_depth_sort(Vertex v, bool *visited,
                          List<Vertex> &topological_order)
/*
Pre:  Vertex v of the Digraph does not belong to
      the partially completed List topological_order.
Post: All the successors of v and finally v itself are added to
      topological_order with a depth-first search.
Uses: Methods of class List and the function recursive_depth_sort.
*/
{
   visited[v] = true;
   int degree = neighbors[v].size();
   for (int i = 0; i < degree; i++) {
      Vertex w;                       //  A (neighboring) successor of v
      neighbors[v].retrieve(i, w);
      if (!visited[w])                //  Order the successors of w.
         recursive_depth_sort(w, visited, topological_order);
   }
   topological_order.insert(0, v);    //  Put v into topological_order.
}


template <int graph_size>
void Digraph<graph_size>::breadth_sort(List<Vertex> &topological_order)
/*
Post: The vertices of the Digraph are arranged into the List
      topological_order which is found with a breadth-first
      traversal of those vertices that do not belong to a cycle.
Uses: Methods of classes Queue and List.
*/
{
   topological_order.clear();
   Vertex v, w;
   int predecessor_count[graph_size];
   for (v = 0; v < count; v++) predecessor_count[v] = 0;
   for (v = 0; v < count; v++)
      for (int i = 0; i < neighbors[v].size(); i++) { //  Loop over all edges v -- w.
         neighbors[v].retrieve(i, w);
         predecessor_count[w]++;
      }
   Queue ready_to_process;
   for (v = 0; v < count; v++)
      if (predecessor_count[v] == 0)
         ready_to_process.append(v);
   while (!ready_to_process.empty()) {
      ready_to_process.retrieve(v);
      topological_order.insert(topological_order.size(), v);
      for (int j = 0; j < neighbors[v].size(); j++) { //  Traverse successors of v.
         neighbors[v].retrieve(j, w);
         predecessor_count[w]--;
         if (predecessor_count[w] == 0)
            ready_to_process.append(w);
      }
      ready_to_process.serve();
   }
}




// Section 12.5:

template <class Weight, int graph_size>
class Digraph {
public:
    //  Add a constructor and methods for Digraph input and output.
   void set_distances(Vertex source, Weight distance[]) const;
protected:
   int count;
   Weight adjacency[graph_size][graph_size];
};


const Weight infinity = numeric_limits<int>::max();


template <class Weight, int graph_size>
void Digraph<Weight, graph_size>::set_distances(Vertex source,
                                  Weight distance[]) const
/*
Post: The array distance gives the minimal path weight from vertex source
      to each vertex of the Digraph.
*/
{
   Vertex v, w;
   bool found[graph_size];   //  Vertices found in S
   for (v = 0; v < count; v++) {
      found[v] = false;
      distance[v] = adjacency[source][v];
   }
   found[source] = true; //  Initialize with vertex source alone in the set S.
   distance[source] = 0;
   for (int i = 0; i < count; i++) { //  Add one vertex v to S on each pass.
      Weight min = infinity;
      for (w = 0; w < count; w++) if (!found[w])
         if (distance[w] < min) {
            v = w;
            min = distance[w];
         }
      found[v] = true;
      for (w = 0; w < count; w++) if (!found[w])
         if (min + adjacency[v][w] < distance[w])
             distance[w] = min + adjacency[v][w];
   }
}




// Section 12.6:

template <class Weight, int graph_size>
class Network: public Digraph<Weight, graph_size> {
public:
   Network();
   void read();   //  overridden method to enter a Network
   void make_empty(int size = 0);
   void add_edge(Vertex v, Vertex w, Weight x);
   void minimal_spanning(Vertex source,
                         Network<Weight, graph_size> &tree) const;
};


template <class Weight, int graph_size>
void Network<Weight, graph_size>::minimal_spanning(Vertex source,
                     Network<Weight, graph_size> &tree) const
/*
Post: The Network tree contains a minimal spanning tree for the
      connected component of the original Network that contains vertex source.
*/
{
   tree.make_empty(count);
   bool component[graph_size];   //  Vertices in set X
   Weight distance[graph_size];  //  Distances of vertices adjacent to X
   Vertex neighbor[graph_size];  //  Nearest neighbor in set X
   Vertex w;

   for (w = 0; w < count; w++) {
      component[w] = false;
      distance[w] = adjacency[source][w];
      neighbor[w] = source;
   }
   component[source] = true;     //  source alone is in the set X.
   for (int i = 1; i < count; i++) {
      Vertex v;                  //  Add one vertex v to X on each pass.
      Weight min = infinity;
      for (w = 0; w < count; w++) if (!component[w])
         if (distance[w] < min) {
            v = w;
            min = distance[w];
         }

      if (min < infinity) {
         component[v] = true;
         tree.add_edge(v, neighbor[v], distance[v]);
         for (w = 0; w < count; w++) if (!component[w])
            if (adjacency[v][w] < distance[w]) {
               distance[w] = adjacency[v][w];
               neighbor[w] = v;
            }
      }
      else break;            //  finished a component in disconnected graph
   }
}

/*************************************************************************/

