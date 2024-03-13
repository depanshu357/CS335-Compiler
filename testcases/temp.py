# Test case 2: Accessing an array with a non-integer index
def test_array_index()->None:
    my_list:list[int] = [10, 20, 30]
    value:int = my_list['index']
