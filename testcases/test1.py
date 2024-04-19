def bubbleSort(array: list[int]) -> None:
  i: int = 0
  j: int = 0
  for i in range(len(array)):
    swapped: bool = False
    for j in range(0, len(array) - i - 1):
      if array[j] > array[j + 1]:
        temp: int = array[j]
        array[j] = array[j + 1]
        array[j + 1] = temp
        swapped = True
    if not swapped:
      break

def binarySearch(array: list[int], x: int, low: int, high: int) -> int:
  while low <= high:
      mid: int = low + (high - low) // 2
      if array[mid] == x:
          return mid
      elif array[mid] < x:
          low = mid + 1
      else:
          high = mid - 1
  return -1


def main():
  data: list[int] = [3, 0, 5, -9, 10, 15, -7, -5]
  bubbleSort(data)

  print("Sorted Array in Ascending Order:")
  i: int = 0
  for i in range(len(data)):
    print(data[i])

  index:int = 0
  index = binarySearch(data, 11, 0, len(data) - 1)
  if(index == -1):
    print("11 not found in the array")
  else:
    print("11 found at index: ")
    print(index)

  index = 0
  index = binarySearch(data, -9, 0, len(data) - 1)
  if(index == -1):
    print("-9 not found in the array")
  else:
    print("-9 found at index: ")
    print(index)
  
  index = 0
  index = binarySearch(data, 100, 0, len(data) - 1)
  if(index == -1):
    print("100 not found in the array")
  else:
    print("100 found at index: ")
    print(index)

if __name__ == "__main__":
  main()
