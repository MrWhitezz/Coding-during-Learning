# magicians = ['adaf', 'bbb', 'nice']
# for magician in magicians:
#     print("I love " + magician)
#     print("And you?" + magician + "\n" )

#     print("ANother")
# print("Finish")
# message = "YEs"
# print(message)
# for val in range(1,10):
#     print(val)
numbers = list(range(1, 11))
# print(numbers)
squares = []
for val in numbers:
    squares.append(val ** 2)
# print(min(squares))
# print(max(squares))
# print(sum(squares))
cubes = [val ** 3 for val in numbers]
print(cubes)
