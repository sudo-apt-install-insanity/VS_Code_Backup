echo "Enter the range min and max:"
read n1 n2
echo "Prime numbers between $n1 and $n2"

while [ $n1 -le $n2 ]
do
    i=2; flag=1
    while [ $i -lt $n1 ]
    do
        if [ `expr $n1 % $i` -eq 0 ]
        then
            flag=0
            break
        else
            i=`expr $i + 1`
        fi
    done
    if [ $flag -eq 1 ]
    then
        echo $n1
    fi
    n1=`expr $n1 + 1`
done