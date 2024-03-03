class Node:
    def __init__(self, data):
        self.left = None
        self.right = None
        self.data = data

class BinarySearchTree:
    def __init__(self):
        self.root = None

    def insert(self, data):
        if self.root is None:
            self.root = Node(data)
        else:
            self._insert(data, self.root)

    def _insert(self, data, node):
        if data < node.data:
            if node.left is None:
                node.left = Node(data)
            else:
                self._insert(data, node.left)
        elif data > node.data:
            if node.right is None:
                node.right = Node(data)
            else:
                self._insert(data, node.right)
        else:
            print("Value is already present in tree.")

    def find(self, data):
        if self.root:
            is_found = self._find(data, self.root)
            if is_found:
                return True
            return False
        else:
            return None

    def _find(self, data, node):
        if data > node.data and node.right:
            return self._find(data, node.right)
        elif data < node.data and node.left:
            return self._find(data, node.left)
        if data == node.data:
            return True

# Test cases
def test_binary_search_tree():
    bst = BinarySearchTree()

    # Test inserting into an empty tree
    bst.insert(4)
    assert bst.find(4)

    # Test inserting smaller and larger values
    bst.insert(2)
    bst.insert(6)
    assert bst.find(2)
    assert bst.find(6)

    # Test inserting duplicate values
    bst.insert(4)
    assert bst.find(4)

    # Test finding non-existent values
    assert not bst.find(1)

if __name__ == "__main__":
  test_binary_search_tree()
