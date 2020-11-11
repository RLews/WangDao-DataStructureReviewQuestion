CC = gcc
TOP ?= $(shell pwd)
CSRCS = $(wildcard *.c)

COBJS = $(patsubst %.c, %.o, $(CSRCS)) 
TAGS = $(basename $(CSRCS))

	

all: $(TOP) $(COBJS) $(TAGS) $(CSRCS) 



$(COBJS): %.o:%.c 
	@echo $<
	$(CC) -g -c $< -o $@
	
$(TOP): 
	$(foreach n,$(TAGS),$(CC) -g $(n).o -o $(n)) 
	

test_echo:
	@echo $(TAGS)
	@echo $(TOP)
	@echo $(COBJS)
	@echo $(CSRCS)


clean:
	rm -f $(TOP)/*.o
