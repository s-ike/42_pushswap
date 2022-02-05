# 42_pushswap
aとbのスタックがあり、aには重複のない乱数が含まれ、より少ない手数で昇順にソートする.

## Rules
| 命令 | 説明 |
| ------------- | ------------- |
| sa | swap a - スタックaの一番上にある最初の2つの要素を交換します |
| sb | swap b - スタックbの一番上にある最初の2つの要素を交換します |
| ss | saとsbを同時に行います |
| pa | push a - bの一番上にある最初の要素をaの上部に移動します |
| pb | push b - aの一番上にある最初の要素をbの上部に移動します |
| ra | rotate a - スタックaの全ての要素を1つ上にシフトします 最初の要素が最後の要素になります |
| rb | rotate b - スタックbの全ての要素を1つ上にシフトします 最初の要素が最後の要素になります |
| rr | raとrbを同時に行います |
| rra | reverse rotate a - スタックaの全ての要素を1つ下にシフトします 最後の要素が最初の要素になります
| rrb | reverse rotate b - スタックbの全ての要素を1つ下にシフトします 最後の要素が最初の要素になります
| rrr | rraとrrbを同時に行います |

## Examples
```
$ ./push_swap 2 1 3 4
sa
```
```
$ ./push_swap 2 1 4 3
ra
pb
sa
rra
pa
```