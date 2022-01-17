var="$(../fillit test_2_tetriminos)"

if [[ $var =~ "ABB.
ABB.
A...
A..." ]]; then
    echo "All good"
else
    echo "Something is wrong in test_2_tetriminos"
fi

var_JCC_1="$(../fillit JCC_EX_1)"

if [[ $var_JCC_1 =~ "ACCB
ACCB
A.BB
A..." ]]; then
    echo "All good"
else
    echo "Something is wrong in JCC_EX_1"
fi

var_JCC_2="$(../fillit JCC_EX_2)"

if [[ $var_JCC_2 =~ "A.CC
AACC
.AB.
.BBB" ]]; then
    echo "All good"
else
    echo "Something is wrong JCC_EX_2"
fi
var_JCC_3="$(../fillit JCC_EX_3)"

if [[ $var_JCC_3 =~ ".A.C
.AAC
.BAC
BBBC" ]]; then
    echo "All good"
else
    echo "Something is wrong in JCC_EX_3"
fi
var_vali_26_minos="$(../fillit valid_26minos)"

if [[ $var_vali_26_minos =~ "ABBBBCD..EE
AFFF.CDDDE.
AG.FCCHIIE.
AG..HHH.IKK
MGGJJJLLIKK
MMNJ.LLOOOP
WMNNQ.RROPP
WWNQQQSRR.P
XWTTTSSYYYZ
XXTUUSVVYZZ
X..UUVV...Z" ]]; then
    echo "All good"
else
    echo "Something is wrong in valid_26minos"
fi
