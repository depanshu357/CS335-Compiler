class HashTable:
    def __init__(self):
        self.size = 10
        self.table = [[] for _ in range(self.size)]

    def hash_function(self, key):
        return key % self.size

    def insert(self, key, value):
        key_hash = self.hash_function(key)
        key_value = [key, value]

        if self.table[key_hash] is None:
            self.table[key_hash] = list([key_value])
            return True
        else:
            for pair in self.table[key_hash]:
                if pair[0] == key:
                    pair[1] = value
                    return True
            self.table[key_hash].append(key_value)
            return True

    def search(self, key):
        key_hash = self.hash_function(key)
        if self.table[key_hash] is not None:
            for pair in self.table[key_hash]:
                if pair[0] == key:
                    return pair[1]
        return None

    def delete(self, key):
        key_hash = self.hash_function(key)

        if self.table[key_hash] is None:
            return False
        for i in range (0, len(self.table[key_hash])):
            if self.table[key_hash][i][0] == key:
                self.table[key_hash].pop(i)
                return True
        return False

# Test cases
def test_hash_table():
    hash_table = HashTable()

    # Test inserting into an empty hash table
    hash_table.insert(1, 'one')
    assert hash_table.search(1) == 'one'

    # Test deleting from the hash table
    assert hash_table.delete(1)
    assert hash_table.search(1) is None

    # Test deleting from an empty hash table
    assert not hash_table.delete(1)

    # Test searching in an empty hash table
    assert hash_table.search(1) is None

test_hash_table()