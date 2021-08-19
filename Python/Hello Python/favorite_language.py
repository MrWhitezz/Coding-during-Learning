favorite_languages = { 
    'jen': 'python', 
    'sarah': 'c', 
    'edward': 'ruby', 
    'phil': 'python',
}
print("Sarah's favorite language is " + 
    favorite_languages['sarah'].title() + 
    ".")

for name, language in favorite_languages.items(): 
    print(name.title() + "'s favorite language is " + 
    language.title() + ".")

for name in favorite_languages.keys(): 
    print(name.title())
print(favorite_languages.items())
print(favorite_languages)
print(favorite_languages.keys())
print(sorted(favorite_languages.keys()))

for name in sorted(favorite_languages.keys()): 
    print(name.title() + ", thank you for taking the poll.")
for language in favorite_languages.values(): 
    print(language.title())

print("The following languages have been mentioned:") 
for language in set(favorite_languages.values()): 
    print(language.title())

favorite_languages = { 
    'jen': ['python', 'ruby'], 
    'sarah': ['c'], 
    'edward': ['ruby', 'go'], 
    'phil': ['python', 'haskell'], 
}
for name, languages in favorite_languages.items(): 
    print("\n" + name.title() + "'s favorite languages are:") 
    for language in languages: 
        print("\t" + language.title())