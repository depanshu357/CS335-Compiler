class Test:
    def __init__(self):
        self.a:int = 1

    def add(self,  b:int)->int:
        x:int = self.a +b
        return x


                

def main():
    # arr:list[int] = [64, 34, 25, 12, 22, 11, 90]
    # t1:Test = Test()
    # t2:Test = Test()
    # arr:list[Test]=[t1,t2]
    i:Test = Test()
    j:int = 0
    # for i in arr:
    j = i.add(1)
    print(j)



