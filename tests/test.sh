var="$(../fillit test_2_tetriminos)" 

if [[ $var =~ "ABB.
ABB.
A...
A..." ]]; then
    echo "All good"
else
    echo "Something is wrong"
fi
