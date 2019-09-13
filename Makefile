#----------------------------------------------------------------------------
#       Macros
#----------------------------------------------------------------------------
CC            = gcc
CXX           = g++
LD            = $(CXX) $(CCFLAGS) $(CPPFLAGS)
AR            = ar
PICFLAGS      = -fPIC
CPPFLAGS      = $(PICFLAGS) $(GENFLAGS) -std=c++11 -D_REENTRANT
OBJEXT        = .o
OUTPUT_OPTION = -o "$@"
COMPILE.c     = $(CC) $(CFLAGS) $(CPPFLAGS) -c
COMPILE.cc    = $(CXX) $(CCFLAGS) $(CPPFLAGS) -c
LDFLAGS       = -L"."
CCC           = $(CXX)
MAKEFILE      = Makefile.assignment4
DEPENDENCIES  = .depend.$(MAKEFILE)
BTARGETDIR    = ./
BIN           = $(BTARGETDIR)assignment4$(EXESUFFIX)$(EXEEXT)
CAT           = cat
MV            = mv -f
RM            = rm -rf
CP            = cp -p
NUL           = /dev/null
MKDIR         = mkdir -p
TESTDIRSTART  = test -d
TESTDIREND    = ||
TOUCH         = touch
EXEEXT        = 
LIBPREFIX     = lib
LIBSUFFIX     = 
GENFLAGS      = -O
LDLIBS        = -ldl $(subst lib,-l,$(sort $(basename $(notdir $(wildcard /usr/lib/librt.so /lib/librt.so))))) -lpthread
OBJS          = Add_Expr_Node$(OBJEXT) Bin_Expr_Node$(OBJEXT) Calculator$(OBJEXT) Div_Expr_Node$(OBJEXT) driver$(OBJEXT) Eval_Expr_Tree$(OBJEXT) Expr_Builder$(OBJEXT) Expr_Node_Visitor$(OBJEXT) Expr_Node$(OBJEXT) Expr_Tree_Builder$(OBJEXT) Expr_Tree$(OBJEXT) Math_Expr$(OBJEXT) Mod_Expr_Node$(OBJEXT) Mult_Expr_Node$(OBJEXT) Num_Expr_Node$(OBJEXT) Sub_Expr_Node$(OBJEXT) Unary_Expr_Node$(OBJEXT)
SRC           = Add_Expr_Node.cpp Bin_Expr_Node.cpp Calculator.cpp Div_Expr_Node.cpp driver.cpp Eval_Expr_Tree.cpp Expr_Builder.cpp Expr_Node_Visitor.cpp Expr_Node.cpp Expr_Tree_Builder.cpp Expr_Tree.cpp Math_Expr.cpp Mod_Expr_Node.cpp Mult_Expr_Node.cpp Num_Expr_Node.cpp Sub_Expr_Node.cpp Unary_Expr_Node.cpp
LINK.cc       = $(LD) $(LDFLAGS)
EXPORTFLAGS   = 
DEPLIBS       = $(foreach lib, , $(foreach libpath, ., $(wildcard $(libpath)/lib$(lib).a)))

#----------------------------------------------------------------------------
#       Local targets
#----------------------------------------------------------------------------

all: $(BIN)

$(BIN): $(OBJS) $(DEPLIBS)
	@$(TESTDIRSTART) "$(BTARGETDIR)" $(TESTDIREND) $(MKDIR) "$(BTARGETDIR)"
	$(LINK.cc) $(OBJS) $(LDLIBS) $(OUTPUT_OPTION)

generated: $(GENERATED_DIRTY)
	@-:

Add_Expr_Node$(OBJEXT): Add_Expr_Node.cpp
	$(COMPILE.cc) $(EXPORTFLAGS) $(OUTPUT_OPTION) Add_Expr_Node.cpp

