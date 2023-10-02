# Usage: `local_testing_tool.py`.

from collections import Counter

import math
import random
import sys

RANDOM_SEED = 123456789
TEST_CASES = 100
MIN_AB = 1
MAX_AB = 10**9
MIN_N = MAX_N = 100
MAX_LINE_LENGTH = 100000
TEST_TYPES = 7
test_types_seen = set()


def ConfigureIO():
  """Configures IO backed by stdin/stdout and encapsulating common processing.

  Common processing includes things like raising exceptions on invalid input and
  flushing stdout after each output.

  Returns:
    (Input, Output) tuple where both members are functions, reading and output a
    line to standard IO streams respectively
  """

  def Input():
    try:
      return input()
    except Error as e:
      raise Error(INVALID_LINE_ERROR + str(e))

  Output = ActuallyOutput
  return Input, Output


def RunCase(test_case):
  Input, Output = ConfigureIO()

  random.seed(RANDOM_SEED + test_case)

  n = random.randint(MIN_N, MAX_N)

  Output(n)

  # Read the set of N numbers provided by the solution.
  a = ReadInts(
      Input(),
      inclusive_min_n=n,
      inclusive_max_n=n,
      inclusive_min_value=MIN_AB,
      inclusive_max_value=MAX_AB)
  a_as_set = set(a)

  if len(a) != len(a_as_set):
    raise Error(NUMBERS_ARE_NOT_UNIQUE)

  sum_a = sum(a)

  # Print a set of N numbers which are:
  # 1. Different from whatever the solution provided
  # 2. Add up to an even number with the numbers provided by the solution.

  test_type = test_case % TEST_TYPES
  test_types_seen.add(test_type)

  # N random numbers.
  b = PickFromPool(n, random.choices(range(MIN_AB, MAX_AB + 1), k=2 * n),
                   a_as_set)
  EnsureParity(a_as_set, b)
  ValidateB(a_as_set, b, n)

  # Normalize B to ensure that shuffling produces consistent results.
  b = list(sorted(b))
  random.shuffle(b)

  Output(" ".join(map(str, b)))

  # Read the set of numbers the solution chosen for us.
  c = ReadInts(
      Input(),
      inclusive_min_n=1,
      inclusive_max_n=2 * n - 1,
      inclusive_min_value=MIN_AB,
      inclusive_max_value=MAX_AB)

  # Numbers should be unique.
  if len(c) != len(set(c)):
    raise Error(NUMBERS_ARE_NOT_UNIQUE)

  # Numbers should only come from the sets of the numbers above.
  diff = Counter(a + b)
  diff.subtract(Counter(c))
  if min(diff.values()) < 0:
    raise Error(NUMBER_NOT_FROM_THE_SET)

  # The sum of the chosen numbers should be equal to the half of the total sum.
  return sum(a) + sum(b) == 2 * sum(c)


def PickFromPool(n, pool, a_as_set):
  """Returns n items from the pool which do not appear in a_as_set.

  Args:
    n: number of items to return.
    pool: an sequence of elements to choose from.
    a_as_set: a set of elements which should not appear in the result.

  Returns:
    List of n items from the pool which do not appear in a_as_set.
  """
  assert isinstance(a_as_set, set)

  # Remove the ones that are in A.
  filtered_pool = list(filter(lambda x: x not in a_as_set, pool))
  # Pick N random numbers out of the pool.
  return random.sample(filtered_pool, k=n)


def EnsureParity(a_as_set, b):
  """Modifies b in place to ensure that the sum of a_as_set and b is even.

  While modifying b it ensures that modified elements do not also appear in
  a_as_set.

  Args:
    a_as_set: a set of elements which should not appear in b.
    b: the list to modify.
  """

  assert isinstance(a_as_set, set)

  sum_a = sum(a_as_set)
  if (sum_a + sum(b)) % 2 == 0:
    return

  min_b = min(b)
  n = len(b)
  b.remove(min_b)
  b_as_set = set(b)
  min_b += 1
  while min_b in b_as_set or min_b in a_as_set and min_b <= MAX_AB:
    min_b += 2
  if min_b > MAX_AB:
    min_b -= 2 * (n + 1)
  b.append(min_b)


def ValidateB(a_as_set, b, n):
  """Validate b to ensure that it complies with the problem statement.

  Args:
    a_as_set: a set of elements which should not appear in b.
    b: the list to validagte.
    n: the number of elements b should contain.
  """

  assert isinstance(a_as_set, set)

  assert len(b) == n, "Incorrect length"
  assert min(b) >= MIN_AB and max(b) <= MAX_AB, "Values out of range"
  b_as_set = set(b)
  assert len(b) == len(b_as_set), "Non-unique elements"
  assert len(b_as_set) == len(b_as_set - a_as_set), "Elements from A appear in B"
  assert (sum(a_as_set) + sum(b)) % 2 == 0, "Odd sum"


