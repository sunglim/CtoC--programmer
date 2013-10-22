#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <string>
#include <vector>
#include <cmath>

typedef int ElementType;

const int kGraphSize = 10;
int getRandomNumber() {
  return rand() % kGraphSize;
}
double randomDistance() {
  const double kStart = 1.0;
  const double kEnd = 10.0;
  double k = (double)(rand() % 100 + 1)/10;
  std::cout << k << "@@@"<< std::endl;
  return k;
}

struct Node {
  Node(){
    Distance = -1;
  }
  double Distance;
};


// using adjacency matrix.
class Graph {
 public:
  Graph() {
    adjacent = std::vector<std::vector<Node> >(kGraphSize, std::vector<Node>(kGraphSize,Node()));
  }
  Graph(double density) {
    adjacent = std::vector<std::vector<Node> >(kGraphSize, std::vector<Node>(kGraphSize,Node()));
    srand(time(NULL));
    int edgesNeeded = static_cast<int>(std::floor((density*kGraphSize*(kGraphSize-1)/2)));
    std::cout << edgesNeeded << "!!" << std::endl;
    int rand_x;
    int rand_y;
    double distance;
    while (edgesNeeded) {
      rand_x = getRandomNumber(); 
      rand_y = getRandomNumber(); 
      if (rand_x == rand_y) continue;
      distance = randomDistance();
      if (adjacent[rand_x][rand_y].Distance == -1) {
        adjacent[rand_x][rand_y].Distance = distance;
        adjacent[rand_y][rand_x].Distance = distance;
        edgesNeeded--;
      }
    }
  }

  // Returns the number of vertices in the graph.
  int V(Graph graph) {
    return -1;
  };
  
  // Returns the number of edges in the graph.
  int E(Graph graph) {
    return -1;
  };
  
  // tests whether there is an edge from node x to node y.
  static bool is_adjacent(const Graph& graph, const Node& node_x,
                          const Node& node_y) {
    return false;
  }

  // lists all nodes y such that there is an edge from x to y.
  static std::list<Node> neighbors(const Graph& graph, const Node& node) {
    return std::list<Node>();
  }

  // Adds to G the edge from x to y, if it is not there.
  bool static add(Graph* graph, const Node& node_x, const Node& node_y) {
    return false;
  }

  // removes the edge from x to y, if it is there
  bool static deleteEdge(Graph* graph, const Node& node_x, const Node& node_y) {
    return false;
  }

  // returns the value asssociated with the node x.
  int get_node_value(Graph* graph, const Node& node) {
    return -1; 
  }

  // set the vlaue associated with the node x to a.
  bool set_node_value(Graph* graph, const Node& node_x, const Node& node_a) {
    return false;
  }

  // returns the vlaue ssociated to the edge (x,y)
  int get_edge_value(Graph& graph, const Node& node_x, const Node& node_y) {
    return -1;
  }

  bool set_edge_value(Graph* graph, const Node& node_x, const Node& node_y,
                      const Node& node_v) {
    return -1;
  }

  void printGraph() {
    for (int i=0;i<kGraphSize;i++) {
      for (int j=0;j<kGraphSize;j++) {
        std::cout << std::setw(3) <<  adjacent[i][j].Distance << " ";
      }
      std::cout << std::endl;
    }
  }

 private:
  std::vector<std::vector<Node> > adjacent;
};

struct QueueElement {
  int priority_;
  int data_;
  bool operator<(QueueElement element) {
    return priority_ < element.priority_;
  }
  bool operator>(QueueElement element) {
    return priority_ > element.priority_;
  }
};

class PriorityQueue {
 public:
  void chgPriority(int priority) {
  }
  void minPriority() {
    queue[0] = queue.back();
    queue.pop_back();
    int here = 0;
    while (true) {
      int left = here *2 +1, right = here *2 +2;
      if (left >= queue.size()) 
        break;
      int next = here;
      if (queue[next] < queue[left])
        next =left;
      if (right < queue.size() && queue[next] < queue[right])
        next = right;
      if (next ==here) break;
      std::swap(queue[next],queue[here]);
      here = next;
    }
  }
  bool contains(QueueElement queue_element) {
    return std::find(queue.begin(), queue.end(), queue_element) != queue.end();
  }
  void Insert(QueueElement queue_element) {
    queue.push_back(queue_element);
    int idx = queue.size() - 1;
    while (idx > 0 && queue[(idx -1) /2] > queue[idx]) {
      std::swap(queue[idx],queue[(idx-1)/2]); 
      idx = (idx-1)/2;
    }
  }
  QueueElement top() {
    if (queue.empty()) {
      QueueElement errorElement;
      errorElement.priority_ = 0;
      errorElement.data_ = 0;
      return errorElement;
    }
    return queue.front();
  }
  int size(){
    return queue.size();
  }
 private:
  std::vector<QueueElement> queue;
};

class ShortestPath {
 public:
  std::list<int> vertices() {
  }
  void path(Node x, Node y) {
  }
  int path_size(Node x, Node y) {
    return -1;
  }
 private:
};

int main()
{
  Graph graph(0.4);
  graph.printGraph();
  return 0;
}
