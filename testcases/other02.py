class Graph:
    def __init__(self):
        self.graph = {}

    def add_vertex(self, vertex):
        if vertex not in self.graph:
            self.graph[vertex] = []

    def add_edge(self, vertex1, vertex2):
        if vertex1 in self.graph and vertex2 in self.graph:
            self.graph[vertex1].append(vertex2)
            self.graph[vertex2].append(vertex1)

    def remove_vertex(self, vertex):
        if vertex in self.graph:
            while self.graph[vertex] != []:
                adjacent_vertex = self.graph[vertex][0]
                self.remove_edge(vertex, adjacent_vertex)
            del self.graph[vertex]

    def remove_edge(self, vertex1, vertex2):
        if vertex1 in self.graph and vertex2 in self.graph:
            self.graph[vertex1].remove(vertex2)
            self.graph[vertex2].remove(vertex1)

    def search(self, vertex):
        return vertex in self.graph

# Test cases
def test_graph():
    graph = Graph()

    # Test adding vertices
    graph.add_vertex(1)
    graph.add_vertex(2)
    assert graph.search(1)
    assert graph.search(2)

    # Test adding edges
    graph.add_edge(1, 2)
    assert 2 in graph.graph[1]
    assert 1 in graph.graph[2]

    # Test removing edges
    graph.remove_edge(1, 2)
    assert 2 not in graph.graph[1]
    assert 1 not in graph.graph[2]

    # Test removing vertices
    graph.remove_vertex(1)
    assert not graph.search(1)

    # Test adding edges to non-existent vertices
    graph.add_edge(1, 2)
    assert 2 not in graph.graph
    assert 1 not in graph.graph

    # Test removing non-existent vertices
    graph.remove_vertex(1)
    assert not graph.search(1)

    # Test searching for non-existent vertices
    assert not graph.search(1)

if __name__ == "__main__":
  test_graph()
