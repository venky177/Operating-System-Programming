echo "Enter directory name:"
read a 

cd $a
for c in *
do
wc $c
done
