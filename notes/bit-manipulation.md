# Bit Manipulation

## Set a bit at `index`

`target |= 1 << index`

## Toggle a bit at `index`

`target ^= 1 << index`

## Get the lowest bit

```cpp
function lowbit(int x) {
    return x & (-x);
}
```

## Reference 

* https://oi-wiki.org/math/bit/