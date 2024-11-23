from cs50 import get_string
import re
import string

def main():
    text = get_string("Text: ")

    letter = count_letters(text)
    word = count_words(text)
    sentence = count_sentences(text)

    L = (float(letter) / float(word)) * 100
    S = (float(sentence) / float(word)) * 100
    index = round(0.0588 * L - 0.296 * S - 15.8, 0)

    if (index < 1):
        print(f"Before Grade 1")
    elif (index >= 16):
        print(f"Grade 16+")
    else:
        print(f"Grade {index}")

def count_letters(text):
    count = 0
    for char in text:
        if (re.match("[a-zA-Z]", char)):
            count += 1
    return count

def count_words(text):
    count = 0
    for char in text:
        if (char == " "):
            count += 1
    return count

def count_sentences(text):
    count = 0
    for char in text:
        if (char == ".") or (char == "!") or (char == "?"):
            count += 1
    return count

if __name__ == "__main__":
    main()
