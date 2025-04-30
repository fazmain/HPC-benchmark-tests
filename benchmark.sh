# This script benchmarks a matrix multiplication program with different optimization levels.
SOURCE="matrix_multiplication.cpp"
LOGFILE="results.log"

echo "Matrix Multiplication Benchmark" > $LOGFILE
echo "--------------------------------" >> $LOGFILE
echo "" >> $LOGFILE

for OPT in O0 O2 O3
do
    echo "Compiling with -$OPT..." | tee -a $LOGFILE
    { time g++ -$OPT $SOURCE -o matrix_$OPT ; } 2>> $LOGFILE

    echo "Running matrix_$OPT..." | tee -a $LOGFILE
    { time ./matrix_$OPT ; } >> $LOGFILE 2>&1

    echo "" >> $LOGFILE
done

echo "Benchmark complete. See results.log"
