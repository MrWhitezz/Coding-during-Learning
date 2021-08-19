from random import randint

# while (input()):
#     x = randint(1, 6)
#     print(x)

class Die():
    def __init__(self, sides=6):
        self.sides_of_die = sides
    
    def roll_die(self):
        print(randint(1, self.sides_of_die))

my_die = Die(20)
for i in range(1,11):
    my_die.roll_die()