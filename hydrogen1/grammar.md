# Grammar

```
DecNumber -> [1-9][0-9]* | 0
HexNumber -> 0(x|X)([0-9][a-f][A-F])*
OctNumber -> 0[0-7]+
BinNumber -> 0(b|B)[0-1]*
Identifier -> [a-z][A-Z]_([a-z][A-Z][0-9]_)*
String -> "([^\\\n\r]|(\\.))*"
```

# Character Set

```
0 => 0
1 => 1
[2-7] => 2
[8-9] => 3
(a|A)[c-f][C-F] => 4
(b|B) => 5
[g-w][G-W](y|z)(Y|Z)_ => 6
(x|X) => 7
"=>8
\n\r=>9
\\=>10
other=>11
eof=>12
```

# Lexer Automata

| M\(S, C\) | 0   | 1   | \[2-7\] | \[8-9\] | \(aA\)\[c-f\]\[C-F\] | \(bB\) | \[g-w\]\[G-W\]\(yY\)\(zZ\)_ | \(xX\) | "   | \\n\\r | \\  | other | eof |
| --------- | --- | --- | ------- | ------- | -------------------- | ------ | --------------------------- | ------ | --- | ------ | --- | ----- | --- |
| 0         | 1   | 2   | 2       | 2       | 3                    | 3      | 3                           | 3      | 7   | /      | /   | /     | /   |
| 1         | 4   | 4   | 4       | /       | /                    | 5      | /                           | 6      | /   | /      | /   | /     | /   |
| 2         | 2   | 2   | 2       | 2       | /                    | /      | /                           | /      | /   | /      | /   | /     | /   |
| 3         | 3   | 3   | 3       | 3       | 3                    | 3      | 3                           | 3      | /   | /      | /   | /     | /   |
| 4         | 4   | 4   | 4       | /       | /                    | /      | /                           | /      | /   | /      | /   | /     | /   |
| 5         | 5   | 5   | /       | /       | /                    | /      | /                           | /      | /   | /      | /   | /     | /   |
| 6         | 6   | 6   | 6       | 6       | 6                    | 6      | /                           | /      | /   | /      | /   | /     | /   |
| 7         | 7   | 7   | 7       | 7       | 7                    | 7      | 7                           | 7      | 8   | /      | 9   | 7     | /   |
| 8         | /   | /   | /       | /       | /                    | /      | /                           | /      | /   | /      | /   | /     | /   |
| 9         | 10  | 10  | 10      | 10      | 7                    | 7      | 7                           | 12     | 7   | 7      | 7   | 7     | /   |
| 10        | 11  | 11  | 11      | 11      | /                    | /      | /                           | /      | /   | /      | /   | /     | /   |
| 11        | 7   | 7   | 7       | 7       | /                    | /      | /                           | /      | /   | /      | /   | /     | /   |
| 12        | 13  | 13  | 13      | 13      | 13                   | 13     | /                           | /      | /   | /      | /   | /     | /   |
| 13        | 7   | 7   | 7       | 7       | 7                    | 7      | /                           | /      | /   | /      | /   | /     | /   |

```
0:Start
1:DecNumber
2:DecNumber
3:Identifier
4:OctNumber
5:BinNumber
6:HexNumber
8:String
```