data : list[int] = [5, 3, 8, 2, 1, 9, 4, 6, 7]

def bubble_sort(arr:list[int]) -> list[int]:
    n:int = len(arr)
    i:int = 0
    j:int = 0
    for i in range(n - 1):
        for j in range(0, n - i - 1):
            if arr[j] > arr[j + 1]:
                arr[j], arr[j + 1] = arr[j + 1], arr[j]
    return arr

sorted_data:list[int] = bubble_sort(data)

if(sorted_data == [1, 2, 3, 4, 5, 6, 7, 8, 9]):
    print("Test passed!")



data2:list[int] = [9, 8, 7, 6, 5, 4, 3, 2, 1]
sorted_data2:list[int] = bubble_sort(data2)
if sorted_data2 == [1, 2, 3, 4, 5, 6, 7, 8, 9] :
    print("Additional test passed!")

data3:list[int] = [5, 5, 3, 8, 2, 2, 1, 1, 9, 4, 6, 6, 7]
sorted_data3:list[int] = bubble_sort(data3)
if sorted_data3 == [1, 1, 2, 2, 3, 4, 5, 5, 6, 6, 7, 8, 9] :
    print("Test with duplicate elements passed!")