class Node:
    def __init__(self, data=None):
        self.data = data
        self.next = None
        self.prev = None

class Queue:
    def __init__(self):
        self.head = None
        self.tail = None
        self.count = 0

    def is_empty(self):
        return self.count == 0

    def enqueue(self, data):
        new_node = Node(data)
        if self.tail:
            new_node.prev = self.tail
            self.tail.next = new_node
            self.tail = new_node
        else:
            self.tail = new_node
            self.head = new_node
        self.count += 1

    def dequeue(self):
        if not self.head:
            return None
        ret = self.head.data
        self.head = self.head.next
        if self.head:
            self.head.prev = None
        else:
            self.tail = None
        self.count -= 1
        return ret

    def size(self):
        return self.count

# Test cases
def test_queue():
    queue = Queue()

    # Test enqueueing to an empty queue
    queue.enqueue(1)
    assert queue.size() == 1

    # Test dequeueing from the queue
    assert queue.dequeue() == 1
    assert queue.is_empty()

    # Test dequeueing from an empty queue
    assert queue.dequeue() is None

    # Test checking the size of an empty queue
    assert queue.size() == 0

test_queue()