Bin_Expr_Node$(OBJEXT): Bin_Expr_Node.cpp
	$(COMPILE.cc) $(EXPORTFLAGS) $(OUTPUT_OPTION) Bin_Expr_Node.cpp

Calculator$(OBJEXT): Calculator.cpp
	$(COMPILE.cc) $(EXPORTFLAGS) $(OUTPUT_OPTION) Calculator.cpp

Div_Expr_Node$(OBJEXT): Div_Expr_Node.cpp
	$(COMPILE.cc) $(EXPORTFLAGS) $(OUTPUT_OPTION) Div_Expr_Node.cpp

driver$(OBJEXT): driver.cpp
	$(COMPILE.cc) $(EXPORTFLAGS) $(OUTPUT_OPTION) driver.cpp

Eval_Expr_Tree$(OBJEXT): Eval_Expr_Tree.cpp
	$(COMPILE.cc) $(EXPORTFLAGS) $(OUTPUT_OPTION) Eval_Expr_Tree.cpp

Expr_Builder$(OBJEXT): Expr_Builder.cpp
	$(COMPILE.cc) $(EXPORTFLAGS) $(OUTPUT_OPTION) Expr_Builder.cpp

Expr_Node_Visitor$(OBJEXT): Expr_Node_Visitor.cpp
	$(COMPILE.cc) $(EXPORTFLAGS) $(OUTPUT_OPTION) Expr_Node_Visitor.cpp

Expr_Node$(OBJEXT): Expr_Node.cpp
	$(COMPILE.cc) $(EXPORTFLAGS) $(OUTPUT_OPTION) Expr_Node.cpp

Expr_Tree_Builder$(OBJEXT): Expr_Tree_Builder.cpp
	$(COMPILE.cc) $(EXPORTFLAGS) $(OUTPUT_OPTION) Expr_Tree_Builder.cpp

Expr_Tree$(OBJEXT): Expr_Tree.cpp
	$(COMPILE.cc) $(EXPORTFLAGS) $(OUTPUT_OPTION) Expr_Tree.cpp

Math_Expr$(OBJEXT): Math_Expr.cpp
	$(COMPILE.cc) $(EXPORTFLAGS) $(OUTPUT_OPTION) Math_Expr.cpp

Mod_Expr_Node$(OBJEXT): Mod_Expr_Node.cpp
	$(COMPILE.cc) $(EXPORTFLAGS) $(OUTPUT_OPTION) Mod_Expr_Node.cpp

Mult_Expr_Node$(OBJEXT): Mult_Expr_Node.cpp
	$(COMPILE.cc) $(EXPORTFLAGS) $(OUTPUT_OPTION) Mult_Expr_Node.cpp

Num_Expr_Node$(OBJEXT): Num_Expr_Node.cpp
	$(COMPILE.cc) $(EXPORTFLAGS) $(OUTPUT_OPTION) Num_Expr_Node.cpp

Sub_Expr_Node$(OBJEXT): Sub_Expr_Node.cpp
	$(COMPILE.cc) $(EXPORTFLAGS) $(OUTPUT_OPTION) Sub_Expr_Node.cpp

Unary_Expr_Node$(OBJEXT): Unary_Expr_Node.cpp
	$(COMPILE.cc) $(EXPORTFLAGS) $(OUTPUT_OPTION) Unary_Expr_Node.cpp

clean:
	-$(RM) $(OBJS)

realclean: clean
	-$(RM) $(BIN)

check-syntax:
	$(COMPILE.cc) $(EXPORTFLAGS) -Wall -Wextra -pedantic -fsyntax-only $(CHK_SOURCES)

#----------------------------------------------------------------------------
#       Dependencies
#----------------------------------------------------------------------------


depend:
	-$(MPC_ROOT)/depgen.pl  $(CFLAGS) $(CCFLAGS) $(CPPFLAGS) -f $(DEPENDENCIES) $(SRC) 2> $(NUL)

-include $(DEPENDENCIES)
