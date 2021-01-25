def decodeMorse(morse_code):
    # ToDo: Accept dots, dashes and spaces, return human-readable message
    return ' '.join(''.join(MORSE_CODE[letter] for letter in word.split(' ')) for word in morse_code.strip().split('   '))

decodeMorse("")