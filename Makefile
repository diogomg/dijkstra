all:
	echo execucao
	time ./dijkstra\ binary\ heap/dijkstra < ger_in.txt > bh.txt
	time ./dijkstra\ veb/dijkstra < ger_in.txt > veb.txt
	time ./dijkstra\ avl/dijkstra < ger_in.txt > avl.txt
	echo comparacao bh e veb
	diff bh.txt veb.txt
	echo comparacao bh e avl
	diff bh.txt avl.txt
	echo comparacao veb e avl
	diff veb.txt avl.txt
	echo valgrind bh
	valgrind --tool=callgrind ./dijkstra\ binary\ heap/dijkstra < ger_in.txt > null
	mv callgrind.out.* callgrind.heap
	echo valgrind veb
	valgrind --tool=callgrind ./dijkstra\ veb/dijkstra < ger_in.txt > null
	mv callgrind.out.* callgrind.veb
	echo valgrind avl
	valgrind --tool=callgrind ./dijkstra\ avl/dijkstra < ger_in.txt > null
	mv callgrind.out.* callgrind.avl
	kcachegrind callgrind.* &

clean:
	rm callgrind*
