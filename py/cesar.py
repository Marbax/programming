#!/usr/bin/python
import sys

alphabet = 'abcdefghijklmnopqrstuvwxyz'
text = sys.argv[1].lower()
shift = int(sys.argv[2])
coded_text = ''
new_letter = ''
letter_position = None

for letter in text:
    letter_position = alphabet.find(letter)
    if letter_position != -1:
        new_letter = alphabet[(letter_position + shift) % len(alphabet)]
    else:
        new_letter = letter
    coded_text = coded_text + new_letter
print coded_text
