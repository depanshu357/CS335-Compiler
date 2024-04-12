# def main():
#     i:int=123
#     print(i)
#     # data : list[int] = [5, 3, 8, 2, 1, 9, 4, 6, 7]
#     # i: int = data[0]
#     # j: int = data[8]
#     # print(i)
#     # print(j)
    




def temp(a:int)->int:
    if(a==0):
        return 0
    if(a==1):
        return 1
    return temp(a-1)+ temp(a-2)

def main():
    i:int=123
    print(i)
    i=temp(30)
    print(i)
    # i=temp(12)
    # print(i)
    # i=4
    # i:int = 4 and 5 
