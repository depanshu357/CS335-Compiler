def max(a: int, b: int) -> int: 
    if (a > b):
        return a
    else:
        return b
    
def knapSack(W: int, wt: list[int], val: list[int], n: int) -> int:
    if n == 0 or W == 0:
        return 0
    result:int = 0
    if( wt[n - 1]) > W:
        result = knapSack(W, wt, val, n - 1)
    else:
        temp1:int =5 + knapSack(W - wt[n - 1], wt, val, n - 1)
        temp2:int = knapSack(W, wt, val, n - 1)
        result = max(temp1, temp2)
    return result

if __name__ == "__main__":
    val:list[int] = [60, 100, 120]
    wt:list[int] = [10, 20, 30]
    W:int = 50
    n:int = 3
    z:int=max(3, 4)
    print("KnapSack done")

