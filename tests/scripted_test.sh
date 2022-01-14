var="$(../fillit test_2_tetriminos)" 

if [[ $var =~ "ABB.
ABB.
A...
A..." ]]; then
    echo "All good"
else
    echo "Something is wrong"
fi

var_JCC_1="$(../fillit JCC_EX_1)"

if [[ $var_JCC_1 =~ "ACCB
ACCB
A.BB
A..." ]]; then
    echo "All good"
else
    echo "Something is wrong"
fi

var_JCC_2="$(../fillit JCC_EX_2)"

if [[ $var_JCC_2 =~ "A.CC
AACC
.AB.
.BBB" ]]; then
    echo "All good"
else
    echo "Something is wrong"
fi
var_JCC_3="$(../fillit JCC_EX_3)"

if [[ $var_JCC_3 =~ ".A.C
.AAC
.BAC
BBBC" ]]; then
    echo "All good"
else
    echo "Something is wrong"
fi
