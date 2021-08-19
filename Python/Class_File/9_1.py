class Restaurant():
    def __init__(self, name, type):
        self.restaurant_name = name
        self.cuisine_type = type

    def descibe_restaurant(self):
        print("The name of this restaurant is " + self.restaurant_name)
        print("The type of cuisine is " + self.cuisine_type)
    
    def open_restanrant(self):
        print("OPEN")

r1 = Restaurant('Jinjishihui', 'complex')
r2 = Restaurant('Beijiang', 'XinJiang')
r3 = Restaurant('LongMap', 'Italian')

r1.descibe_restaurant()
r2.descibe_restaurant()
r3.open_restanrant()