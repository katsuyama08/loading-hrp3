# このファイルは tecsgen により自動生成されました
# Makefile.temp は gen の一つ上のディレクトリに移して使用します
#  % mv Makefile.temp Makefile
# 
# clean のデフォルト動作は $(GEN_DIR)/Makefile.* を削除します

# 変数 #_MVAR_#
TARGET = composite_namespace.exe
TIMESTAMP = tecsgen.timestamp
TECSGEN_EXE = tecsgen
CC = gcc
CFLAGS = -I . -I gen
LD = gcc
LDFLAGS = 
GEN_DIR = gen
SRC_DIR = src
vpath %.c $(SRC_DIR) $(GEN_DIR)

vpath %.h $(SRC_DIR) $(GEN_DIR)

# ルール #_MRUL_#
no_target :
	@echo "no target specified"
	@echo "at first or when edit .cdl files, do below"
	@echo "% make tecs"
	@echo "at second, do below"
	@echo "% make all"
	@echo "to clean"
	@echo "% make clean"

all : $(TARGET) 


# depend を include #_MDEP_#
-include gen/Makefile.tecsgen
-include gen/Makefile.depend

$(TARGET) : $(TIMESTAMP) $(CELLTYPE_COBJS) $(TECSGEN_COBJS) $(PLUGIN_COBJS)
	$(LD) $(LDFLAGS) -o $(TARGET) $(TECSGEN_COBJS) $(CELLTYPE_COBJS) $(PLUGIN_COBJS)


clean :
	rm -rf $(GEN_DIR)
	rm -f $(TECS_COBJS)
	rm -f $(TARGET)
	rm -f $(TIMESTAMP)

tecs : $(TIMESTAMP)

$(TIMESTAMP) : $(TECS_IMPORTS)
	$(TECSGEN_EXE) -I /usr/include composite_namespace.cdl
	touch $(TIMESTAMP)

#####  TECSFlow targets  #####
tecsflow : $(GEN_DIR)/tecsgen.rbdmp tcflow
	tecsflow -g $(GEN_DIR)

$(GEN_DIR)/tecsgen.rbdmp : tecs

tcflow : tecs
	make tcflow_exec

tcflow_exec : $(GEN_DIR)/tcflow.rbdmp
$(GEN_DIR)/tcflow.rbdmp : $(CELLTYPE_SRCS) $(PLUGIN_SRCS)
	tcflow -g $(GEN_DIR) -c '$(CC) -E -DTECSFLOW -DTECSGEN $(CFLAGS) -I ./' $^

#####  end TECSFlow targets  #####

tCell.o : tCell.c
	$(CC) -c $(CFLAGS) -o $@ $<
 
ns1_tCell.o : ns1_tCell.c
	$(CC) -c $(CFLAGS) -o $@ $<
 
