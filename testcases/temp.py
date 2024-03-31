data: list[float] = [-2.3, 3.14, 0.9, 11, -9.1]


def compute_min() -> int:
  min_value: float = 0
  i: int = 0
  for i in range(len(data)):
    if not min_value:
      min_value = data[i]
    elif data[i] < min_value:
      min_value = data[i]
  return min_value


def compute_avg() -> int:
  avg_value: float = 0
  sum: int = 0
  i: int = 0
  for i in range(len(data)):
    sum += data[i]
  return sum / len(data)


def main():
  min_value: int = compute_min()
  print("Minimum value: ")
  print(min_value)
  avg_value: int = compute_avg()
  print("Average value: ")
  print(avg_value)


if __name__ == "__main__":
  main()
