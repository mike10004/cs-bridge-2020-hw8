#!/usr/bin/env python3

import json
import random


def main():
    n = 20
    rng = random.Random()
    bound_pairs = [
        (-10000, 10000),
        (1, 20),
        (-3, 5),
        (-50, 50),
        (-20, 5),
        (-200, -170),
    ]
    book_case = [
        "14 5 12 5 6 14 5 12 14 12 14 6 8 7 5 136 9 2189 10 6",
        "5",
        "1 3 6 14",
    ]
    cases = [book_case]
    for minval, maxval in bound_pairs:
        numbers = []
        for i in range(n):
            numbers.append(rng.randrange(minval, maxval))
        minval = min(numbers)
        indices = [i for i, x in enumerate(numbers) if x == minval]
        case = (
            ' '.join(map(str, numbers)),
            str(minval),
            ' '.join(map(str, indices)),
        )
        cases.append(case)
    definition = {
        "input": "{numbers}\n",
        "expected": "Please enter 20 integers separated by a space:\n{numbers}\nThe minimum value is {minvalue}, and it is located in the following indices: {indices}\n",
        "param_names": [
            "numbers", "minvalue", "indices"
        ],
        "test_cases": cases
    }
    print(json.dumps(definition, indent=2))
    return 0


if __name__ == '__main__':
    exit(main())
