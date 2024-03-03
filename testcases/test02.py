class Stack:
    def __init__(self):
        self.stack = []

    def is_empty(self):
        return len(self.stack) == 0

    def push(self, data):
        self.stack.append(data)

    def pop(self):
        if self.is_empty():
            return None
        return self.stack.pop()

    def peek(self):
        if self.is_empty():
            return None
        return self.stack[-1]

    def size(self):
        return len(self.stack)

# Test cases
def test_stack():
    stack = Stack()

    # Test pushing onto the stack
    stack.push(1)
    assert stack.peek() == 1
    assert stack.size() == 1

    # Test popping from the stack
    assert stack.pop() == 1
    assert stack.is_empty()

    # Test popping from an empty stack
    assert stack.pop() is None

    # Test peeking at an empty stack
    assert stack.peek() is None

    # Test checking the size of an empty stack
    assert stack.size() == 0

test_stack()