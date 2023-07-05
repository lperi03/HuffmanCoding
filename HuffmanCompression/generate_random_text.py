import random
import string

#use this file to generate random text of chosen length. You can play around with the length of the text to see how the compression works
#remember to change the name of the input file in the huffmanCompression.cpp file if you decide to change the output_filename here
#have fun!!

def generate_random_text(length):
    # Generate random text of the specified length
    letters = string.ascii_letters + string.digits + string.punctuation + " "
    random_text = ''.join(random.choice(letters) for _ in range(length))
    return random_text

def save_text_to_file(text, filename):
    # Save the generated text to a file
    with open(filename, 'w') as file:
        file.write(text)

def main():
    # Define the desired length of the random text
    text_length = 1000

    # Generate random text
    random_text = generate_random_text(text_length)

    # Save the text to a file
    output_filename = "random_text.txt"
    save_text_to_file(random_text, output_filename)

    print("Random text saved to", output_filename)

if __name__ == "__main__":
    main()