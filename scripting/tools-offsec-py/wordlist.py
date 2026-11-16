##Username Generator
for i in range(150):
    if i % 3 == 0:
        print('wiener');     
    else:
        print('carlos');
        

print('\n\n--------------------\n\n')

##Password Generator
file = open("example.txt", "r")

i = 0;
for line in file:
    if i % 2 == 0:
        print('peter');
        print(line.strip('\n'));
    else:
        print(line.strip('\n'));
    i+= 1;

file.close()