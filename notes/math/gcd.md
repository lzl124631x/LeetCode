# Greatest Common Divisor

## Euclidean algorithm

```
gcd(a, 0) = a
gcd(a, b) = gcd(b, a % b)
```

Recursive:
```cpp
int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}
```

Iterative:
```cpp
int gcd(int a, int b) {
    if (b) while ((a %= b) && (b %= a));
    return a + b;
}
```