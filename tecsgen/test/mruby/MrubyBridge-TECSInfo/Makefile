# ���Υե������ tecsgen �ˤ�꼫ư��������ޤ���
# Makefile.temp �� gen �ΰ�ľ�Υǥ��쥯�ȥ�˰ܤ��ƻ��Ѥ��ޤ�
#  % mv Makefile.temp Makefile
# 
# clean �Υǥե����ư��� $(GEN_DIR)/Makefile.* �������ޤ�
#
# ���Υե������ GNU make �� gcc ���Ѥ� POSIX �Ķ���ư���⥸�塼���ӥ�ɤ���Τ�Ŭ�ڤʤ褦����������Ƥ��ޤ�
# vpath, CFLAGS, OTHER_OBJS �ʤɤ�Ĵ������ɬ�פ����뤫�⤷��ޤ���
# ¾�δĶ��䥿�����åȤξ�硢���Υե�����򸵤��ѹ�����ɬ�פ�����ޤ�

# �ѿ� #_MVAR_#
TARGET = SimpleSample.exe
TIMESTAMP = $(GEN_DIR)/tecsgen.timestamp
TECSGEN_EXE = tecsgen
# exerb �Ǥ�Ȥ����ϡ��嵭���ؤ��ơ��ʲ���ͭ���ˤ��Ƥ�������
# TECSGEN_EXE = tecsgen.exe
BASE_DIR = .
CC = gcc
CFLAGS = -I $(BASE_DIR)/. -I ../include -I $(TECSPATH)/../../test/cygwin -I $(TECSPATH) -I $(TECSPATH)/mruby -I $(TECSPATH)/posix -I $(TECSPATH)/rpc -I $(TECSPATH)/TECSInfo -I $(MRUBYPATH)/include -I $(GEN_DIR) -D "Inline=static inline"
LD = gcc
LDFLAGS = -L $(MRUBYLDPATH) -lm -lmruby
GEN_DIR = $(BASE_DIR)/gen
SRC_DIR = $(BASE_DIR)/src
_TECS_OBJ_DIR = $(GEN_DIR)/
#   _TECS_OBJ_DIR   # should end with '/'
PRE_TECSGEN_TARGET =
POST_TECSGEN_TARGET =

vpath %.c $(SRC_DIR) $(GEN_DIR)  $(TECSPATH)/../../test/cygwin $(TECSPATH) $(TECSPATH)/mruby $(TECSPATH)/posix $(TECSPATH)/rpc $(TECSPATH)/TECSInfo $(MRUBYPATH)/include
vpath %.h $(SRC_DIR) $(GEN_DIR)  $(TECSPATH)/../../test/cygwin $(TECSPATH) $(TECSPATH)/mruby $(TECSPATH)/posix $(TECSPATH)/rpc $(TECSPATH)/TECSInfo $(MRUBYPATH)/include

OTHER_OBJS =                      # Add objects out of tecs care.
# OTHER_OBJS = $(_TECS_OBJ_DIR)vasyslog.o

# Additional VARS
# CHANGE this into suitable path

# Place this line before any target. first target described here
include ../Makefile.common

# �롼�� #_MRUL_#
allall: mruby mruby_lib tecs
	make all     # in order to include generated Makefile.tecsgen & Makefile.depend

all : $(TARGET)


# depend �� include #_MDEP_#
-include $(GEN_DIR)/Makefile.tecsgen
-include $(GEN_DIR)/Makefile.depend

$(TARGET) : $(TIMESTAMP) $(CELLTYPE_COBJS) $(TECSGEN_COBJS) $(PLUGIN_COBJS) $(OTHER_OBJS)
	$(LD) -o $(TARGET) $(TECSGEN_COBJS) $(CELLTYPE_COBJS) $(PLUGIN_COBJS) $(OTHER_OBJS) $(LDFLAGS)
clean :
	rm -f $(CELLTYPE_COBJS) $(TECSGEN_COBJS) $(PLUGIN_COBJS) $(OTHER_OBJS) $(TARGET)  $(TIMESTAMP)
	rm -rf $(GEN_DIR)

tecs : $(PRE_TECSGEN_TARGET) $(TIMESTAMP) $(POST_TECSGEN_TARGET)

$(TIMESTAMP) : $(TECS_IMPORTS)
	$(TECSGEN_EXE)  -I $(TECSPATH)/../../test/cygwin SimpleSample.cdl
	touch $(TIMESTAMP)

#####  TECSFlow targets  #####
tecsflow : $(GEN_DIR)/tecsgen.rbdmp tcflow
	tecsflow -g $(GEN_DIR)

tecsflow_u : $(GEN_DIR)/tecsgen.rbdmp tcflow
	tecsflow -g $(GEN_DIR) -U

$(GEN_DIR)/tecsgen.rbdmp : tecs

tcflow : tecs
	make tcflow_exec

tcflow_exec : $(GEN_DIR)/tcflow.rbdmp
$(GEN_DIR)/tcflow.rbdmp : $(CELLTYPE_SRCS) $(PLUGIN_CELLTYPE_SRCS)
	tcflow -g $(GEN_DIR) -c '$(CC) -E -DTECSFLOW -DTECSGEN $(CFLAGS) -I ./' $^
#####  end TECSFlow targets  #####

# generic target for objs
# generic target for objs
$(_TECS_OBJ_DIR)%.o : %.c
	$(CC) -c $(CFLAGS) -o $@ $<

$(_TECS_OBJ_DIR)tSample.o : tSample.c
	$(CC) -c $(CFLAGS) -o $@ $<
 
$(_TECS_OBJ_DIR)nMruby_tTECSInitializer.o : nMruby_tTECSInitializer.c
	$(CC) -c $(CFLAGS) -o $@ $<
 
$(_TECS_OBJ_DIR)nMruby_tCharPointer.o : nMruby_tCharPointer.c
	$(CC) -c $(CFLAGS) -o $@ $<
 
$(_TECS_OBJ_DIR)nMruby_tMrubyProc.o : nMruby_tMrubyProc.c
	$(CC) -c $(CFLAGS) -o $@ $<
 
$(_TECS_OBJ_DIR)nMruby_tsSample.o : nMruby_tsSample.c
	$(CC) -c $(CFLAGS) -o $@ $<
 
$(_TECS_OBJ_DIR)nMruby_tsSample_Initializer.o : nMruby_tsSample_Initializer.c
	$(CC) -c $(CFLAGS) -o $@ $<
 
$(_TECS_OBJ_DIR)nC2TECS_tnPosix_sMain.o : nC2TECS_tnPosix_sMain.c
	$(CC) -c $(CFLAGS) -o $@ $<
 