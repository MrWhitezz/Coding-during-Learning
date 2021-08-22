# import os

# cwd = os.getcwd()  # Get the current working directory (cwd)
# files = os.listdir(cwd)  # Get all the files in that directory
# print("Files in %r: %s" % (cwd, files))

file_path = '/Users/xyq/projects/Coding-during-Learning/Python/Class_File/pi_digits.txt'
with open(file_path) as file_object: 
    #contents = file_object.read() 
    for line in file_object:
        print(line.rstrip())