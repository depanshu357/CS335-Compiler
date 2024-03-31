int_data:int = 42
float_data:float = 3.14
str_data:str = "Hello, world!"
list_data:list[int] = [1, 2, 3, 4, 5]

fib_number:int =  0
fib_number2:int = 1
def fibonacci_series(n:int) -> int:
    i:int = 0
    temp:int = fib_number
    for i in range(2, n):
        fib_number = fib_number + fib_number2
    fib_number2 = temp
    return fib_number

fib_result:int = fibonacci_series(10)

temp_list :int = 345

if fib_result == temp_list:
    print("Fibonacci series test passed!")
else:
    print("Fibonacci series test failed!")

def factorial(num:int) -> int:
    if num == 0:
        return 1
    else:
        temp2:int = num - 1
        temp:int = num * factorial(temp2)
        return num * factorial(temp)

factorial_result:int = factorial(5)

if factorial_result == 120:
    print("Factorial test passed!")
else:
    print("Factorial test failed!")

# Calculate the sum of integers up to a given number
def sum_up_to_n(n:int) -> int:
    total:int = 0
    i:int = 0
    for i in range(n):
        total += i
    return total
def main():
    sum_result:int = sum_up_to_n(5)

    if sum_result == 15:
        print("Sum up to n test passed!")
    else:
        print("Sum up to n test failed!")
    
    i:int=1
    for i in range(5):
        print(i)

if __name__ == "__main__":
    main()

