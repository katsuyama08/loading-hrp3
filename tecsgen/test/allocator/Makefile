# このファイルは tecsgen により自動生成されました
# Makefile.temp は gen の一つ上のディレクトリに移して使用します
#  % mv Makefile.temp Makefile
# 
# clean のデフォルト動作は $(GEN_DIR)/Makefile.* を削除します

# 変数 #_MVAR_#
TARGET = allocator.exe
TECSGEN_EXE = tecsgen
CC = gcc
CFLAGS = -I . -I ../RUNTIME/tecs-runtime/target -I ../RUNTIME/tecs-runtime/include -I gen -I src -I gen
LD = gcc
LDFLAGS = 
GEN_DIR = gen
SRC_DIR = src
vpath %.c $(SRC_DIR) $(GEN_DIR)

# ルール #_MRUL_#
no_target :
	@echo "no target specified"
	@echo "at first or when edit .cdl files, do below"
	@echo "% make tecsgen"
	@echo "at second, do below"
	@echo "% make all"
	@echo "to clean"
	@echo "% make clean"

all : $(TARGET) 


# depend を include #_MDEP_#
-include gen/Makefile.tecsgen
-include gen/Makefile.depend

$(TARGET) : tecsgen.timestamp $(CELLTYPE_COBJS) $(TECSGEN_COBJS) $(PLUGIN_COBJS)
	$(LD) $(LDFLGAS) -o $(TARGET) $(TECSGEN_COBJS) $(CELLTYPE_COBJS) $(PLUGIN_COBJS)

# For temporal construction using template code.
TEMPL_COBJS = \
 	$(GEN_DIR)/tAlloc_templ.o \
 	$(GEN_DIR)/tTestComponent_templ.o \
 	$(GEN_DIR)/tTestClient_templ.o \
# TEMPL_COBJS terminater

TEMPL_SRCS = \
 	$(GEN_DIR)/tAlloc_templ.c \
 	$(GEN_DIR)/tTestComponent_templ.c \
 	$(GEN_DIR)/tTestClient_templ.c \
# TEMPL_SRCS terminater

# テンプレートコードでメークしてみる場合 #_TCM_#
# $(TARGET) : tecsgen.timestamp $(TECSGEN_COBJS) $(TEMPL_COBJS) $(PLUGIN_COBJS)
#	$(LD) $(LDFLGAS) -o $(TARGET) $(TECSGEN_COBJS) $(TEMPL_COBJS) $(PLUGIN_COBJS)

clean :
	rm -rf $(GEN_DIR)
	rm -f $(TECS_COBJS)
	rm -f $(TARGET)
	rm -f tecsgen.timestamp

tecsgen : tecsgen.timestamp

tecsgen.timestamp : $(TECS_IMPORTS)
	$(TECSGEN_EXE) -r -I../RUNTIME/tecs-runtime/target -I../RUNTIME/tecs-runtime/include -Igen -Isrc allocator.cdl
	touch tecsgen.timestamp

#####  TECSFlow targets  #####
tecsflow : $(GEN_DIR)/tecsgen.rbdmp tcflow
	tecsflow -g $(GEN_DIR)

$(GEN_DIR)/tecsgen.rbdmp : tecsgen

tcflow : tecsgen
	make tcflow_exec

tcflow_exec : $(GEN_DIR)/tcflow.rbdmp
$(GEN_DIR)/tcflow.rbdmp : $(CELLTYPE_SRCS) $(PLUGIN_SRCS)
	tcflow -g $(GEN_DIR) -c '$(CC) -E -DTECSFLOW -DTECSGEN $(CFLAGS) -I ./' $^

#####  end TECSFlow targets  #####

# Celltype: tAlloc
$(GEN_DIR)/tAlloc_tecsgen.o : $(GEN_DIR)/tAlloc_tecsgen.c
	$(CC) -c $(CFLAGS) -o $@ $<

$(GEN_DIR)/tAlloc_templ.o : $(GEN_DIR)/tAlloc_templ.c
	$(CC) -c $(CFLAGS) -o $@ $<

tAlloc.o : tAlloc.c
	$(CC) -c $(CFLAGS) -o $@ $<

# Celltype: tTestComponent
$(GEN_DIR)/tTestComponent_tecsgen.o : $(GEN_DIR)/tTestComponent_tecsgen.c
	$(CC) -c $(CFLAGS) -o $@ $<

$(GEN_DIR)/tTestComponent_templ.o : $(GEN_DIR)/tTestComponent_templ.c
	$(CC) -c $(CFLAGS) -o $@ $<

tTestComponent.o : tTestComponent.c
	$(CC) -c $(CFLAGS) -o $@ $<

# Celltype: tTestClient
$(GEN_DIR)/tTestClient_tecsgen.o : $(GEN_DIR)/tTestClient_tecsgen.c
	$(CC) -c $(CFLAGS) -o $@ $<

$(GEN_DIR)/tTestClient_templ.o : $(GEN_DIR)/tTestClient_templ.c
	$(CC) -c $(CFLAGS) -o $@ $<

tTestClient.o : tTestClient.c
	$(CC) -c $(CFLAGS) -o $@ $<

