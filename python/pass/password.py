import pyperclip
import secrets

VALID = [' ', '!', '"', '#', ' ', '$', '%', '&', "'", '(', ')', '*', '+', ',', '-', '.', '/', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', ':', ';', '<', '=', '>', '?', '@', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
         'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '[', '\\', ']', '^', '_', '`', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '{', '|', '}', '~']


def password(length):
    if (length < 5 or length > 128):
        raise AssertionError

    result = ""
    for _ in range(length):
        rand = secrets.randbelow(len(VALID))
        ascii_char = VALID[rand]
        result += ascii_char

    return result


def read_user_input():
    while True:
        try:
            user_input = input()

            is_num = user_input.isdigit()
            if not is_num:
                raise TypeError

            result = int(user_input)

            if result < 5 or result > 128:
                raise ValueError
            else:
                break

        except ValueError:
            print(
                "Remember that this number must be greater than 4 and smaller than 129 (not inclusive)")
        except TypeError:
            print("Input must be an integer")

    return result


def main():
    print("Hello! Please type the number of characters that your password will have:")
    print("Remember that this number must be greater than 4 and smaller than 129 (not inclusive)")

    length = read_user_input()
    passw = password(length)

    print(f"Your new password is: " + passw)
    pyperclip.copy(passw)
    print("Your password has been copied to clipboard!")


if __name__ == '__main__':
    main()
