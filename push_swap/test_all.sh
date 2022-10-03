test_ps() {

echo -n "Testing $1 numbers	-->  "
total=0
for i in $(seq 1 $2)
do
	if [ $(($i % ($END / 30))) -eq "0" ]
	then
		echo -n "~"

	fi
	if [ $i -eq $2 ]
	then
		echo " ✓"
	fi
	ARG=$(shuf -i 0-1000 -n $1)
	calcs=$(./push_swap $ARG | wc -l)
	total=$((total + calcs))
done

mean=$((total / $2))
echo "Average instructions for $1 numbers = $mean\n"
}

echo "Compiling push_swap\n"
make re;

RANGE=3
END=250
test_ps $RANGE $END
RANGE=5
test_ps $RANGE $END
RANGE=100
test_ps $RANGE $END
RANGE=500
END=50
test_ps $RANGE $END
