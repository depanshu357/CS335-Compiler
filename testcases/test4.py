
def fibonacci(n:int)->int:
    if n <= 0:
        return 0
    elif n == 1:
        return 1
    else:
        return fibonacci(n-1) + fibonacci(n-2)

def main():
    # Fibonacci code
    fib_number1:int = fibonacci(9)
    fib_number2:int = fibonacci(10)
    fib_number3:int = fibonacci(11)
    print(fib_number1)    
    print(fib_number2)
    print(fib_number3)
    # Correct answer: 34, 55, 89
    if(fib_number1 == 34 and fib_number2 == 55 and fib_number3 == 89):
        print("Fibonacci test passed")
    else:
        print("Fibonacci test failed")
    
    if(fib_number3 == fib_number2 + fib_number1):
        print("Fibonacci test passed")
    else:
        print("Fibonacci test failed")

if __name__ == "__main__":
    main()
