def merge_sort(lst):
    if len(lst) <= 1:
        return lst
    mid = len(lst) // 2
    left = merge_sort(lst[:mid])
    right = merge_sort(lst[mid:])
    return merge(left, right)

def merge(left, right):
    merged = []
    left_index = right_index = 0
    while left_index < len(left) and right_index < len(right):
        if left[left_index] <= right[right_index]:
            merged.append(left[left_index])
            left_index += 1
        else:
            merged.append(right[right_index])
            right_index += 1
    merged.extend(left[left_index:])
    merged.extend(right[right_index:])
    return merged

def quick_sort(lst):
    if len(lst) <= 1:
        return lst
    pivot = lst[len(lst) // 2]
    left = []
    middle = []
    right = []
    for x in lst:
        if x < pivot:
            left.append(x)
        elif x == pivot:
            middle.append(x)
        else:
            right.append(x)
    return quick_sort(left) + middle + quick_sort(right)

# Test cases
def test_sorting_algorithms():
    # Test sorting an empty list
    assert merge_sort([]) == []
    assert quick_sort([]) == []

    # Test sorting a list with one element
    assert merge_sort([1]) == [1]
    assert quick_sort([1]) == [1]

    # Test sorting a list with multiple elements
    assert merge_sort([3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5]) == [1, 1, 2, 3, 3, 4, 5, 5, 5, 6, 9]
    assert quick_sort([3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5]) == [1, 1, 2, 3, 3, 4, 5, 5, 5, 6, 9]

    # Test sorting a list with negative elements
    assert merge_sort([3, -1, 4, 1, -5, 9, 2, -6, 5, 3, 5]) == [-6, -5, -1, 1, 2, 3, 3, 4, 5, 5, 9]
    assert quick_sort([3, -1, 4, 1, -5, 9, 2, -6, 5, 3, 5]) == [-6, -5, -1, 1, 2, 3, 3, 4, 5, 5, 9]

if __name__ == "__main__":
  test_sorting_algorithms()
