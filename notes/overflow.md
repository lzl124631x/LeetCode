# Overflow Detection

If we are detecting if `a * 10` will overflow `INT_MAX`, we compare `a` with `INT_MAX / 10`. If `a > INT_MAX / 10`, it will overflow.

If we are detecting if `a * 10 + b` will overflow `INT_MAX`, we use this check: If `a > INT_MAX / 10 || (a == INT_MAX / 10 && b > INT_MAX % 10)`, it will overflow.