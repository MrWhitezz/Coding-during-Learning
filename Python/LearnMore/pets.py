pets = ['dog', 'cat', 'dog', 'goldfish', 'cat', 'rabbit', 'cat'] 
print(pets) 
while 'cat' in pets: 
    pets.remove('cat') 
print(pets)

def describe_pet(animal_type, pet_name): 
    """显示宠物的信息""" 
    print("\nI have a " + animal_type + ".") 
    print("My " + animal_type + "'s name is " + pet_name.title() + ".") 
describe_pet('hamster', 'harry')
describe_pet(animal_type='hamster', pet_name='harry') 
describe_pet(pet_name='harry', animal_type='hamster')

def describe_pet(pet_name, animal_type='dog'): 
    """显示宠物的信息""" 
    print("\nI have a " + animal_type + ".") 
    print("My " + animal_type + "'s name is " + pet_name.title() + ".")
describe_pet('sjz')