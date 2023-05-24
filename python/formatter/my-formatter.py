
def readFile(input):
    try:
        with open(input, 'rb') as f:
            byte_string = f.read()
    except IOError:
        print("Error: File does not appear to exist.")
    return byte_string

def bracket_counter(byte_string):
    stack = []
    positions = []
    brackets = []
    counter = 0
    i = 0
    for byte in byte_string:
        if byte == 123:
            stack.append(counter)
            counter += 1
            positions.append(i)
            brackets.append(byte)
            print(counter)
        elif byte == 125:
            counter -= 1
            stack.append(counter)
            positions.append(i)
            brackets.append(byte)
            print(counter)
        i = i + 1
    return stack, positions, brackets


def newString(byte_string, stack: list, positions: list, brackets: list):
    new_string = []
    for i in range(len(byte_string)):
        if i == positions[0]:
            if brackets[0] == 123:
                new_string.append(10)
                j = 0
                while j < stack[0]*4 :
                    new_string.append(32)
                    j += 1

                new_string.append(byte_string[i])
                new_string.append(10)

                positions.pop(0)
                brackets.pop(0)
                stack.pop(0)
            else:
                
                while j < stack[0]*4 :
                    new_string.append(32)
                    j += 1
                new_string.append(byte_string[i])
                new_string.append(10)

                positions.pop(0)
                brackets.pop(0)
                stack.pop(0)
                
        else:
            new_string.append(byte_string[i])

    return new_string

def listToString(s):
    str1 = ""
    for ele in s:
        str1 += chr(ele)
    return str1

def main():
    byte_string = readFile('test.c')
    stack, positions, brackets = bracket_counter(byte_string)
    print(stack)
    new_string = newString(byte_string, stack, positions, brackets)
    s1 = listToString(new_string)

    print(s1)

if __name__ == "__main__":
    main()
