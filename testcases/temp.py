def main():
    data : list[int] = [5, 3, 8, 2, 1, 9, 4, 6, 7]
    i:int=0
    for i in range(0,8):
        data[i] = data[i+1]
    i = data[8]
    print(i)