def AssertEqual(expected, actual):
  assert expected == actual, ("Expected [{}], got [{}]".format(
      expected, actual))


class Error(Exception):
  pass


class JudgeError(Exception):
  pass


def AssertReturns(expected, fn, *args, **kwargs):
  result = fn(*args, **kwargs)
  AssertEqual(expected, result)


def AssertRaisesError(expected_message, fn, *args, **kwargs):
  try:
    fn(*args, **kwargs)
    assert False, (
        "Expected error [{}], but there was none".format(expected_message))
  except Error as error:
    message = str(error)
    assert expected_message == message, ("Expected error [{}], got [{}]".format(
        expected_message, message))


def AssertReturnsIO(ret, expected_output, fn, *args):
  test_output_storage = []
  AssertReturns(ret, fn, *(args + (test_output_storage,)))
  AssertEqual(expected_output, test_output_storage)


def AssertRaisesErrorIO(expected_message, expected_output, fn, *args):
  test_output_storage = []
  AssertRaisesError(expected_message, fn, *(args + (test_output_storage,)))
  AssertEqual(expected_output, test_output_storage)


INVALID_LINE_ERROR = "Couldn't read a valid line"
TOO_LONG_LINE_ERROR = "Line too long: {} characters".format
WRONG_NUM_TOKENS_ERROR = ("Wrong number of tokens, expected between {} and {}, "
                          "but got {}").format
NOT_INTEGER_ERROR = "Not an integer: {}".format
OUT_OF_BOUNDS_ERROR = "{} is out of bounds".format
REPEATED_INTEGERS_ERROR = "Received repeated integers: {}".format
TOO_MANY_QUERIES_ERROR = "Queried too many times"
WRONG_ORDER_ERROR = "Guessed wrong order"
CASE_ERROR = "Case #{} failed: {}".format
EXCEPTION_AFTER_END_ERROR = (
    "Exception raised while reading input after all cases finish.")
ADDITIONAL_INPUT_ERROR = "Additional input after all cases finish: {}".format
QUERIES_USED = "Total Queries Used: {}/{}".format
NUMBERS_ARE_NOT_UNIQUE = "Some provided numbers are not unique"
NUMBER_NOT_FROM_THE_SET = ("Some provided numbers are missing in the original "
                           "set")
WRONG_ANSWER = "Wrong answer"
INVALID_OUTPUT = -1


def ParseInteger(line):
  try:
    return int(line)
  except:
    raise Error(NOT_INTEGER_ERROR(line))


def ReadInts(line, inclusive_min_n, inclusive_max_n, inclusive_min_value,
             inclusive_max_value):
  if len(line) > max(
      MAX_LINE_LENGTH,
      inclusive_max_n *
      (max(len(str(inclusive_min_value)), len(str(inclusive_max_value))) + 5)):
    raise Error(TOO_LONG_LINE_ERROR(len(line)))

  tokens = line.split()
  if not (inclusive_min_n <= len(tokens) <= inclusive_max_n):
    raise Error(
        WRONG_NUM_TOKENS_ERROR(inclusive_min_n, inclusive_max_n, len(tokens)))

  ints = list(map(ParseInteger, tokens))

  out_of_bounds = list(
      filter(lambda x: not (inclusive_min_value <= x <= inclusive_max_value),
             ints))
  if out_of_bounds:
    raise Error(OUT_OF_BOUNDS_ERROR(out_of_bounds))

  return ints


def ActuallyOutput(line):
  try:
    print(line)
    sys.stdout.flush()
  except:
    # If we let stdout be closed by the end of the program, then an unraisable
    # broken pipe exception will happen, and we won't be able to finish
    # normally.
    try:
      sys.stdout.close()
    except:
      pass


def RunCases():
  Input, Output = ConfigureIO()

  ok = True

  Output(TEST_CASES)
  for test_case in range(TEST_CASES):
    try:
      test_case_ok = RunCase(test_case)
      ok = ok and test_case_ok
    except Error as err:
      Output(INVALID_OUTPUT)
      raise Error(CASE_ERROR(test_case, err))

  assert len(test_types_seen) == TEST_TYPES, "Not all test types tried"

  try:
    extra_input = Input()
  except EOFError:
    if not ok:
      raise Error(WRONG_ANSWER)
    return
  except Exception as e:
    raise Error(EXCEPTION_AFTER_END_ERROR + str(e))
  raise Error(ADDITIONAL_INPUT_ERROR(extra_input[:100]))


def main():
  try:
    RunCases()
  except Error as err:
    print(str(err)[:1000], file=sys.stderr)
    sys.exit(1)
  except Exception as exception:
    ActuallyOutput(INVALID_OUTPUT)
    print(
        ("JUDGE_ERROR! Internal judge exception: {}".format(exception))[:1000],
        file=sys.stderr)
    sys.exit(1)


if __name__ == "__main__":
  main()
