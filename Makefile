# These are mostly examples from the GSL book
#
CC=gcc
FLAGS=-Wall -g
INCDIRS=/usr/local/include
LIBDIRS=/usr/local/lib
LIBSYMBS0=-lgsl -lm
LIBSYMBS=-lgsl -latlas -lcblas -lm
LIBSYMBS1=-lgsl -lgoto2 -lgfortran -lm
LIBSYMBS2=-lgsl -lgslcblas -lm
EXES= allperms rnperm matv vecv2 comb1 comb2 p0 p1 p2 ms1 ms2 qrex p0a rnd0 rnd1 rnd2 rnd3 pdf3 pdf3a

allperms: allperms.c
	$(CC) $(FLAGS) -o $@ $^ -I$(INCDIRS) -L$(LIBDIRS) $(LIBSYMBS)

rnperm: rnperm.c
	# $(CC) $(FLAGS) -o $@ $^ -I$(INCDIRS) -L$(LIBDIRS) $(LIBSYMBS)
	$(CC) $(FLAGS) -o $@ $^ $(LIBSYMBS2)

# Used to be called vecv.c, but it's really about matrix views, so changed.
matv: matv.c
	$(CC) -o $@ $^ $(LIBSYMBS2)
# 	$(CC) -o $@ $^ -I$(INCDIRS) -L$(LIBDIRS) $(LIBSYMBS1)

vecv2: vecv2.c
	$(CC) $(FLAGS) -o $@ $^ -I$(INCDIRS) -L$(LIBDIRS) $(LIBSYMBS)

# Following prog takes an integer argument and lists all its subsets. All the possible combinations of each subset
# are given. But the man full set: only the orginal is given
comb1: comb1.c
	$(CC) $(FLAGS) -o $@ $^ -I$(INCDIRS) -L$(LIBDIRS) $(LIBSYMBS)

comb2: comb2.c
	$(CC) $(FLAGS) -o $@ $^ -I$(INCDIRS) -L$(LIBDIRS) $(LIBSYMBS)


# Taking up from the comb programs: what about focssing on pairs.
c0: c0.c
	$(CC) $(FLAGS) -o $@ $^ -I$(INCDIRS) -L$(LIBDIRS) $(LIBSYMBS)

# Pair combos: My own way: and it seems to have worked.
oc0: oc0.c
	$(CC) $(FLAGS) -o $@ $^ -I$(INCDIRS) -L$(LIBDIRS) $(LIBSYMBS)

# try and elaborate
# OK, for n=20, there's still only 190 pairs. Small compared to the number of permutations at 20, that is.
# You can store these as  char's because you won't bother going over 255. So a struct of 2 chars could do it.
oc1: oc1.c
	$(CC) $(FLAGS) -o $@ $^ -I$(INCDIRS) -L$(LIBDIRS) $(LIBSYMBS)

# Simple permu
p0: p0.c
	$(CC) $(FLAGS) -o $@ $^ -I$(INCDIRS) -L$(LIBDIRS) $(LIBSYMBS2)

# As is, the gsl permu is quit emonolithic, to pull out the individual symbols you've gotta do this:
p0a: p0a.c
	$(CC) $(FLAGS) -o $@ $^ -I$(INCDIRS) -L$(LIBDIRS) $(LIBSYMBS2)

p1: p1.c
	$(CC) $(FLAGS) -o $@ $^ -I$(INCDIRS) -L$(LIBDIRS) $(LIBSYMBS)

p2: p2.c
	$(CC) $(FLAGS) -o $@ $^ $(LIBSYMBS2)

# multisets is relatively new ... you need gsl-1-14 at least.
ms1: ms1.c
	$(CC) $(FLAGS) -o $@ $^ -I$(INCDIRS) -L$(LIBDIRS) $(LIBSYMBS2)

# Multiset example
ms2: ms2.c
	$(CC) $(FLAGS) -o $@ $^ -I$(INCDIRS) -L$(LIBDIRS) -L${LL} $(LIBSYMBS)

qrex: qrex.c
	$(CC) $(FLAGS) -o $@ $^ -I$(INCDIRS) -L$(LIBDIRS) -L${LL} $(LIBSYMBS)

# random number distirubtion practice
rnd0: rnd0.c
	$(CC) -o $@ $^ $(LIBSYMBS2)
rnd1: rnd1.c
	$(CC) -o $@ $^ $(LIBSYMBS2)
rnd2: rnd2.c
	$(CC) -o $@ $^ $(LIBSYMBS2)
rnd3: rnd3.c
	$(CC) -o $@ $^ $(LIBSYMBS2)
pdf3: pdf3.c
	$(CC) -o $@ $^ $(LIBSYMBS2)
pdf3a: pdf3a.c
	$(CC) -o $@ $^ $(LIBSYMBS2)


.PHONY: clean

.PHONY: clean

clean:
	rm -f ${EXES}
