#Flags for the make file
CXX="g++-10"
CFLAGS="-lX11 -lGL -lpthread -lpng -lstdc++fs -std=c++17 -g -Wall -lSDL2 -lSDL2_image"

ODIR="o"
OUT="a"

#Files to check through
src=`find . -name "*.cpp"`

#Create makefile and folder to put stuff in
touch makefile
rm makefile
touch makefile
mkdir $ODIR
echo "CXX = "$CXX >> makefile
echo "CFLAGS = "$CFLAGS >> makefile
echo "ODIR = "$ODIR >> makefile
echo "OUT = "$OUT >> makefile
echo "" >> makefile
printf "\$(OUT): " >> makefile

#Create Main executable recipe
for entry in $src #Loop to add dependant files
do
	name=`echo $entry | head -n1 | cut -d "." -f2`
	printf "\$(ODIR)$name.o " >> makefile
done
echo "" >> makefile
printf "	\$(CXX) -o \$(OUT) " >> makefile

for entry in $src #Loop to write recipe to create main executable
do
	name=`echo $entry | head -n1 | cut -d "." -f2`
	printf "\$(ODIR)$name.o " >> makefile
	dir=${name//"/"/" "} #Loop recursive directories
	curDir=$ODIR
	for dirName in $dir
	do
		#Make sub-directories
		mkdir $curDir/$dirName
		curDir+="/$dirName"
	done #Remove last directory
	rmdir $curDir/../`echo $curDir | rev | cut -d "/" -f1 | rev`
done
echo "\$(CFLAGS)" >> makefile

#Parse file for header depends
dependHeader() {
	file=$1
	local loc=`echo $file | rev | cut -d "/" -f 2- | rev`
	if [[ $loc == "" ]]; then
		loc=.
	fi
	#echo "Doing dependencies for file: "$file" Directory is: "$loc
	#Loop through lines in file that have "#include"
	cat $file | grep '#include "' | while read line; do
		begn=`echo $line  | cut -d " " -f 1`
		#Check if line is an include statement
		if [[ $begn == "#include" ]]; then
			inc=`echo $line | cut -d '"' -f 2`
			printf " $loc/$inc" >> makefile
			dependHeader $loc/$inc
		fi
	done
}


#Create recipes for each translation unit
for entry in $src
do
	echo "Creating recipe for target: "$entry
	name=`echo $entry | head -n1 | cut -d "." -f2`
	#Print target for file
	echo "" >>makefile
	printf "\$(ODIR)$name.o: $entry" >> makefile
	#Search file for dependancies
	dependHeader $entry

	#Print compilation recipe for this translation unit
	echo "" >> makefile
	printf "	\$(CXX) -o \$(ODIR)$name.o $entry \$(CFLAGS) -c" >> makefile
	echo "" >> makefile
done

echo "" >> makefile
echo "clean:" >> makefile
echo "	rm \$(OUT) \`find $ODIR -name '*.o'\`" >> makefile
echo "" >> makefile
