def readFile(input):
    try:
        with open(input, 'rb') as f:
            byte_string = f.read()
    except IOError:
        print("Error: File does not appear to exist.")
    return byte_string

def newFile(byteString):
    newArray = []
    for byte in byteString:
        if byte == 123:
            newArray.append(10)
            newArray.append(byte)
        else:
            newArray.append(byte)
    result = ''.join(chr(i) for i in newArray)
    return result.encode("ascii")

print(readFile('test.c'))
print("\nAfter formatting: ")
print(newFile(readFile('test.c')))