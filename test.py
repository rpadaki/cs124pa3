import subprocess
from timeit import default_timer as timer
import sys

def makeRandInts():
	sp = subprocess.call("make randints", shell=True)

def randInts(i):
	sp = subprocess.call("./randints 100 " + str(i) + ".txt", shell=True)

def makeRun(rep, alg):
	sp = subprocess.call("make " + rep + " " + alg + " kk", shell=True)

def run(i):
	start = timer()
	out = subprocess.check_output("./kk " + str(i) + ".txt", shell=True)
	end = timer()
	return out, end-start

def makeClean():
	sp = subprocess.call("make clean", shell=True)

def cleanUp():
	makeClean()
	sp = subprocess.call("rm *.txt", shell=True)

reps = ["repstd", "repstd", "repstd", "repstd", "repprep", "repprep", "repprep"]
algs =["kkalg", "rralg", "hcalg", "saalg", "rralg", "hcalg", "saalg"]
out = []
time = []
makeRandInts()
for x in xrange(100):
	randInts(x)
	out.append([0,0,0,0,0,0,0])
	time.append([0,0,0,0,0,0,0])
makeClean()

for y in xrange(7):
	makeRun(reps[y], algs[y])
	for x in xrange(100):
		out[x][y], time[x][y] = run(x)
		if x%10==0:
			print y, x
	makeClean()
cleanUp()

orig_stdout = sys.stdout
f = open('out.dat', 'w')
sys.stdout = f
for x in xrange(7):
	print reps[x], algs[x],
for x in xrange(7):
	print reps[x], algs[x],
print
for x in xrange(100):
	for y in xrange(7):
		print out[x][y],
	for y in xrange(7):
		print time[x][y],
	print
sys.stdout = orig_stdout
f.close()