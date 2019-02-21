for i do
{
    sum=$(expr $sum + $i)
    let "var++"
}
done
avg=$(expr $sum/$var)
echo $avg | bc -l