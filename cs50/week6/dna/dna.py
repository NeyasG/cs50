import csv
import sys
import re


def main():

    # Check for command-line usage
    if __name__ == "__main__" and len(sys.argv) != 3:
        print("Usage: python dna.py data.csv sequence.txt")

    # Read database file into a variable
    with open(sys.argv[1], "r") as csvfile:
        database = csv.DictReader(csvfile)
        # debug
        # for row in database:
        #     print(row['name'], row['AGATC'])
        headers = database.fieldnames

        # Read DNA sequence file into a variable
        with open(sys.argv[2], "r") as file:
            sequence = file.read()
            # print(sequence)

        # decided to make my own longest Match :)
        # Find longest match of each STR in DNA sequence
        # Create empty dict to store STR lengths
        STR_counts = {}
        for name in headers[1:]:
            # finds a list of all matches of {name}
            regex = f'(?:{name})+'
            matches = re.findall(regex, sequence)
            # finds max length of values returned list
            # from https://stackoverflow.com/questions/59746080/count-max-consecutive-re-groups-in-a-string
            try:
                max_len = max(map(len, matches)) // len(name)
            except ValueError:
                max_len = 0
            # adds to dict with key = name and value = max_len
            STR_counts[name] = str(max_len)

        print(STR_counts)

        # TODO: Check database for matching profiles
        # if STR_counts.items() <= database.items():
        #     print("True")

    return


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


main()
