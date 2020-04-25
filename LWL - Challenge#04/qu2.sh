if [ $# -eq 0 ]
then
    echo "kindly pass the file name"
    exit
fi

fl=$1
ch=1

while [ $ch -eq 1 ]
do
    find . -name "$1" -type f
	find . -name "$1" -type f -delete
done
