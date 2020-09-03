#Flags for the make file
CXX="g++-10"
CFLAGS="-lX11 -lGL -lpthread -lpng -lstdc++fs -std=c++17 -g -Wall"

ODIR="o"
OUT="a"

#Files to check through
src=`find *.cpp`
heads=`find *.h`

#Create makefile
rm makefile
touch makefile
echo "CXX = "$CXX >> makefile
echo "CFLAGS = "$CFLAGS >> makefile
echo "ODIR = "$ODIR >> makefile
echo "OUT = "$OUT >> makefile
echo "" >> makefile
printf "\$(OUT): " >> makefile

#Create Main executable recipe
for entry in $src #Loop to add dependant files
do
	name=`echo $entry | head -n1 | cut -d "." -f1`
	printf "\$(ODIR)/$name.o " >> makefile
done
echo "" >> makefile
printf "	\$(CXX) -o \$(OUT) " >> makefile
for entry in $src #Loop to write recipe to create main executable
do
	name=`echo $entry | head -n1 | cut -d "." -f1`
	printf "\$(ODIR)/$name.o" >> makefile
done
echo "\$(CFLAGS)" >> makefile

#Create recipes for each translation unit
for entry in $src
do
	name=`echo $entry | head -n1 | cut -d "." -f1`

	#Print target for file
	echo "" >>makefile
	printf "\$(ODIR)/$name.o: $entry " >> makefile
	#Search file for dependancies
	cat $entry | while read line; do
		#TODO - Check for "#include", check if surrounded by quotes, and append to recipe





	done

	#Print compilation recipe for this translation unit
	echo "" >> makefile
	printf "	\$(CXX) -o \$(OD)/$name.o $entry \$(CFLAGS) -c" >> makefile
	echo "" >> makefile
done

echo "" >> makefile
echo "clean:" >> makefile
echo "	rm \$(OUT) \$(ODIR)/*.o" >> makefile
echo "" >> makefile

