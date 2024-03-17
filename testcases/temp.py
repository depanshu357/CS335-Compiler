class fun():
    def __init__(self,b:int)->None:
        self.x:int = 110
        self.y:int = b

    def run(self)->None:
        self.y=12
        y:int = 8
        self.y = y

        print(self.y, y)
        return


