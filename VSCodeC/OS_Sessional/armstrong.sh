echo "Enter range min and max->"
read n1 n2
for (( i=$n1; $i<=$n2; i++))
do
    s=0
    t=$i
    l=$i
    while [ "$l" != 0 ]
    do
        r=`expr $l % 10`
        d=`expr $r \* $r \* $r`
        s=`expr $s + $d`
        l=`expr $l / 10`
    done
    if [ $t -eq $s ]
    then
        echo "it is a armstrong->$t"
    fi
done