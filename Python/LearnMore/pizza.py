# def make_pizza(*toppings): 
#     """概述要制作的比萨""" 
#     print("\nMaking a pizza with the following toppings:") 
#     #toppings[0] = 'nothing'
#     for topping in toppings: 
#         #topping = topping + " hello"
#         print("- " + topping)
#     # for topping in toppings:
#     #     print(topping)

# p1 = 'pepperoni'; p2 = 'mushrooms'; p3 = 'green peppers'; p4 = 'extra cheese';
# make_pizza(p1) 
# make_pizza(p2, p3, p4)
# print(p1, p2, p3, p4)

def make_pizza(size, *toppings): 
    """概述要制作的比萨""" 
    print("\nMaking a " + str(size) + 
    "-inch pizza with the following toppings:") 
    for topping in toppings: 
        print("- " + topping)