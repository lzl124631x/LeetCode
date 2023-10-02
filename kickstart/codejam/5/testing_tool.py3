# "Twisty Little Passages" local testing tool.
#
# Usage: `python3 local_testing_tool.py`

import sys
import random

NUM_CASES = 100
N = 100000
K = 8000
NEED_CORRECT = 90

class Error(Exception):
  pass

class WrongAnswer(Exception):
  pass

WRONG_NUM_TOKENS_ERROR = ("Wrong number of tokens: expected {}, found {}.".format)
NOT_INTEGER_ERROR = "Not an integer: {}.".format
INVALID_LINE_ERROR = "Couldn't read a valid line."
ADDITIONAL_INPUT_ERROR = "Additional input after all cases finish: {}.".format
OUT_OF_BOUNDS_ERROR = "Request out of bounds: {}.".format
TOO_FEW_CORRECT_ERROR = "Too few correct answers: {}.".format
INVALID_COMMAND_ERROR = "couldn't understand player command: {}.".format
DID_NOT_GIVE_AN_ESTIMATE_ERROR = "Player did not give an estimate after K rounds."


def ReadValues(line):
  t = line.split()
  return t

def ConvertToInt(token, min, max):
    try:
      v = int(token)
    except:
      raise Error(NOT_INTEGER_ERROR(token[:100]))
    if v < min or v > max:
      raise Error(OUT_OF_BOUNDS_ERROR(v))
    return v

def ConvertToAnyInt(token):
    try:
      v = int(token)
    except:
      raise Error(NOT_INTEGER_ERROR(token[:100]))
    return v

def Input():
  try:
    return input()
  except EOFError:
    raise
  except:
    raise Error(INVALID_LINE_ERROR)

def Output(line):
  try:
    print(line)
    sys.stdout.flush()
  except:
    try:
      sys.stdout.close()
    except:
      pass

def RunCases():
  Output("{}".format(NUM_CASES))
  correct = 0
  for case_number in range(NUM_CASES):
    Output("{} {}".format(N, K))

    # Construct a graph in adj.
    adj = [[] for _ in range(N)]
    correct_total_edges = 0
    order = [i for i in range(N)]
    random.shuffle(order)
    for i in range(0, N, 2):
      v1 = order[i]
      v2 = order[i+1]
      adj[v1].append(v2)
      adj[v2].append(v1)
      correct_total_edges += 1
    add = random.randint(0, 4*N)
    add = random.randint(0, add)
    for j in range(add):
      v1 = random.randint(0,N-1)
      v2 = random.randint(0,N-1)
      if v1 != v2 and v2 not in adj[v1] and len(adj[v1])<N-2 and len(adj[v2])<N-2:
        adj[v1].append(v2)
        adj[v2].append(v1)
        correct_total_edges += 1
    complement = random.choice([False, True])
    if complement:
      correct_total_edges = (N*(N-1))//2 - correct_total_edges

    # Play the game.
    where = random.randint(0,N-1)
    for move_number in range(K+1):
      # Output current room number (1-based) and number of adjacent passages.
      if complement:
        Output("{} {}".format(where+1, N-1-len(adj[where])))
      else:
        Output("{} {}".format(where+1, len(adj[where])))

      # Get the user's move.
      try:
        move = ReadValues(Input())
      except EOFError:
        raise Error(INVALID_LINE_ERROR)
      except Error as error:
          raise error
      if len(move) == 0:
        raise Error(INVALID_LINE_ERROR)

      if move[0] == "E":
        # The user provided an estimate.
        if len(move) != 2:
          raise Error(WRONG_NUM_TOKENS_ERROR(2,len(move)))
        estimate = ConvertToAnyInt(move[1])
        lo = (correct_total_edges * 2 + 2) // 3
        hi = (correct_total_edges * 4) // 3
        if lo <= estimate and estimate <= hi:
          print(f"Case #{case_number}: Correct -- got {estimate}; exact answer is {correct_total_edges}.", file=sys.stderr)
          correct += 1
        else:
          print(f"Case #{case_number}: Wrong -- got {estimate}; exact answer is {correct_total_edges}; acceptable range is [{lo}, {hi}].", file=sys.stderr)
        # Go to the next test case.
        break
      elif move_number == K:
        # The cave is now closed!
        raise Error(DID_NOT_GIVE_AN_ESTIMATE_ERROR)
      elif move[0] == "W":
        # The user took a random exit.
        if len(move) != 1:
          raise Error(WRONG_NUM_TOKENS_ERROR(1,len(move)))
        if complement:
          while True:
            next = random.randint(0,N-1)
            if next not in adj[where]:
              where = next
              break
        else:
          l = adj[where]
          where = l[random.randint(0,len(l)-1)]
      elif move[0] == "T":
        # The user teleported to a room.
        if len(move) != 2:
          raise Error(WRONG_NUM_TOKENS_ERROR(1,len(move)))
        where = ConvertToInt(move[1], 1, N)
        where -= 1
      else:
        raise Error(INVALID_COMMAND_ERROR(move[0][:1000]))

  # Check there is no extraneous input from the user.
  try:
    extra_input = Input()
    raise Error(ADDITIONAL_INPUT_ERROR(extra_input[:100]))
  except EOFError:
    pass

  # Finished.
  print(f"User got {correct} cases correct.", file=sys.stderr)
  if correct < NEED_CORRECT:
    raise WrongAnswer(TOO_FEW_CORRECT_ERROR(correct))

def main():
  if len(sys.argv) == 2 and int(sys.argv[1]) < 0:
    sys.exit(0)
  random.seed(12345)
  try:
    RunCases()
  except Error as error:
    print(error, file=sys.stderr)
    sys.exit(1)
  except WrongAnswer as error:
    print(error, file=sys.stderr)
    sys.exit(1)

if __name__ == "__main__":
  main()
