class Node:
    def __init__(self, key):
        self.left = None
        self.right = None
        self.val = key

class BST:
    def __init__(self):
        self.root = None

    def insert(self, key):
        if self.root is None:
            self.root = Node(key)
        else:
            self._insert(self.root, key)

    def _insert(self, node, key):
        if key < node.val:
            if node.left is None:
                node.left = Node(key)
            else:
                self._insert(node.left, key)
        elif key > node.val:
            if node.right is None:
                node.right = Node(key)
            else:
                self._insert(node.right, key)

    def search(self, key):
        return self._search(self.root, key)

    def _search(self, node, key):
        if node is None or node.val == key:
            return node
        if key < node.val:
            return self._search(node.left, key)
        return self._search(node.right, key)

# Test cases
def test_bst():
    bst = BST()

    # Test inserting into an empty tree
    bst.insert(50)
    assert bst.root.val == 50

    # Test inserting values less than the root
    bst.insert(30)
    assert bst.root.left.val == 30

    # Test inserting values greater than the root
    bst.insert(70)
    assert bst.root.right.val == 70

    # Test inserting duplicate values
    bst.insert(70)
    assert bst.root.right.val == 70

    # Test searching for a value in the tree
    assert bst.search(70) is not None

    # Test searching for a value not in the tree
    assert bst.search(100) is None

test_bst()