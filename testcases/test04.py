class Node:
    def __init__(self, data=None):
        self.data = data
        self.next = None

class LinkedList:
    def __init__(self):
        self.head = None

    def add(self, data):
        if not self.head:
            self.head = Node(data)
        else:
            current = self.head
            while current.next:
                current = current.next
            current.next = Node(data)

    def remove(self, data):
        if self.head is None:
            return
        if self.head.data == data:
            self.head = self.head.next
            return
        current = self.head
        while current.next:
            if current.next.data == data:
                current.next = current.next.next
                return
            current = current.next

    def search(self, data):
        current = self.head
        while current:
            if current.data == data:
                return True
            current = current.next
        return False

# Test cases
def test_linked_list():
    linked_list = LinkedList()

    # Test adding to an empty list
    linked_list.add(1)
    assert linked_list.search(1)

    # Test removing from the list
    linked_list.remove(1)
    assert not linked_list.search(1)

    # Test removing from an empty list
    linked_list.remove(1)
    assert not linked_list.search(1)

    # Test searching in an empty list
    assert not linked_list.search(1)

test_linked_list()