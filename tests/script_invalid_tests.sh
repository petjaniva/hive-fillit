var="$(../fillit invalid_1)"

if [[ $var =~ "error" ]]; then
    echo "All good"
else
    echo "Something is wrong in invalid_1"
fi

var="$(../fillit invalid_2)"

if [[ $var =~ "error" ]]; then
    echo "All good"
else
    echo "Something is wrong in invalid_2"
fi

var="$(../fillit invalid_3)"

if [[ $var =~ "error" ]]; then
    echo "All good"
else
    echo "Something is wrong in invalid_3"
fi

var="$(../fillit invalid_4)"

if [[ $var =~ "error" ]]; then
    echo "All good"
else
    echo "Something is wrong in invalid_4"
fi

var="$(../fillit invalid_5)"

if [[ $var =~ "error" ]]; then
    echo "All good"
else
    echo "Something is wrong in invalid_5"
fi

var="$(../fillit invalid_6)"

if [[ $var =~ "error" ]]; then
    echo "All good"
else
    echo "Something is wrong in invalid_6"
fi

var="$(../fillit invalid_7)"

if [[ $var =~ "error" ]]; then
    echo "All good"
else
    echo "Something is wrong in invalid_7"
fi

var="$(../fillit invalid_8)"

if [[ $var =~ "error" ]]; then
    echo "All good"
else
    echo "Something is wrong in invalid_8"
fi

var="$(../fillit invalid_9)"

if [[ $var =~ "error" ]]; then
    echo "All good"
else
    echo "Something is wrong in invalid_9"
fi

var="$(../fillit invalid_nonewline)"

if [[ $var =~ "error" ]]; then
    echo "All good"
else
    echo "Something is wrong in invalid_nonewline"
fi

var="$(../fillit invalid_twonewlines)"

if [[ $var =~ "error" ]]; then
    echo "All good"
else
    echo "Something is wrong in invalid_twonewlines"
fi

var="$(../fillit valid_but_30_minos)"

if [[ $var =~ "error" ]]; then
    echo "All good"
else
    echo "Something is wrong in valid_but_30_minos"
fi
