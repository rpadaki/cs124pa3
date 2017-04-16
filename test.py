import subprocess
from timeit import default_timer as timer

def randInts():
	sp = subprocess.call("make randints")
	sp = subprocess.call("./randints 100 file")
	sp = subprocess.call("make clean")

def clean():
	sp = subprocess.call("make clean")
	sp = subprocess.call("remove file")

def run(rep, alg):
	sp = subprocess.call("make " + rep + " " + alg + " kk")
	start = timer()
	out = subprocess.check_output("./kk file")
	end = timer()
	sp = subprocess.call("make clean")
	return out, end-start

reps = ["", "repstd", "repstd", "repstd", "repprep", "repprep", "repprep"]
algs =["", "rralg", "hcalg", "saalg", "rralg", "hcalg", "saalg"]
out = [][]
time = [][]
for x in xrange(100):
	randInts()
	for y in xrange(7):
		out[x][y], time[x][y] = run(reps[y], algs[y])
	clean()